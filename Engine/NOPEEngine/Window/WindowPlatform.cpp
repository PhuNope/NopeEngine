#include "WindowPlatform.h"

#include "pch.h"

namespace NOPEEngine {
	NativeWindow* WindowPlatform::Create(EWindowPlatformSpec spec) {
		NativeWindow* window = nullptr;

		switch (spec) {
			case NOPEEngine::EWindowPlatformSpec::GLFW:
				window = new GLFWPlatformWindow();
				break;
			case NOPEEngine::EWindowPlatformSpec::SDL:
				NOPE_ASSERT("SDL window not suppported!");
				break;
			case NOPEEngine::EWindowPlatformSpec::None:
				NOPE_ASSERT("Unknown window detected!");
				break;
			default:
				NOPE_ASSERT("Unknown window detected!");
				break;
		}

		return dynamic_cast<NativeWindow*>(window);
	}
}
