#include "Treadmill.hpp"

Treadmill::Treadmill(double maxSpeed)
  : Equipment("Treadmill"), maxSpeed_(maxSpeed)
{}

std::unique_ptr<Equipment> Treadmill::clone() const {
    return std::make_unique<Treadmill>(*this);
}

void Treadmill::printDetails(std::ostream& os) const {
    os << "  [MaxSpeed: " << maxSpeed_ << " km/h]";
}
