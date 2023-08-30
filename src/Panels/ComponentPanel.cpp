#include "Panels/ComponentPanel.hpp"


// =================== Constructors ===================== //
ComponentPanel::ComponentPanel(){
    htmlComponents = std::make_unique<std::vector<const char*>>();
    htmlComponents->push_back("Text");
    htmlComponents->push_back("Image");
}


// =================== Destructors ===================== //
ComponentPanel::~ComponentPanel(){
}



// ================== Other Functions ================== //
void ComponentPanel::renderUI(){
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {5, 5});
    ImGui::Begin("Component Panel");
    // Drag and drop
    for(const auto& component: HTML_COMPONENTS){
        // ImGui::SetCursorPosX(10);
        const char* componentName = component.first.c_str();
        ImGui::Button(componentName, ImVec2(ImGui::GetWindowSize().x, 30));
        if(ImGui::BeginDragDropSource()){
            ImGui::SetDragDropPayload("HTMLComponents", componentName, (size_t)10);
            ImGui::Text(componentName);
            ImGui::EndDragDropSource();
        }
    }    
    ImGui::End();
    ImGui::PopStyleVar();
}