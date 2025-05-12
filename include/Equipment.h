#pragma once
#include <string>
#include <memory>

class Equipment {
public:
    Equipment(std::string type);
    virtual ~Equipment();

    // Copy & swap
    Equipment(const Equipment& other);
    Equipment& operator=(Equipment other);

    // Polimorfism
    virtual void update() = 0;
    virtual void startUsage(int duration, const std::string& user) = 0;
    virtual std::unique_ptr<Equipment> clone() const = 0;

    const std::string& getType() const noexcept;
    int getUsageCount() const noexcept;
    bool isUnderMaintenance() const noexcept;
    void scheduleMaintenance();
    void completeMaintenance();

    friend void swap(Equipment& a, Equipment& b) noexcept;
protected:
    std::string type_;
    bool inUse_;
    int remaining_;
    std::string user_;
    int usageCount_;
    bool underMaintenance_;
};
