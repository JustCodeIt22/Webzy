#pragma once
// Lib Includes
#include <iostream>
#include "SFML/Graphics.hpp"
#include "imgui.h"
#include "imgui-SFML.h"


class ViewPortPanel{
    public:
        ViewPortPanel();
        // ~ViewPortPanel();
        void renderUI();
        void render();

        friend class Webzy;
    
    private:
        void handle_events(sf::Event &event);
        // Panel Setup
        sf::RenderTexture m_windowTexture;     // View Port Window
        sf::View m_mainView;                   // View  OR  Camera
        sf::Color bg_color;
        int viewPort_w;
        int viewPort_h;

        // Canvas Texture
        sf::RectangleShape canvas;
        int canvas_w, canvas_h;
        sf::Color canvas_color;
        
        // Panel Flags
        bool m_isHovered;                      
        bool m_isPanning;


};