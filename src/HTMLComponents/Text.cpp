#include "HTMLComponents/Text.hpp"
#define RED sf::Color(255, 0, 0, 255)


// =============== Constructor =================== //
Text::Text():Component("Text", RED){
    init_properties();                  // initializes properties
    code = "<h1> Sample Text </h1>";
    properties->setProperty("Color", "Red");
    properties->setFloatProperty("width", width);
}

// =============== init_properties ================//
void Text::init_properties(){
    width = 200;
}


// ================ Destructor ================== //
Text::~Text(){
}