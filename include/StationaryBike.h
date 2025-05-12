#pragma once
#include "Equipment.h"

class StationaryBike : public Equipment {
public:
    StationaryBike();
    void describe()   const override;
    void update()          override;
    void startUsage(int duration, const std::string& user) override;
    std::unique_ptr<FacilityElement> clone() const override;
};
