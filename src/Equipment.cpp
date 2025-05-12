#include "Equipment.h"
#include <iostream>
#include <utility>

Equipment::Equipment(std::string type)
  : type_{std::move(type)}, inUse_{false}, remaining_{0}, user_{},
    usageCount_{0}, underMaintenance_{false} {
    std::cout << "Created equipment: " << type_ << "\n";
}

Equipment::~Equipment() = default;

Equipment::Equipment(const Equipment& other)
  : type_{other.type_}, inUse_{other.inUse_}, remaining_{other.remaining_},
    user_{other.user_}, usageCount_{other.usageCount_},
    underMaintenance_{other.underMaintenance_} {}

Equipment& Equipment::operator=(Equipment other) {
    swap(*this, other);
    return *this;
}

void swap(Equipment& a, Equipment& b) noexcept {
    using std::swap;
    swap(a.type_, b.type_);
    swap(a.inUse_, b.inUse_);
    swap(a.remaining_, b.remaining_);
    swap(a.user_, b.user_);
    swap(a.usageCount_, b.usageCount_);
    swap(a.underMaintenance_, b.underMaintenance_);
}

const std::string& Equipment::getType() const noexcept { return type_; }
int Equipment::getUsageCount() const noexcept { return usageCount_; }
bool Equipment::isUnderMaintenance() const noexcept { return underMaintenance_; }

void Equipment::scheduleMaintenance() {
    underMaintenance_ = true;
    std::cout << type_ << " scheduled for maintenance" << "\n";
}

void Equipment::completeMaintenance() {
    underMaintenance_ = false;
    std::cout << type_ << " maintenance completed" << "\n";
}

// Exemplu subclasă: Treadmill
class Treadmill : public Equipment {
public:
    Treadmill() : Equipment("Treadmill") {}
    void update() override {
        if (underMaintenance_) return;
        if (inUse_ && --remaining_ == 0) {
            inUse_ = false;
            user_.clear();
            std::cout << type_ << " now available\n";
        }
    }
    void startUsage(int duration, const std::string& user) override {
        if (underMaintenance_) {
            std::cout << type_ << " is under maintenance\n";
            return;
        }
        if (inUse_) {
            std::cout << type_ << " already in use by " << user_ << "\n";
            return;
        }
        inUse_ = true; remaining_ = duration; user_ = user;
        ++usageCount_;
        std::cout << "Started " << type_
                  << " for " << user << " ("<< duration <<")\n";
    }
    std::unique_ptr<Equipment> clone() const override {
        return std::make_unique<Treadmill>(*this);
    }
};
