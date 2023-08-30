#include "HTMLComponents/Image.hpp"
#define BLUE sf::Color(0, 0, 255, 255)


// =============== Constructor =================== //
Image::Image():Component("Image", BLUE){
    code = "Image Code";
    properties->setProperty("Color", "Blue");
    properties->setProperty("Image", "../../res/imgs/player.png");
}


// ================ Destructor ================== //
Image::~Image(){}