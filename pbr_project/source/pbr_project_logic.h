// Copyright 2015 Spraylight

#ifndef __PBR_PROJECT_LOGIC_H__
#define __PBR_PROJECT_LOGIC_H__

#include "murl_app_types.h"
#include "murl_logic_base_processor.h"
#include "logic_camera.h"
#include "logic_ui.h"

namespace Murl
{
    namespace App
    {
        class PbrProjectLogic : public Logic::BaseProcessor
        {
        public:
            PbrProjectLogic(Logic::IFactory* factory);
            virtual ~PbrProjectLogic();

        protected:
            virtual Bool OnInit(const Logic::IState* state);
            virtual Bool OnDeInit(const Logic::IState* state);
            virtual void OnProcessTick(const Logic::IState* state);
            
            LogicUI mUserInterface;
            LogicCamera mMainCamera;
        };
    }
}

#endif  // __PBR_PROJECT_LOGIC_H__
