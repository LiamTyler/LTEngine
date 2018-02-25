#include "include/input.h"

Input::Input() {
}

bool Input::HandleInput() {
    memset(pressed_, false, sizeof(pressed_));
    memset(released_, false, sizeof(released_));
    mouse.Update();
    mouseEvent_ = false;
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return true;
        } else if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
            switch (event.key.keysym.sym) {
                case SDLK_a:
                    pressed_[K_A] = true;
                    break;
                case SDLK_b:
                    pressed_[K_B] = true;
                    break;
                case SDLK_c:
                    pressed_[K_C] = true;
                    break;
                case SDLK_d:
                    pressed_[K_D] = true;
                    break;
                case SDLK_e:
                    pressed_[K_E] = true;
                    break;
                case SDLK_f:
                    pressed_[K_F] = true;
                    break;
                case SDLK_g:
                    pressed_[K_G] = true;
                    break;
                case SDLK_h:
                    pressed_[K_H] = true;
                    break;
                case SDLK_i:
                    pressed_[K_I] = true;
                    break;
                case SDLK_j:
                    pressed_[K_J] = true;
                    break;
                case SDLK_k:
                    pressed_[K_K] = true;
                    break;
                case SDLK_l:
                    pressed_[K_L] = true;
                    break;
                case SDLK_m:
                    pressed_[K_M] = true;
                    break;
                case SDLK_n:
                    pressed_[K_N] = true;
                    break;
                case SDLK_o:
                    pressed_[K_O] = true;
                    break;
                case SDLK_p:
                    pressed_[K_P] = true;
                    break;
                case SDLK_q:
                    pressed_[K_Q] = true;
                    break;
                case SDLK_r:
                    pressed_[K_R] = true;
                    break;
                case SDLK_s:
                    pressed_[K_S] = true;
                    break;
                case SDLK_t:
                    pressed_[K_T] = true;
                    break;
                case SDLK_u:
                    pressed_[K_U] = true;
                    break;
                case SDLK_v:
                    pressed_[K_V] = true;
                    break;
                case SDLK_w:
                    pressed_[K_W] = true;
                    break;
                case SDLK_x:
                    pressed_[K_X] = true;
                    break;
                case SDLK_y:
                    pressed_[K_Y] = true;
                    break;
                case SDLK_z:
                    pressed_[K_Z] = true;
                    break;
                case SDLK_ESCAPE:
                    pressed_[K_ESC] = true;
                    break;
                case SDLK_F1:
                    pressed_[K_F1] = true;
                    break;
                case SDLK_F2:
                    pressed_[K_F2] = true;
                    break;
                case SDLK_F3:
                    pressed_[K_F3] = true;
                    break;
                case SDLK_F4:
                    pressed_[K_F4] = true;
                    break;
                case SDLK_F5:
                    pressed_[K_F5] = true;
                    break;
                case SDLK_F6:
                    pressed_[K_F6] = true;
                    break;
                case SDLK_F7:
                    pressed_[K_F7] = true;
                    break;
                case SDLK_F8:
                    pressed_[K_F8] = true;
                    break;
                case SDLK_F9:
                    pressed_[K_F9] = true;
                    break;
                case SDLK_F10:
                    pressed_[K_F10] = true;
                    break;
                case SDLK_F11:
                    pressed_[K_F11] = true;
                    break;
                case SDLK_F12:
                    pressed_[K_F12] = true;
                    break;
                case SDLK_PRINTSCREEN:
                    pressed_[K_PRINTSCREEN] = true;
                    break;
                case SDLK_INSERT:
                    pressed_[K_INSERT] = true;
                    break;
                case SDLK_DELETE:
                    pressed_[K_DELETE] = true;
                    break;
                case SDLK_HOME:
                    pressed_[K_HOME] = true;
                    break;
                case SDLK_END:
                    pressed_[K_END] = true;
                    break;
                case SDLK_PAGEUP:
                    pressed_[K_PAGEUP] = true;
                    break;
                case SDLK_PAGEDOWN:
                    pressed_[K_PAGEDOWN] = true;
                    break;
                case SDLK_BACKQUOTE:
                    pressed_[K_BACKQUOTE] = true;
                    break;
                case SDLK_1:
                    pressed_[K_1] = true;
                    break;
                case SDLK_2:
                    pressed_[K_2] = true;
                    break;
                case SDLK_3:
                    pressed_[K_3] = true;
                    break;
                case SDLK_4:
                    pressed_[K_4] = true;
                    break;
                case SDLK_5:
                    pressed_[K_5] = true;
                    break;
                case SDLK_6:
                    pressed_[K_6] = true;
                    break;
                case SDLK_7:
                    pressed_[K_7] = true;
                    break;
                case SDLK_8:
                    pressed_[K_8] = true;
                    break;
                case SDLK_9:
                    pressed_[K_9] = true;
                    break;
                case SDLK_0:
                    pressed_[K_0] = true;
                    break;
                case SDLK_MINUS:
                    pressed_[K_MINUS] = true;
                    break;
                case SDLK_EQUALS:
                    pressed_[K_EQUALS] = true;
                    break;
                case SDLK_BACKSPACE:
                    pressed_[K_BACKSPACE] = true;
                    break;
                case SDLK_TAB:
                    pressed_[K_TAB] = true;
                    break;
                case SDLK_LEFTBRACKET:
                    pressed_[K_LBRACKET] = true;
                    break;
                case SDLK_RIGHTBRACKET:
                    pressed_[K_RBRACKET] = true;
                    break;
                case SDLK_BACKSLASH:
                    pressed_[K_BACKSLASH] = true;
                    break;
                case SDLK_CAPSLOCK:
                    pressed_[K_CAPSLOCK] = true;
                    break;
                case SDLK_SEMICOLON:
                    pressed_[K_SEMICOLON] = true;
                    break;
                case SDLK_QUOTE:
                    pressed_[K_QUOTE] = true;
                    break;
                case SDLK_RETURN:
                    pressed_[K_ENTER] = true;
                    break;
                case SDLK_LSHIFT:
                    pressed_[K_LSHIFT] = true;
                    break;
                case SDLK_COMMA:
                    pressed_[K_COMMA] = true;
                    break;
                case SDLK_PERIOD:
                    pressed_[K_PERIOD] = true;
                    break;
                case SDLK_SLASH:
                    pressed_[K_SLASH] = true;
                    break;
                case SDLK_RSHIFT:
                    pressed_[K_RSHIFT] = true;
                    break;
                case SDLK_LCTRL:
                    pressed_[K_LCONTROL] = true;
                    break;
                // case SDLK_:
                //     pressed_[K_FN] = true;
                //     break;
                case SDLK_APPLICATION:
                    pressed_[K_SUPER] = true;
                    break;
                case SDLK_LALT:
                    pressed_[K_LALT] = true;
                    break;
                case SDLK_SPACE:
                    pressed_[K_SPACE] = true;
                    break;
                case SDLK_RALT:
                    pressed_[K_RALT] = true;
                    break;
                case SDLK_MENU:
                    pressed_[K_MENU] = true;
                    break;
                case SDLK_RCTRL:
                    pressed_[K_RCONTROL] = true;
                    break;
                case SDLK_LEFT:
                    pressed_[K_LEFT] = true;
                    break;
                case SDLK_RIGHT:
                    pressed_[K_RIGHT] = true;
                    break;
                case SDLK_UP:
                    pressed_[K_UP] = true;
                    break;
                case SDLK_DOWN:
                    pressed_[K_DOWN] = true;
                    break;
                default:
                    break;
            }
        } else if (event.type == SDL_KEYUP) {
            switch (event.key.keysym.sym) {
                case SDLK_a:
                    released_[K_A] = true;
                    break;
                case SDLK_b:
                    released_[K_B] = true;
                    break;
                case SDLK_c:
                    released_[K_C] = true;
                    break;
                case SDLK_d:
                    released_[K_D] = true;
                    break;
                case SDLK_e:
                    released_[K_E] = true;
                    break;
                case SDLK_f:
                    released_[K_F] = true;
                    break;
                case SDLK_g:
                    released_[K_G] = true;
                    break;
                case SDLK_h:
                    released_[K_H] = true;
                    break;
                case SDLK_i:
                    released_[K_I] = true;
                    break;
                case SDLK_j:
                    released_[K_J] = true;
                    break;
                case SDLK_k:
                    released_[K_K] = true;
                    break;
                case SDLK_l:
                    released_[K_L] = true;
                    break;
                case SDLK_m:
                    released_[K_M] = true;
                    break;
                case SDLK_n:
                    released_[K_N] = true;
                    break;
                case SDLK_o:
                    released_[K_O] = true;
                    break;
                case SDLK_p:
                    released_[K_P] = true;
                    break;
                case SDLK_q:
                    released_[K_Q] = true;
                    break;
                case SDLK_r:
                    released_[K_R] = true;
                    break;
                case SDLK_s:
                    released_[K_S] = true;
                    break;
                case SDLK_t:
                    released_[K_T] = true;
                    break;
                case SDLK_u:
                    released_[K_U] = true;
                    break;
                case SDLK_v:
                    released_[K_V] = true;
                    break;
                case SDLK_w:
                    released_[K_W] = true;
                    break;
                case SDLK_x:
                    released_[K_X] = true;
                    break;
                case SDLK_y:
                    released_[K_Y] = true;
                    break;
                case SDLK_z:
                    released_[K_Z] = true;
                    break;
                case SDLK_ESCAPE:
                    released_[K_ESC] = true;
                    break;
                case SDLK_F1:
                    released_[K_F1] = true;
                    break;
                case SDLK_F2:
                    released_[K_F2] = true;
                    break;
                case SDLK_F3:
                    released_[K_F3] = true;
                    break;
                case SDLK_F4:
                    released_[K_F4] = true;
                    break;
                case SDLK_F5:
                    released_[K_F5] = true;
                    break;
                case SDLK_F6:
                    released_[K_F6] = true;
                    break;
                case SDLK_F7:
                    released_[K_F7] = true;
                    break;
                case SDLK_F8:
                    released_[K_F8] = true;
                    break;
                case SDLK_F9:
                    released_[K_F9] = true;
                    break;
                case SDLK_F10:
                    released_[K_F10] = true;
                    break;
                case SDLK_F11:
                    released_[K_F11] = true;
                    break;
                case SDLK_F12:
                    released_[K_F12] = true;
                    break;
                case SDLK_PRINTSCREEN:
                    released_[K_PRINTSCREEN] = true;
                    break;
                case SDLK_INSERT:
                    released_[K_INSERT] = true;
                    break;
                case SDLK_DELETE:
                    released_[K_DELETE] = true;
                    break;
                case SDLK_HOME:
                    released_[K_HOME] = true;
                    break;
                case SDLK_END:
                    released_[K_END] = true;
                    break;
                case SDLK_PAGEUP:
                    released_[K_PAGEUP] = true;
                    break;
                case SDLK_PAGEDOWN:
                    released_[K_PAGEDOWN] = true;
                    break;
                case SDLK_BACKQUOTE:
                    released_[K_BACKQUOTE] = true;
                    break;
                case SDLK_1:
                    released_[K_1] = true;
                    break;
                case SDLK_2:
                    released_[K_2] = true;
                    break;
                case SDLK_3:
                    released_[K_3] = true;
                    break;
                case SDLK_4:
                    released_[K_4] = true;
                    break;
                case SDLK_5:
                    released_[K_5] = true;
                    break;
                case SDLK_6:
                    released_[K_6] = true;
                    break;
                case SDLK_7:
                    released_[K_7] = true;
                    break;
                case SDLK_8:
                    released_[K_8] = true;
                    break;
                case SDLK_9:
                    released_[K_9] = true;
                    break;
                case SDLK_0:
                    released_[K_0] = true;
                    break;
                case SDLK_MINUS:
                    released_[K_MINUS] = true;
                    break;
                case SDLK_EQUALS:
                    released_[K_EQUALS] = true;
                    break;
                case SDLK_BACKSPACE:
                    released_[K_BACKSPACE] = true;
                    break;
                case SDLK_TAB:
                    released_[K_TAB] = true;
                    break;
                case SDLK_LEFTBRACKET:
                    released_[K_LBRACKET] = true;
                    break;
                case SDLK_RIGHTBRACKET:
                    released_[K_RBRACKET] = true;
                    break;
                case SDLK_BACKSLASH:
                    released_[K_BACKSLASH] = true;
                    break;
                case SDLK_CAPSLOCK:
                    released_[K_CAPSLOCK] = true;
                    break;
                case SDLK_SEMICOLON:
                    released_[K_SEMICOLON] = true;
                    break;
                case SDLK_QUOTE:
                    released_[K_QUOTE] = true;
                    break;
                case SDLK_RETURN:
                    released_[K_ENTER] = true;
                    break;
                case SDLK_LSHIFT:
                    released_[K_LSHIFT] = true;
                    break;
                case SDLK_COMMA:
                    released_[K_COMMA] = true;
                    break;
                case SDLK_PERIOD:
                    released_[K_PERIOD] = true;
                    break;
                case SDLK_SLASH:
                    released_[K_SLASH] = true;
                    break;
                case SDLK_RSHIFT:
                    released_[K_RSHIFT] = true;
                    break;
                case SDLK_LCTRL:
                    released_[K_LCONTROL] = true;
                    break;
                // case SDLK_:
                //     released_[K_FN] = true;
                //     break;
                case SDLK_APPLICATION:
                    released_[K_SUPER] = true;
                    break;
                case SDLK_LALT:
                    released_[K_LALT] = true;
                    break;
                case SDLK_SPACE:
                    released_[K_SPACE] = true;
                    break;
                case SDLK_RALT:
                    released_[K_RALT] = true;
                    break;
                case SDLK_MENU:
                    released_[K_MENU] = true;
                    break;
                case SDLK_RCTRL:
                    released_[K_RCONTROL] = true;
                    break;
                case SDLK_LEFT:
                    released_[K_LEFT] = true;
                    break;
                case SDLK_RIGHT:
                    released_[K_RIGHT] = true;
                    break;
                case SDLK_UP:
                    released_[K_UP] = true;
                    break;
                case SDLK_DOWN:
                    released_[K_DOWN] = true;
                    break;
                default:
                    break;
            }
        } else if (event.type == SDL_MOUSEMOTION) {
            mouseEvent_ = true;
            float dx = event.motion.xrel;
            float dy = event.motion.yrel;
            mouse.dx = dx;
            mouse.dy = dy;
            mouse.x = event.motion.x;
            mouse.y = event.motion.y;
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            switch(event.button.button) {
                case SDL_BUTTON_LEFT:
                    pressed_[M_LEFT] = true;
                    break;
                case SDL_BUTTON_MIDDLE:
                    pressed_[M_MIDDLE] = true;
                    break;
                case SDL_BUTTON_RIGHT:
                    pressed_[M_RIGHT] = true;
                    break;
                default:
                    break;
            }
        } else if (event.type == SDL_MOUSEBUTTONUP) {
            switch(event.button.button) {
                case SDL_BUTTON_LEFT:
                    released_[M_LEFT] = true;
                    break;
                case SDL_BUTTON_MIDDLE:
                    released_[M_MIDDLE] = true;
                    break;
                case SDL_BUTTON_RIGHT:
                    released_[M_RIGHT] = true;
                    break;
                default:
                    break;
            }
        }
    }
    return false;
}

bool Input::KeyPressed(KeyCode k) {
    return pressed_[k];
}

bool Input::KeyReleased(KeyCode k) {
    return released_[k];
}
