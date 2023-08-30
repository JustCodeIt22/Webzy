#pragma once
#include <string>
#include "imgui.h"

#include "Panels/ViewPortPanel.hpp"

class PropertiesPanel{
    public:
        PropertiesPanel();
        void renderUI(ViewPortPanel &vpp);   
};