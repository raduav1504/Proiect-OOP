#pragma once
#include "Equipment.h"

class Elliptical : public Equipment {
public:
    Elliptical();
    void update() override;
    void startUsage(int duration, const std::string& user) override;
    std::unique_ptr<Equipment> clone() const override;
};
