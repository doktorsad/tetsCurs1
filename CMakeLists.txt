cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
project(C++)
add_executable(Source source/main.cpp)
add_library(Dyn_lib_race SHARED library/Race.h 
library/IRaceAir.h library/IRaceAir.cpp 
library/IRaceAirGround.h library/IRaceAirGround.cpp 
library/IRaceGround.h library/IRaceGround.cpp 
library/RaceInAir.h library/RaceInAir.cpp 
library/RaceOnGroundAndInAir.h library/RaceOnGroundAndInAir.cpp 
library/RaceOnGround.h library/RaceOnGround.cpp
library/TransportVehicle.h 
library/AllTerrainBoots.h library/AllTerrainBoots.cpp 
library/Broomstick.h library/Broomstick.cpp 
library/Camel.h library/Camel.cpp 
library/CamelIsFast.h library/CamelIsFast.cpp 
library/Centaur.h library/Centaur.cpp 
library/Eagle.h library/Eagle.cpp 
library/ITransportAir.h library/ITransportAir.cpp 
library/ITransportGround.h library/ITransportGround.cpp 
library/MagicCarpet.h library/MagicCarpet.cpp 
library/TransportVehicleInAir.h library/TransportVehicleInAir.cpp 
library/TransportVehicleGround.h library/TransportVehicleGround.cpp)
target_link_libraries(Source Dyn_lib_race)
