#include "RegularMember.h"
#include <iostream>

RegularMember::RegularMember(const std::string& name, int id)
  : Member(name, id) {}

std::unique_ptr<Member> RegularMember::clone() const {
    return std::make_unique<RegularMember>(*this);
}

void RegularMember::info() const {
    std::cout << "RegularMember: " << getName()
              << " (ID " << getID() << ")\n";
}
