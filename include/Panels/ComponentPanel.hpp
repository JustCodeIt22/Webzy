#pragma once
#include <vector>

#include "imgui.h"

#include "HTMLComponents/ComponentLoader.hpp"

class ComponentPanel{
    public:
        // Constructor and Destructor
        ComponentPanel();
        ~ComponentPanel();

        // other functions
        void renderUI();
    
    private:
        std::unique_ptr<std::vector<const char*>> htmlComponents;
};