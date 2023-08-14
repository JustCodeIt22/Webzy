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
    canvas_w = 900;
    canvas_h = 600;
    canvas_color = sf::Color(255, 255, 255, 255);
    canvas.setSize(sf::Vector2f(canvas_w, canvas_h));
    canvas.setOrigin(sf::Vector2f(canvas_w/2, canvas_h/2));
    canvas.setPosition(viewPort_w/2 - 150.5, viewPort_h/2);
    canvas.setFillColor(canvas_color);
}


// ================================ Destructor ================================================ #


// =================================== ViewPort Handle Events =============================== #
void ViewPortPanel::handle_events(sf::Event &event){
    // handling zoom events
    if(m_isHovered){
        // zooming 
        if(event.type == sf::Event::MouseWheelMoved){
            if(event.mouseWheel.delta > 0){ 
                m_mainView.zoom(0.9f); // zoom in 
            } 
            else if(event.mouseWheel.delta < 0){
                m_mainView.zoom(1.1f); // zoom out
            }
            m_windowTexture.setView(m_mainView);
        }

        if(event.type == sf::Event::MouseButtonPressed){
            sf::Vector2i mouse_pos = sf::Mouse::getPosition();
            std::cout << mouse_pos.x - 303 << " " << mouse_pos.y - 88 << "\n";
        }
    }
}


// For Resizing and Placing the object according to ViewPort aspect ratio
sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight) {

    // Compares the aspect ratio of the window to the aspect ratio of the view,
    // and sets the view's viewport accordingly in order to archieve a letterbox effect.
    // A new view (with a new viewport set) is returned.

    float windowRatio = windowWidth / (float) windowHeight;
    float viewRatio = view.getSize().x / (float) view.getSize().y;
    float viewWidth = 1;
    float viewHeight = 1;
    float viewposX = 0;
    float viewposY = 0;

    bool horizontalSpacing = true;
    if (windowRatio < viewRatio)
        horizontalSpacing = false;

    // If horizontalSpacing is true, the black bars will appear on the left and right side.
    // Otherwise, the black bars will appear on the top and bottom.

    if (horizontalSpacing) {
        viewWidth = viewRatio / windowRatio;
        viewposX = (1 - viewWidth) / 2.f;
    } else {
        viewHeight = windowRatio / viewRatio;
        viewposY = (1 - viewHeight) / 2.f;
    }

    view.setViewport( sf::FloatRect(viewposY, viewposY, viewWidth, viewHeight) );

    return view;
}


// Render the ui
void ViewPortPanel::renderUI(){
    
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(4, 4));
    ImGui::Begin("ViewPort Panel", nullptr, ImGuiWindowFlags_NoScrollbar);
    ImVec2 viewport_size = ImGui::GetContentRegionAvail();
    ImGui::Image(m_windowTexture, sf::Vector2f(viewport_size.x, viewport_size.y));
    // m_windowTexture.setView(getLetterboxView(m_mainView, viewport_size.x, viewport_size.y));
    m_isHovered = ImGui::IsWindowHovered();
    
    
    // Drag and Drop
    if(ImGui::BeginDragDropTarget()){
        if(const ImGuiPayload *payload = ImGui::AcceptDragDropPayload("HTMLComponents")){
            const char* s = (const char*)payload;
            std::cout << s;
            ImGui::Button("Done");
        }
        ImGui::EndDragDropTarget();
    }


    ImGui::End();
    ImGui::PopStyleVar(); 
}



// Display the main content
void ViewPortPanel::render(){

    m_windowTexture.clear(bg_color);
    m_windowTexture.draw(canvas);
    m_windowTexture.display();
}