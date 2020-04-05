#include "pch.h"
#include "ndmtEngine.h"

namespace mt
{
	ndmtEngine::ndmtEngine()
	{
		m_hConsoleIn = GetStdHandle(STD_INPUT_HANDLE);
		m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		m_hOriginConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		m_nScreenWidth = 30;
		m_nScreenHeight = 20;
		m_rect = { 0, 0, 1, 1 };
		m_appName = L"Default";
	}

	ndmtEngine::~ndmtEngine()
	{
		SetConsoleActiveScreenBuffer(m_hOriginConsole);
		delete[] m_buffer;
	}

	int ndmtEngine::ConstructConsole(short w, short h, short fontw, short fonth, std::wstring appName)
	{
		if (m_hConsole == INVALID_HANDLE_VALUE)
			return Error(L"Bad Handle");

		m_nScreenWidth = w;
		m_nScreenHeight = h;
		m_appName = appName;


		//set to default
		//so we can set other size for buffer
		m_rect = { 0,0,1,1 };
		if (!SetConsoleWindowInfo(m_hConsole, TRUE, &m_rect))
			return Error(L"SetConsoleWindowInfo");

		COORD coord = { m_nScreenWidth, m_nScreenHeight };
		if (!SetConsoleScreenBufferSize(m_hConsole, coord))
			return Error(L"SetConsoleScreenBufferSize");

		if (!SetConsoleActiveScreenBuffer(m_hConsole))
			return Error(L"SetConsoleActiveScreenBuffer");

		//set font info
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.dwFontSize.X = fontw;
		cfi.dwFontSize.Y = fonth;
		cfi.FontFamily = FF_DONTCARE;
		cfi.nFont = 0;
		cfi.FontWeight = FW_NORMAL;

		wcscpy_s(cfi.FaceName, L"Consolas");
		if (!SetCurrentConsoleFontEx(m_hConsole, FALSE, &cfi))
			return Error(L"SetConsoleFont");

		//valid size screen
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		if (!GetConsoleScreenBufferInfo(m_hConsole, &csbi))
			return Error(L"GetConsoleScreenBufferInfo");
		if (m_nScreenWidth > csbi.dwMaximumWindowSize.X)
			return Error(L"Screen Width Too Big");
		if (m_nScreenHeight > csbi.dwMaximumWindowSize.Y)
			return Error(L"Screen Height Too Big");

		// Set Console Mode
		if (!SetConsoleMode(m_hConsoleIn, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT))
			return Error(L"SetConsoleMode");

		//set window size
		m_rect = { 0, 0, m_nScreenWidth - 1, m_nScreenHeight - 1 };
		SetConsoleWindowInfo(m_hConsole, TRUE, &m_rect);
		m_buffer = new CHAR_INFO[m_nScreenWidth * m_nScreenHeight];
		memset((void*)m_buffer, 0, sizeof(CHAR_INFO) * m_nScreenWidth * m_nScreenHeight);

		return 1;
	}

	void ndmtEngine::DrawPoint(int x, int y, short ch, short col)
	{
		if (x < m_nScreenWidth && x >= 0 && y < m_nScreenHeight && y >= 0)
		{
			m_buffer[m_nScreenWidth * y + x].Char.UnicodeChar = ch;
			m_buffer[m_nScreenWidth * y + x].Attributes = col;
		}
	}

	void ndmtEngine::draw(const Drawable* object)
	{
		Drawable* a = const_cast<Drawable*>(object);
		a->draw(this);
	}

	void ndmtEngine::clear()
	{
		for (int y = 0; y < m_nScreenHeight; y++)
		{
			for (int x = 0; x < m_nScreenWidth; x++)
			{
				m_buffer[y * m_nScreenWidth + x].Char.UnicodeChar = PIXEL_SOLID;
				m_buffer[y * m_nScreenWidth + x].Attributes = FG_BLACK;
			}
		}
	}

	void ndmtEngine::start()
	{
		gameThread();
	}


	int ndmtEngine::gameThread()
	{
		if (!OnUserCreate())
			return Error(L"OnUserCreate");

		Clock clock;

		// Fast as possible as
		while (1)
		{
			// Handle timing
			float fElapseTime = clock.getElapsedTime();

			if (!OnUserUpdate(fElapseTime))
				break;

			wchar_t title[256];
			swprintf_s(title, 256, L"ndmtEngine - %s - FPS: %3.2f", m_appName.c_str(), 1.0f / fElapseTime);
			SetConsoleTitle(title);
			WriteConsoleOutput(m_hConsole, m_buffer, { m_nScreenWidth, m_nScreenHeight }, { 0,0 }, &m_rect);
		}

		return 1;
	}


	bool ndmtEngine::OnUserDestroy()
	{
		return true;
	}


	int ndmtEngine::Error(const wchar_t* msg)
	{
		wchar_t buff[256];
		FormatMessage(
			FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,
			GetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			buff,
			256,
			NULL);
		SetConsoleActiveScreenBuffer(m_hOriginConsole);
		std::wcout << msg << std::endl << buff << std::endl;

		return 0;
	}
}