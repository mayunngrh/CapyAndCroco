#ifndef Lesson07_GUI_H
#define Lesson07_GUI_H

#include "Game.h"
#include "Setting.h"
#include "MainMenuScreen.h"
#include "InGameScreen.h"
#include "TopDownCapy.h"
#include "PlatformCapy.h"
#include "WinMenuScreen.h"

namespace Engine {
	class Lesson07_GUI :public Engine::Game
	{
	public:
		Lesson07_GUI(Setting* setting);
		~Lesson07_GUI();
		virtual void Init();
		virtual void Update();
		virtual void Render();
		float timeScore = 0;
	};
}

#endif

