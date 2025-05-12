#include "Gym.h"
#include <iostream>
#include <utility>

int Gym::gymCount_ = 0;

Gym::Gym(std::string name)
  : name_{std::move(name)} {
    ++gymCount_;
    std::cout << "Gym opened: " << name_ << "\n";
}

Gym::~Gym() {
    std::cout << "Gym closed: " << name_ << "\n";
    --gymCount_;
}

Gym::Gym(const Gym& other)
  : name_{other.name_}
  , equipments_{}
  , members_{}
{
    for (auto const& e : other.equipments_)
        equipments_.push_back(e->clone());
    for (auto const& m : other.members_)
        members_.push_back(m->clone());
}

Gym& Gym::operator=(Gym other) {
    swap(*this, other);
    return *this;
}

void swap(Gym& a, Gym& b) noexcept {
    using std::swap;
    swap(a.name_, b.name_);
    swap(a.equipments_, b.equipments_);
    swap(a.members_, b.members_);
}

void Gym::addEquipment(const Equipment& eq) {
    equipments_.push_back(eq.clone());
}

void Gym::addMember(const Member& m) {
    members_.push_back(m.clone());
}

void Gym::updateAll() {
    for (auto& e : equipments_)
        e->update();
}

void Gym::startUsage(size_t eqIdx, size_t memIdx, int duration) {
    if (eqIdx >= equipments_.size())
        throw IndexException("Equipment", static_cast<int>(eqIdx));
    if (memIdx >= members_.size())
        throw IndexException("Member", static_cast<int>(memIdx));

    // exemplu de dynamic_cast:
    if (auto* tr = dynamic_cast<Treadmill*>(equipments_[eqIdx].get())) {
        tr->startUsage(duration, members_[memIdx]->getName());
    } else {
        equipments_[eqIdx]->startUsage(duration, members_[memIdx]->getName());
    }
}

void Gym::printStatus() const {
    std::cout << "=== " << name_ << " ===\n";
    for (size_t i = 0; i < equipments_.size(); ++i)
        std::cout << "["<<i<<"] " << equipments_[i]->getType() << "\n";
    for (size_t i = 0; i < members_.size(); ++i)
        members_[i]->info();
    std::cout << "Total gyms: " << totalGyms() << "\n";
}

int Gym::totalGyms() noexcept {
    return gymCount_;
}

