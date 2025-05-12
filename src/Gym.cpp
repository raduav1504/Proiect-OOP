#include "Gym.h"
#include "Exception.h"
#include <algorithm>
#include <iostream>

Gym::Gym(std::string name)
  : name_{std::move(name)}
{}

Gym::Gym(const Gym& other)
  : name_{other.name_}
{
    for (auto& eq : other.equipments_) {
        equipments_.push_back(eq->clone());
    }
    for (auto& m : other.members_) {
        members_.push_back(m->clone());
    }
}

Gym& Gym::operator=(Gym other) {
    swap(*this, other);
    return *this;
}

Gym::~Gym() = default;

void swap(Gym& a, Gym& b) {
    using std::swap;
    swap(a.name_,       b.name_);
    swap(a.equipments_, b.equipments_);
    swap(a.members_,    b.members_);
}

void Gym::addEquipment(std::unique_ptr<Equipment> eq) {
    if (!eq) throw IndexException("addEquipment", -1);
    equipments_.push_back(std::move(eq));
}

void Gym::removeEquipment(int idx) {
    if (idx < 0 || idx >= static_cast<int>(equipments_.size()))
        throw IndexException("equipment", idx);
    equipments_.erase(equipments_.begin() + idx);
}

void Gym::addMember(std::unique_ptr<Member> m) {
    if (!m) throw IndexException("addMember", -1);
    members_.push_back(std::move(m));
}

void Gym::removeMember(int idx) {
    if (idx < 0 || idx >= static_cast<int>(members_.size()))
        throw IndexException("member", idx);
    members_.erase(members_.begin() + idx);
}

void Gym::startEquipmentUsage(int eqIndex, int duration, int memberIndex) {
    if (eqIndex < 0 || eqIndex >= static_cast<int>(equipments_.size()))
        throw IndexException("equipment", eqIndex);
    if (memberIndex < 0 || memberIndex >= static_cast<int>(members_.size()))
        throw IndexException("member", memberIndex);
    equipments_[eqIndex]->startUsage(duration, members_[memberIndex]->getName());
}

void Gym::scheduleMaintenance(int eqIndex, int duration) {
    if (eqIndex < 0 || eqIndex >= static_cast<int>(equipments_.size()))
        throw IndexException("equipment", eqIndex);
    equipments_[eqIndex]->scheduleMaintenance(duration);
}

void Gym::completeMaintenance(int eqIndex) {
    if (eqIndex < 0 || eqIndex >= static_cast<int>(equipments_.size()))
        throw IndexException("equipment", eqIndex);
    equipments_[eqIndex]->completeMaintenance();
}

void Gym::update() {
    for (auto& eq : equipments_) {
        eq->update();
    }
}

std::vector<int> Gym::searchEquipmentByType(const std::string& type) const {
    std::vector<int> result;
    for (int i = 0; i < static_cast<int>(equipments_.size()); ++i) {
        if (equipments_[i]->getType() == type)
            result.push_back(i);
    }
    return result;
}

void Gym::printStatus(std::ostream& os) const {
    os << "\nGym: " << name_ << "\n\nEquipments:\n";
    for (int i = 0; i < static_cast<int>(equipments_.size()); ++i) {
        os << " [" << i << "] " << *equipments_[i] << "\n";
    }
    os << "\nMembers:\n";
    for (auto const& m : members_) {
        m->info();  // prints to cout
    }
}

Equipment* Gym::getEquipment(int idx) const {
    if (idx < 0 || idx >= static_cast<int>(equipments_.size()))
        throw IndexException("equipment", idx);
    return equipments_[idx].get();
}

int Gym::getEquipmentCount() const noexcept {
    return static_cast<int>(equipments_.size());
}
