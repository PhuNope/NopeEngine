//
// Created by ADMIN on 9/22/2024.
//

namespace NOPEEngine {
	struct NOPE_API ApplicationConfiguration {
		int Width, Height;
		const char* WindowTitle;
	};

	class NOPE_API Application {
	public:
		virtual ~Application() = default;

		virtual bool Init() { return true; };

		void Run();

		virtual void Shutdown() {};

	protected:
		Application() = default;

		Application(const ApplicationConfiguration&);

	private:
		ApplicationConfiguration mConfig;
	};

	extern Application* CreateApplication();
}
