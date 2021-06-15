// Copyright 2015 Spraylight

#ifndef __PBR_PROJECT_APP_H__
#define __PBR_PROJECT_APP_H__

#include "murl_app_base.h"

namespace Murl
{
    namespace App
    {
        class PbrProjectLogic;

        class PbrProjectApp : public AppBase
        {
        public:
            PbrProjectApp();
            virtual ~PbrProjectApp();

            virtual Bool Configure(IEngineConfiguration* engineConfig, IFileInterface* fileInterface);
            virtual Bool Init(const IAppState* appState);
            virtual Bool DeInit(const IAppState* appState);

        protected:
            PbrProjectLogic* mLogic;
        };
    }
}

#endif  // __PBR_PROJECT_APP_H__
