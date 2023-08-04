#include "Panels/ComponentPanel.hpp"
#include "imgui.h"

ComponentPanel::ComponentPanel(){}

void ComponentPanel::renderUI(){
    ImGui::Begin("Component Panel");
    
    // Drag and drop
    ImGui::Button("Drag Me");
    if(ImGui::BeginDragDropSource()){
        ImGui::SetDragDropPayload("DEMO", (const char*)"Hello", (size_t)5);
        ImGui::Text("Dragging");
        ImGui::EndDragDropSource();
    }


    ImGui::End();
}