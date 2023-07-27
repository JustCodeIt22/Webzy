#pragma once
#include <SFML/Graphics.hpp>
#include "imgui-SFML.h"
#include "imgui.h"
#include "fontAwesome.h"
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
        sf::RenderWindow window;
        sf::Clock deltaClock;
};