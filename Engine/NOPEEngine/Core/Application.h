//
// Created by ADMIN on 9/22/2024.
//
#pragma once
#include <pch.h>
#include "Window/Window.h"
#include "Event/EventDispatcher.h"

namespace NOPEEngine {
	struct NOPE_API ApplicationConfiguration {
		int Width, Height;
		const char* WindowTitle;
		EWindowPlatformSpec WindowSpec;
	};

	class NOPE_API Application {
	public:
		virtual ~Application() = default;

		bool Init();

		virtual void OnInitClient() = 0;

		void Run();

		void Shutdown();

		virtual void OnShutdownClient() = 0;

	protected:
		Application() = default;

		Application(const ApplicationConfiguration&);

	private:
		bool OnWindowResizeEvent(const WindowResizedEvent&);

	private:
		ApplicationConfiguration mConfig;
		Unique<NativeWindow> mNativeWindow;
		EventDispatcher mEventDispatcher;
	};

	extern Application* CreateApplication();
}
