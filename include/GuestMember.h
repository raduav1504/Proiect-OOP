#pragma once
#include "Member.h"

class GuestMember : public Member {
public:
    GuestMember(const std::string& name, int id);
    std::unique_ptr<Member> clone() const override;
    void info() const override;
};
