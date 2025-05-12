#include "PremiumMember.h"
#include <iostream>

PremiumMember::PremiumMember(const std::string& name, int id)
  : Member(name, id) {}

std::unique_ptr<Member> PremiumMember::clone() const {
    return std::make_unique<PremiumMember>(*this);
}

void PremiumMember::info() const {
    std::cout << "PremiumMember: " << getName()
              << " (ID " << getID() << ")\n";
}
