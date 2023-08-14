#pragma once
#include "imgui.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class MenuBar{
    public:
        MenuBar();
        friend class Webzy;
        
    private:
        void render(sf::RenderWindow &window);
};