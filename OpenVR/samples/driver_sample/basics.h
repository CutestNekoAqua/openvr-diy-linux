#ifndef BASICS_H
#define BASICS_H

#include <openvr_driver.h>

#if defined(_WINDOWS)
#include <windows.h>
#else
#include <cstring>
#include <X11/Xlib.h>
#include "X11/keysym.h"
#define _stricmp strcasecmp
bool GetAsyncKeyState(KeySym key);

#define VK_NUMPAD3 XK_KP_3
#define VK_NUMPAD1 XK_KP_1
#define VK_NUMPAD4 XK_KP_4
#define VK_NUMPAD6 XK_KP_6
#define VK_NUMPAD8 XK_KP_8
#define VK_NUMPAD2 XK_KP_2
#define VK_NUMPAD9 XK_KP_9
#define VK_UP      XK_Up
#define VK_DOWN    XK_Down
#define VK_LEFT    XK_Left
#define VK_RIGHT   XK_Right
#define VK_PRIOR   XK_Prior
#define VK_NEXT    XK_Next
#define VK_END     XK_End
#endif

// keys for use with the settings API
extern const char *const k_pch_Sample_Section;
extern const char *const k_pch_Sample_SerialNumber_String;
extern const char *const k_pch_Sample_ModelNumber_String;
extern const char *const k_pch_Sample_WindowX_Int32;
extern const char *const k_pch_Sample_WindowY_Int32;
extern const char *const k_pch_Sample_WindowWidth_Int32;
extern const char *const k_pch_Sample_WindowHeight_Int32;
extern const char *const k_pch_Sample_RenderWidth_Int32;
extern const char *const k_pch_Sample_RenderHeight_Int32;
extern const char *const k_pch_Sample_SecondsFromVsyncToPhotons_Float;
extern const char *const k_pch_Sample_DisplayFrequency_Float;

extern bool g_bExiting;

inline vr::HmdQuaternion_t HmdQuaternion_Init( double w, double x, double y, double z )
{
    vr::HmdQuaternion_t quat{};
    quat.w = w;
    quat.x = x;
    quat.y = y;
    quat.z = z;
    return quat;
}

inline void HmdMatrix_SetIdentity(vr::HmdMatrix34_t *pMatrix)
{
    pMatrix->m[0][0] = 1.f;
    pMatrix->m[0][1] = 0.f;
    pMatrix->m[0][2] = 0.f;
    pMatrix->m[0][3] = 0.f;
    pMatrix->m[1][0] = 0.f;
    pMatrix->m[1][1] = 1.f;
    pMatrix->m[1][2] = 0.f;
    pMatrix->m[1][3] = 0.f;
    pMatrix->m[2][0] = 0.f;
    pMatrix->m[2][1] = 0.f;
    pMatrix->m[2][2] = 1.f;
    pMatrix->m[2][3] = 0.f;
}

#endif // BASICS_H
