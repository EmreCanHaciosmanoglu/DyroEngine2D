#include "Main.h"

#include "Core/Engine.h"
#include "Core/Game/Game.h"

#include "Helpers/Singleton.h"
#include "Diagnostics/Logger.h"

#include "Defines/iostream.h"

#if defined (DEBUG) | defined(_DEBUG)
int _tmain(int argc, char* argv[])
{
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	int return_value = WinMain((HINSTANCE)GetModuleHandle(NULL), 0, 0, SW_SHOW);

	return std::cin.get();
}
#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

#if defined (DEBUG) | defined(_DEBUG)
	HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);

	////Enable run-time memory leak check for debug builds.
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(0);
#endif

	Singleton<Logger>::createInstance();
	Singleton<Logger>::getInstance().initialize();

	Engine engine(new Game());
	int result = engine.mainLoop();

	Singleton<Logger>::getInstance().shutdown();
	Singleton<Logger>::destroyInstance();

	return result;
}