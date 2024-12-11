#ifndef WINMENUSCREEN_H
#define WINMENUSCREEN_H

#include "Screen.h"
#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"
#include "Button.h"
#include "Text.h"
#include "Sound.h"
#include <vector>
#include "ScreenManager.h"
#include "TopDownCapy.h"

namespace Engine {
	class WinMenuScreen :
		public Engine::Screen
	{
	public:
		WinMenuScreen(Setting* setting, float time);
		void Init();
		void Update();
		void Draw();
	private:
		vector<Button*> buttons;
		Text* text;
		Sprite* backgroundSprite = NULL;
		Sprite* starsSprite = NULL;
		Sound* scoreSound = NULL;
		float score = 0;
		int currentButtonIndex = 0;
	};
}

#endif
