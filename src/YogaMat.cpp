#include "YogaMat.hpp"

YogaMat::YogaMat(double thicknessMM)
  : Equipment("YogaMat"), thicknessMM_(thicknessMM)
{}

std::unique_ptr<Equipment> YogaMat::clone() const {
    return std::make_unique<YogaMat>(*this);
}

void YogaMat::printDetails(std::ostream& os) const {
    os << "  [Thickness: " << thicknessMM_ << " mm]";
}
