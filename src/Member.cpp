#include "Member.hpp"
#include <utility>

int Member::nextId_ = 1;

Member::Member(std::string name)
  : id_(nextId_++), name_(std::move(name))
{}

Member::Member(const Member& other)
  : id_(nextId_++), name_(other.name_)
{}

Member& Member::operator=(Member other) {
    swap(*this, other);
    return *this;
}

void swap(Member& a, Member& b) {
    using std::swap;
    swap(a.id_,    b.id_);
    swap(a.name_,  b.name_);
}

int Member::getId() const { return id_; }
const std::string& Member::getName() const { return name_; }

void Member::print(std::ostream& os) const {
    os << "Member[" << id_ << "] " << name_;
}
