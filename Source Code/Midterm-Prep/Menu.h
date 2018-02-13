//
// Created by TheLoneWoof on 10/5/17.
//

#ifndef MIDTERM_PREP_MENU_H
#define MIDTERM_PREP_MENU_H

#include <string>
#include <vector>

// Dependent Struct to Menu
struct MenuItem {
    char idx; // All converted to uppercase by default.
    std::string lbl;

    MenuItem() {
        idx = ' ';
        lbl = "";
    }
    MenuItem(int in_idx, std::string in_lbl) {
        idx = in_idx;
        lbl = in_lbl;
    }
};

class Menu {
private:
    std::vector<MenuItem> items;

public:
    Menu() {}
    ~Menu() {}

    // Add item to menu.
    void addItem(char idx, std::string lbl);

    // Turn menu into a formatted string.
    std::string stringify(int = 0, std::string = "[ ", std::string = " ]");

    // Is the given index valid?
    bool isValidIdx(char);

    // Gets items by index. Throws exception is cannot find one.
    std::string getLabelByIdx(char);
};


#endif // MIDTERM_PREP_MENU_H
