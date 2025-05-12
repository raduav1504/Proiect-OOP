#include "Treadmill.h"
#include <iostream>

Treadmill::Treadmill()
  : Equipment("Treadmill")
{}

void Treadmill::update() {
    if (underMaintenance_) {
        if (--maintenanceRemaining_ == 0) {
            completeMaintenance();
        }
        return;
    }
    if (inUse_ && --remaining_ == 0) {
        inUse_ = false;
        user_.clear();
        std::cout << type_ << " now available\n";
    }
}

void Treadmill::startUsage(int duration, const std::string& user) {
    if (underMaintenance_) {
        std::cout << type_ << " is under maintenance\n";
        return;
    }
    if (inUse_) {
        std::cout << type_ << " already in use by " << user_ << "\n";
        return;
    }
    inUse_      = true;
    remaining_  = duration;
    user_       = user;
    ++usageCount_;
    std::cout << "Started " << type_
              << " for " << user << " (" << duration << ")\n";
}

std::unique_ptr<Equipment> Treadmill::clone() const {
    return std::make_unique<Treadmill>(*this);
}
