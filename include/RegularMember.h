#pragma once
#include "Member.h"

class RegularMember : public Member {
public:
    RegularMember(const std::string& name, int id);
    std::unique_ptr<Member> clone() const override;
    void info() const override;
};
