#include "Panels/PropertiesPanel.hpp"

// ================== Constructor ==============================//
PropertiesPanel::PropertiesPanel(){
}


// ================== Render UI ==============================//
void PropertiesPanel::renderUI(ViewPortPanel &vpp){
    ImGui::Begin("Properties Panel");
    vpp.renderProperties();             // renders properties of the selected component
    ImGui::End();
}