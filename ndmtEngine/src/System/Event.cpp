#include "pch.h"
#include "System/Event.h"

namespace mt
{
	HANDLE Event::m_hConsoleIn = GetStdHandle(STD_INPUT_HANDLE);
	short Event::m_keyOldState[256]{ 0 };
	short Event::m_keyNewState[256]{ 0 };
	Event::KeyState Event::m_keys[256]{ 0 };

	bool Event::m_mouseNewState[5]{ false };
	bool Event::m_mouseOldState[5]{ false };
	Event::KeyState Event::m_mouse[5]{ false };
	Vector2i Event::m_posMouse(0, 0);

	Event::Event()
	{
		update();
	}

	bool Event::isKeyPressed(int virtualKeyCode)
	{
		if (virtualKeyCode < 0 || virtualKeyCode > 255)
			return false;

		return (m_keys[virtualKeyCode].pressed);

	}

	bool Event::isKeyHold(int virtualKeyCode)
	{
		if (virtualKeyCode < 0 || virtualKeyCode > 255)
			return false;

		return (m_keys[virtualKeyCode].held);
	}

	bool Event::isKeyReleased(int virtualKeyCode)
	{
		if (virtualKeyCode < 0 || virtualKeyCode > 255)
			return false;

		return (m_keys[virtualKeyCode].released);
	}

	bool Event::isMousePressed(int index)
	{
		if (index < 0 || index >= 5)
			return false;

		return (m_mouse[index].pressed);
	}

	bool Event::isMouseHold(int index)
	{
		if (index < 0 || index >= 5)
			return false;

		return (m_mouse[index].held);
	}

	bool Event::isMouseReleased(int index)
	{
		if (index < 0 || index >= 5)
			return false;

		return (m_mouse[index].released);
	}

	const Vector2i& Event::getMousePosition()
	{
		return m_posMouse;
	}

	void Event::update()
	{
		// Handle Keyboard
		for (int i = 0; i < 256; i++)
		{
			m_keyNewState[i] = GetAsyncKeyState(i);

			m_keys[i].pressed = false;
			m_keys[i].released = false;

			if (m_keyNewState[i] != m_keyOldState[i])
			{
				if (m_keyNewState[i] & 0x8000)
				{
					m_keys[i].pressed = !m_keys[i].held;
					m_keys[i].held = true;
				}
				else
				{
					m_keys[i].released = true;
					m_keys[i].held = false;
				}
			}

			m_keyOldState[i] = m_keyNewState[i];
		}

		// Handle Mouse
		INPUT_RECORD inBuf[32];
		DWORD events = 0;
		GetNumberOfConsoleInputEvents(m_hConsoleIn, &events);

		if (events > 0)
			ReadConsoleInput(m_hConsoleIn, inBuf, events, &events);

		for (DWORD i = 0; i < events; i++)
		{
			switch (inBuf[i].EventType)
			{
			case FOCUS_EVENT:
			{

			}
			break;

			case MOUSE_EVENT:
			{
				switch (inBuf[i].Event.MouseEvent.dwEventFlags)
				{
				case MOUSE_MOVED:
				{
					m_posMouse.x = inBuf[i].Event.MouseEvent.dwMousePosition.X;
					m_posMouse.y = inBuf[i].Event.MouseEvent.dwMousePosition.Y;
				}
				break;

				case 0:
				{
					for (int m = 0; m < 5; m++)
						m_mouseNewState[m] = (inBuf[i].Event.MouseEvent.dwButtonState & (1 << m)) > 0;
				}
				break;

				default:
					break;
				}
			}
			break;

			}
		}

		for (int i = 0; i < 5; i++)
		{
			m_mouse[i].pressed = false;
			m_mouse[i].released = false;

			if (m_mouseNewState[i] != m_mouseOldState[i])
			{
				if (m_mouseNewState[i])
				{
					m_mouse[i].pressed = true;
					m_mouse[i].held = true;
				}
				else
				{
					m_mouse[i].released = true;
					m_mouse[i].held = false;
				}
			}

			m_mouseOldState[i] = m_mouseNewState[i];
		}
	}
}