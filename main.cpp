// src/main.cpp

#include <iostream>
#include "ClubManager.hpp"
#include "Treadmill.hpp"
#include "Dumbbell.hpp"
#include "StationaryBike.hpp"
#include "YogaMat.hpp"
#include "Member.hpp"
#include "Exceptions.hpp"

int main() {
    try {
        ClubManager cm;

        // adăugăm echipamente
        cm.addEquipment(Treadmill{10.0, 2});
        cm.addEquipment(Dumbbell{15.0});
        cm.addEquipment(StationaryBike{5});
        cm.addEquipment(YogaMat{6.0});  // noua clasă derivată, fără să modificăm alt cod

        // adăugăm membri
        cm.addMember(Member{"Alice"});
        cm.addMember(Member{"Bob"});

        // afișăm starea curentă
        cm.showAll();

        // pornim câteva sesiuni de utilizare
        cm.startUsage(1, 0,  2);  // Alice folosește Treadmill 2s
        cm.startUsage(2, 1,  3);  // Bob folosește Dumbbell 3s
        // cm.startUsage(1, 2, -5); // aruncă UsageException

    } catch (const MemberException&   e) {
        std::cerr << "Member error:    " << e.what() << "\n";
    } catch (const EquipmentException& e) {
        std::cerr << "Equipment error: " << e.what() << "\n";
    } catch (const UsageException&     e) {
        std::cerr << "Usage error:     " << e.what() << "\n";
    } catch (const std::exception&     e) {
        std::cerr << "Unexpected:      " << e.what() << "\n";
    }

    return 0;
}
