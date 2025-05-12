#include <iostream>
#include "Gym.h"
#include "Equipment.h"
#include "Member.h"
#include "Exception.h"

int main() {
    try {
        Gym gym{"SuperGym"};

        // Adăugăm 2 echipamente
        gym.addEquipment(Treadmill{});
        gym.addEquipment(Bike{});

        // Adăugăm 2 membri
        gym.addMember(Regular{"Ana", 1});
        gym.addMember(Regular{"Bogdan", 2});

        int choice;
        do {
            std::cout << "\n1) Update all\n"
                      << "2) Start usage\n"
                      << "3) Print status\n"
                      << "0) Exit\n"
                      << "> ";
            std::cin >> choice;
            switch (choice) {
                case 1:
                    gym.updateAll();
                    break;
                case 2: {
                    size_t ei, mi;
                    int dur;
                    std::cout << "Eq idx, Mem idx, Dur: ";
                    std::cin >> ei >> mi >> dur;
                    gym.startUsage(ei, mi, dur);
                    break;
                }
                case 3:
                    gym.printStatus();
                    break;
                case 0:
                    break;
                default:
                    std::cout << "Invalid\n";
            }
        } while (choice != 0);

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}
