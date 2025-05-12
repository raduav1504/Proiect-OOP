#include "Equipment.h"
#include <iostream>
#include <utility>

int Equipment::totalCount_ = 0;

Equipment::Equipment(std::string type)
  : type_{std::move(type)}
  , inUse_{false}
  , remaining_{0}
  , user_{}
  , usageCount_{0}
  , underMaintenance_{false}
  , maintenanceRemaining_{0}
{
    ++totalCount_;
    std::cout << "Created equipment: " << type_ << "\n";
}

Equipment::~Equipment() {
    --totalCount_;
}

Equipment::Equipment(const Equipment& other)
  : type_{other.type_}
  , inUse_{other.inUse_}
  , remaining_{other.remaining_}
  , user_{other.user_}
  , usageCount_{other.usageCount_}
  , underMaintenance_{other.underMaintenance_}
  , maintenanceRemaining_{other.maintenanceRemaining_}
{
    ++totalCount_;
}

Equipment& Equipment::operator=(Equipment other) {
    swap(*this, other);
    return *this;
}

void Equipment::scheduleMaintenance(int duration) {
    if (inUse_) {
        std::cout << type_ << " is currently in use, cannot schedule maintenance\n";
        return;
    }
    underMaintenance_    = true;
    maintenanceRemaining_ = duration;
    std::cout << type_ << " scheduled for maintenance (" << duration << ")\n";
}

void Equipment::completeMaintenance() {
    underMaintenance_    = false;
    maintenanceRemaining_ = 0;
    std::cout << type_ << " maintenance completed\n";
}

const std::string& Equipment::getType() const noexcept        { return type_; }
int                 Equipment::getUsageCount() const noexcept { return usageCount_; }
bool                Equipment::isUnderMaintenance() const noexcept { return underMaintenance_; }
bool                Equipment::isInUse() const noexcept      { return inUse_; }

int Equipment::getTotalEquipmentCount() noexcept { return totalCount_; }

void swap(Equipment& a, Equipment& b) noexcept {
    using std::swap;
    swap(a.type_,               b.type_);
    swap(a.inUse_,              b.inUse_);
    swap(a.remaining_,          b.remaining_);
    swap(a.user_,               b.user_);
    swap(a.usageCount_,         b.usageCount_);
    swap(a.underMaintenance_,   b.underMaintenance_);
    swap(a.maintenanceRemaining_, b.maintenanceRemaining_);
}

std::ostream& operator<<(std::ostream& os, const Equipment& eq) {
    os << eq.getType() << " [";
    if (eq.isUnderMaintenance()) {
        os << "maintenance (" << eq.maintenanceRemaining_ << ")";
    }
    else if (eq.isInUse()) {
        os << "in use by " << eq.user_ << " (" << eq.remaining_ << ")";
    }
    else {
        os << "available";
    }
    os << ", used " << eq.getUsageCount() << " times]";
    return os;
}
