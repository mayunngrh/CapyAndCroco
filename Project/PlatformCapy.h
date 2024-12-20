#ifndef PLATFORM_CAPY
#define PLATFORM_CAPY

#include "Game.h"
#include "Setting.h"
#include "Screen.h"
#include "Texture.h"
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "Text.h"
#include <vector>
#include "ScreenManager.h"
#include "TopDownCapy.h"

namespace Engine {
	class PlatformCapy : public Engine::Screen
	{
	public:
		PlatformCapy(Setting* setting, float time);
		~PlatformCapy();
		virtual void Init();
		virtual void Update();
		virtual void Draw();
	private:
		Texture* dotTexture = NULL;
		vector<Sprite*> platforms;
		Sprite* monsterSprite = NULL;
		Sprite* keySprite = NULL;
		Sprite* backgroundSprite = NULL;
		Sprite* dotSprite1 = NULL;
		Sprite* dotSprite2 = NULL;
		Sprite* dotSprite3 = NULL;
		Sprite* dotSprite4 = NULL;
		Music* music = NULL;;
		Sound* sound = NULL;
		Text* text = NULL;
		Setting* gameSetting = NULL;
		float timeScore = 0;
		float yVelocity = 0, gravity = 0;
		bool jump = false, debug = false;
		
	};
}
#endif

