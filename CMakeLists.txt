cmake_minimum_required(VERSION 3.27)
project(BankSystem
        VERSION 0.0.1
        DESCRIPTION "Simple command line Bank Management System"
        LANGUAGES CXX
        )
add_executable(run main.cpp
                ./source/library/src/ArrayListException.cpp
                ./source/library/src/HashMapException.cpp
                
                ./source/bankSystem/accounts/src/BankAccount.cpp
                ./source/bankSystem/accounts/src/SavingAccount.cpp
                ./source/bankSystem/accounts/src/CheckingAccount.cpp

                ./source/bankSystem/Exceptions/src/InsufficientBalanceException.cpp
                ./source/bankSystem/Exceptions/src/AccountNotFoundException.cpp
                ./source/bankSystem/Exceptions/src/NegativeAmountException.cpp

                ./source/bankSystem/Transactions/src/WithdrawTransaction.cpp
                ./source/bankSystem/Transactions/src/DepositTransaction.cpp
                ./source/bankSystem/Transactions/src/TransferTransaction.cpp

                ./source/bankSystem/Users/src/Admin.cpp
                ./source/bankSystem/Users/src/User.cpp
                ./source/bankSystem/Users/src/Customer.cpp

                ./source/bankSystem/Services/src/BankService.cpp
                ./source/bankSystem/bs/src/BankSystem.cpp
                )

target_compile_features(run PRIVATE cxx_std_23)

target_include_directories(run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/BankSystem/include)
target_include_directories(run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/library/include)
target_include_directories(run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/bankSystem/accounts/include)
target_include_directories(run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/bankSystem/Exceptions/include)
target_include_directories(run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/bankSystem/Transactions/include)
target_include_directories(run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/bankSystem/Users/include)
target_include_directories(run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/bankSystem/Services/include)
target_include_directories(run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/bankSystem/bs/include)
