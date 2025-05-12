#include "StationaryBike.h"
#include <iostream>

StationaryBike::StationaryBike() : Equipment("Stationary Bike") {}

void StationaryBike::describe() const {
    std::cout << "Stationary bike\n";
}

void StationaryBike::update() {
    if (underMaintenance_) {
        if (--maintenanceRemaining_ == 0) completeMaintenance();
        return;
    }
    if (inUse_ && --remaining_ == 0) {
        inUse_ = false; user_.clear();
        std::cout << name_ << " now available\n";
    }
}

void StationaryBike::startUsage(int duration, const std::string& user) {
    if (underMaintenance_ || inUse_) return;
    inUse_ = true; remaining_ = duration; user_ = user; ++usageCount_;
    std::cout << user << " started " << name_ << "\n";
}

std::unique_ptr<FacilityElement> StationaryBike::clone() const {
    return std::make_unique<StationaryBike>(*this);
}
