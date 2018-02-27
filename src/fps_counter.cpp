#include <iostream>
#include <iomanip>
#include "include/fps_counter.h"

FPSCounter::FPSCounter() {
    Clear();
}

FPSCounter::~FPSCounter() {}

void FPSCounter::Clear() {
    time_ = 0;
    frameCounter_ = 0;
    fpsTime_ = 0;
}

void FPSCounter::StartFrame(float time) {
    time_ = time;
}

void FPSCounter::EndFrame() {
    prevTime_ = time_;
    ++frameCounter_;
    if (time_ > fpsTime_ + 1) {
        std::cout << "FPS: " << frameCounter_ << std::endl;
        frameCounter_ = 0;
        fpsTime_ = time_;
        if (function_) {
            function_(data_);
        }
    }
}

void FPSCounter::SetCallback(std::function<void(void*)> f, void* data) {
    function_ = f;
    data_ = data;
}
