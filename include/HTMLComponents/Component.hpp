#pragma once
#include <iostream> // for debugging
#include <unordered_map>

#include "imgui.h"
#include "imgui-SFML.h"

#include "SFML/Graphics.hpp"

/*
    --- Naming convention
        umap = unordered map;
        s = string;
        f = float;
        c = sf::Color;
*/

using umap_s_s = std::unordered_map<std::string, std::string>;
using umap_s_f = std::unordered_map<std::string, float>;
using umap_s_c = std::unordered_map<std::string, sf::Color>;


// ================================== Component Utils Class Properties ================================== //
class Properties{
    public:
        // Getters
        inline std::string getProperty(std::string property_name){return str_properties[property_name];}        // return property values
        inline int getSize(){return str_properties.size();}                                                     // return properties size
        inline umap_s_s getProperties(){return str_properties;}                                                 // return all string properties
        inline umap_s_f getFloatProperties(){return float_properties;}                                          // return all float properties

        // Setters 
        inline void setProperty(const std::string &prop_name, const std::string &prop_value){str_properties[prop_name] = prop_value;}  // passing parameter by ref
        inline void setFloatProperty(const std::string &prop_name, const float &prop_value){float_properties[prop_name] = prop_value;}
        inline void setColorProperty(const std::string &prop_name, const sf::Color &prop_value){color_properties[prop_name] = prop_value;}
        


    private:
        umap_s_s str_properties;    // This will store string properties values;
        umap_s_f float_properties;  // This will store float properties values;
        umap_s_c color_properties;  // This will store color properties values;
};


// ================================== Component Class ================================== //
class Component{
    public:
        std::unique_ptr<Properties> properties;

        // Constructor and Destructor
        Component(const char* name, sf::Color bgRectColor);
        ~Component();

        // Helper Functions
        void const render();                                            // render
        void const renderProperties();                                  // renders component properties in PropertiesPanel
        inline const char* getName(){return name;}                      // returns Component Name
        inline const sf::RectangleShape getBgRect(){return bgrect;}     // returns the background rect

    protected:
        // for code generation
        std::string code;
    
    private:
        // for identifying
        const char* name;
        sf::RectangleShape bgrect;

        // All properties
        static char prop_txt;
        float      *prop_color;
        sf::Texture prop_img;            // want to add the image texture
};
