#pragma once
#include <string>
#include <vector>
#include <memory>
#include <ostream>
#include "FacilityElement.h"
#include "Member.h"

class Gym {
public:
    explicit Gym(std::string name);
    Gym(const Gym& other);
    Gym& operator=(Gym other);
    ~Gym();

    // facilitati si membri
    void addFacility(std::unique_ptr<FacilityElement> elem);
    void removeFacility(int idx);
    void addMember(std::unique_ptr<Member> m);
    void removeMember(int idx);

    // afisare si actualizare
    void printStatus(std::ostream& os) const;
    void updateAll();
    void reportFacilities() const;

    int getFacilityCount() const noexcept;
    FacilityElement* getFacility(int idx) const;

    friend void swap(Gym& a, Gym& b) noexcept;

private:
    std::string name_;
    std::vector<std::unique_ptr<FacilityElement>> facilities_;
    std::vector<std::unique_ptr<Member>>          members_;
};
