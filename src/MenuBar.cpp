#include "MenuBar.hpp"
#include <iostream>
#include <windows.h>

MenuBar::MenuBar(){
    show_documentation = false;
}

// ============================= Render ================================= //
void MenuBar::render(sf::RenderWindow &window){
    if(ImGui::BeginMainMenuBar()){
        // File Option
        if(ImGui::BeginMenu("File")){
            if(ImGui::MenuItem("New", "CTRL+N")){
                // const wchar_t* dir_path = L"C:\\Users\\omkar\\OneDrive\\Desktop\\All_codes";
                // ShellExecuteW(NULL, L"open", L"explorer.exe", dir_path, NULL, SW_SHOWNORMAL);
            }
            ImGui::MenuItem("Open", "CTRL+O");
            ImGui::Separator();
            if(ImGui::MenuItem("Exit", "CTRL+Q")){
                window.close();
            }
            ImGui::EndMenu();
        }

        // Edit Option
        if(ImGui::BeginMenu("Edit")){
            ImGui::MenuItem("Preferences");
            ImGui::EndMenu();
        }

        // Help Option
        if(ImGui::BeginMenu("Help")){
            ImGui::MenuItem("Documentation", NULL, &show_documentation);
            ImGui::EndMenu();
        }
    }
    ImGui::EndMainMenuBar();

    // show documentaion
    if(show_documentation) showDocumentaionWindow(&show_documentation);
}

// ============================= Show Documentation ============================//
void MenuBar::showDocumentaionWindow(bool *p_open){
    ImGui::Begin("Documentation", p_open);
    ImGui::Text("Documentation");
    ImGui::End();
}