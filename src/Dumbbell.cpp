#include "Dumbbell.hpp"

Dumbbell::Dumbbell(int weightKg)
  : Equipment("Dumbbell"), weightKg_(weightKg)
{}

std::unique_ptr<Equipment> Dumbbell::clone() const {
    return std::make_unique<Dumbbell>(*this);
}

void Dumbbell::printDetails(std::ostream& os) const {
    os << "  [Weight: " << weightKg_ << " kg]";
}
