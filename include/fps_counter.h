#ifndef INCLUDE_FPS_COUNTER_H_
#define INCLUDE_FPS_COUNTER_H_

#include <functional>

class FPSCounter {
    public:
        FPSCounter();
        ~FPSCounter();
        void Clear();
        void StartFrame(float dt);
        void EndFrame();
        float GetDT() { return time_ - prevTime_; }
        void SetCallback(std::function<void(void*)> func, void* data);

    protected:
        float time_;
        float prevTime_;
        float fpsTime_;
        unsigned int frameCounter_;
        std::function<void(void*)> function_;
        void* data_;
};

#endif  // INCLUDE_FPS_COUNTER_H_
