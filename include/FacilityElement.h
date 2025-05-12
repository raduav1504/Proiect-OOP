#pragma once
#include <string>
#include <memory>
#include <ostream>

class FacilityElement {
public:
    FacilityElement(std::string name);
    ~FacilityElement() override = default;
    FacilityElement(const FacilityElement& other);
    FacilityElement& operator=(FacilityElement other);
    friend void swap(FacilityElement& a, FacilityElement& b) noexcept;

    // non-virtual
    void print(std::ostream& os) const;

    // virtual
    virtual void describe() const = 0;
    virtual std::unique_ptr<FacilityElement> clone() const = 0;

    const std::string& getName() const noexcept;

protected:
    std::string name_;
};

std::ostream& operator<<(std::ostream& os, const FacilityElement& elem);
