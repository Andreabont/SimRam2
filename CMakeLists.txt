cmake_minimum_required(VERSION 2.6)
project(simram)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") 

set(BOOST_LIBS program_options system)
find_package(Boost COMPONENTS ${BOOST_LIBS} REQUIRED)

add_executable(simram main.cpp RamInstruction.h RamInstruction.cpp)

target_link_libraries(simram ${Boost_LIBRARIES})

install(TARGETS simram RUNTIME DESTINATION bin)
