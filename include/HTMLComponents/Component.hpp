#pragma once
#include <iostream> // for debugging
#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"

class Component{
    public:
        // Constructor and Destructor
        Component(const char* name);
        ~Component();

        // Helper Functions
        void const render();
        const inline char* getName(){return name;}

    protected:
        // for code generation
        std::string code;
    
    private:
        // for identifying
        const char* name;
        sf::Texture img;

};