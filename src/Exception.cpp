#include "Exception.h"

GymException::GymException(std::string msg) noexcept
  : message_{std::move(msg)} {}

const char* GymException::what() const noexcept {
    return message_.c_str();
}

IndexException::IndexException(const std::string& who, int idx) noexcept
  : GymException(who + " index invalid: " + std::to_string(idx)) {}

