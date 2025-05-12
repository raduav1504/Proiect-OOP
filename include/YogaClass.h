#pragma once
#include "FitnessClass.h"

class YogaClass : public FitnessClass {
public:
    explicit YogaClass(int duration);
    void describe()   const override;
    void attend(const std::string& memberName) override;
    void update()                 override;
    std::unique_ptr<FacilityElement> clone() const override;
};
