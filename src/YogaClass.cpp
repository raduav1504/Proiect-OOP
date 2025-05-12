#include "YogaClass.h"
#include <iostream>

YogaClass::YogaClass(int duration)
  : FitnessClass("Yoga Class", duration) {}

void YogaClass::describe() const {
    std::cout << "Relaxing yoga (" << duration_ << " min)\n";
}

void YogaClass::attend(const std::string& memberName) {
    attendees_.push_back(memberName);
    std::cout << memberName << " joined Yoga\n";
}

void YogaClass::update() {
    if (!attendees_.empty()) {
        std::cout << "Yoga finished for " << attendees_.size() << " attendees\n";
        attendees_.clear();
    }
}

std::unique_ptr<FacilityElement> YogaClass::clone() const {
    return std::make_unique<YogaClass>(*this);
}
