//
// Created by ADMIN on 9/22/2024.
//

#include "Application.h"
#include <iostream>

#include"Logger/Logger.h"
#include "Window/WindowPlatform.h"

namespace NOPEEngine {
	Application::Application(const ApplicationConfiguration& config) : mConfig(config), mEventDispatcher() {
		mNativeWindow.reset(WindowPlatform::Create(config.WindowSpec));
	}

	bool Application::OnWindowResizeEvent(const WindowResizedEvent& windowResizeEvent) {
		CORE_LOG_TRACE("Width: {0}, Height: {1}", windowResizeEvent.GetWidth(), windowResizeEvent.GetHeight());
		return false;
	};

	bool Application::Init() {
		Logger::Init();

		if (!mNativeWindow->Init(mConfig, &mEventDispatcher)) {
			return false;
		}

		mEventDispatcher.AddEventListener<WindowResizedEvent>(BIND_EVENT_FUNCTION(OnWindowResizeEvent));

		return true;
	}

	void Application::Run() {
		CORE_LOG_INFO("App is running: {0}, {1}, {2}", mConfig.Width, mConfig.Height, mConfig.WindowTitle);

		OnInitClient();

		while (!mNativeWindow->ShouldClose()) {
			mNativeWindow->SwapBuffers();

			mNativeWindow->PoolEvents();
		}

		OnShutdownClient();
	}

	void Application::Shutdown() {
		mNativeWindow->ShutDown();
	}
}
