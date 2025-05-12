#include "SpinningClass.h"
#include <iostream>

SpinningClass::SpinningClass(int duration)
  : FitnessClass("Spinning Class", duration) {}

void SpinningClass::describe() const {
    std::cout << "High-intensity spinning (" << duration_ << " min)\n";
}

void SpinningClass::attend(const std::string& memberName) {
    attendees_.push_back(memberName);
    std::cout << memberName << " joined Spinning\n";
}

void SpinningClass::update() {
    if (!attendees_.empty()) {
        std::cout << "Spinning finished for " << attendees_.size() << " attendees\n";
        attendees_.clear();
    }
}

std::unique_ptr<FacilityElement> SpinningClass::clone() const {
    return std::make_unique<SpinningClass>(*this);
}
