#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "imgui.h"
#include "imgui-SFML.h"

class ViewPortPanel{
    public:
        ViewPortPanel();
        void renderUI();
        void render();

        friend class Webzy;
    
    private:
        void handle_events(sf::Event &event);


        
        sf::RenderTexture m_windowTexture;     // View Port Window
        sf::View m_mainView;                   // View  OR  Camera
        sf::Color bg_color;
};