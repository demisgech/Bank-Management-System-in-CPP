cmake_minimum_required(VERSION 3.27)
project(BankSystem
        VERSION 0.0.1
        DESCRIPTION "Simple command line Bank Management System"
        LANGUAGES CXX
        )
add_executable(run main.cpp
                ./source/library/src/ArrayListException.cpp
                ./source/library/src/HashMapException.cpp
                )

target_compile_features(run PRIVATE cxx_std_23)

target_include_directories(run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/BankSystem/include)
target_include_directories(run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/library/include)
