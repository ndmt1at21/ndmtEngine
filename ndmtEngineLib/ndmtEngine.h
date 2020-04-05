#pragma once

#include "Graphics/Export.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include "Graphics.h"
#include "System.h"

namespace mt
{
	class ndmtEngine
	{
	protected:
		HANDLE m_hConsoleIn;
		HANDLE m_hConsole;
		HANDLE m_hOriginConsole;
		std::wstring m_appName;
		CHAR_INFO* m_buffer;
		SMALL_RECT m_rect;
		short m_nScreenWidth;
		short m_nScreenHeight;

	public:
		ndmtEngine();
		virtual ~ndmtEngine();

	public:
		int ConstructConsole(short w, short h, short fontw, short fonth, std::wstring appName = L"Default");
		void DrawPoint(int x, int y, short ch = 0x2588, short col = 0x000F);
		void draw(const Drawable* object);
		void clear();
		void start();

	private:
		int gameThread();

	public:
		virtual bool OnUserCreate() = 0;
		virtual bool OnUserUpdate(float fElapseTime) = 0;
		virtual bool OnUserDestroy();

	protected:
		int Error(const wchar_t* msg);
	};
}