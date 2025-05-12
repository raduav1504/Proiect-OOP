#include "StationaryBike.hpp"

StationaryBike::StationaryBike(int resistance)
  : Equipment("StationaryBike"), resistance_(resistance)
{}

std::unique_ptr<Equipment> StationaryBike::clone() const {
    return std::make_unique<StationaryBike>(*this);
}

void StationaryBike::printDetails(std::ostream& os) const {
    os << "  [Resistance: level " << resistance_ << "]";
}
