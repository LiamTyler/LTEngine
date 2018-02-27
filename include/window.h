#ifndef INCLUDE_WINDOW_H_
#define INCLUDE_WINDOW_H_

#include "include/utils.h"
#include "include/fps_counter.h"

class Window {
    public:
        Window();
        Window(const std::string& title, int w, int h);
        ~Window();
        void Init();
        void SwapWindow();
        void StartFrame();
        void EndFrame();
        float GetTotalRuntime();
        float GetDT();
        void SetFPSCallback(std::function<void(void*)> f, void* data);
        void ClearFPSCallback();

        SDL_Window* GetWindow() { return sdlWindow_; }
        SDL_GLContext GetContext() { return glContext_; }
        void SetRelativeMouse(bool b);

    protected:
        std::string title_;
        int width_;
        int height_;
        FPSCounter fpsCounter_;

        // SDL specifics
        SDL_Window* sdlWindow_;
        SDL_GLContext glContext_;

};

#endif  // INCLUDE_WINDOW_H_
