#include "Equipment.hpp"

int Equipment::nextId_ = 1;

Equipment::Equipment(std::string name)
  : id_(nextId_++), name_(std::move(name))
{}

void Equipment::show(std::ostream& os) const {
    os << "Equipment[" << id_ << "] " << name_;
    printDetails(os);
    os << '\n';
}
