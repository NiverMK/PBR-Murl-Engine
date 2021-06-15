// Copyright 2015 Spraylight

#include "pbr_project_app.h"
#include "pbr_project_logic.h"

using namespace Murl;

App::PbrProjectApp::PbrProjectApp()
: mLogic(0)
{
}

App::PbrProjectApp::~PbrProjectApp()
{
}

Bool App::PbrProjectApp::Configure(IEngineConfiguration* engineConfig, IFileInterface* fileInterface)
{
    IAppConfiguration* appConfig = engineConfig->GetAppConfiguration();
    const IPlatformConfiguration* platformConfig = engineConfig->GetPlatformConfiguration();

    engineConfig->SetProductName("PbrProject");
    appConfig->SetWindowTitle("PbrProject powered by Murl Engine");

    appConfig->SetSystemDebugInfoItems(IEnums::STATISTIC_ITEM_FRAMES_PER_SECOND);

    if (platformConfig->IsTargetHostMatching(IEnums::TARGET_HOST_NATIVE))
    {
        if (platformConfig->IsTargetClassMatching(IEnums::TARGET_CLASS_COMPUTER))
        {
            appConfig->SetDisplaySurfaceSize(1280, 800);
            appConfig->SetFullScreenEnabled(true);
        }
        else if (platformConfig->IsTargetClassMatching(IEnums::TARGET_CLASS_HANDHELD))
        {
            // set landscape
            appConfig->SetScreenOrientation(IEnums::SCREEN_ORIENTATION_LANDSCAPE_1);
            // allow screenorientation
            appConfig->SetOrientationActive(true);
            appConfig->SetAllowedScreenOrientations(IEnums::SCREEN_ORIENTATIONS_ALL);
            appConfig->SetAutoRotationActive(true);
        }
        else if (platformConfig->IsTargetClassMatching(IEnums::TARGET_CLASS_CONSOLE))
        {
            if (platformConfig->IsTargetDeviceMatching(IEnums::TARGET_DEVICE_APPLETV))
            {
                appConfig->SetDebugMouseEnabled(true);
            }
        }
    }

    return true;
}

Bool App::PbrProjectApp::Init(const IAppState* appState)
{
    mLogic = new PbrProjectLogic(appState->GetLogicFactory());
    ILoader* loader = appState->GetLoader();

    if (Util::IsDebugBuild())
    {
        loader->AddPackage("debug", ILoader::LOAD_MODE_STARTUP);
    }

    loader->AddPackage("startup", ILoader::LOAD_MODE_STARTUP);
    loader->AddPackage("main", ILoader::LOAD_MODE_BACKGROUND, mLogic->GetProcessor());
    return true;
}

Bool App::PbrProjectApp::DeInit(const IAppState* appState)
{
    Util::Release(mLogic);
    return true;
}
