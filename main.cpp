// main.cpp
#include <iostream>
#include "Gym.h"
#include "Equipment.h"
#include "Member.h"
#include "exceptions.h"

int main() {
    try {
        Gym gym("FMI-Fitness");

        // add some kit
        gym.addEquipment(std::make_unique<Equipment>("Treadmill"));
        gym.addEquipment(std::make_unique<Equipment>("Elliptical"));
        gym.addEquipment(std::make_unique<Equipment>("Stationary Bike"));

        // add members
        gym.addMember(Member("Alice", 101));
        gym.addMember(Member("Bob",   102));

        gym.printStatus(std::cout);

        // start usage
        gym.startEquipmentUsage(0, 5, 0);  // Alice on Treadmill 5 ticks
        gym.scheduleMaintenance(2, 3);     // Bike into maintenance for 3 ticks

        std::cout << "\n--- Running 6 updates ---\n";
        for (int i = 0; i < 6; ++i) {
            gym.update();
            gym.printStatus(std::cout);
        }

        // search for all “Elliptical”
        auto ellips = gym.searchEquipmentByType("Elliptical");
        std::cout << "\nAll Elliptical indexes:";
        for (int idx : ellips) std::cout << " " << idx;
        std::cout << "\n";

        // remove Bob
        gym.removeMember(1);
        gym.removeEquipment(1);

        std::cout << "\nAfter removing some entries:\n";
        gym.printStatus(std::cout);

    } 
    catch (const IndexException& ex) {
        std::cerr << "Index error: " << ex.what() << "\n";
        return 1;
    }
    catch (const std::exception& ex) {
        std::cerr << "Unexpected error: " << ex.what() << "\n";
        return 2;
    }
    return 0;
}
