#include "FitnessClass.h"
#include <utility>

FitnessClass::FitnessClass(std::string name, int duration)
  : FacilityElement(std::move(name)), duration_{duration} {}

FitnessClass::~FitnessClass() = default;

FitnessClass::FitnessClass(const FitnessClass& other)
  : FacilityElement(other)
  , duration_{other.duration_}
  , attendees_{other.attendees_}
{}

FitnessClass& FitnessClass::operator=(FitnessClass other) {
    swap(*this, other);
    return *this;
}

void swap(FitnessClass& a, FitnessClass& b) noexcept {
    using std::swap;
    swap(static_cast<FacilityElement&>(a), static_cast<FacilityElement&>(b));
    swap(a.duration_, b.duration_);
    swap(a.attendees_, b.attendees_);
}

int FitnessClass::getDuration() const noexcept {
    return duration_;
}
