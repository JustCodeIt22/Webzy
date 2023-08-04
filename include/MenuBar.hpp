#pragma once
#include "imgui.h"

class MenuBar{
    public:
        MenuBar();
        friend class Webzy;
        
    private:
        void render();
};