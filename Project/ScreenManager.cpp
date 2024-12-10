#include "ScreenManager.h"

Engine::ScreenManager* Engine::ScreenManager::instance = new ScreenManager();


Engine::ScreenManager::ScreenManager()
{
	engine = nullptr;
	currentScreen = nullptr;
}

void Engine::ScreenManager::Update()
{
	if (currentScreen == nullptr) return;
	currentScreen->Update();
}

void Engine::ScreenManager::Draw()
{
	if (currentScreen == nullptr) return;
	currentScreen->Draw();
}

Engine::ScreenManager* Engine::ScreenManager::AddScreen(string name, Screen* screen)
{
	screen->SetGame(engine);
	screen->Init();
	screens.insert(pair<string, Screen*>(name, screen));
	return this;
}

Engine::ScreenManager* Engine::ScreenManager::UpdateScreen(string name, Screen* screen) {
    if (screen == nullptr) {
        std::cerr << "Error: Cannot update screen. Screen is nullptr." << std::endl;
        return this;
    }

    auto it = screens.find(name);
    if (it != screens.end()) {
        delete it->second;  
        it->second = screen;  
    }
    else {
        screens.insert(std::make_pair(name, screen));
    }

    screen->SetGame(engine);  
    screen->Init();         

    return this;
}




Engine::ScreenManager* Engine::ScreenManager::SetCurrentScreen(string name)
{
	this->currentScreen = screens[name];
	return this;
}


Engine::Screen* Engine::ScreenManager::GetCurrentScreen()
{
	return currentScreen;
}

Engine::Game* Engine::ScreenManager::GetGame()
{
	return engine;
}

Engine::ScreenManager* Engine::ScreenManager::SetGame(Game* engine)
{
	this->engine = engine;
	return this;
}

Engine::ScreenManager* Engine::ScreenManager::GetInstance(Game* engine)
{
	return Engine::ScreenManager::instance->SetGame(engine);
}
