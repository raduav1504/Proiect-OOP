#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

// baza proprie derivată din std::runtime_error
class AppException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class EquipmentException : public AppException {
public:
    explicit EquipmentException(const std::string& msg)
      : AppException("Equipment error: " + msg) {}
};

class MemberException : public AppException {
public:
    explicit MemberException(const std::string& msg)
      : AppException("Member error: " + msg) {}
};

class UsageException : public AppException {
public:
    explicit UsageException(const std::string& msg)
      : AppException("Usage error: " + msg) {}
};

#endif // EXCEPTIONS_HPP
