#include "Window.h"
#include "pch.h"

#include "Core/Application.h"
#include "Core/Logger/Logger.h"

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace NOPEEngine {
	GLFWPlatformWindow::GLFWPlatformWindow() : mWindow(nullptr) {}

	GLFWPlatformWindow::~GLFWPlatformWindow() {}

	bool GLFWPlatformWindow::Init(const struct ApplicationConfiguration& config, EventDispatcher* eventDispatcher) {
		if (!glfwInit()) {
			CORE_LOG_CRITICAL("GLFW init failed!");
			return false;
		}

		// Setup context for OpenGL 4.3 Core
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		mWindow = glfwCreateWindow(config.Width, config.Height, config.WindowTitle, nullptr, nullptr);
		if (!mWindow) {
			CORE_LOG_CRITICAL("Window created failed!");
			glfwTerminate();
			return false;
		}

		CORE_LOG_INFO("Window created success!");

		glfwMakeContextCurrent(mWindow);

		mData.Dispatcher = eventDispatcher;

		glfwSetWindowUserPointer(mWindow, &mData);

		glfwSetWindowSizeCallback(mWindow, [](GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);

			WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);
			data->Width = width;
			data->Height = height;
			WindowResizedEvent eventContext(width, height);
			data->Dispatcher->DispatchEventListener<WindowResizedEvent>(eventContext);
								  }
		);

		if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress)) {
			CORE_LOG_CRITICAL("GLAD loaded fail!");
			glfwTerminate();
			return false;
		}

		CORE_LOG_INFO("GLAD loaded success!");

		return true;
	}

	void GLFWPlatformWindow::ShutDown() {
		glfwTerminate();
	}
	void GLFWPlatformWindow::SwapBuffers() {
		glClearColor(1.0f, 0.3f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mWindow);
	}

	void GLFWPlatformWindow::PoolEvents() {
		glfwPollEvents();
	}

	bool GLFWPlatformWindow::ShouldClose() {
		return glfwWindowShouldClose(mWindow);
	}
}