#include "Panels/ComponentPanel.hpp"
#include "imgui.h"

// =================== Constructors ===================== //
ComponentPanel::ComponentPanel(){}


// =================== Destructors ===================== //
ComponentPanel::~ComponentPanel(){
}


// ================== Other Functions ================== //
void ComponentPanel::renderUI(){
    Component* htmlComponents[2] = {new Text(), new Image()};
    ImGui::Begin("Component Panel");
    
    // Drag and drop
    for(const auto& component:htmlComponents){
        component->render();
        if(ImGui::BeginDragDropSource()){
            ImGui::SetDragDropPayload("HTMLComponents", component->getName(), (size_t)5);
            ImGui::Text(component->getName());
            ImGui::EndDragDropSource();
        }
        delete component;
    }

    
    ImGui::End();
}