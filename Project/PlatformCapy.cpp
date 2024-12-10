#include "PlatformCapy.h"
#include <iomanip>
#include <sstream> 

using namespace Engine;

PlatformCapy::PlatformCapy(Setting* setting, float time)
{
	setting->windowTitle = "Platform Capy";
	gameSetting = setting;
	timeScore = time;
}


PlatformCapy::~PlatformCapy()
{
	delete dotTexture;
	delete monsterSprite;
	delete dotSprite1;
	delete dotSprite2;
	delete dotSprite3;
	delete dotSprite4;
	delete music;
	delete text;
}

void PlatformCapy::Init()
{
	// 1
	Texture* platformTexture = new Texture("platforms8.png");
	vec2 start = vec2(270, 160);
	int tilesPerPlatform = 5; // Number of tiles to repeat per platform section

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < tilesPerPlatform; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile = new Sprite(platformTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile->SetSize(platformWidth, platformHeight)
				->SetPosition(start.x + i * 250 + j * platformWidth, start.y + i * -25);
			platformTile->SetBoundingBoxSize(platformTile->GetScaleWidth(), platformTile->GetScaleHeight());
			platforms.push_back(platformTile);
		}
	}

	//2
	Texture* platformTexture2 = new Texture("platforms8.png");
	vec2 start2 = vec2(100, 250);
	int tilesPerPlatform2 = 3; // Number of tiles to repeat per platform section

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < tilesPerPlatform2; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile2 = new Sprite(platformTexture2, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile2->SetSize(platformWidth, platformHeight)
				->SetPosition(start2.x + i * 480 + j * platformWidth, start2.y + i * 0);
			platformTile2->SetBoundingBoxSize(platformTile2->GetScaleWidth(), platformTile2->GetScaleHeight());
			platforms.push_back(platformTile2);
		}
	}

	//3
	Texture* platformTexture3 = new Texture("platforms8.png");
	vec2 start3 = vec2(900, 240);
	int tilesPerPlatform3 = 2; // Number of tiles to repeat per platform section

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < tilesPerPlatform3; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile3 = new Sprite(platformTexture3, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile3->SetSize(platformWidth, platformHeight)
				->SetPosition(start3.x + i * -200 + j * platformWidth, start3.y + i * 90);
			platformTile3->SetBoundingBoxSize(platformTile3->GetScaleWidth(), platformTile3->GetScaleHeight());
			platforms.push_back(platformTile3);
		}
	}

	//4
	Texture* platformTexture4 = new Texture("platforms8.png");
	vec2 start4 = vec2(780, 330);
	int tilesPerPlatform4 = 2; // Number of tiles to repeat per platform section

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < tilesPerPlatform4; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile4 = new Sprite(platformTexture4, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile4->SetSize(platformWidth, platformHeight)
				->SetPosition(start4.x + i * -375 + j * platformWidth, start4.y + i * -40);
			platformTile4->SetBoundingBoxSize(platformTile4->GetScaleWidth(), platformTile4->GetScaleHeight());
			platforms.push_back(platformTile4);
		}
	}

	//5
	Texture* platformTexture5 = new Texture("platforms8.png");
	vec2 start5 = vec2(830, 420);
	int tilesPerPlatform5 = 2; // Number of tiles to repeat per platform section

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < tilesPerPlatform5; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile5 = new Sprite(platformTexture5, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile5->SetSize(platformWidth, platformHeight)
				->SetPosition(start5.x + i * -270 + j * platformWidth, start5.y + i * -30);
			platformTile5->SetBoundingBoxSize(platformTile5->GetScaleWidth(), platformTile5->GetScaleHeight());
			platforms.push_back(platformTile5);
		}
	}

	//6
	Texture* platformTexture6 = new Texture("platforms8.png");
	vec2 start6 = vec2(900, 500);
	int tilesPerPlatform6 = 2; // Number of tiles to repeat per platform section

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < tilesPerPlatform6; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile6 = new Sprite(platformTexture6, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile6->SetSize(platformWidth, platformHeight)
				->SetPosition(start6.x + i * -270 + j * platformWidth, start6.y + i * -40);
			platformTile6->SetBoundingBoxSize(platformTile6->GetScaleWidth(), platformTile6->GetScaleHeight());
			platforms.push_back(platformTile6);
		}
	}

	//7
	Texture* platformTexture7 = new Texture("platforms8.png");
	vec2 start7 = vec2(775, 550);
	int tilesPerPlatform7 = 2; // Number of tiles to repeat per platform section

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < tilesPerPlatform7; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile7 = new Sprite(platformTexture7, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile7->SetSize(platformWidth, platformHeight)
				->SetPosition(start7.x + i * -150 + j * platformWidth, start7.y + i * -20);
			platformTile7->SetBoundingBoxSize(platformTile7->GetScaleWidth(), platformTile7->GetScaleHeight());
			platforms.push_back(platformTile7);
		}
	}

	//8
	Texture* platformTexture8 = new Texture("platforms8.png");
	vec2 start8 = vec2(170, 440);
	int tilesPerPlatform8 = 3; // Number of tiles to repeat per platform section

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < tilesPerPlatform8; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile8 = new Sprite(platformTexture8, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile8->SetSize(platformWidth, platformHeight)
				->SetPosition(start8.x + i * -150 + j * platformWidth, start8.y + i * -20);
			platformTile8->SetBoundingBoxSize(platformTile8->GetScaleWidth(), platformTile8->GetScaleHeight());
			platforms.push_back(platformTile8);
		}
	}

	//9
	Texture* platformTexture9 = new Texture("platforms8.png");
	vec2 start9 = vec2(70, 490);
	int tilesPerPlatform9 = 2; // Number of tiles to repeat per platform section

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < tilesPerPlatform9; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile9 = new Sprite(platformTexture9, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile9->SetSize(platformWidth, platformHeight)
				->SetPosition(start9.x + i * -150 + j * platformWidth, start9.y + i * -20);
			platformTile9->SetBoundingBoxSize(platformTile9->GetScaleWidth(), platformTile9->GetScaleHeight());
			platforms.push_back(platformTile9);
		}
	}

	//10
	Texture* platformTexture10 = new Texture("platforms8.png");
	vec2 start10 = vec2(200, 600);
	int tilesPerPlatform10 = 2; // Number of tiles to repeat per platform section

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < tilesPerPlatform10; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile10 = new Sprite(platformTexture10, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile10->SetSize(platformWidth, platformHeight)
				->SetPosition(start10.x + i * 170 + j * platformWidth, start10.y + i * 20);
			platformTile10->SetBoundingBoxSize(platformTile10->GetScaleWidth(), platformTile10->GetScaleHeight());
			platforms.push_back(platformTile10);
		}
	}

	//11
	Texture* platformTexture11 = new Texture("platforms8.png");
	vec2 start11 = vec2(1000, 70);
	int tilesPerPlatform11 = 2; // Number of tiles to repeat per platform section

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < tilesPerPlatform11; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile11 = new Sprite(platformTexture11, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile11->SetSize(platformWidth, platformHeight)
				->SetPosition(start11.x + i * 150 + j * platformWidth, start11.y + i * 10);
			platformTile11->SetBoundingBoxSize(platformTile11->GetScaleWidth(), platformTile11->GetScaleHeight());
			platforms.push_back(platformTile11);
		}
	}

	//12
	Texture* platformTexture12 = new Texture("platforms8.png");
	vec2 start12 = vec2(1230, 170);
	int tilesPerPlatform12 = 3; // Number of tiles to repeat per platform section

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < tilesPerPlatform12; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile12 = new Sprite(platformTexture12, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile12->SetSize(platformWidth, platformHeight)
				->SetPosition(start12.x + i * 140 + j * platformWidth, start12.y + i * 30);
			platformTile12->SetBoundingBoxSize(platformTile12->GetScaleWidth(), platformTile12->GetScaleHeight());
			platforms.push_back(platformTile12);
		}
	}

	//13
	Texture* platformTexture13 = new Texture("platforms8.png");
	vec2 start13 = vec2(1170, 320);
	int tilesPerPlatform13 = 2; // Number of tiles to repeat per platform section

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < tilesPerPlatform13; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile13 = new Sprite(platformTexture13, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile13->SetSize(platformWidth, platformHeight)
				->SetPosition(start13.x + i * 150 + j * platformWidth, start13.y + i * -30);
			platformTile13->SetBoundingBoxSize(platformTile13->GetScaleWidth(), platformTile13->GetScaleHeight());
			platforms.push_back(platformTile13);
		}
	}

	//14
	Texture* platformTexture14 = new Texture("platforms8.png");
	vec2 start14 = vec2(1000, 390);
	int tilesPerPlatform14 = 2; // Number of tiles to repeat per platform section

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < tilesPerPlatform14; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile14 = new Sprite(platformTexture14, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile14->SetSize(platformWidth, platformHeight)
				->SetPosition(start14.x + i * 130 + j * platformWidth, start14.y + i * 40);
			platformTile14->SetBoundingBoxSize(platformTile14->GetScaleWidth(), platformTile14->GetScaleHeight());
			platforms.push_back(platformTile14);
		}
	}

	//15
	Texture* platformTexture15 = new Texture("platforms8.png");
	vec2 start15 = vec2(1000, 580);
	int tilesPerPlatform15 = 2; // Number of tiles to repeat per platform section

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < tilesPerPlatform15; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile15 = new Sprite(platformTexture15, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile15->SetSize(platformWidth, platformHeight)
				->SetPosition(start15.x + i * 140 + j * platformWidth, start15.y + i * 10);
			platformTile15->SetBoundingBoxSize(platformTile15->GetScaleWidth(), platformTile15->GetScaleHeight());
			platforms.push_back(platformTile15);
		}
	}

	//16
	Texture* platformTexture16 = new Texture("platforms8.png");
	vec2 start16 = vec2(1280, 700);
	int tilesPerPlatform16 = 3; // Number of tiles to repeat per platform section

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < tilesPerPlatform16; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile16 = new Sprite(platformTexture16, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile16->SetSize(platformWidth, platformHeight)
				->SetPosition(start16.x + i * -200 + j * platformWidth, start16.y + i * 5);
			platformTile16->SetBoundingBoxSize(platformTile16->GetScaleWidth(), platformTile16->GetScaleHeight());
			platforms.push_back(platformTile16);
		}
	}

	//17
	Texture* platformTexture17 = new Texture("platforms8.png");
	vec2 start17 = vec2(150, 750);
	int tilesPerPlatform17 = 3; // Number of tiles to repeat per platform section

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < tilesPerPlatform17; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile17 = new Sprite(platformTexture17, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile17->SetSize(platformWidth, platformHeight)
				->SetPosition(start17.x + i * 250 + j * platformWidth, start17.y + i * 10);
			platformTile17->SetBoundingBoxSize(platformTile17->GetScaleWidth(), platformTile17->GetScaleHeight());
			platforms.push_back(platformTile17);
		}
	}

	//Create background
	Texture* bgTexture1 = new Texture("bg_fix.png");
	backgroundSprite = (new Sprite(bgTexture1, game->GetDefaultSpriteShader(), game->GetDefaultQuad()))->SetSize((float)game->GetSettings()->screenWidth, (float)game->GetSettings()->screenHeight);

	// a capy spritesheet has 7 cols and 2 rows (total frames = 6x2 = 12 frames)
	Texture* monsterTexture = new Texture("capy_sprite.png");
	monsterSprite = new Sprite(monsterTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	monsterSprite->SetPosition(0, 0)->SetNumXFrames(7)->SetNumYFrames(3)->SetAnimationDuration(100)->SetScale(0.5f)
		->AddAnimation("idle", 0, 4)
		->AddAnimation("walk", 5, 9)
		->AddAnimation("jump", 20, 20);

	monsterSprite->SetBoundingBoxSize(monsterSprite->GetScaleWidth() - (32 * monsterSprite->GetScale()),
		monsterSprite->GetScaleHeight() - (32 * monsterSprite->GetScale()));


	// init key
	Texture* keyTexture = new Texture("key_sprite.png");
	keySprite = new Sprite(keyTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	keySprite->SetPosition(50, 750)->SetNumXFrames(3)->SetNumYFrames(3)->SetAnimationDuration(100)->SetScale(3.0f)
		->AddAnimation("stay", 0, 6);

	
	keySprite->SetBoundingBoxSize(keySprite->GetScaleWidth() - (32 * keySprite->GetScale()),
		keySprite->GetScaleHeight() - (32 * keySprite->GetScale()));

	// This dot sprite is for visual debugging (to see the actual bounding box) 
	dotTexture = new Texture("dot.png");
	dotSprite1 = new Sprite(dotTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	dotSprite2 = new Sprite(dotTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	dotSprite3 = new Sprite(dotTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	dotSprite4 = new Sprite(dotTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());

	// Add input mapping 
	game->GetInputManager()->AddInputMapping("Walk Right", SDLK_RIGHT)
		->AddInputMapping("Walk Left", SDLK_LEFT)
		->AddInputMapping("Walk Right", SDLK_RIGHT)
		//->AddInputMapping("Walk Up", SDLK_UP)
		//->AddInputMapping("Walk Down", SDLK_DOWN)
		->AddInputMapping("Run Right", SDL_CONTROLLER_BUTTON_DPAD_RIGHT)
		->AddInputMapping("Run Left", SDL_CONTROLLER_BUTTON_DPAD_LEFT)
		->AddInputMapping("Jump", SDLK_SPACE)
		->AddInputMapping("Attack", SDL_CONTROLLER_BUTTON_X)
		->AddInputMapping("Quit", SDLK_ESCAPE)
		->AddInputMapping("Quit", SDL_CONTROLLER_BUTTON_Y);

	// Playing music
	music = (new Music("2021-08-16_-8_Bit_Adventure-_www.FesliyanStudios.com.ogg"))->SetVolume(40)->Play(true);

	sound = (new Sound("jump.wav"))->SetVolume(0);

	text = new Text("lucon.ttf", 45, game->GetDefaultTextShader());
	text->SetScale(1.0f)->SetColor(255, 255, 255)->SetPosition(0, game->GetSettings()->screenHeight - (text->GetFontSize() * text->GetScale()));

	//Set the background color
	game->SetBackgroundColor(102, 195, 242);

	// Set debug
	debug = true;
}

void PlatformCapy::Update()
{
	// If user press "Quit" key then exit
	if (game->GetInputManager()->IsKeyReleased("Quit")) {
		game->SetState(State::EXIT);
		return;
	}
	
	keySprite->PlayAnim("stay");
	monsterSprite->PlayAnim("idle");

	// Move monster sprite using keyboard
	vec2 oldMonsterPos = monsterSprite->GetPosition();
	float x = oldMonsterPos.x, y = oldMonsterPos.y;
	if (game->GetInputManager()->IsKeyPressed("Walk Right")) {
		x += 0.2f * game->GetGameTime();
		monsterSprite->PlayAnim("walk")->SetFlipHorizontal(true);
	}

	if (game->GetInputManager()->IsKeyPressed("Walk Left")) {
		x -= 0.2f * game->GetGameTime();
		monsterSprite->PlayAnim("walk")->SetFlipHorizontal(false);
	}

	monsterSprite->SetPosition(x, y);

	for (Sprite* s : platforms) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			monsterSprite->SetPosition(x, y);
			break;
		}
	}

	if (game->GetInputManager()->IsKeyPressed("Jump") && !jump) {
		//Set gravity and yVelocity
		monsterSprite->PlayAnim("jump");
		float ratio = (game->GetGameTime() / 20.0f);
		gravity = 0.12f * ratio;
		yVelocity = 1.1f;
		jump = true;
		sound->Play(false);
	}

	if (y > 0) {
		yVelocity -= gravity;
	}
	else if (y < 0) {
		jump = false;
		yVelocity = 0;
		y = 0;
	}


	y += yVelocity * game->GetGameTime();
	monsterSprite->SetPosition(x, y);

	for (Sprite* s : platforms) {
		if (s->GetBoundingBox()->CollideWith(monsterSprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldMonsterPos.y;
			monsterSprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}

	if (game->GetInputManager()->IsKeyPressed("Attack")) {
		monsterSprite->PlayAnim("attack");
	}

	//Time Text
	timeScore += game->GetGameTime() / 1000;

	// Konversi time menjadi string dengan 2 angka belakang koma
	std::ostringstream timeStream;
	timeStream << std::fixed << std::setprecision(2) << timeScore;

	// Gunakan hasil stream sebagai text
	text
		->SetScale(1.0f)
		->SetColor(255, 255, 255)
		->SetPosition(gameSetting->screenWidth - 550, game->GetSettings()->screenHeight - (text->GetFontSize() * text->GetScale()))
		->SetText("Score = " + timeStream.str() + " second");

	monsterSprite->Update(game->GetGameTime());
	keySprite->Update(game->GetGameTime());

	if (monsterSprite->GetBoundingBox()->CollideWith(keySprite->GetBoundingBox())) {
		ScreenManager::GetInstance(game)->UpdateScreen("ingame", new TopDownCapy(gameSetting, timeScore,200,770,true));
		ScreenManager::GetInstance(game)->SetCurrentScreen("ingame");
	}
	if (debug) {
		//Shape for debug
		BoundingBox* bb = monsterSprite->GetBoundingBox();
		dotSprite1->SetPosition(bb->GetVertices()[0].x - (0.5f * dotSprite1->GetScaleWidth()),
			bb->GetVertices()[0].y - (0.5f * dotSprite1->GetScaleHeight()));
		dotSprite2->SetPosition(bb->GetVertices()[1].x - (0.5f * dotSprite2->GetScaleWidth()),
			bb->GetVertices()[1].y - (0.5f * dotSprite2->GetScaleHeight()));
		dotSprite3->SetPosition(bb->GetVertices()[2].x - (0.5f * dotSprite3->GetScaleWidth()),
			bb->GetVertices()[2].y - (0.5f * dotSprite3->GetScaleHeight()));
		dotSprite4->SetPosition(bb->GetVertices()[3].x - (0.5f * dotSprite4->GetScaleWidth()),
			bb->GetVertices()[3].y - (0.5f * dotSprite3->GetScaleHeight()));
	}

}

void PlatformCapy::Draw()
{
	backgroundSprite->Draw();
	text->Draw();
	for (Sprite* s : platforms) {
		s->Draw();
	}
	monsterSprite->Draw();
	keySprite->Draw();


	if (debug) {
		dotSprite1->Draw();
		dotSprite2->Draw();
		dotSprite3->Draw();
		dotSprite4->Draw();
	}

}