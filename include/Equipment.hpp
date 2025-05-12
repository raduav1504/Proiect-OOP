#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP

#include <memory>
#include <iostream>
#include <string>

class Equipment {
public:
    Equipment(const Equipment&) = default;
    Equipment& operator=(const Equipment&) = default;
    virtual ~Equipment() = default;

    // Non-virtual interface
    void show(std::ostream& os = std::cout) const;

    // Clone pattern (constructor virtual)
    virtual std::unique_ptr<Equipment> clone() const = 0;

protected:
    Equipment(std::string name);

    // detaliile concrete sunt în această funcţie virtuală
    virtual void printDetails(std::ostream& os) const = 0;

    int         id_;
    std::string name_;

private:
    static int nextId_;
};

#endif // EQUIPMENT_HPP
