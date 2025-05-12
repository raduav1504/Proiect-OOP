#include "Scheduler.h"
#include "SpinningClass.h"
#include <iostream>

Scheduler::Scheduler(std::unique_ptr<FitnessClass> cls)
  : currentClass_{std::move(cls)} {}

void Scheduler::schedule(const std::string& memberName) {
    if (!currentClass_) return;
    currentClass_->attend(memberName);
}

void Scheduler::tick() {
    if (!currentClass_) return;
    currentClass_->describe();
    currentClass_->update();
    // demo dynamic_cast
    if (auto* spin = dynamic_cast<SpinningClass*>(currentClass_.get())) {
        std::cout << "[Report] Spinning duration: "
                  << spin->getDuration() << " min\n";
    }
}
