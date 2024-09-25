#include "Logger.h"

#include <spdlog/spdlog.h>
#include <spdlog/common.h>

namespace NOPEEngine {
	Shared<spdlog::logger> Logger::sCoreLogger = nullptr;
	Shared<spdlog::logger> Logger::sClientLogger = nullptr;

	void Logger::Init() {
		// Example: [11:11:00] [NOPEEngine::Application:Init:11] [NOPEEngine] [thread 1000] Logger works
		spdlog::set_pattern("%^[%H:%M:%S] [%!:%#] [%n] [thread %t] %v%$");

		sCoreLogger = spdlog::stdout_color_mt("NOPEEngine");
		sCoreLogger->set_level(spdlog::level::trace);

		sClientLogger = spdlog::stdout_color_mt("Client");
		sClientLogger->set_level(spdlog::level::trace);
	}
}