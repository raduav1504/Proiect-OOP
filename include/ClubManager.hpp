#ifndef CLUBMANAGER_HPP
#define CLUBMANAGER_HPP

#include "Equipment.hpp"
#include "Member.hpp"
#include "Exceptions.hpp"

#include <vector>
#include <memory>

class ClubManager {
public:
    ClubManager() = default;
    ClubManager(const ClubManager& other);
    ClubManager& operator=(ClubManager other);

    void addEquipment(const Equipment& eq);
    void addMember   (const Member&   m);

    // funcție exemplar specifică teme:
    // folosește funcțiile virtuale prin Equipment*
    void startUsage(int memberId, int equipmentIndex, int durationSec);

    void showAll() const;

    friend void swap(ClubManager& a, ClubManager& b);

private:
    std::vector<std::unique_ptr<Equipment>> equipment_;
    std::vector<Member>                    members_;
};

#endif // CLUBMANAGER_HPP
