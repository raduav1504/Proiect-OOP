#pragma once
#include "FitnessClass.h"

class PilatesClass : public FitnessClass {
public:
    PilatesClass(int duration);
    void describe()   const override;
    void attend(const std::string& memberName) override;
    void update()                 override;
    std::unique_ptr<FacilityElement> clone() const override;
};
