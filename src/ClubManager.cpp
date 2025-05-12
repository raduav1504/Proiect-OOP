// src/ClubManager.cpp

#include "ClubManager.hpp"
#include "Exceptions.hpp"
#include "Treadmill.hpp"
#include "Dumbbell.hpp"
#include "StationaryBike.hpp"

#include <algorithm>
#include <iostream>

void ClubManager::addEquipment(const Equipment& eq) {
    equipment_.push_back(eq.clone());
}

void ClubManager::addMember(const Member& m) {
    members_.push_back(m);
}

void ClubManager::startUsage(int memberId, int equipmentIndex, int durationSec) {
    // aruncam dacă durata e negativa
    if (durationSec < 0)
        throw UsageException("Duration must be non-negative");

    // cautam membrul
    auto mIt = std::find_if(
        members_.begin(), members_.end(),
        [&](auto& m){ return m.getId() == memberId; }
    );
    if (mIt == members_.end())
        throw MemberException("Member ID not found");

    // validam indexul de echipament
    if (equipmentIndex < 0 || equipmentIndex >= (int)equipment_.size())
        throw EquipmentException("Invalid equipment index");

    // demonstrație dynamic_cast pentru downcast
    auto& eqPtr = equipment_[equipmentIndex];
    if (auto* t = dynamic_cast<Treadmill*>(eqPtr.get())) {
        std::cout << "[DEBUG] It's a Treadmill\n";
    } else if (auto* d = dynamic_cast<Dumbbell*>(eqPtr.get())) {
        std::cout << "[DEBUG] It's a Dumbbell\n";
    } else if (auto* b = dynamic_cast<StationaryBike*>(eqPtr.get())) {
        std::cout << "[DEBUG] It's a StationaryBike\n";
    }

    // pornim utilizarea
    std::cout << mIt->getName() << " starts using ";
    equipment_[equipmentIndex]->show();
    std::cout << " for " << durationSec << " seconds\n";
}

void ClubManager::showAll() const {
    std::cout << "--- Members ---\n";
    for (const auto& m : members_)
        std::cout << m << "\n";

    std::cout << "\n--- Equipment ---\n";
    for (const auto& eq : equipment_)
        eq->show();
    std::cout << std::endl;
}
