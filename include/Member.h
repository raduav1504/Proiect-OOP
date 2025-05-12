#pragma once
#include <string>
#include <memory>

class Member {
public:
    Member(std::string name, int id);
    virtual ~Member();

    Member(const Member& other);
    Member& operator=(Member other);

    virtual std::unique_ptr<Member> clone() const = 0;
    virtual void info() const = 0;

    int getID() const noexcept;
    const std::string& getName() const noexcept;

    friend void swap(Member& a, Member& b) noexcept;
protected:
    std::string name_;
    int id_;
};

