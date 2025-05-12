#include "Member.h"

int Member::totalCount_ = 0;

Member::Member(std::string name, int id)
  : name_{std::move(name)}, id_{id}
{
    ++totalCount_;
}

Member::~Member() {
    --totalCount_;
}

Member::Member(const Member& other)
  : name_{other.name_}, id_{other.id_}
{
    ++totalCount_;
}

Member& Member::operator=(Member other) {
    swap(*this, other);
    return *this;
}

void swap(Member& a, Member& b) noexcept {
    using std::swap;
    swap(a.name_, b.name_);
    swap(a.id_,   b.id_);
}

int Member::getID() const noexcept         { return id_; }
const std::string& Member::getName() const noexcept { return name_; }
int Member::getTotalCount() noexcept       { return totalCount_; }

std::ostream& operator<<(std::ostream& os, const Member& m) {
    m.info();
    return os;
}
