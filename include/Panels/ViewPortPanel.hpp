#pragma once
// Lib Includes
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <memory>

#include "SFML/Graphics.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

#include "HTMLComponents/ComponentLoader.hpp"



class ViewPortPanel{
    public:
        ViewPortPanel();
        // ~ViewPortPanel();
        static void handle_properties_to_render();     // rendering properties of selected component
        static void createNewCanvas();                 // creates a new canvas
        
        void renderUI();
        void render();                      
        void renderProperties();                       // render Properties of current component in Properties Panel

        friend class Webzy;
    
    private:
        void handle_events(sf::Event &event);

        // Panel Setup
        sf::RenderTexture m_windowTexture;     // View Port Window
        sf::View m_mainView;                   // View  OR  Camera
        sf::Color bg_color;
        int viewPort_w;
        int viewPort_h;
        int viewPort_x;
        int viewPort_y;

        // Zoom vars;
        const float zoomInDelta = 0.9f;
        const float zoomOutDelta = 1.1f;

        // Canvas Texture
        sf::RectangleShape canvas;
        int canvas_w, canvas_h, canvas_x, canvas_y;
        sf::Color canvas_color;

        // Mouse Pos
        float mousePosX;
        float mousePosY;

        // Panel Flags
        bool m_isHovered;                      
        bool m_isPanning;

        // webzyUIFile.txt
        std::ofstream file;
        std::ofstream htmlFile;         // TODO: want to create
        std::ofstream cssFile;          // TODO: want to create
        
        // Html component
        std::unordered_map<int, std::pair<std::shared_ptr<Component>, sf::Vector2f>> htmlComponentsOnViewPort; // { Component id : {Component, Pos}}
        const char* componentName;
        int componentPosX, componentPosY;
        int componentID = 1;

        // panning
        bool isPanning = false;
        sf::Vector2i lastMousePos, currMousePos;
        sf::Vector2f deltaMousePos; 

        // Debugging
        sf::CircleShape debugCircle;
};