#include "EngineFramework/Engine.h"

int main()
{
    EngineSetting::RefreshEngineSetting();
    Engine::Init();
    Engine::Run();
    return 0;
}