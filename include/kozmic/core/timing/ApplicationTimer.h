//
// Created by Vitor Chaves on 10/07/2022.
//

#ifndef KOZMIC_APPLICATIONTIMER_H
#define KOZMIC_APPLICATIONTIMER_H

#include <chrono>

namespace Kozmic::Core::Timing {
    class K_ApplicationTimer {

    //<editor-fold desc="Properties">

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::duration<double>> m_currentFrameTime;
        std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::duration<double>> m_lastFrameTime;

        double m_nIdealFrameTime;

    //</editor-fold>

    //<editor-fold desc="Constructors and Destructors">

    public:
        K_ApplicationTimer();

    //</editor-fold>

    //<editor-fold desc="Getters">

    public:
        [[maybe_unused]] [[nodiscard]] double getIdealFrameTime() const;

    //</editor-fold>

    //<editor-fold desc="Setters">

    public:
        [[maybe_unused]] void setFramesPerSecond(int t_nFramesPerSecond);

    //</editor-fold>

    //<editor-fold desc="Timer specific">

    public:
        [[maybe_unused]] void markCurrentFrameTime();
        [[maybe_unused]] void markLastFrameTime();
        [[maybe_unused]] double deltaTime();

    //</editor-fold>

    };
}

#endif //KOZMIC_APPLICATIONTIMER_H
