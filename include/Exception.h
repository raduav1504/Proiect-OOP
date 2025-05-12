#pragma once
#include <exception>
#include <string>

class FitnessException : public std::exception {
public:
    explicit FitnessException(std::string msg) noexcept;
    const char* what() const noexcept override;
private:
    std::string msg_;
};

// 3 erori specifice independente de ierarhia FacilityElement
class EquipmentException : public FitnessException {
public:
    EquipmentException(const std::string& op, int idx) noexcept;
};
class MemberException : public FitnessException {
public:
    MemberException(const std::string& op, int id) noexcept;
};
class ScheduleException : public FitnessException {
public:
    ScheduleException(const std::string& detail) noexcept;
};
