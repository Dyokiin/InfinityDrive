#pragma once

#include "Button.hpp"
#include "TtfManager.hpp"

class Menu {
private:
    std::vector<Label*> _mainMenu;
    std::vector<Label*> _echapMenu;
    std::vector<Label*> _titleScreen;
    unsigned int _current;

public:
    Menu() = default;
    ~Menu() = default;

    inline void setCurrentMenu(const int c) {_current = c;}
    inline const int getCurrentMenu() const {return _current;} 

    void init();
    void init(TtfManager &printer);

    void display() const;
    int click(const int &x, const int &y) const;
};