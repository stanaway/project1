cmake_minimum_required(VERSION 4.3)
project(project1_clion)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
add_executable(project1_clion
        src/CancellationHistory.cpp
        src/main.cpp
        src/Reservation.cpp
        src/ReservationManager.cpp
        src/Resource.cpp
        src/ResourceManager.cpp
        src/WaitingList.cpp
)
