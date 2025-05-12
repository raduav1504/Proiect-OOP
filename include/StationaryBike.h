#pragma once
#include "Equipment.h"

class StationaryBike : public Equipment {
public:
    StationaryBike();
    void update() override;
    void startUsage(int duration, const std::string& user) override;
    std::unique_ptr<Equipment> clone() const override;
};
