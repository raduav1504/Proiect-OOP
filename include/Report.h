#pragma once
#include <vector>
#include <memory>
#include "FacilityElement.h"

class Report {
public:
    static void facilityReport(const std::vector<std::unique_ptr<FacilityElement>>& elems);
};
