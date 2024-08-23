#include "Score.hpp"

#include <stdexcept>

namespace Logic {
    Score::Score() : _score(2000) {}

    void Score::addScore(int score) {
        if (score < 0) {
            throw std::invalid_argument("Score must be a positive number.");
        }
        if (_score < 0) {
            throw std::invalid_argument("Score cannot be negative.");
        }
        _score += score;
    }

    void Score::subtractScore(int score) {
        if (score < 0) {
            throw std::invalid_argument("Score must be a positive number.");
        }
        if (_score < 0) {
            throw std::invalid_argument("Score cannot be negative.");
        }
        _score -= score;
    }

    int Score::getScore() const {
        return _score;
    }
} // Logic