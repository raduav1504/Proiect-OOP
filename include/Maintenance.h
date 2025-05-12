#pragma once
#include <string>

class MaintenanceRequest {
public:
    MaintenanceRequest(std::string equipmentType, int equipmentId, std::string date);
    const std::string& getEquipmentType() const noexcept;
    int getEquipmentId() const noexcept;
    const std::string& getDate() const noexcept;
private:
    std::string equipmentType_;
    int equipmentId_;
    std::string date_;  // Simplu, YYYY-MM-DD
};
