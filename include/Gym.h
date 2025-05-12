#pragma once
#include <vector>
#include <memory>
#include "Equipment.h"
#include "Member.h"
#include "Exception.h"

class Gym {
public:
    Gym(std::string name);
    ~Gym();

    Gym(const Gym& other);
    Gym& operator=(Gym other);

    void addEquipment(const Equipment& eq);
    void addMember(const Member& m);

    void updateAll();
    void startUsage(size_t eqIdx, size_t memIdx, int duration);

    void printStatus() const;

    static int totalGyms() noexcept;
private:
    std::string name_;
    std::vector<std::unique_ptr<Equipment>> equipments_;
    std::vector<std::unique_ptr<Member>> members_;

    static int gymCount_;
    friend void swap(Gym& a, Gym& b) noexcept;
};

