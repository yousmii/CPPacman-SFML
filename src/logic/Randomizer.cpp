#include "Randomizer.hpp"

namespace Logic {

RNG RNG::getInstance() {
    static RNG instance;
    return instance;
}
int RNG::getRandomInt(const int min, const int max) {
    generator.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}
} // Logic