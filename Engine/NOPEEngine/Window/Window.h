#pragma once

class GLFWwindow;

namespace NOPEEngine {
	enum class EWindowPlatformSpec {
		GLFW,
		SDL,
		None
	};

	class EventDispatcher;

	struct WindowData {
		int32_t Width, Height;
		EventDispatcher* Dispatcher;
	};

	class NativeWindow {
	public:
		virtual bool Init(const struct ApplicationConfiguration&, EventDispatcher*) = 0;
		virtual void ShutDown() = 0;
		virtual void SwapBuffers() = 0;
		virtual void PoolEvents() = 0;
		virtual bool ShouldClose() = 0;
		virtual ~NativeWindow() = default;

	protected:
		NativeWindow() = default;
		NativeWindow(NativeWindow&) = default;
	};

	class GLFWPlatformWindow : public NativeWindow {
	public:
		GLFWPlatformWindow();
		~GLFWPlatformWindow();

		virtual bool Init(const struct ApplicationConfiguration&, EventDispatcher*) override;
		virtual void ShutDown() override;
		virtual void SwapBuffers() override;
		virtual void PoolEvents() override;
		virtual bool ShouldClose() override;

	private:
		GLFWwindow* mWindow;
		WindowData mData;
	};
}