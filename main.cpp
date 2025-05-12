#include <iostream>
#include "Gym.h"
#include "Treadmill.h"
#include "Elliptical.h"
#include "StationaryBike.h"
#include "RegularMember.h"
#include "Exception.h"

int main() {
    try {
        Gym gym("FMI-Fitness");

        // add equipment
        gym.addEquipment(std::make_unique<Treadmill>());
        gym.addEquipment(std::make_unique<Elliptical>());
        gym.addEquipment(std::make_unique<StationaryBike>());

        // add members
        gym.addMember(std::make_unique<RegularMember>("Alice", 101));
        gym.addMember(std::make_unique<RegularMember>("Bob",   102));

        gym.printStatus(std::cout);

        // start usage & maintenance
        gym.startEquipmentUsage(0, 5, 0); // Alice uses treadmill 5 ticks
        gym.scheduleMaintenance(2, 3);    // Bike into maintenance for 3 ticks

        std::cout << "\n--- Running 6 updates ---\n";
        for (int i = 0; i < 6; ++i) {
            gym.update();
            gym.printStatus(std::cout);
        }

        // search
        auto ellips = gym.searchEquipmentByType("Elliptical");
        std::cout << "\nAll Elliptical indexes:";
        for (int idx : ellips) std::cout << " " << idx;
        std::cout << "\n";

        // dynamic_cast demo
        std::cout << "\n-- Dynamic cast demo --\n";
        for (int i = 0; i < gym.getEquipmentCount(); ++i) {
            Equipment* eq = gym.getEquipment(i);
            if (auto* tm = dynamic_cast<Treadmill*>(eq)) {
                std::cout << "Equipment " << i << " is a treadmill\n";
            }
        }

        // static counts
        std::cout << "\nTotal equipment ever created: "
                  << Equipment::getTotalEquipmentCount() << "\n";
        std::cout << "Current members: "
                  << Member::getTotalMembers() << "\n";

        // remove some entries
        gym.removeMember(1);
        gym.removeEquipment(1);

        std::cout << "\nAfter removing some entries:\n";
        gym.printStatus(std::cout);
    }
    catch (const IndexException& ex) {
        std::cerr << "Index error: " << ex.what() << "\n";
        return 1;
    }
    catch (const GymException& ex) {
        std::cerr << "Gym error: " << ex.what() << "\n";
        return 2;
    }
    catch (const std::exception& ex) {
        std::cerr << "Unexpected error: " << ex.what() << "\n";
        return 3;
    }
    return 0;
}
