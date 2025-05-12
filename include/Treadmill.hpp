#ifndef TREADMILL_HPP
#define TREADMILL_HPP

#include "Equipment.hpp"

class Treadmill : public Equipment {
public:
    explicit Treadmill(double maxSpeed);

    std::unique_ptr<Equipment> clone() const override;

protected:
    void printDetails(std::ostream& os) const override;

private:
    double maxSpeed_;
};

#endif // TREADMILL_HPP
