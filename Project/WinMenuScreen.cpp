#include "WinMenuScreen.h"
#include <iostream>
#include <sstream>
#include <iomanip>


Engine::WinMenuScreen::WinMenuScreen(Setting* setting, float time)
{
	text = NULL;
	score = time;
}

void Engine::WinMenuScreen::Init()
{

	// Create a Texture
	Texture* texture = new Texture("buttons.png");

	// Create Sprites
	Sprite* playSprite = (new Sprite(texture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()))
		->SetNumXFrames(6)->SetNumYFrames(1)->AddAnimation("normal", 5, 5)->AddAnimation("hover", 3, 4)
		->AddAnimation("press", 3, 4)->SetAnimationDuration(400);

	Sprite* exitSprite = (new Sprite(texture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()))
		->SetNumXFrames(6)->SetNumYFrames(1)->AddAnimation("normal", 2, 2)->AddAnimation("hover", 0, 1)
		->AddAnimation("press", 0, 1)->SetAnimationDuration(400);

	//Create Background
	Texture* bgTexture = new Texture("winMenuBackground.png");
	backgroundSprite = (new Sprite(bgTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()))->SetSize((float)game->GetSettings()->screenWidth, (float)game->GetSettings()->screenHeight);


	//Create Background
	if (score < 40) {
		Texture* starsTexture = new Texture("3stars.png");
		starsSprite = (new Sprite(starsTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()))->SetSize((float)game->GetSettings()->screenWidth, (float)game->GetSettings()->screenHeight);
	}
	else if (score < 60) {
		Texture* starsTexture = new Texture("2stars.png");
		starsSprite = (new Sprite(starsTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()))->SetSize((float)game->GetSettings()->screenWidth, (float)game->GetSettings()->screenHeight);
	}
	else if (score < 120) {
		Texture* starsTexture = new Texture("1stars.png");
		starsSprite = (new Sprite(starsTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()))->SetSize((float)game->GetSettings()->screenWidth, (float)game->GetSettings()->screenHeight);
	}else{
		Texture* starsTexture = new Texture("nostars.png");
		starsSprite = (new Sprite(starsTexture, game->GetDefaultSpriteShader(), game->GetDefaultQuad()))->SetSize((float)game->GetSettings()->screenWidth, (float)game->GetSettings()->screenHeight);
	}

	//Create Buttons
	Button* playButton = new Button(playSprite, "play");
	playButton->SetPosition((game->GetSettings()->screenWidth / 2 + 300) - (playSprite->GetScaleWidth() / 2),
		250);
	buttons.push_back(playButton);

	Button* exitButton = new Button(exitSprite, "exit");
	exitButton->SetPosition((game->GetSettings()->screenWidth / 2 + 300) - (exitSprite->GetScaleWidth() / 2),
		150);
	buttons.push_back(exitButton);

	// Set play button into active button
	currentButtonIndex = 0;
	buttons[currentButtonIndex]->SetButtonState(Engine::ButtonState::HOVER);

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2) << score;
	std::string result = oss.str() + " Second";
	std::cout << result << std::endl;

	// Create Text
	text = (new Text("8-bit Arcade In.ttf", 100, game->GetDefaultTextShader()))
		->SetText(result)->SetPosition(game->GetSettings()->screenWidth * 0.5f + 25 , game->GetSettings()->screenHeight - 500)->SetColor(0, 0, 0);

	// Add input mappings
	game->GetInputManager()->AddInputMapping("next", SDLK_DOWN)
		->AddInputMapping("prev", SDLK_UP)
		->AddInputMapping("press", SDLK_SPACE);

	
	if (score != 0) {
		//add music
		//scoreSound = (new Sound("score_level.ogg"))->SetVolume(40);
		//scoreSound->Play(true);
	}
}


void Engine::WinMenuScreen::Update()
{
	// Set background
	game->SetBackgroundColor(52, 155, 235);

	if (game->GetInputManager()->IsKeyReleased("Walk Down")) {
		// Set previous button to normal state
		buttons[currentButtonIndex]->SetButtonState(Engine::ButtonState::NORMAL);
		// Next Button
		currentButtonIndex = (currentButtonIndex < (int)buttons.size() - 1) ? currentButtonIndex + 1 : currentButtonIndex;
		// Set current button to hover state
		buttons[currentButtonIndex]->SetButtonState(Engine::ButtonState::HOVER);
	}

	if (game->GetInputManager()->IsKeyReleased("Walk Up")) {
		// Set previous button to normal state
		buttons[currentButtonIndex]->SetButtonState(Engine::ButtonState::NORMAL);
		// Prev Button
		currentButtonIndex = currentButtonIndex > 0 ? currentButtonIndex - 1 : currentButtonIndex;
		// Set current button to hover state
		buttons[currentButtonIndex]->SetButtonState(Engine::ButtonState::HOVER);
	}

	if (game->GetInputManager()->IsKeyReleased("Jump")) {
		// Set current button to press state
		Button* b = buttons[currentButtonIndex];
		b->SetButtonState(Engine::ButtonState::PRESS);
		// If play button then go to InGame, exit button then exit
		if ("play" == b->GetButtonName()) {
			ScreenManager::GetInstance(game)->UpdateScreen("ingame", new TopDownCapy(game->GetSettings(), 0, 0, 0, false))->SetCurrentScreen("ingame");
		}
		else if ("exit" == b->GetButtonName()) {
			game->SetState(Engine::State::EXIT);
		}
	}

	// Update All buttons
	for (Button* b : buttons) {
		b->Update(game->GetGameTime());
	}

}

void Engine::WinMenuScreen::Draw()
{
	backgroundSprite->Draw();
	starsSprite->Draw();
	text->Draw();

	// Render all buttons
	for (Button* b : buttons) {
		b->Draw();
	}
}