#include "Panels/ViewPortPanel.hpp"

ViewPortPanel::ViewPortPanel()
:m_mainView(m_windowTexture.getDefaultView())
{
    m_windowTexture.create(800, 600);
    bg_color = sf::Color(15, 15, 15, 255);
    m_isPanning = false;

    // ViewPort Setup
    viewPort_w = 1234;
    viewPort_h = 1023;

    // Canvas Setup
    float scale = 1.7;
    canvas_w = 1920/scale;
    canvas_h = 1080/scale;
    canvas_x = viewPort_w/2;
    canvas_y = viewPort_h/2;
    canvas_color = sf::Color(255, 255, 255, 255);
    canvas.setSize(sf::Vector2f(canvas_w, canvas_h));
    canvas.setOrigin(sf::Vector2f(canvas_w/2, canvas_h/2));
    canvas.setPosition(canvas_x, canvas_y);
    canvas.setFillColor(canvas_color);

    // component pos
    componentName = "None";
    componentPosX =  2000;
    componentPosY = 2000;

    // debug circle
    debugCircle.setRadius(20);
    debugCircle.setFillColor(sf::Color::Red);

    // html component on viewport
}


// ================================ Create New Canvas ======================================== #
void ViewPortPanel::createNewCanvas(){
    // TODO 
}


// =================================== ViewPort Handle Events =============================== #
void ViewPortPanel::handle_events(sf::Event &event){
    // handling zoom events
    if(m_isHovered){
        // Keyboard Events
        if(event.type == sf::Event::KeyPressed){
            if(event.key.code == sf::Keyboard::P){
                file.open("webzyUILog.txt");
                for(auto &component:htmlComponentsOnViewPort){
                    int compID = component.first;
                    std::shared_ptr<Component> comp = component.second.first;
                    std::cout << compID << " " << comp->getName() << "\n";
                    file << compID << " " << comp->getName() << "\n";
                }
                file.close();
            }
        }

        // zooming 
        if(event.type == sf::Event::MouseWheelMoved){
            if(event.mouseWheel.delta > 0){ 
                m_mainView.zoom(zoomInDelta); // zoom in 
            } 
            else if(event.mouseWheel.delta < 0){
                m_mainView.zoom(zoomOutDelta); // zoom out
            }
            m_windowTexture.setView(m_mainView);
        }

        if(event.type == sf::Event::MouseButtonPressed){
            debugCircle.setPosition(mousePosX, mousePosY);
        }
    }
}

// =================================== Render Properties ===============================//
void ViewPortPanel::renderProperties(){
    if(htmlComponentsOnViewPort.size())
        htmlComponentsOnViewPort.at(componentID - 1).first->renderProperties(); // Component.renderProperties()
}



// Render the ui
void ViewPortPanel::renderUI(){
    
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(4, 4));
    ImGui::Begin("ViewPort Panel", nullptr, ImGuiWindowFlags_NoScrollbar);
    ImVec2 viewport_size = ImGui::GetContentRegionAvail();
    ImGui::Image(m_windowTexture, sf::Vector2f(viewport_size.x, viewport_size.y));


    // setting camera
    float aspectRatio = float(viewport_size.x) / float(viewport_size.y);
    m_mainView.setSize(m_mainView.getSize().y * aspectRatio, m_mainView.getSize().y);
    m_mainView.setCenter(viewport_size.x/2, viewport_size.y/2);

    // setting mouse Pos
    mousePosX = (sf::Mouse::getPosition().x * (m_mainView.getSize().x/viewport_size.x)) - ImGui::GetWindowPos().x - 10;
    mousePosY = (sf::Mouse::getPosition().y * (m_mainView.getSize().y/viewport_size.y)) - ImGui::GetWindowPos().y - 84;


    m_isHovered = ImGui::IsWindowHovered();         // VIEW_PORT_PANEL_HOVERED
    viewPort_x = ImGui::GetWindowPos().x;
    viewPort_y = ImGui::GetWindowPos().y;
    
    
    // Drag and Drop
    if(ImGui::BeginDragDropTarget()){
        if(const ImGuiPayload *payload = ImGui::AcceptDragDropPayload("HTMLComponents")){
            // writing in files
            componentName = (const char*)payload->Data;      // get the componentName
            std::cout << componentName;
            std::cout << HTML_COMPONENTS.at(componentName)->getName() << "\n";
            std::cout << HTML_COMPONENTS.at(componentName)->properties->getProperty("Color") << "\n";
           
            
            // placing htmlComponents
            int offsetX = 421; // Component Panel width
            int offsetY = 276; // Menubar + Titlebar height
            componentPosX =  mousePosX;
            componentPosY = mousePosY;
            std::cout << componentPosX << " " << componentPosY << std::endl;
            htmlComponentsOnViewPort[componentID].first = HTML_COMPONENTS.at(componentName);   // storing the component
            htmlComponentsOnViewPort[componentID].second = sf::Vector2f(mousePosX, mousePosY); // storing the mousePosition in unorder_map
            componentID++;
        }
        ImGui::EndDragDropTarget();
    }

    ImGui::End();
    ImGui::PopStyleVar();

}


// Rendering Properties of current selected Component on Property Panel
void ViewPortPanel::handle_properties_to_render(){
    ImGui::Button("Body");
}


// Display the main content
void ViewPortPanel::render(){
    m_windowTexture.setView(m_mainView);
    m_windowTexture.clear(bg_color);
    m_windowTexture.draw(canvas);
    if(htmlComponentsOnViewPort.size()){
        for(auto &component:htmlComponentsOnViewPort){
            std::shared_ptr<Component> comp = component.second.first;
            sf::RectangleShape rect = comp->getBgRect();
            sf::Vector2f compPos = component.second.second;
            rect.setPosition(compPos);
            m_windowTexture.draw(rect); // gets the bgRect of the respective component
        }
    }
    m_windowTexture.draw(debugCircle);
    m_windowTexture.display();
}