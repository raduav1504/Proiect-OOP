#include <iostream>
#include "Gym.h"
#include "Treadmill.h"
#include "Elliptical.h"
#include "StationaryBike.h"
#include "YogaClass.h"
#include "SpinningClass.h"
#include "PilatesClass.h"
#include "RegularMember.h"
#include "PremiumMember.h"
#include "GuestMember.h"
#include "Scheduler.h"
#include "Exception.h"

int main() {
    try {
        Gym gym("FMI-Fitness");

        // ── facilitati
        gym.addFacility(std::make_unique<Treadmill>());
        gym.addFacility(std::make_unique<Elliptical>());
        gym.addFacility(std::make_unique<StationaryBike>());

        gym.addFacility(std::make_unique<YogaClass>(60));
        gym.addFacility(std::make_unique<SpinningClass>(45));
        gym.addFacility(std::make_unique<PilatesClass>(50));

        // ── membri 
        gym.addMember(std::make_unique<RegularMember>("Alice",101));
        gym.addMember(std::make_unique<PremiumMember>("Bob",102));
        gym.addMember(std::make_unique<GuestMember>("Carol",103));

        gym.printStatus(std::cout);

        // ── demonstram apel virtual si dynamic_cast
        if (auto* eq = dynamic_cast<Equipment*>(gym.getFacility(0)))
            eq->startUsage(5,"Alice");

        if (auto* cls = dynamic_cast<FitnessClass*>(gym.getFacility(3)))
            cls->attend("Bob");

        std::cout << "\n-- ticking 3 rounds --\n";
        for (int i = 0; i < 3; ++i)
            gym.updateAll();

        // ── Scheduler demo 
        Scheduler sched(std::make_unique<SpinningClass>(30));
        sched.schedule("Carol");
        sched.tick();

        // ── statice 
        std::cout << "\nTotal equipments: " << Equipment::getTotalCount() << "\n";
        std::cout << "Total members:   " << Member::getTotalCount()   << "\n";

        // ── raport 
        gym.reportFacilities();
    }
    catch (const FitnessException& ex) {
        std::cerr << "FitnessException: " << ex.what() << "\n";
        return 1;
    }
    catch (const std::exception& ex) {
        std::cerr << "std::exception: " << ex.what() << "\n";
        return 2;
    }
    return 0;
}
