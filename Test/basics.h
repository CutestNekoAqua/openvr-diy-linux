//
// Created by waterdev on 04.12.21.
//

#ifndef BASICS_H
#define BASICS_H

#include <cstring>
#include <X11/Xlib.h>
#include "X11/keysym.h"
#define _stricmp strcasecmp
bool GetAsyncKeyState(KeySym key);

#endif
