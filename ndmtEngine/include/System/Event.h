#pragma once

#include "System/Export.h"
#include <Windows.h>
#include "System/Vector2.h"

namespace mt
{
	enum MouseCode
	{
		MC_LEFT = 0,
		MC_RIGHT = 1,
		MC_MIDDLE = 2
	};

	class NDMTENGINE_API Event
	{
	public:
		static bool isKeyPressed(int virtualKeyCode);
		static bool isKeyHold(int virtualKeyCode);
		static bool isKeyReleased(int virtualKeyCode);
		static bool isMousePressed(int index);
		static bool isMouseHold(int index);
		static bool isMouseReleased(int index);
		static const Vector2i& getMousePosition();

		Event();

	private:
		static HANDLE m_hConsoleIn;
		static short m_keyOldState[256];
		static short m_keyNewState[256];

		static bool m_mouseNewState[5];
		static bool m_mouseOldState[5];
		static Vector2i m_posMouse;

		struct KeyState
		{
			bool pressed;
			bool held;
			bool released;
		};

		static KeyState m_keys[256];
		static KeyState m_mouse[5];


		void update();
	};
}

