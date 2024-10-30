//
// Created by ADMIN on 9/23/2024.
//
#include<NOPEEngine/Core/Entry.h>
#include <NOPEEngine/Window/Window.h>
#include<Core/Logger/Logger.h>

class Game : public NOPEEngine::Application {
public:
	Game(const NOPEEngine::ApplicationConfiguration& config) : NOPEEngine::Application(config) {};

	virtual void OnInitClient() override {
		LOG_INFO("Game is init");
	};

	virtual void OnShutdownClient() override {
		LOG_INFO("Game is shutdown");
	};
};

NOPEEngine::Application* NOPEEngine::CreateApplication() {
	NOPEEngine::ApplicationConfiguration appConfig;
	appConfig.Width = 800;
	appConfig.Height = 600;
	appConfig.WindowTitle = "Nope Engine Alpha ver";
	appConfig.WindowSpec = NOPEEngine::EWindowPlatformSpec::GLFW;

	return new Game(appConfig);
}
