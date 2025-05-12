#pragma once
#include <string>
#include <vector>
#include <memory>
#include <ostream>
#include "Equipment.h"
#include "Member.h"

class Gym {
public:
    explicit Gym(std::string name);
    Gym(const Gym& other);
    Gym& operator=(Gym other);
    ~Gym();

    // equipment
    void addEquipment(std::unique_ptr<Equipment> eq);
    void removeEquipment(int eqIndex);

    // members
    void addMember(std::unique_ptr<Member> m);
    void removeMember(int memberIndex);

    // usage & maintenance
    void startEquipmentUsage(int eqIndex, int duration, int memberIndex);
    void scheduleMaintenance(int eqIndex, int duration);
    void completeMaintenance(int eqIndex);

    // advance time
    void update();

    // queries
    std::vector<int> searchEquipmentByType(const std::string& type) const;
    void printStatus(std::ostream& os) const;

    // for dynamic_cast demo
    Equipment* getEquipment(int idx) const;
    int getEquipmentCount() const noexcept;

    friend void swap(Gym& a, Gym& b);

private:
    std::string name_;
    std::vector<std::unique_ptr<Equipment>> equipments_;
    std::vector<std::unique_ptr<Member>>    members_;
};
