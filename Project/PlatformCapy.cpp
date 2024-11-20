#include "PlatformCapy.h"

using namespace Engine;

PlatformCapy::PlatformCapy(Setting* setting)
{
	setting->windowTitle = "Platform Capy";
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
	vec2 start = vec2(300, 120);
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

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < tilesPerPlatform2; j++) {
			float platformWidth = 32; // Set to the width of your platform texture
			float platformHeight = 32; // Set to the height of your platform texture
			Sprite* platformTile2 = new Sprite(platformTexture2, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
			platformTile2->SetSize(platformWidth, platformHeight)
				->SetPosition(start2.x + i * 900 + j * platformWidth, start2.y + i * -100);
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
	int tilesPerPlatform5 = 1; // Number of tiles to repeat per platform section

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

	text = new Text("lucon.ttf", 24, game->GetDefaultTextShader());
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

	// Update monster sprite animation
	monsterSprite->Update(game->GetGameTime());

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

	if (debug) {
		dotSprite1->Draw();
		dotSprite2->Draw();
		dotSprite3->Draw();
		dotSprite4->Draw();
	}

}