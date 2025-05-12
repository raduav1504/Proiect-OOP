#include "Report.h"
#include <iostream>
#include <map>

void Report::facilityReport(const std::vector<std::unique_ptr<FacilityElement>>& elems) {
    std::map<std::string,int> cnt;
    for (auto const& e : elems) cnt[e->getName()]++;
    std::cout << "\n-- Facility Report --\n";
    for (auto const& [name, c] : cnt) {
        std::cout << name << " : " << c << "\n";
    }
}
