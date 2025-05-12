#pragma once
#include "Equipment.h"

class Treadmill : public Equipment {
public:
    Treadmill();
    void describe()   const override;
    void update()          override;
    void startUsage(int duration, const std::string& user) override;
    std::unique_ptr<FacilityElement> clone() const override;
};
