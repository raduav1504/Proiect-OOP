#pragma once
#include "Member.h"

class PremiumMember : public Member {
public:
    PremiumMember(const std::string& name, int id);
    std::unique_ptr<Member> clone() const override;
    void info() const override;
};
