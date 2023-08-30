#pragma once
#include "HTMLComponents/Component.hpp"

class Text:public Component{
    public:
        Text();
        ~Text();
    
    private:
        void  init_properties(); // Initializes all the properties values

        // All Properties
        const char* text;
        float width;

};