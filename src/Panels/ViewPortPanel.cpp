#include "Panels/ViewPortPanel.hpp"


ViewPortPanel::ViewPortPanel()
:m_mainView(m_windowTexture.getDefaultView())
{
    m_windowTexture.create(800, 600);
    bg_color = sf::Color(15, 15, 15, 255);
}


void ViewPortPanel::handle_events(sf::Event &event){
}


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
    
    ImGui::Begin("ViewPort Panel", nullptr, ImGuiWindowFlags_NoScrollbar);
    ImVec2 viewport_size = ImGui::GetContentRegionAvail();
    ImGui::Image(m_windowTexture, sf::Vector2f(viewport_size.x, viewport_size.y));
    m_windowTexture.setView(getLetterboxView(m_mainView, viewport_size.x, viewport_size.y));
    
    
    // Drag and Drop
    if(ImGui::BeginDragDropTarget()){
        if(const ImGuiPayload *payload = ImGui::AcceptDragDropPayload("DEMO")){
            const char* s = (const char*)payload;
            ImGui::Button("Done");
        }
        ImGui::EndDragDropTarget();
    }


    ImGui::End();  
}



// Display the main content
void ViewPortPanel::render(){
    // Render Texture
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(100, 100));
    rect.setPosition(0, 0);
    rect.setFillColor(sf::Color(200, 100, 100, 255));


    m_windowTexture.clear(bg_color);

    m_windowTexture.draw(rect);

    m_windowTexture.display();
}