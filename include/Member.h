#ifndef MEMBER_HPP
#define MEMBER_HPP

#include <string>
#include <iostream>

class Member {
public:
    explicit Member(std::string name);

    Member(const Member& other);
    Member& operator=(Member other);

    friend void swap(Member& a, Member& b);

    int getId()   const;
    const std::string& getName() const;

    void print(std::ostream& os = std::cout) const;

private:
    static int nextId_;
    int id_;
    std::string name_;
};

#endif // MEMBER_HPP
