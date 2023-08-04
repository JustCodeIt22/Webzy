#include "MenuBar.hpp"
#include <iostream>

MenuBar::MenuBar(){}

void MenuBar::render(){
    if(ImGui::BeginMainMenuBar()){
        if(ImGui::BeginMenu("File")){
            if(ImGui::MenuItem("New", "CTRL+N")){std::cout << "Create New File";}
            ImGui::MenuItem("Open", "CTRL+O");
            ImGui::Separator();
            ImGui::MenuItem("Exit", "CTRL+Q");
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