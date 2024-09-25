#include "Application.h"

int main() {
	NOPEEngine::Application* application = NOPEEngine::CreateApplication();

	if (application->Init()) {
		application->Run();
	}

	application->Shutdown();
	NOPE_FREE_MEMORY(application);

	return 0;
}
