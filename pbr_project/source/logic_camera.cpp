//
//  camera.cpp
//  p_b_r_project
//
//  Created by Mikhail Kavalyan on 4/13/20.
//  Copyright © 2020 Spraylight. All rights reserved.
//

#include "logic_camera.h"

using namespace Murl;

App::LogicCamera::LogicCamera(Logic::IFactory* factory) : BaseProcessor(factory)
{
    
}

Bool App::LogicCamera::OnInit(const Logic::IState* state)
{
    Graph::IRoot* root = state->GetGraphRoot();

    AddGraphNode(mCamera.GetReference(root, "MainCamera"));
    AddGraphNode(mCameraTransform.GetReference(root, "MainCameraTransform"));
    AddGraphNode(mCameraRotateTransform.GetReference(root, "MainCameraRotateTransform"));
    
    return true;
}


void App::LogicCamera::OnProcessTick(const Logic::IState* state)
{
    Logic::IDeviceHandler* deviceHandler = state->GetDeviceHandler();

    //Double tickDuration = state->GetCurrentTickDuration();
        
    Real x = 0;
    Real y = 0;
    
    if (deviceHandler->WasMouseButtonPressed(IEnums::MOUSE_BUTTON_LEFT))
    {
        deviceHandler->GetMousePosition(mouseCurrentX, mouseCurrentY);
        
        mousePreviousX = mouseCurrentX;
        mousePreviousY = mouseCurrentY;
    }

    if (deviceHandler->IsMouseButtonPressed(IEnums::MOUSE_BUTTON_LEFT))
    {
        deviceHandler->GetMousePosition(mouseCurrentX, mouseCurrentY);
        
        yawAngle += mouseCurrentX - mousePreviousX;
        pitchAngle += mouseCurrentY - mousePreviousY;

        if(pitchAngle < -1.57079f || pitchAngle > 1.57079f)
        {
            pitchAngle = 1.57078f * pitchAngle / Math::Abs(pitchAngle);
        }
        
        mCameraRotateTransform->SetRotation(pitchAngle, -yawAngle, 0);

        if(pitchAngle < -1.57079f || pitchAngle > 1.57079f)
        {
            pitchAngle = 1.57078f * pitchAngle / Math::Abs(pitchAngle);
        }
        mCameraRotateTransform->SetRotation(pitchAngle, -yawAngle, 0.0);
        
        mousePreviousX = mouseCurrentX;
        mousePreviousY = mouseCurrentY;
    }
    
    if(deviceHandler->GetRawWheelDelta(x, y))
    {
        cameraPosZ -= y;
        
        if(cameraPosZ > 12001.f)
            cameraPosZ = 12000.f;
        
        if(cameraPosZ < 5199.f)
            cameraPosZ = 5200.f;
        
        mCameraTransform->GetTransformInterface()->SetPositionZ(cameraPosZ);
    }
}
