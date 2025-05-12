#ifndef DUMBBELL_HPP
#define DUMBBELL_HPP

#include "Equipment.hpp"

class Dumbbell : public Equipment {
public:
    explicit Dumbbell(int weightKg);

    std::unique_ptr<Equipment> clone() const override;

protected:
    void printDetails(std::ostream& os) const override;

private:
    int weightKg_;
};

#endif // DUMBBELL_HPP
