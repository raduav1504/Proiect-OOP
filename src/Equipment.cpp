#include "Equipment.h"
#include <iostream>

int Equipment::totalCount_ = 0;

Equipment::Equipment(std::string type)
  : FacilityElement(std::move(type))
  , inUse_{false}, remaining_{0}, user_{}, usageCount_{0}
  , underMaintenance_{false}, maintenanceRemaining_{0}
{
    ++totalCount_;
    std::cout << "Created equipment: " << name_ << "\n";
}

Equipment::~Equipment() {
    --totalCount_;
}

Equipment::Equipment(const Equipment& other)
  : FacilityElement(other)
  , inUse_{other.inUse_}, remaining_{other.remaining_}
  , user_{other.user_}, usageCount_{other.usageCount_}
  , underMaintenance_{other.underMaintenance_}
  , maintenanceRemaining_{other.maintenanceRemaining_}
{
    ++totalCount_;
}

Equipment& Equipment::operator=(Equipment other) {
    swap(*this, other);
    return *this;
}

void swap(Equipment& a, Equipment& b) noexcept {
    using std::swap;
    swap(static_cast<FacilityElement&>(a), static_cast<FacilityElement&>(b));
    swap(a.inUse_, a.inUse_ = b.inUse_);
    swap(a.remaining_, b.remaining_);
    swap(a.user_, b.user_);
    swap(a.usageCount_, b.usageCount_);
    swap(a.underMaintenance_, b.underMaintenance_);
    swap(a.maintenanceRemaining_, b.maintenanceRemaining_);
}

void Equipment::scheduleMaintenance(int duration) {
    if (inUse_) return;
    underMaintenance_ = true;
    maintenanceRemaining_ = duration;
    std::cout << name_ << " scheduled for maintenance (" << duration << ")\n";
}

void Equipment::completeMaintenance() {
    underMaintenance_ = false;
    maintenanceRemaining_ = 0;
    std::cout << name_ << " maintenance completed\n";
}

bool Equipment::isUnderMaintenance() const noexcept { return underMaintenance_; }
bool Equipment::isInUse()          const noexcept { return inUse_; }
int  Equipment::getUsageCount()    const noexcept { return usageCount_; }
int  Equipment::getTotalCount()    noexcept       { return totalCount_; }
