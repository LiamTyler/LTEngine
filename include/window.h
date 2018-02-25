#ifndef INCLUDE_WINDOW_H_
#define INCLUDE_WINDOW_H_

#include "include/utils.h"

class Window {
    public:
        Window();
        Window(const std::string& title, int w, int h);
        void Init();
        void SwapWindow();
        SDL_Window* GetWindow() { return sdlWindow_; }
        SDL_GLContext GetContext() { return glContext_; }
        void SetRelativeMouse(bool b);

    protected:
        std::string title_;
        int width_;
        int height_;

        // SDL specifics
        SDL_Window* sdlWindow_;
        SDL_GLContext glContext_;

};

#endif  // INCLUDE_WINDOW_H_
