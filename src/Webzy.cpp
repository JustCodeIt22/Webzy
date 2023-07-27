#include "Webzy.hpp"

// Initiating
Webzy::Webzy() 
:window(sf::VideoMode(WIDTH, HEIGHT), TITLE)
{
    // Initiating ImGui
    ImGui::SFML::Init(window);
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Enable Docking
    ImGui::StyleColorsClassic();

    // Setting Fonts;
    io.Fonts->Clear();
    // Setting Font
    // Font Awesome
    ImFontConfig config;
    io.Fonts->AddFontFromFileTTF("../res/fonts/JetBrainsMono-Regular.ttf", 22);
    ImGui::SFML::UpdateFontTexture();
}



// Handle Events
void Webzy::handle_events(){
    sf::Event event;
    while (window.pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(event);
        if(event.type == sf::Event::Closed){
            window.close();
        }
    }
}


void Webzy::update(){
    ImGui::SFML::Update(window, deltaClock.restart());
    ImGui::DockSpaceOverViewport();
}


// Render Panels
void render_panels(){
    ImGui::ShowDemoWindow();
}


// Main Render
void Webzy::render(){
    render_panels();

    window.clear(sf::Color::Black);
    ImGui::SFML::Render(window);
    window.display();
}


// run method
void Webzy::run(){
    while(window.isOpen()){
        handle_events();
        update();
        render();
    }
    ImGui::SFML::Shutdown();
}