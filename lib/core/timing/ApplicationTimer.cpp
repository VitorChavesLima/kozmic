//
// Created by Vitor Chaves on 10/07/2022.
//

#include <kozmic/core/timing/ApplicationTimer.h>

using namespace Kozmic::Core::Timing;

//<editor-fold desc="Constructors and Destructors">

K_ApplicationTimer::K_ApplicationTimer() {
    this->m_currentFrameTime = { };
    this->m_lastFrameTime = { };

    this->m_nIdealFrameTime = 0;
}

//</editor-fold>

//<editor-fold desc="Getters">

[[maybe_unused]] double K_ApplicationTimer::getIdealFrameTime() const {
    return this->m_nIdealFrameTime;
}

//</editor-fold>

//<editor-fold desc="Setters">

[[maybe_unused]] void K_ApplicationTimer::setFramesPerSecond(int t_nFramesPerSecond) {
    this->m_nIdealFrameTime = 1.0f / (float) t_nFramesPerSecond;
}

//</editor-fold>

//<editor-fold desc="Timer specific">

[[maybe_unused]] void K_ApplicationTimer::markCurrentFrameTime() {
    this->m_currentFrameTime = std::chrono::high_resolution_clock::now();
}

[[maybe_unused]] void K_ApplicationTimer::markLastFrameTime() {
    this->m_lastFrameTime = std::chrono::high_resolution_clock::now();
}

[[maybe_unused]] double K_ApplicationTimer::deltaTime() {
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(this->m_lastFrameTime - this->m_currentFrameTime).count();
    auto deltaTime = std::chrono::duration<double, std::nano>(elapsed).count();
    this->m_currentFrameTime = this->m_lastFrameTime;
    return deltaTime;
}

//</editor-fold>
