#include "Stopwatch.hpp"

namespace Logic {
void Stopwatch::Start() { _start = std::chrono::high_resolution_clock::now(); }

void Stopwatch::Tick() {
    std::chrono::system_clock::time_point now = std::chrono::high_resolution_clock::now();

    dt = std::chrono::duration_cast<std::chrono::seconds>(now - _start);
    _start = now;
}

[[nodiscard]] float Stopwatch::GetFrameTime() { return std::chrono::duration<float>(dt).count(); }
} // namespace Logic