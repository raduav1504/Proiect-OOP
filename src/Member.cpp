#include "Member.h"
#include <iostream>
#include <utility>

Member::Member(std::string name, int id)
  : name_{std::move(name)}, id_{id} {
    std::cout << "New member: " << name_ << " (ID " << id_ << ")\n";
}

Member::~Member() = default;

Member::Member(const Member& other)
  : name_{other.name_}, id_{other.id_}
{}

Member& Member::operator=(Member other) {
    swap(*this, other);
    return *this;
}

void swap(Member& a, Member& b) noexcept {
    using std::swap;
    swap(a.name_, b.name_);
    swap(a.id_, b.id_);
}

int Member::getID() const noexcept { return id_; }
const std::string& Member::getName() const noexcept { return name_; }

// Exemplu subclasă concretă
class Regular : public Member {
public:
    Regular(const std::string& name, int id)
      : Member(name, id) {}
    std::unique_ptr<Member> clone() const override {
        return std::make_unique<Regular>(*this);
    }
    void info() const override {
        std::cout << "Regular Member: " << name_
                  << " (ID " << id_ << ")\n";
    }
};

