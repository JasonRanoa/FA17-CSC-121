//
// Created by TheLoneWoof on 10/5/17.
//

#include "Menu.h"
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Menu-Related Methods

void Menu::addItem(char idx, std::string lbl) {
    if (!isalnum(idx) && !ispunct(idx)) {
        throw invalid_argument("Menu Class: Indices can only be alphanumeric or punctuation.");
    }

    bool isUnique = true;
    for (MenuItem m : items ) {
        if (m.idx == toupper(idx)) {
            isUnique = false;
            break;
        }
    }
    if (isUnique) {
        items.push_back(MenuItem(toupper(idx), lbl));
    } else {
        throw invalid_argument( "Menu Class: MenuItems must have unique indices." );
    }
}

string Menu::stringify(int indent_w, std::string prefix, std::string suffix) {
    stringstream ss;
    string indent;
    indent.assign(indent_w, ' ');

    for (MenuItem m : items) {
        ss << indent << prefix << m.idx << suffix << " " << m.lbl << endl;
    }

    return ss.str();
}

bool Menu::isValidIdx(char try_idx) {
    bool isValid = false;
    for (MenuItem m : items ) {
        if (m.idx == toupper(try_idx)) {
            isValid = true;
            break; // No need to check for duplicates. Already taken care of.
        }
    }
    return isValid;
}

string Menu::getLabelByIdx(char try_idx) {
    if (!isValidIdx(try_idx)) {
        throw invalid_argument("Menu::getItemByIdx -- Please check index before using it.");
    }

    string temp_item;
    for (MenuItem item : items ) {
        if (item.idx == toupper(try_idx)) {
            temp_item = item.lbl;
            break;
        }
    }

    return temp_item;
}