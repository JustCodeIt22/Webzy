#pragma once
#include <string>

#include "imgui.h"

namespace Utils{
    // Convert RGB Color to ImGui Color 
    ImVec4 cnvColor(float red, float green, float blue, float alpha = 255.f){
        float r = red/255.f;        // red
        float g = green/255.f;      // green
        float b = blue/255.f;       // blue
        float av = alpha/255.f;     // alpha_value
        return ImVec4{r, g, b, av};
    }
}