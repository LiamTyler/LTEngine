#ifndef INCLUDE_FPS_COUNTER_H_
#define INCLUDE_FPS_COUNTER_H_

class FPSCounter {
    public:
        FPSCounter();
        ~FPSCounter();
        void StartFrame(float dt);
        void EndFrame();
        float GetDT() { return time_ - prevTime_; }

    protected:
        float time_;
        float prevTime_;
        float fpsTime_;
        unsigned int frameCounter_;
};

#endif  // INCLUDE_FPS_COUNTER_H_
