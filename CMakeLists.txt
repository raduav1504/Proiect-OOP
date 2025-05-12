cmake_minimum_required(VERSION 3.10)
project(Gym)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# equipment lib (includes subclasses)
add_library(Equipment
    src/Equipment.cpp
    src/Treadmill.cpp
    src/Elliptical.cpp
    src/StationaryBike.cpp
)
target_include_directories(Equipment PUBLIC include)

# member lib (and subclass)
add_library(MemberLib
    src/Member.cpp
    src/RegularMember.cpp
)
target_include_directories(MemberLib PUBLIC include)

# exceptions
add_library(ExceptionLib
    src/Exception.cpp
)
target_include_directories(ExceptionLib PUBLIC include)

# gym core
add_library(GymLib
    src/Gym.cpp
)
target_include_directories(GymLib PUBLIC include)

# maintenance requests
add_library(MaintenanceLib
    src/Maintenance.cpp
)
target_include_directories(MaintenanceLib PUBLIC include)

# final executable
add_executable(main_exec main.cpp)
target_link_libraries(main_exec
    Equipment
    MemberLib
    ExceptionLib
    GymLib
    MaintenanceLib
)
