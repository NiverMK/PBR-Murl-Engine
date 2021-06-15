//
//  camera.hpp
//  p_b_r_project
//
//  Created by Mikhail Kavalyan on 4/13/20.
//  Copyright © 2020 Spraylight. All rights reserved.
//

#ifndef camera_hpp
#define camera_hpp

#include "murl_app_types.h"
#include "murl_logic_base_processor.h"

namespace Murl
{
    namespace App
    {
    class LogicCamera : public Logic::BaseProcessor
        {
        public:

            LogicCamera(Logic::IFactory* factory);
    
        protected:
            Real mouseCurrentX = 0.f;
            Real mouseCurrentY = 0.f;
            Real mousePreviousX = 0.f;
            Real mousePreviousY = 0.f;
            Real yawAngle = 0.f;
            Real pitchAngle = 0.f;
            Real cameraPosZ = 5000.f;
            
            Murl::Logic::CameraNode mCamera;
            Murl::Logic::CameraTransformNode mCameraTransform;
            Murl::Logic::TransformNode mCameraRotateTransform;
            
            virtual Bool OnInit(const Logic::IState* state);
            virtual void OnProcessTick(const Logic::IState* state);
        };
    }
}

#endif /* camera_hpp */
