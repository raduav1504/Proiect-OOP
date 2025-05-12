#include "FacilityElement.h"
#include <utility>

FacilityElement::FacilityElement(std::string name)
  : name_{std::move(name)} {}

FacilityElement::~FacilityElement() = default;

FacilityElement::FacilityElement(const FacilityElement& other)
  : name_{other.name_} {}

FacilityElement& FacilityElement::operator=(FacilityElement other) {
    swap(*this, other);
    return *this;
}

void swap(FacilityElement& a, FacilityElement& b) noexcept {
    using std::swap;
    swap(a.name_, b.name_);
}

void FacilityElement::print(std::ostream& os) const {
    os << name_ << ": ";
    describe();
}

const std::string& FacilityElement::getName() const noexcept {
    return name_;
}

std::ostream& operator<<(std::ostream& os, const FacilityElement& elem) {
    elem.print(os);
    return os;
}
