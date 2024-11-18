#include "Lesson10_Platform.h"

using namespace Engine;

Lesson10_Platform::Lesson10_Platform(Setting* setting) :Game(setting)
{
	setting->windowTitle = "Platform";
}


Lesson10_Platform::~Lesson10_Platform()
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

void Lesson10_Platform::Init()
{
	// Generate Platforms
	Texture* platformTexture = new Texture("batu.png");
	vec2 start = vec2(200, 90);
	
	int maze[20][20] = {
	{1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0},
	{1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1},
	{1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1},
	{0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1},
	{1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1},
	{1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0},
	{1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0},
	{1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},
	{0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0},
	{1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0},
	{1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0},
	{1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1}
	};

	int mazeWidth = 20;  // Updated maze width
	int mazeHeight = 20; // Updated maze height

	int spriteWidth = 40*2;  // Adjusted sprite width for better fit
	int spriteHeight = 28*2; // Adjusted sprite height for better fit
	int spacing = 2;  // Space between platforms

	// Loop to create the maze sprites
	for (int y = 0; y < mazeHeight; y++) {
		for (int x = 0; x < mazeWidth; x++) {
			// Check the maze layout: if it's a wall (1), create a sprite
			if (maze[y][x] == 0) {
				Sprite* platformSprite = new Sprite(platformTexture, defaultSpriteShader, defaultQuad);
				platformSprite->SetSize(spriteWidth, spriteHeight)
					->SetPosition(start.x + x * (spriteWidth + spacing), start.y + y * (spriteHeight + spacing));
				platformSprite->SetBoundingBoxSize(platformSprite->GetScaleWidth() - (16 * platformSprite->GetScale()), platformSprite->GetScaleHeight());
				platforms.push_back(platformSprite);
			}
		}
	}



	//Create background
	Texture* bgTexture = new Texture("tanah.png");
	backgroundSprite = (new Sprite(bgTexture, defaultSpriteShader, defaultQuad))->SetSize((float)setting->screenWidth, (float)setting->screenHeight);

	// a capy spritesheet has 7 cols and 2 rows (total frames = 6x2 = 12 frames)
	Texture* monsterTexture = new Texture("capy_sprite.png");
	monsterSprite = new Sprite(monsterTexture, defaultSpriteShader, defaultQuad);
	monsterSprite->SetPosition(0, 0)->SetNumXFrames(7)->SetNumYFrames(3)->SetAnimationDuration(100)->SetScale(0.4f)
		->AddAnimation("idle", 0, 4)
		->AddAnimation("walk", 5, 9)
		->AddAnimation("walk_down", 10,14)
		->AddAnimation("walk_up", 15, 19)
		->AddAnimation("jump", 20, 20);

	monsterSprite->SetBoundingBoxSize(monsterSprite->GetScaleWidth() - (16 * monsterSprite->GetScale()),
		monsterSprite->GetScaleHeight() - (16 * monsterSprite->GetScale()));

	// This dot sprite is for visual debugging (to see the actual bounding box) 
	dotTexture = new Texture("dot.png");
	dotSprite1 = new Sprite(dotTexture, defaultSpriteShader, defaultQuad);
	dotSprite2 = new Sprite(dotTexture, defaultSpriteShader, defaultQuad);
	dotSprite3 = new Sprite(dotTexture, defaultSpriteShader, defaultQuad);
	dotSprite4 = new Sprite(dotTexture, defaultSpriteShader, defaultQuad);

	// Add input mapping 
	inputManager->AddInputMapping("Walk Right", SDLK_RIGHT)
		->AddInputMapping("Walk Left", SDLK_LEFT)
		->AddInputMapping("Walk Up", SDLK_UP)
		->AddInputMapping("Walk Down", SDLK_DOWN)
		->AddInputMapping("Attack", SDLK_x)
		->AddInputMapping("Run Right", SDL_CONTROLLER_BUTTON_DPAD_RIGHT)
		->AddInputMapping("Run Left", SDL_CONTROLLER_BUTTON_DPAD_LEFT)
		->AddInputMapping("Jump", SDL_CONTROLLER_BUTTON_A)
		->AddInputMapping("Attack", SDL_CONTROLLER_BUTTON_X)
		->AddInputMapping("Quit", SDLK_ESCAPE)
		->AddInputMapping("Quit", SDL_CONTROLLER_BUTTON_Y);

	// Playing music
	music = (new Music("2021-08-16_-_8_Bit_Adventure_-_www.FesliyanStudios.com.ogg"))->SetVolume(40)->Play(true);

	sound = (new Sound("jump.wav"))->SetVolume(100);

	text = new Text("lucon.ttf", 24, defaultTextShader);
	text->SetScale(1.0f)->SetColor(255, 255, 255)->SetPosition(0, setting->screenHeight - (text->GetFontSize() * text->GetScale()));

	//Set the background color
	SetBackgroundColor(102, 195, 242);

	// Set debug
	debug = true;
}

void Lesson10_Platform::Update()
{
	// If user press "Quit" key then exit
	if (inputManager->IsKeyReleased("Quit")) {
		state = State::EXIT;
		return;
	}

	text->SetText(("[FPS = " + to_string(currentFrameRate)) +
		"] Right-Left-Up-X to Move, Jump, Attack");

	monsterSprite->PlayAnim("idle");

	// Move monster sprite using keyboard
	vec2 oldMonsterPos = monsterSprite->GetPosition();
	float x = oldMonsterPos.x, y = oldMonsterPos.y;
	if (inputManager->IsKeyPressed("Walk Right")) {
		x += 0.2f * GetGameTime();
		monsterSprite->PlayAnim("walk")->SetFlipHorizontal(true);
	}

	if (inputManager->IsKeyPressed("Walk Left")) {
		x -= 0.2f * GetGameTime();
		monsterSprite->PlayAnim("walk")->SetFlipHorizontal(false);
	}

	if (inputManager->IsKeyPressed("Walk Up")) {
		y += 0.2f * GetGameTime();
		monsterSprite->PlayAnim("walk_up");
	}

	if (inputManager->IsKeyPressed("Walk Down")) {
		y -= 0.2f * GetGameTime();
		monsterSprite->PlayAnim("walk_down");
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

	if (inputManager->IsKeyPressed("Jump") && !jump) {
		//Set gravity and yVelocity
		monsterSprite->PlayAnim("jump");
		float ratio = (GetGameTime() / 16.7f);
		gravity = 0.16f * ratio;
		yVelocity = 1.8f;
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


	y += yVelocity * GetGameTime();
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

	if (inputManager->IsKeyPressed("Attack")) {
		monsterSprite->PlayAnim("attack");
	}

	// Update monster sprite animation
	monsterSprite->Update(GetGameTime());

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

void Lesson10_Platform::Render()
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

