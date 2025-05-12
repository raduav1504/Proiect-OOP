#include "Elliptical.h"
#include <iostream>

Elliptical::Elliptical() : Equipment("Elliptical") {}

void Elliptical::describe() const {
    std::cout << "Elliptical trainer\n";
}

void Elliptical::update() {
    if (underMaintenance_) {
        if (--maintenanceRemaining_ == 0) completeMaintenance();
        return;
    }
    if (inUse_ && --remaining_ == 0) {
        inUse_ = false; user_.clear();
        std::cout << name_ << " now available\n";
    }
}

void Elliptical::startUsage(int duration, const std::string& user) {
    if (underMaintenance_ || inUse_) return;
    inUse_ = true; remaining_ = duration; user_ = user; ++usageCount_;
    std::cout << user << " started " << name_ << "\n";
}

std::unique_ptr<FacilityElement> Elliptical::clone() const {
    return std::make_unique<Elliptical>(*this);
}
