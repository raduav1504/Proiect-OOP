// src/Exceptions.cpp

#include "Exceptions.hpp"

// definițiile out-of-line ale constructorilor

MemberException::MemberException(const std::string& msg)
  : std::runtime_error(msg)
{}

EquipmentException::EquipmentException(const std::string& msg)
  : std::runtime_error(msg)
{}

UsageException::UsageException(const std::string& msg)
  : std::runtime_error(msg)
{}
