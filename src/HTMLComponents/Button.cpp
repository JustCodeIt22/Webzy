#include "HTMLComponents/Button.hpp"
#define Magenta sf::Color(255, 0, 255, 255) // Defining Color


// =============== Constructor =================== //
Button::Button():Component("Button", Magenta){
    code = "Button Code";
    properties->setProperty("Color", "Magenta");
}


// ================ Destructor ================== //
Button::~Button(){}