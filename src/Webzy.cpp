#include "Webzy.hpp"
#include "Styles.hpp"

// Initiating
Webzy::Webzy() 
:MainWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE)
{
    // Initiating ImGui
    ImGui::SFML::Init(MainWindow);
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Enable Docking
    Styles::setFancyImguiStyle(); // Setting Style

    // Setting Fonts;
    io.Fonts->Clear();
    ImFontConfig config;
    io.Fonts->AddFontFromFileTTF("../res/fonts/Roboto-Regular.ttf", 22);
    ImGui::SFML::UpdateFontTexture();

    ctrl = false;

}


// Handle Events
void Webzy::handle_events(){
    sf::Event event;
    while (MainWindow.pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(event);
        viewport_panel.handle_events(event);

        if(event.type == sf::Event::Closed){
            MainWindow.close();
        }

        // KeyDown Events
        if(event.type == sf::Event::KeyPressed){
            // Ctrl Key
            if(event.key.code == sf::Keyboard::LControl){
                ctrl = true;
            }
            else if(event.key.code == sf::Keyboard::Q && ctrl){// Exit -> CTRL + Q
                MainWindow.close();
            }
        }

        // KeyUp Event
        if(event.type == sf::Event::KeyReleased){
            if(event.key.code == sf::Keyboard::LControl){
                ctrl = false;
            }
        }
    }
}


void Webzy::update(){
    ImGui::SFML::Update(MainWindow, deltaClock.restart());
    ImGui::DockSpaceOverViewport();
}


// Main Render
void Webzy::render(){
    menu_bar.render(MainWindow);
    component_panel.renderUI();
    viewport_panel.renderUI();
    properties_panel.renderUI(viewport_panel);
    
 
    viewport_panel.render();
    ImGui::ShowDemoWindow();

    // Render Window
    MainWindow.clear(sf::Color::Black);
    ImGui::SFML::Render(MainWindow);
    MainWindow.display();
}


// run method
void Webzy::run(){
    while(MainWindow.isOpen()){
        handle_events();
        update();
        render();
    }
    ImGui::SFML::Shutdown();
}