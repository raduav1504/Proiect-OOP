#include "Equipment.h"
#include <iostream>
#include <utility>

Equipment::Equipment(std::string type)
  : type_{std::move(type)}, inUse_{false}, remaining_{0}, user_{} {
    std::cout << "Created equipment: " << type_ << "\n";
}

Equipment::~Equipment() = default;

Equipment::Equipment(const Equipment& other)
  : type_{other.type_}
  , inUse_{other.inUse_}
  , remaining_{other.remaining_}
  , user_{other.user_}
{}

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
}

const std::string& Equipment::getType() const noexcept {
    return type_;
}

// Example concrete subclass
class Treadmill : public Equipment {
public:
    Treadmill() : Equipment("Treadmill") {}
    void update() override {
        if (inUse_ && --remaining_ == 0) {
            inUse_ = false;
            user_.clear();
            std::cout << type_ << " now available\n";
        }
    }
    void startUsage(int duration, const std::string& user) override {
        if (inUse_) {
            std::cout << type_ << " already in use by " << user_ << "\n";
            return;
        }
        inUse_ = true; remaining_ = duration; user_ = user;
        std::cout << "Started " << type_
                  << " for " << user << " ("<< duration << ")\n";
    }
    std::unique_ptr<Equipment> clone() const override {
        return std::make_unique<Treadmill>(*this);
    }
};

// Dacă vrei și alte tipuri, le adaugi aici, în același fișier:
class Bike : public Equipment {
public:
    Bike() : Equipment("Bike") {}
    void update() override {
        if (inUse_ && --remaining_ == 0) {
            inUse_ = false;
            user_.clear();
            std::cout << type_ << " now available\n";
        }
    }
    void startUsage(int duration, const std::string& user) override {
        if (inUse_) {
            std::cout << type_ << " already in use by " << user_ << "\n";
            return;
        }
        inUse_ = true; remaining_ = duration; user_ = user;
        std::cout << "Started " << type_
                  << " for " << user << " ("<< duration << ")\n";
    }
    std::unique_ptr<Equipment> clone() const override {
        return std::make_unique<Bike>(*this);
    }
}

