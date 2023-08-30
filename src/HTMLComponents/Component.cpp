#include "HTMLComponents/Component.hpp"

// ============= Init ================= //
Component::Component(const char* name, sf::Color bgRectColor){
    this->name = name;
    properties = std::make_unique<Properties>();

    bgrect.setSize(sf::Vector2f(50, 50));
    bgrect.setFillColor(bgRectColor);
    properties->setProperty("text", "Hello world");
    // bgrect.setFillColor(bgColor);
}


// ============ render ================//
const void Component::render(){
    ImGui::Button(name);
}



// ================= Center Text ================================//
void centerText(std::string text) {
    auto windowWidth = ImGui::GetWindowSize().x;
    auto textWidth   = ImGui::CalcTextSize(text.c_str()).x;

    ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
    ImGui::Text(text.c_str());
}


// =========== RenderProperties =========//
const void Component::renderProperties(){
    static char name[32] = "Label1";
    float cl[3] = {255, 255, 255};
    centerText(this->getName());
    ImGui::Separator();
    for(auto &prop:properties->getProperties()){
        if(prop.first == "Color"){
            ImGui::ColorPicker3("Color", cl, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
        }else{
            ImGui::InputText(prop.first.c_str(), name, IM_ARRAYSIZE(name));
        }
        // ImGui::Button(prop.first.c_str());
    }

    for(auto &prop:properties->getFloatProperties()){
        ImGui::InputFloat("Float", &prop.second);
    }
}


// ============ Destructor ============ //
Component::~Component(){
}

