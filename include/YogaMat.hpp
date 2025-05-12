#ifndef YOGAMAT_HPP
#define YOGAMAT_HPP

#include "Equipment.hpp"

class YogaMat : public Equipment {
public:
    explicit YogaMat(double thicknessMM);

    std::unique_ptr<Equipment> clone() const override;

protected:
    void printDetails(std::ostream& os) const override;

private:
    double thicknessMM_;
};

#endif // YOGAMAT_HPP
