#pragma once
#include <string>
#include <memory>
#include <ostream>

class Equipment {
public:
    Equipment(std::string type);
    virtual ~Equipment();

    Equipment(const Equipment& other);
    Equipment& operator=(Equipment other);

    // polymorphic interface
    virtual void update() = 0;
    virtual void startUsage(int duration, const std::string& user) = 0;
    virtual std::unique_ptr<Equipment> clone() const = 0;

    // maintenance
    void scheduleMaintenance(int duration);
    void completeMaintenance();

    // status queries
    const std::string& getType()        const noexcept;
    int                 getUsageCount() const noexcept;
    bool                isUnderMaintenance() const noexcept;
    bool                isInUse()      const noexcept;

    // static tracking
    static int getTotalEquipmentCount() noexcept;

    // swap for copy-and-swap
    friend void swap(Equipment& a, Equipment& b) noexcept;

    // pretty-print
    friend std::ostream& operator<<(std::ostream& os, const Equipment& eq);

protected:
    std::string type_;
    bool        inUse_;
    int         remaining_;
    std::string user_;
    int         usageCount_;
    bool        underMaintenance_;
    int         maintenanceRemaining_;

private:
    static int totalCount_;
};
