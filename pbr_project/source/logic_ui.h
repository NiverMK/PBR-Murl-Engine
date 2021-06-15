//
//  ui_logic.hpp
//  p_b_r_project
//
//  Created by Mikhail Kavalyan on 4/30/20.
//  Copyright © 2020 Spraylight. All rights reserved.
//

#ifndef ui_logic_hpp
#define ui_logic_hpp

#include "murl_app_types.h"
#include "murl_logic_base_processor.h"


namespace Murl
{
    namespace App
    {
    class LogicUI : public Logic::BaseProcessor
        {
        public:

            LogicUI(Logic::IFactory* factory);
            
        protected:
            Real angle = 0.0;
            SInt8 rotationFlag = 0;
            
            /*
             0,1,2,3 - rgba
             4 - metalness
             5 - roughness
             6 - exposure
             */
            Real shaderParams[7];
            
            //left buttons
            Murl::Logic::ButtonNode sceneLeft;
            Murl::Logic::ButtonNode sceneRight;
            Murl::Logic::ButtonNode skyboxLeft;
            Murl::Logic::ButtonNode skyboxRight;
            Murl::Logic::ButtonNode rotateLeft;
            Murl::Logic::ButtonNode rotateRight;
            
            //right buttons
            Murl::Logic::ButtonNode redLeft;
            Murl::Logic::ButtonNode redRight;
            Murl::Logic::ButtonNode greenLeft;
            Murl::Logic::ButtonNode greenRight;
            Murl::Logic::ButtonNode blueLeft;
            Murl::Logic::ButtonNode blueRight;
            Murl::Logic::ButtonNode metalnessLeft;
            Murl::Logic::ButtonNode metalnessRight;
            Murl::Logic::ButtonNode roughnessLeft;
            Murl::Logic::ButtonNode roughnessRight;
            
            //text values
            Murl::Logic::TextGeometryNode redValue;
            Murl::Logic::TextGeometryNode greenValue;
            Murl::Logic::TextGeometryNode blueValue;
            Murl::Logic::TextGeometryNode roughnessValue;
            Murl::Logic::TextGeometryNode metalnessValue;
            
            Murl::Logic::TextGeometryNode redText;
            Murl::Logic::TextGeometryNode greenText;
            Murl::Logic::TextGeometryNode blueText;
            Murl::Logic::TextGeometryNode roughnessText;
            Murl::Logic::TextGeometryNode metalnessText;

            //transform containers with models
            Murl::Logic::TransformNode scenesContainer[3];
            Murl::Logic::TransformNode sceneTransform;

            //skyboxes
            Murl::Logic::TextureStateNode skyboxState[2];
            Murl::Logic::TextureStateNode irradianceState[2];
            
            //shader parameters
            Murl::Logic::ShaderParametersNode shaderParams_1;
            Murl::Logic::ShaderParametersNode shaderParams_2;

            Bool checkLeftButtons(Real tickDuration);
            Bool checkRightButtons();
            void changeMaterialParameters();
            void rightButtonsSetStatus(Bool status);
            
            virtual Bool OnInit(const Logic::IState* state);
            virtual void OnProcessTick(const Logic::IState* state);
        };
    }
}
#endif /* ui_logic_hpp */
