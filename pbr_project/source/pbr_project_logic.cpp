// Copyright 2015 Spraylight

#include "pbr_project_logic.h"
#include "murl_system_opengl_es20.h"

using namespace Murl;

App::PbrProjectLogic::PbrProjectLogic(Logic::IFactory* factory)
: BaseProcessor(factory), mMainCamera(factory), mUserInterface(factory)
{
    //CUBEMAP_SEAMLESS
    System::OpenGl::Es20::Enable(0x884F);
}

App::PbrProjectLogic::~PbrProjectLogic()
{
}

Bool App::PbrProjectLogic::OnInit(const Logic::IState* state)
{
    state->GetLoader()->UnloadPackage("startup");

    Graph::IRoot* root = state->GetGraphRoot();

    AddChild(mMainCamera);
    AddChild(mUserInterface);
    
    if (!AreGraphNodesValid())
    {
        return false;
    }

    state->SetUserDebugMessage("PbrProject Init succeeded!");
    return true;
}

Bool App::PbrProjectLogic::OnDeInit(const Logic::IState* state)
{
    return true;
}

void App::PbrProjectLogic::OnProcessTick(const Logic::IState* state)
{
    Logic::IDeviceHandler* deviceHandler = state->GetDeviceHandler();
    //Double tickDuration = state->GetCurrentTickDuration();

    // Exit
    if (deviceHandler->WasRawKeyPressed(RAWKEY_ESCAPE) ||
        deviceHandler->WasRawButtonPressed(RAWBUTTON_BACK))
    {
        deviceHandler->TerminateApp();
    }
}
