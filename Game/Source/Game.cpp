//
// Created by ADMIN on 9/23/2024.
//
#include<NOPEEngine/Core/Entry.h>
#include<iostream>
#include<Core/Logger/Logger.h>

class Game : public NOPEEngine::Application {
public:
	Game(const NOPEEngine::ApplicationConfiguration& config) : NOPEEngine::Application(config) {};

	virtual bool Init() override {
		LOG_INFO("Game is init");
		return true;
	};

	virtual void Shutdown() override {
		LOG_INFO("Game is shutdown");
	};
};

NOPEEngine::Application* NOPEEngine::CreateApplication() {
	NOPEEngine::ApplicationConfiguration appConfig;
	appConfig.Width = 800;
	appConfig.Height = 600;
	appConfig.WindowTitle = "Nope Engine Alpha ver";

	return new Game(appConfig);
}
