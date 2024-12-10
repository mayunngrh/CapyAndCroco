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
#include "PlatformCapy.h"

namespace Engine {
	class TopDownCapy : public Engine::Screen {
	public:
		TopDownCapy(Setting* setting, float time, int xPos, int yPos, bool getKey);
		~TopDownCapy();
		virtual void Init();
		virtual void Update();
		virtual void Draw();
	private:
		Texture* dotTexture = NULL;
		vector<Sprite*> platforms;
		Sprite* capySprite = NULL;
		Sprite* caveSprite = NULL;
		Sprite* crocoSprite = NULL;
		Sprite* backgroundSprite = NULL;
		Sprite* dotSprite1 = NULL;
		Sprite* dotSprite2 = NULL;
		Sprite* dotSprite3 = NULL;
		Sprite* dotSprite4 = NULL;
		Music* music = NULL;;
		Sound* sound = NULL;
		Text* timeText = NULL;
		Text* text = NULL;
		Setting* gameSetting = NULL;
		float timeScore = 0;
		float yVelocity = 0, gravity = 0;
		bool jump = false, debug = false;
		bool isGetKey = false; string currentText = "";
		float textTime = 0; int xCapy = 0; int yCapy = 0;
		bool isCrocoSave = false;
	};
}

#endif 
