#include "Maintenance.h"

MaintenanceRequest::MaintenanceRequest(std::string equipmentType, int equipmentId, std::string date)
  : equipmentType_{std::move(equipmentType)}
  , equipmentId_{equipmentId}
  , date_{std::move(date)}
{}

const std::string& MaintenanceRequest::getEquipmentType() const noexcept { return equipmentType_; }
int                 MaintenanceRequest::getEquipmentId()   const noexcept { return equipmentId_; }
const std::string& MaintenanceRequest::getDate()           const noexcept { return date_; }

