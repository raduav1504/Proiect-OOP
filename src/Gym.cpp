#include "Gym.h"
#include "Exception.h"
#include "Report.h"
#include <iostream>

Gym::Gym(std::string name)
  : name_{std::move(name)} {}

Gym::Gym(const Gym& other)
  : name_{other.name_}
{
    for (auto const& e : other.facilities_)
        facilities_.push_back(e->clone());
    for (auto const& m : other.members_)
        members_.push_back(m->clone());
}

Gym& Gym::operator=(Gym other) {
    swap(*this, other);
    return *this;
}

Gym::~Gym() = default;

void swap(Gym& a, Gym& b) noexcept {
    using std::swap;
    swap(a.name_,       b.name_);
    swap(a.facilities_, b.facilities_);
    swap(a.members_,    b.members_);
}

void Gym::addFacility(std::unique_ptr<FacilityElement> elem) {
    if (!elem) throw EquipmentException("addFacility",-1);
    facilities_.push_back(std::move(elem));
}

void Gym::removeFacility(int idx) {
    if (idx<0 || idx>=static_cast<int>(facilities_.size()))
        throw EquipmentException("removeFacility",idx);
    facilities_.erase(facilities_.begin()+idx);
}

void Gym::addMember(std::unique_ptr<Member> m) {
    if (!m) throw MemberException("addMember",-1);
    members_.push_back(std::move(m));
}

void Gym::removeMember(int idx) {
    if (idx<0 || idx>=static_cast<int>(members_.size()))
        throw MemberException("removeMember",idx);
    members_.erase(members_.begin()+idx);
}

void Gym::printStatus(std::ostream& os) const {
    os << "\n=== " << name_ << " ===\nFacilities:\n";
    for (int i = 0; i < static_cast<int>(facilities_.size()); ++i)
        os << " [" << i << "] " << *facilities_[i] << "\n";
    os << "Members:\n";
    for (auto const& m : members_)
        m->info();
}

void Gym::updateAll() {
    for (auto& f : facilities_) {
        // call thematic methods via base-pointer
        if (auto* eq = dynamic_cast<Equipment*>(f.get()))
            eq->update();
        else if (auto* cls = dynamic_cast<FitnessClass*>(f.get()))
            cls->update();
    }
}

void Gym::reportFacilities() const {
    Report::facilityReport(facilities_);
}

int Gym::getFacilityCount() const noexcept {
    return static_cast<int>(facilities_.size());
}

FacilityElement* Gym::getFacility(int idx) const {
    if (idx<0 || idx>=static_cast<int>(facilities_.size()))
        throw EquipmentException("getFacility",idx);
    return facilities_[idx].get();
}
