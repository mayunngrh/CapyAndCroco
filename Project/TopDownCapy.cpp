#include "TopDownCapy.h"
#include <iomanip>
#include <sstream> 

using namespace Engine;

TopDownCapy::TopDownCapy(Setting* setting, float time){
	setting->windowTitle = "Top Down Level Capy";
	gameSetting = setting;
	timeScore = time;

}


TopDownCapy::~TopDownCapy(){
    delete dotTexture;
    delete capySprite;
    delete dotSprite1;
    delete dotSprite2;
    delete dotSprite3;
    delete dotSprite4;
    delete music;
    delete text;
	delete timeText;
}


void TopDownCapy::Init() {
	// Generate MAZE
	Texture* platformTexture = new Texture("batu.png");
	vec2 start = vec2(0, 0);

	int maze[20][25] = {
	{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};


	int mazeWidth = 20;  // Updated maze width
	int mazeHeight = 20; // Updated maze height

	int spriteWidth = 40 * 2;  // Adjusted sprite width for better fit
	int spriteHeight = 25 * 2; // Adjusted sprite height for better fit
	int spacing = 1;  // Space between platforms

	// Loop to create the maze sprites
	for (int y = 0; y < mazeHeight; y++) {
		for (int x = 0; x < mazeWidth; x++) {
			// Check the maze layout: if it's a wall (1), create a sprite
			if (maze[y][x] == 0) {
				Sprite* platformSprite = new Sprite(platformTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
				platformSprite->SetSize(spriteWidth, spriteHeight)
					->SetPosition(start.x + x * (spriteWidth + spacing), start.y + y * (spriteHeight + spacing));
				platformSprite->SetBoundingBoxSize(platformSprite->GetScaleWidth() - (16 * platformSprite->GetScale()), platformSprite->GetScaleHeight());
				platforms.push_back(platformSprite);
			}
		}
	}



	//Create background
	Texture* bgTexture = new Texture("tanah.png");
	backgroundSprite = (new Sprite(bgTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()))->SetSize((float)game->GetSettings()->screenWidth, (float)game->GetSettings()->screenHeight);

	//INIT CAPY
	Texture* capyTexture = new Texture("capy_sprite.png");
	capySprite = new Sprite(capyTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	capySprite->SetPosition(0, 0)->SetNumXFrames(7)->SetNumYFrames(3)->SetAnimationDuration(100)->SetScale(0.4f)
		->AddAnimation("idle", 0, 4)
		->AddAnimation("walk", 5, 9)
		->AddAnimation("walk_down", 10, 14)
		->AddAnimation("walk_up", 15, 19)
		->AddAnimation("jump", 20, 20);

	capySprite->SetBoundingBoxSize(capySprite->GetScaleWidth() - (16 * capySprite->GetScale()),
		capySprite->GetScaleHeight() - (16 * capySprite->GetScale()));


	//INIT CAVE
	Texture* caveTexture = new Texture("cave.png");
	caveSprite = new Sprite(caveTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	caveSprite->SetPosition(0, 720)->SetScale(0.7f);
	caveSprite->SetBoundingBoxSize(caveSprite->GetScaleWidth() - (16 * caveSprite->GetScale()),
		caveSprite->GetScaleHeight() - (16 * caveSprite->GetScale()));

	//INIT CROCO
	Texture* crocoTexture = new Texture("croco_jeruji.png");
	crocoSprite = new Sprite(crocoTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	crocoSprite->SetPosition(1300, 0)->SetNumXFrames(2)->SetNumYFrames(1)->SetAnimationDuration(100)->SetScale(0.8f)
		->AddAnimation("close", 0, 0)
		->AddAnimation("open", 1, 1);
	crocoSprite->SetBoundingBoxSize(crocoSprite->GetScaleWidth() - (16 * crocoSprite->GetScale()),
		crocoSprite->GetScaleHeight() - (16 * crocoSprite->GetScale()));



	// This dot sprite is for visual debugging (to see the actual bounding box) 
	dotTexture = new Texture("dot.png");
	dotSprite1 = new Sprite(dotTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	dotSprite2 = new Sprite(dotTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	dotSprite3 = new Sprite(dotTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());
	dotSprite4 = new Sprite(dotTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad());

	// Add input mapping 
	game->GetInputManager()->AddInputMapping("Walk Right", SDLK_RIGHT)
		->AddInputMapping("Walk Left", SDLK_LEFT)
		->AddInputMapping("Walk Up", SDLK_UP)
		->AddInputMapping("Walk Down", SDLK_DOWN)
		->AddInputMapping("Attack", SDLK_x)
		->AddInputMapping("Run Right", SDL_CONTROLLER_BUTTON_DPAD_RIGHT)
		->AddInputMapping("Run Left", SDL_CONTROLLER_BUTTON_DPAD_LEFT)
		->AddInputMapping("In", SDLK_k)
		->AddInputMapping("Attack", SDL_CONTROLLER_BUTTON_X)
		->AddInputMapping("Quit", SDLK_ESCAPE)
		->AddInputMapping("Quit", SDL_CONTROLLER_BUTTON_Y)
		->AddInputMapping("press", SDLK_KP_ENTER);

	// Playing music
	music = (new Music("capyBackgroundMusic.ogg"))->SetVolume(40)->Play(true);

	sound = (new Sound("jump.wav"))->SetVolume(100);

	text = new Text("lucon.ttf", 45, game->GetDefaultTextShader());

	timeText = new Text("lucon.ttf", 45, game->GetDefaultTextShader());

	//Set the background color
	game->SetBackgroundColor(102, 195, 242);

	// Set debug
	debug = true;
}

void TopDownCapy::Update() {

	// If user press "Quit" key then exit
	if (game->GetInputManager()->IsKeyReleased("Quit")) {
		game->SetState(State::EXIT);
		return;
	}


	capySprite->PlayAnim("idle");
	crocoSprite->PlayAnim("close");


	// Move monster sprite using keyboard
	vec2 oldMonsterPos = capySprite->GetPosition();
	float x = oldMonsterPos.x, y = oldMonsterPos.y;
	if (game->GetInputManager()->IsKeyPressed("Walk Right")) {
		x += 0.2f * game->GetGameTime();
		capySprite->PlayAnim("walk")->SetFlipHorizontal(true);
	}

	if (game->GetInputManager()->IsKeyPressed("Walk Left")) {
		x -= 0.2f * game->GetGameTime();
		capySprite->PlayAnim("walk")->SetFlipHorizontal(false);
	}

	if (game->GetInputManager()->IsKeyPressed("Walk Up")) {
		y += 0.2f * game->GetGameTime();
		capySprite->PlayAnim("walk_up");
	}

	if (game->GetInputManager()->IsKeyPressed("Walk Down")) {
		y -= 0.2f * game->GetGameTime();
		capySprite->PlayAnim("walk_down");
	}

	capySprite->SetPosition(x, y);

	for (Sprite* s : platforms) {
		if (s->GetBoundingBox()->CollideWith(capySprite->GetBoundingBox())) {
			//revert x position if collided
			x = oldMonsterPos.x;
			capySprite->SetPosition(x, y);
			break;
		}
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
	capySprite->SetPosition(x, y);

	for (Sprite* s : platforms) {
		if (s->GetBoundingBox()->CollideWith(capySprite->GetBoundingBox())) {
			//revert y position if collided
			y = oldMonsterPos.y;
			capySprite->SetPosition(x, y);

			//and set jump to false and yVelovity to 0
			yVelocity = 0;
			jump = false;
			break;
		}
	}

	//MASUK PLATFORM atau CAVE
	if (caveSprite->GetBoundingBox()->CollideWith(capySprite->GetBoundingBox())) {
		x = oldMonsterPos.x;
		capySprite->SetPosition(x, y);


		if (game->GetInputManager()->IsKeyPressed("Jump")) {
			ScreenManager::GetInstance(game)->UpdateScreen("platformLevel", new PlatformCapy(gameSetting, timeScore));
			getKey = true;
			ScreenManager::GetInstance(game)->SetCurrentScreen("platformLevel");
		}

	}

	
	Uint32 messageDuration = 2; // 2 seconds in milliseconds
	std::ostringstream textTime2;
	textTime2 << std::fixed << std::setprecision(2) << textTime;

	// If there is a message currently displayed
	if (currentText != "") {
		// Increment the elapsed time using the game's delta time
		textTime += game->GetGameTime();

		// Reset after 2 seconds (2000 milliseconds)
		if (textTime >= 2000) {
			textTime = 0;          // Reset timer
			currentText = "";      // Clear the message
			text->SetText("");     // Clear the displayed text
		}
	}

	if (capySprite->GetBoundingBox()->CollideWith(crocoSprite->GetBoundingBox())) {
		y = oldMonsterPos.y;
		capySprite->SetPosition(x, y);

		if (game->GetInputManager()->IsKeyPressed("Jump") && !getKey) {
			// Display the elapsed time on the screen
			text->SetText("Please Get Key First!")
				->SetPosition(gameSetting->screenWidth / 2, gameSetting->screenHeight / 2);
			currentText = "Please Get Key First";
		}

		if (game->GetInputManager()->IsKeyPressed("Jump") && getKey) {
			text->SetText("YOU SAVE CROCO");
			crocoSprite->PlayAnim("open");
			currentText = "YOU SAVE CROCO";
		}
	}


	if (game->GetInputManager()->IsKeyPressed("Attack")) {
		capySprite->PlayAnim("attack");
	}

	//Time Text
	timeScore += game->GetGameTime() / 1000;

	// Konversi time menjadi string dengan 2 angka belakang koma
	std::ostringstream timeStream;
	timeStream << std::fixed << std::setprecision(2) << timeScore;

	// Gunakan hasil stream sebagai text
	timeText
		->SetScale(1.0f)
		->SetColor(255, 255, 255)
		->SetPosition(0, game->GetSettings()->screenHeight - (text->GetFontSize() * text->GetScale()))
		->SetText("Score = " + timeStream.str() + " second");

	// Update monster sprite animation
	capySprite->Update(game->GetGameTime());
	crocoSprite->Update(game->GetGameTime());

	if (debug) {
		//Shape for debug
		BoundingBox* bb = capySprite->GetBoundingBox();
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

void TopDownCapy::Draw() {

	backgroundSprite->Draw();
	
	for (Sprite* s : platforms) {
		s->Draw();
	}
	capySprite->Draw();
	caveSprite->Draw();
	crocoSprite->Draw();

	if (debug) {
		dotSprite1->Draw();
		dotSprite2->Draw();
		dotSprite3->Draw();
		dotSprite4->Draw();
	}
	text->Draw();
	timeText->Draw();
}

