#include "Lesson07_GUI.h"

Engine::Lesson07_GUI::Lesson07_GUI(Setting* setting) :Engine::Game(setting)
{
	setting->windowTitle = "GUI Demo";
}

Engine::Lesson07_GUI::~Lesson07_GUI()
{
}

void Engine::Lesson07_GUI::Init()
{


	Engine::ScreenManager::GetInstance(this)->AddScreen("ingame", new TopDownCapy(setting,timeScore,0,0,false))
		->AddScreen("platformLevel", new PlatformCapy(setting,timeScore))
		->AddScreen("mainmenu", new MainMenuScreen())->SetCurrentScreen("mainmenu");
	
}

void Engine::Lesson07_GUI::Update()
{
	timeScore += GetGameTime()/1000;
	Engine::ScreenManager::GetInstance(this)->Update();
}

void Engine::Lesson07_GUI::Render()
{
	Engine::ScreenManager::GetInstance(this)->Draw();
}





