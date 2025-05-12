#pragma once
#include <memory>
#include "FitnessClass.h"

class Scheduler {
public:
    explicit Scheduler(std::unique_ptr<FitnessClass> cls);
    void schedule(const std::string& memberName);
    void tick();

private:
    std::unique_ptr<FitnessClass> currentClass_;
};
