#include "../include/Menu.hpp"

void Menu::init(TtfManager &typewritter) {
    _current = 1;

/* Title Screen */

    Label* title = new Label(texturedPlane( glm::vec2(0.33, 0.25), 
                                        glm::vec2(0.66, 0.5),
                                        typewritter.getLabel("VroomRun")));

    Label* text = new Label(texturedPlane(glm::vec2(0.33, 0.25), 
                                      glm::vec2(0.66, 0.5),
                                      typewritter.getLabel("<Press Any Key to CONTINUE>")));

    _titleScreen.push_back(title);
    _titleScreen.push_back(text);

/* Main Menu */ 

    _mainMenu.push_back(title);



/* Echap Menu */

    _echapMenu.push_back(title);
}

void Menu::init() {
        _current = 1;

/* Title Screen */

    Label* title = new Label(texturedPlane( glm::vec3(0.33, 0.25, 0), 
                                        glm::vec3(0.66, 0.5, 0),
                                        "../ressources/textures/text/title.png"));


    _titleScreen.push_back(title);

/* Main Menu */ 

    _mainMenu.push_back(title);



/* Echap Menu */

    _echapMenu.push_back(title);
}

void Menu::display() const {
    switch (_current)
    {
    case 1:
        for(auto i : _titleScreen)
            i->display();
        break;
    
    case 2:
        for(auto i : _mainMenu)
            i->display();
        break;
    
    case 3:
        for(auto i : _mainMenu)
            i->display();
        break;
    
    default:
        break;
    }
}