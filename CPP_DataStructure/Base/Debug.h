#pragma once

namespace Debug
{
	#define LeakCheck _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	#define MsgBoxAssert(TEXT) MessageBoxA(nullptr, TEXT, "Fatal Error", MB_OK), assert(false);
}
