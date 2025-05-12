#ifndef STATIONARYBIKE_HPP
#define STATIONARYBIKE_HPP

#include "Equipment.hpp"

class StationaryBike : public Equipment {
public:
    explicit StationaryBike(int resistance);

    std::unique_ptr<Equipment> clone() const override;

protected:
    void printDetails(std::ostream& os) const override;

private:
    int resistance_;
};

#endif // STATIONARYBIKE_HPP
