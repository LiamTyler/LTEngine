#ifndef INCLUDE_INPUT_H_
#define INCLUDE_INPUT_H_

#include "include/utils.h"

enum KeyCode : unsigned int {
    // letters
    K_A,
    K_B,
    K_C,
    K_D,
    K_E,
    K_F,
    K_G,
    K_H,
    K_I,
    K_J,
    K_K,
    K_L,
    K_M,
    K_N,
    K_O,
    K_P,
    K_Q,
    K_R,
    K_S,
    K_T,
    K_U,
    K_V,
    K_W,
    K_X,
    K_Y,
    K_Z,
    // row 1
    K_ESC,
    K_F1,
    K_F2,
    K_F3,
    K_F4,
    K_F5,
    K_F6,
    K_F7,
    K_F8,
    K_F9,
    K_F10,
    K_F11,
    K_F12,
    K_PRINTSCREEN,
    K_INSERT,
    K_DELETE,
    K_HOME,
    K_END,
    K_PAGEUP,
    K_PAGEDOWN,
    // row 2
    K_BACKQUOTE,
    K_1,
    K_2,
    K_3,
    K_4,
    K_5,
    K_6,
    K_7,
    K_8,
    K_9,
    K_0,
    K_MINUS,
    K_EQUALS,
    K_BACKSPACE,
    // row 3
    K_TAB,
    K_LBRACKET,
    K_RBRACKET,
    K_BACKSLASH,
    // row 4
    K_CAPSLOCK,
    K_SEMICOLON,
    K_QUOTE,
    K_ENTER,
    // row 5
    K_LSHIFT,
    K_COMMA,
    K_PERIOD,
    K_SLASH,
    K_RSHIFT,
    // row 6
    K_LCONTROL,
    K_FN,
    K_SUPER,
    K_LALT,
    K_SPACE,
    K_RALT,
    K_MENU,
    K_RCONTROL,
    // arrows
    K_LEFT,
    K_RIGHT,
    K_UP,
    K_DOWN,

    K_TOTAL,
};

class Input {
    public:
        Input();
        void HandleInput();
        bool KeyPressed(KeyCode k);
        bool KeyReleased(KeyCode k);

    protected:
        bool pressed_[K_TOTAL];
        bool released_[K_TOTAL];
};

#endif  // INCLUDE_INPUT_H_
