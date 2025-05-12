#pragma once
#include <string>
#include <memory>
#include <ostream>

class Member {
public:
    Member(std::string name, int id);
    virtual ~Member();

    Member(const Member& other);
    Member& operator=(Member other);
    friend void swap(Member& a, Member& b) noexcept;

    virtual std::unique_ptr<Member> clone() const = 0;
    virtual void info() const = 0;

    int                 getID()   const noexcept;
    const std::string&  getName() const noexcept;
    static int          getTotalCount() noexcept;

private:
    std::string name_;
    int         id_;
    static int  totalCount_;
};

std::ostream& operator<<(std::ostream& os, const Member& m);
