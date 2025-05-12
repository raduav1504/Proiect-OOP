// Gym.h
#ifndef GYM_H
#define GYM_H

#include <string>
#include <vector>
#include <memory>
#include <ostream>
#include "Equipment.h"
#include "Member.h"

class Gym {
    std::string name_;
    std::vector<std::unique_ptr<Equipment>> equipments_;
    std::vector<Member>             members_;

public:
    explicit Gym(std::string name);
    Gym(const Gym& other);
    Gym& operator=(Gym other);
    ~Gym();

    // add / remove
    void addEquipment(std::unique_ptr<Equipment> eq);
    void removeEquipment(int eqIndex);

    void addMember(const Member& m);
    void removeMember(int memberIndex);

    // usage
    void startEquipmentUsage(int eqIndex, int duration, int memberIndex);

    // maintenance
    void scheduleMaintenance(int eqIndex, int duration);
    void completeMaintenance(int eqIndex);

    // tick the clock
    void update(); 

    // searches & status
    std::vector<int> searchEquipmentByType(const std::string& type) const;
    void printStatus(std::ostream& os) const;

    friend void swap(Gym& a, Gym& b);
};

#endif // GYM_H
