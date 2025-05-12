#pragma once
#include <exception>
#include <string>

class GymException : public std::exception {
public:
    explicit GymException(std::string msg) noexcept;
    const char* what() const noexcept override;
private:
    std::string message_;
};

class IndexException : public GymException {
public:
    IndexException(const std::string& who, int idx) noexcept;
};
