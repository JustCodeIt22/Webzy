#include "HTMLComponents/Component.hpp"

// ============= Init ================= //
Component::Component(const char* name){
    this->name = name;
}


// ============ render ================//
const void Component::render(){
    ImGui::Button(name);
}


// ============ Destructor ============ //
Component::~Component(){}