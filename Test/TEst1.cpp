//
// Created by waterdev on 04.12.21.
//

#include <X11/Xlib.h>
#include <iostream>
#include "basics.h"
#include "X11/keysym.h"

/**
 *
 * @param ks  like XK_Shift_L, see /usr/include/X11/keysymdef.h
 * @return
 */
bool ctrl_is_pressed() {

    return GetAsyncKeyState(XK_Control_L) || GetAsyncKeyState(XK_Control_R);
}

int main(int argc, char **argv) {

    while(true) {
        std::cout << ctrl_is_pressed() << std::endl;
    }
    return (0);
};