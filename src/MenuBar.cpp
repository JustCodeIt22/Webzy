#include "MenuBar.hpp"


MenuBar::MenuBar(){}

// ============================= Render ================================= //
void MenuBar::render(sf::RenderWindow &window){
    if(ImGui::BeginMainMenuBar()){
        if(ImGui::BeginMenu("File")){
            if(ImGui::MenuItem("New", "CTRL+N")){std::cout << "Create New File";}
            ImGui::MenuItem("Open", "CTRL+O");
            ImGui::Separator();
            if(ImGui::MenuItem("Exit", "CTRL+Q")){
                window.close();
            }
            ImGui::EndMenu();
        }
        if(ImGui::BeginMenu("Edit")){
            ImGui::MenuItem("Preferences");
            ImGui::EndMenu();
        }
        if(ImGui::BeginMenu("Help")){
            ImGui::MenuItem("Documentation");
            ImGui::EndMenu();
        }
    }
    ImGui::EndMainMenuBar();
}