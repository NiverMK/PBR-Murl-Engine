//
//  ui_logic.cpp
//  p_b_r_project
//
//  Created by Mikhail Kavalyan on 4/30/20.
//  Copyright © 2020 Spraylight. All rights reserved.
//

#include "logic_ui.h"

using namespace Murl;

enum Scenes
{
    scene_1 = 0,
    scene_2 = 1,
    scene_3 = 2
} selectedScene;

enum Skyboxes
{
    skybox_1 = 0,
    skybox_2 = 1,
} selectedSkybox;

App::LogicUI::LogicUI(Logic::IFactory* factory) : BaseProcessor(factory)
{
}

Bool App::LogicUI::OnInit(const Logic::IState* state)
{
    Graph::IRoot* root = state->GetGraphRoot();
    
    //left buttons
    AddGraphNode(sceneLeft.GetReference(root, "scene_button_left"));
    AddGraphNode(sceneRight.GetReference(root, "scene_button_right"));
    AddGraphNode(skyboxLeft.GetReference(root, "skybox_button_left"));
    AddGraphNode(skyboxRight.GetReference(root, "skybox_button_right"));
    AddGraphNode(rotateLeft.GetReference(root, "rotate_button_left"));
    AddGraphNode(rotateRight.GetReference(root, "rotate_button_right"));
    
    //right buttons
    AddGraphNode(redLeft.GetReference(root, "red_button_left"));
    AddGraphNode(redRight.GetReference(root, "red_button_right"));
    AddGraphNode(greenLeft.GetReference(root, "green_button_left"));
    AddGraphNode(greenRight.GetReference(root, "green_button_right"));
    AddGraphNode(blueLeft.GetReference(root, "blue_button_left"));
    AddGraphNode(blueRight.GetReference(root, "blue_button_right"));
    AddGraphNode(metalnessLeft.GetReference(root, "metalness_button_left"));
    AddGraphNode(metalnessRight.GetReference(root, "metalness_button_right"));
    AddGraphNode(roughnessLeft.GetReference(root, "roughness_button_left"));
    AddGraphNode(roughnessRight.GetReference(root, "roughness_button_right"));
    
    //text values
    AddGraphNode(redValue.GetReference(root, "red_value"));
    AddGraphNode(greenValue.GetReference(root, "green_value"));
    AddGraphNode(blueValue.GetReference(root, "blue_value"));
    AddGraphNode(metalnessValue.GetReference(root, "metalness_value"));
    AddGraphNode(roughnessValue.GetReference(root, "roughness_value"));
    
    AddGraphNode(redText.GetReference(root, "red_text"));
    AddGraphNode(greenText.GetReference(root, "green_text"));
    AddGraphNode(blueText.GetReference(root, "blue_text"));
    AddGraphNode(metalnessText.GetReference(root, "metalness_text"));
    AddGraphNode(roughnessText.GetReference(root, "roughness_text"));
    
    //transfrom containers
    AddGraphNode(scenesContainer[0].GetReference(root, "spheres_scene"));
    AddGraphNode(scenesContainer[1].GetReference(root, "sphere_scene"));
    AddGraphNode(scenesContainer[2].GetReference(root, "eye_scene"));
    AddGraphNode(sceneTransform.GetReference(root, "scene_transform"));

    //skyboxes
    AddGraphNode(skyboxState[0].GetReference(root, "skybox1_state"));
    AddGraphNode(irradianceState[0].GetReference(root, "irradiance1_state"));
    AddGraphNode(skyboxState[1].GetReference(root, "skybox2_state"));
    AddGraphNode(irradianceState[1].GetReference(root, "irradiance2_state"));
    
    //shader params
    AddGraphNode(shaderParams_1.GetReference(root, "sphere_mat_param"));
    
    selectedScene = scene_1;
    selectedSkybox = skybox_1;
    
    shaderParams[0] = 0.0;      //red
    shaderParams[1] = 0.0;      //green
    shaderParams[2] = 0.0;      //blue
    shaderParams[3] = 1.0;      //alpha
    shaderParams[4] = 0.0;      //metalness
    shaderParams[5] = 0.0;      //roughness
    shaderParams[6] = 4.0;      //exposure
    
    return true;
}

void App::LogicUI::OnProcessTick(const Logic::IState* state)
{
    //Real tickTime = state->GetCurrentTickTime();
    Double tickDuration = state->GetCurrentTickDuration();
    
    if(!checkLeftButtons(tickDuration))
    {
        if(checkRightButtons())
        {
            changeMaterialParameters();
        }
    }
}

Bool App::LogicUI::checkRightButtons()
{
    if(redLeft->WasPressed())
    {
        shaderParams[0] = Math::Max(0.0, shaderParams[0] - 0.05);
        redValue->SetText(Util::DoubleToString(shaderParams[0]));
        return true;
    }
    
    if(redRight->WasPressed())
    {
        shaderParams[0] = Math::Min(1.0, shaderParams[0] + 0.05);
        redValue->SetText(Util::DoubleToString(shaderParams[0]));
        return true;
    }
    
    if(greenLeft->WasPressed())
    {
        shaderParams[1] = Math::Max(0.0, shaderParams[1] - 0.05);
        greenValue->SetText(Util::DoubleToString(shaderParams[1]));
        return true;
    }
    
    if(greenRight->WasPressed())
    {
        shaderParams[1] = Math::Min(1.0, shaderParams[1] + 0.05);
        greenValue->SetText(Util::DoubleToString(shaderParams[1]));
        return true;
    }
    
    if(blueLeft->WasPressed())
    {
        shaderParams[2] = Math::Max(0.0, shaderParams[2] - 0.05);
        blueValue->SetText(Util::DoubleToString(shaderParams[2]));
        return true;
    }
    
    if(blueRight->WasPressed())
    {
        shaderParams[2] = Math::Min(1.0, shaderParams[2] + 0.05);
        blueValue->SetText(Util::DoubleToString(shaderParams[2]));
        return true;
    }
    
    if(metalnessLeft->WasPressed())
    {
        shaderParams[4] = Math::Max(0.0, shaderParams[4] - 0.05);
        metalnessValue->SetText(Util::DoubleToString(shaderParams[4]));
        return true;
    }
    
    if(metalnessRight->WasPressed())
    {
        shaderParams[4] = Math::Min(1.0, shaderParams[4] + 0.05);
        metalnessValue->SetText(Util::DoubleToString(shaderParams[4]));
        return true;
    }
    
    if(roughnessLeft->WasPressed())
    {
        shaderParams[5] = Math::Max(0.0, shaderParams[5] - 0.05);
        roughnessValue->SetText(Util::DoubleToString(shaderParams[5]));
        return true;
    }
    
    if(roughnessRight->WasPressed())
    {
        shaderParams[5] = Math::Min(1.0, shaderParams[5] + 0.05);
        roughnessValue->SetText(Util::DoubleToString(shaderParams[5]));
        return true;
    }
    
    return false;
}

Bool App::LogicUI::checkLeftButtons(Real tickDuration)
{
    if(sceneLeft->WasPressed())
    {
        if(selectedScene != scene_1)
        {
            scenesContainer[(SInt8)selectedScene]->GetNodeInterface()->SetActiveAndVisible(false);
            selectedScene = (Scenes)((SInt8)selectedScene - 1);
            scenesContainer[(SInt8)selectedScene]->GetNodeInterface()->SetActiveAndVisible(true);
            
            if(selectedScene == scene_2)
            {
                rightButtonsSetStatus(true);
            }
            else
            {
                rightButtonsSetStatus(false);
            }
        }
        return true;
    }
    
    if(sceneRight->WasPressed())
    {
        if(selectedScene != scene_3)
        {
            scenesContainer[(SInt8)selectedScene]->GetNodeInterface()->SetActiveAndVisible(false);
            selectedScene = (Scenes)((SInt8)selectedScene + 1);
            scenesContainer[(SInt8)selectedScene]->GetNodeInterface()->SetActiveAndVisible(true);
            
            if(selectedScene == scene_2)
            {
                rightButtonsSetStatus(true);
            }
            else
            {
                rightButtonsSetStatus(false);
            }
        }
        return true;
    }
    
    if(skyboxLeft->WasPressed())
    {
        if(selectedSkybox != skybox_1)
        {
            skyboxState[(SInt8)selectedSkybox]->GetNodeInterface()->SetActiveAndVisible(false);
            irradianceState[(SInt8)selectedSkybox]->GetNodeInterface()->SetActiveAndVisible(false);

            selectedSkybox = (Skyboxes)((SInt8)selectedSkybox - 1);
            
            skyboxState[(SInt8)selectedSkybox]->GetNodeInterface()->SetActiveAndVisible(true);
            irradianceState[(SInt8)selectedSkybox]->GetNodeInterface()->SetActiveAndVisible(true);
        }
        return true;
    }
    
    if(skyboxRight->WasPressed())
    {
        if(selectedSkybox != skybox_2)
        {
            skyboxState[(SInt8)selectedSkybox]->GetNodeInterface()->SetActiveAndVisible(false);
            irradianceState[(SInt8)selectedSkybox]->GetNodeInterface()->SetActiveAndVisible(false);

            selectedSkybox = (Skyboxes)((SInt8)selectedSkybox + 1);
            
            skyboxState[(SInt8)selectedSkybox]->GetNodeInterface()->SetActiveAndVisible(true);
            irradianceState[(SInt8)selectedSkybox]->GetNodeInterface()->SetActiveAndVisible(true);
        }
        return true;
    }
    
    if(rotateLeft->WasPressed())
    {
        rotationFlag = 1;
    }
    
    if(rotateRight->WasPressed())
    {
        rotationFlag = -1;
    }
    
    if(rotationFlag)
    {
        angle += tickDuration * rotationFlag;
        
        sceneTransform->SetRotation(0.0, angle, 0.0);
        
        if(rotateLeft->WasReleasedOutside() || rotateLeft->WasReleasedInside()
           || rotateRight->WasReleasedOutside() || rotateRight->WasReleasedInside())
        {
            rotationFlag = 0;
        }
        return true;
    }
    
    return false;
}

void App::LogicUI::changeMaterialParameters()
{
    auto buf = shaderParams_1->GetConstantBufferParametersInterface()->GetConstantBuffer(0);
    Float* param = reinterpret_cast<Float*>(buf->GetConstantData());
   
    *(param) = shaderParams[0];
    *(param + 1) = shaderParams[1];
    *(param + 2) = shaderParams[2];
    *(param + 3) = shaderParams[3];
    *(param + 4) = shaderParams[4];
    *(param + 5) = shaderParams[5];
    *(param + 6) = shaderParams[6];

    buf->SetByteSize(28);
    buf->SetConstantsModified();
}

void App::LogicUI::rightButtonsSetStatus(Bool status)
{
    redLeft->GetNodeInterface()->SetActiveAndVisible(status);
    redRight->GetNodeInterface()->SetActiveAndVisible(status);
    greenLeft->GetNodeInterface()->SetActiveAndVisible(status);
    greenRight->GetNodeInterface()->SetActiveAndVisible(status);
    blueLeft->GetNodeInterface()->SetActiveAndVisible(status);
    blueRight->GetNodeInterface()->SetActiveAndVisible(status);
    metalnessLeft->GetNodeInterface()->SetActiveAndVisible(status);
    metalnessRight->GetNodeInterface()->SetActiveAndVisible(status);
    roughnessLeft->GetNodeInterface()->SetActiveAndVisible(status);
    roughnessRight->GetNodeInterface()->SetActiveAndVisible(status);
    
    redValue->GetNodeInterface()->SetActiveAndVisible(status);
    greenValue->GetNodeInterface()->SetActiveAndVisible(status);
    blueValue->GetNodeInterface()->SetActiveAndVisible(status);
    metalnessValue->GetNodeInterface()->SetActiveAndVisible(status);
    roughnessValue->GetNodeInterface()->SetActiveAndVisible(status);
    
    redText->GetNodeInterface()->SetActiveAndVisible(status);
    greenText->GetNodeInterface()->SetActiveAndVisible(status);
    blueText->GetNodeInterface()->SetActiveAndVisible(status);
    metalnessText->GetNodeInterface()->SetActiveAndVisible(status);
    roughnessText->GetNodeInterface()->SetActiveAndVisible(status);
}
