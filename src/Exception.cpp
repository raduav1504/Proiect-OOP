#include "Exception.h"

FitnessException::FitnessException(std::string msg) noexcept
  : msg_{std::move(msg)} {}

const char* FitnessException::what() const noexcept {
    return msg_.c_str();
}

EquipmentException::EquipmentException(const std::string& op, int idx) noexcept
  : FitnessException("Equipment error in " + op + ": " + std::to_string(idx))
{}

MemberException::MemberException(const std::string& op, int id) noexcept
  : FitnessException("Member error in " + op + ": " + std::to_string(id))
{}

ScheduleException::ScheduleException(const std::string& detail) noexcept
  : FitnessException("Schedule error: " + detail)
{}
