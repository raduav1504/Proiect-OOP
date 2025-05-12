#pragma once
#include "FacilityElement.h"
#include <vector>

class FitnessClass : public FacilityElement {
public:
    FitnessClass(std::string name, int duration);
    virtual ~FitnessClass();

    FitnessClass(const FitnessClass& other);
    FitnessClass& operator=(FitnessClass other);
    friend void swap(FitnessClass& a, FitnessClass& b) noexcept;

    // Thematic pure-virtual
    virtual void attend(const std::string& memberName) = 0;
    virtual void update() = 0;
    std::unique_ptr<FacilityElement> clone() const override = 0;

    int getDuration() const noexcept;

protected:
    int                     duration_;
    std::vector<std::string> attendees_;
};
