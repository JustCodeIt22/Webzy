#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "imgui-SFML.h"
#include "imgui.h"
#include "fontAwesome.h"
#include "MenuBar.hpp"
#include "Panels/ComponentPanel.hpp"
#include "Panels/PropertiesPanel.hpp"
#include "Panels/ViewPortPanel.hpp"
#define WIDTH 800 
#define HEIGHT 600
#define TITLE "Webzy"



class Webzy{
    public:
        Webzy();
        void run();
    
    private:
        void handle_events();
        void update();
        void render();

        // Window Declaration;
        sf::RenderWindow MainWindow;
        sf::Clock deltaClock;

        // MenuBar
        MenuBar menu_bar;

        // ShortCut
        bool ctrl;

        // Panels
        ComponentPanel component_panel;
        PropertiesPanel properties_panel;
        ViewPortPanel viewport_panel;
};