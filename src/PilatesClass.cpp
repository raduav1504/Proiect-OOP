#include "PilatesClass.h"
#include <iostream>

PilatesClass::PilatesClass(int duration)
  : FitnessClass("Pilates Class", duration) {}

void PilatesClass::describe() const {
    std::cout << "Core-strength Pilates (" << duration_ << " min)\n";
}

void PilatesClass::attend(const std::string& memberName) {
    attendees_.push_back(memberName);
    std::cout << memberName << " joined Pilates\n";
}

void PilatesClass::update() {
    if (!attendees_.empty()) {
        std::cout << "Pilates finished for " << attendees_.size() << " attendees\n";
        attendees_.clear();
    }
}

std::unique_ptr<FacilityElement> PilatesClass::clone() const {
    return std::make_unique<PilatesClass>(*this);
}
