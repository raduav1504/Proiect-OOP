#pragma once
#include "FitnessClass.h"

class SpinningClass : public FitnessClass {
public:
    SpinningClass(int duration);
    void describe()   const override;
    void attend(const std::string& memberName) override;
    void update()                 override;
    std::unique_ptr<FacilityElement> clone() const override;
};
