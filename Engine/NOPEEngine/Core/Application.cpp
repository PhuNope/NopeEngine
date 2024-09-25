//
// Created by ADMIN on 9/22/2024.
//

#include "Application.h"
#include <iostream>
#include"Logger/Logger.h"

namespace NOPEEngine {
	Application::Application(const ApplicationConfiguration& config) : mConfig(config) {
		Logger::Init();
	};

	void Application::Run() {
		CORE_LOG_INFO("App is running: {0}, {1}, {2}", mConfig.Width, mConfig.Height, mConfig.WindowTitle);
	};
}
