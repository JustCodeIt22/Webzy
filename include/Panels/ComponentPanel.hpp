#pragma once
#include "imgui.h"
// My Includes
#include "HTMLComponents/Component.hpp"
#include "HTMLComponents/Text.hpp"
#include "HTMLComponents/Image.hpp"

class ComponentPanel{
    public:
        // Constructor and Destructor
        ComponentPanel();
        ~ComponentPanel();

        // other functions
        void renderUI();
    
    private:
        Component *htmlComponents[2];
};