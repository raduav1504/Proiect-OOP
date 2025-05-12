#include "GuestMember.h"
#include <iostream>

GuestMember::GuestMember(const std::string& name, int id)
  : Member(name, id) {}

std::unique_ptr<Member> GuestMember::clone() const {
    return std::make_unique<GuestMember>(*this);
}

void GuestMember::info() const {
    std::cout << "GuestMember: " << getName()
              << " (ID " << getID() << ")\n";
}
