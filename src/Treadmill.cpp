#include "Treadmill.h"
#include <iostream>

Treadmill::Treadmill() : Equipment("Treadmill") {}

void Treadmill::describe() const {
    std::cout << "Treadmill for cardio\n";
}

void Treadmill::update() {
    if (underMaintenance_) {
        if (--maintenanceRemaining_ == 0) completeMaintenance();
        return;
    }
    if (inUse_ && --remaining_ == 0) {
        inUse_ = false; user_.clear();
        std::cout << name_ << " now available\n";
    }
}

void Treadmill::startUsage(int duration, const std::string& user) {
    if (underMaintenance_ || inUse_) return;
    inUse_ = true; remaining_ = duration; user_ = user; ++usageCount_;
    std::cout << user << " started " << name_ << "\n";
}

std::unique_ptr<FacilityElement> Treadmill::clone() const {
    return std::make_unique<Treadmill>(*this);
}
