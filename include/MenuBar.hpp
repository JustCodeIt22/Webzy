#pragma once
#include <iostream>

#include "imgui.h"

#include "SFML/Graphics.hpp"
#include "Panels/ViewPortPanel.hpp"

class MenuBar{
    public:
        MenuBar();
        friend class Webzy;
        
    private:
        void showDocumentaionWindow(bool *p_open); // shows the documentation window.
        void render(sf::RenderWindow &window);


        bool show_documentation;

};