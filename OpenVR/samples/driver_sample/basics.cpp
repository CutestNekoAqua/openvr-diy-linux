#include "basics.h"

// keys for use with the settings API
const char *const k_pch_Sample_Section = "driver_null";
const char *const k_pch_Sample_SerialNumber_String = "serialNumber";
const char *const k_pch_Sample_ModelNumber_String = "modelNumber";
const char *const k_pch_Sample_WindowX_Int32 = "windowX";
const char *const k_pch_Sample_WindowY_Int32 = "windowY";
const char *const k_pch_Sample_WindowWidth_Int32 = "windowWidth";
const char *const k_pch_Sample_WindowHeight_Int32 = "windowHeight";
const char *const k_pch_Sample_RenderWidth_Int32 = "renderWidth";
const char *const k_pch_Sample_RenderHeight_Int32 = "renderHeight";
const char *const k_pch_Sample_SecondsFromVsyncToPhotons_Float = "secondsFromVsyncToPhotons";
const char *const k_pch_Sample_DisplayFrequency_Float = "displayFrequency";

bool g_bExiting = false;

#if !defined(_WINDOWS)

Display *dpy = XOpenDisplay(":0");

bool GetAsyncKeyState(KeySym ks)
{

    char keys_return[32];
    XQueryKeymap(dpy, keys_return);
    KeyCode kc2 = XKeysymToKeycode(dpy, ks);
    bool isPressed = !!(keys_return[kc2 >> 3] & (1 << (kc2 & 7))); /* keys_return is an array of 32*8 bits,
                                                                    * where every bit with the number kc2 is a status of the corresponding key with keycode kc2.
                                                                    * Our goal is to convert kc2 to somewhat of coordinates in "two-dimensional array" keys_return.
                                                                    * To achieve that, we first need to get correct row by dividing kc2 / 8
                                                                    * remember each "row" is 8 bits.
                                                                    * kc2 >> 3 does the same as kc2 / 8. Then we get "column" kc2 % 8,
                                                                    * which is the same as kc2 & 7. Hovewer, since it's a bit, we need to shift 1 to get it.
                                                                    */
    return isPressed; //  Returns true if pressed otherwise false
}

#endif
