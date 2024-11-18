#pragma once

#ifndef TOP_DOWN_CAPY
#define TOP_DOWN_CAPY

#include "Game.h"
#include "Screen.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"
#include "Text.h"
#include "ScreenManager.h"
#include "Music.h"
#include "Sound.h"

namespace Engine {
	class TopDownCapy : public Engine::Screen {
	public:
		TopDownCapy(Setting* setting);
		~TopDownCapy();
		virtual void Init();
		virtual void Update();
		virtual void Draw();
	private:
		Texture* dotTexture = NULL;
		vector<Sprite*> platforms;
		Sprite* capySprite = NULL;
		Sprite* backgroundSprite = NULL;
		Sprite* dotSprite1 = NULL;
		Sprite* dotSprite2 = NULL;
		Sprite* dotSprite3 = NULL;
		Sprite* dotSprite4 = NULL;
		Music* music = NULL;;
		Sound* sound = NULL;
		Text* text = NULL;
		float yVelocity = 0, gravity = 0;
		bool jump = false, debug = false;
	};
}

#endif 
