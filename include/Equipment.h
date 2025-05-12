#pragma once
#include "FacilityElement.h"
#include <memory>

class Equipment : public FacilityElement {
public:
    Equipment(std::string type);
    ~Equipment() override;

    Equipment(const Equipment& other);
    Equipment& operator=(Equipment other);
    friend void swap(Equipment& a, Equipment& b) noexcept;

    // Thematic pure-virtual
    virtual void update() = 0;
    virtual void startUsage(int duration, const std::string& user) = 0;
    std::unique_ptr<FacilityElement> clone() const override = 0;

    // Maintenance
    void scheduleMaintenance(int duration);
    void completeMaintenance();

    bool isUnderMaintenance() const noexcept;
    bool isInUse() const noexcept;
    int  getUsageCount() const noexcept;

    // Static tracking
    static int getTotalCount() noexcept;

protected:
    bool        inUse_;
    int         remaining_;
    std::string user_;
    int         usageCount_;
    bool        underMaintenance_;
    int         maintenanceRemaining_;

private:
    static int totalCount_;
};
