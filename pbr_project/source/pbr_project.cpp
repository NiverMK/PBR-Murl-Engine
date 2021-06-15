// Copyright 2015 Spraylight

#include "murl_app.h"
#include "pbr_project_app.h"

using namespace Murl;

IApp* App::CreateApp()
{
    return new PbrProjectApp;
}

void App::DestroyApp(IApp* app)
{
    Util::Release(app);
}
