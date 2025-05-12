#pragma once
#include "Equipment.h"

class Treadmill : public Equipment {
public:
    Treadmill();
    void update() override;
    void startUsage(int duration, const std::string& user) override;
    std::unique_ptr<Equipment> clone() const override;
};
