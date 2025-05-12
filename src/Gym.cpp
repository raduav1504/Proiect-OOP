// Gym.cpp
#include "Gym.h"
#include "exceptions.h"   // your own exception types
#include <algorithm>
#include <iostream>

// —————————————————————————————————————————————————————————
//  Ctor / copy / assign / dtor
// —————————————————————————————————————————————————————————

Gym::Gym(std::string name)
  : name_(std::move(name))
{}

Gym::Gym(const Gym& other)
  : name_(other.name_)
{
    for (auto& eq : other.equipments_) {
        equipments_.push_back(std::make_unique<Equipment>(*eq));
    }
    members_ = other.members_;
}

Gym& Gym::operator=(Gym other) {
    swap(*this, other);
    return *this;
}

Gym::~Gym() = default;

void swap(Gym& a, Gym& b) {
    using std::swap;
    swap(a.name_,        b.name_);
    swap(a.equipments_,  b.equipments_);
    swap(a.members_,     b.members_);
}

// —————————————————————————————————————————————————————————
//  add / remove
// —————————————————————————————————————————————————————————

void Gym::addEquipment(std::unique_ptr<Equipment> eq) {
    if (!eq) throw IndexException("null equipment");
    equipments_.push_back(std::move(eq));
}

void Gym::removeEquipment(int idx) {
    if (idx < 0 || idx >= int(equipments_.size()))
        throw IndexException("equipment index out of range");
    equipments_.erase(equipments_.begin() + idx);
}

void Gym::addMember(const Member& m) {
    members_.push_back(m);
}

void Gym::removeMember(int idx) {
    if (idx < 0 || idx >= int(members_.size()))
        throw IndexException("member index out of range");
    members_.erase(members_.begin() + idx);
}

// —————————————————————————————————————————————————————————
//  start usage
// —————————————————————————————————————————————————————————

void Gym::startEquipmentUsage(int eqIndex, int duration, int memberIndex) {
    if (eqIndex < 0 || eqIndex >= int(equipments_.size()))
        throw IndexException("equipment index out of range");
    if (memberIndex < 0 || memberIndex >= int(members_.size()))
        throw IndexException("member index out of range");
    equipments_[eqIndex]->startUsage(duration, members_[memberIndex].getName());
}

// —————————————————————————————————————————————————————————
//  maintenance
// —————————————————————————————————————————————————————————

void Gym::scheduleMaintenance(int eqIndex, int duration) {
    if (eqIndex < 0 || eqIndex >= int(equipments_.size()))
        throw IndexException("equipment index out of range");
    equipments_[eqIndex]->startMaintenance(duration);
}

void Gym::completeMaintenance(int eqIndex) {
    if (eqIndex < 0 || eqIndex >= int(equipments_.size()))
        throw IndexException("equipment index out of range");
    equipments_[eqIndex]->stopMaintenance();
}

// —————————————————————————————————————————————————————————
//  update clock (usage + maintenance)
// —————————————————————————————————————————————————————————

void Gym::update() {
    for (auto& eq : equipments_) {
        eq->updateUsage();
        eq->updateMaintenance();
    }
}

// —————————————————————————————————————————————————————————
//  search by type
// —————————————————————————————————————————————————————————

std::vector<int> Gym::searchEquipmentByType(const std::string& type) const {
    std::vector<int> result;
    for (int i = 0; i < int(equipments_.size()); ++i) {
        if (equipments_[i]->getType() == type)
            result.push_back(i);
    }
    return result;
}

// —————————————————————————————————————————————————————————
//  print everything
// —————————————————————————————————————————————————————————

void Gym::printStatus(std::ostream& os) const {
    os << "\nGym: " << name_ << "\n\n"
       << "Equipments:\n";
    for (int i = 0; i < int(equipments_.size()); ++i) {
        os << " [" << i << "] " << *equipments_[i] << "\n";
    }
    os << "\nMembers:\n";
    for (auto const& m : members_) {
        os << "  - " << m << "\n";
    }
}
