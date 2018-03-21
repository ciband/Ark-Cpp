
cmake_minimum_required(VERSION 3.2.2)

project(Ark-Cpp-lib)

hunter_add_package(nlohmann_json)
hunter_add_package(PocoCpp)

set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
 
include_directories(${PROJECT_SOURCE_DIR})
 
find_package(nlohmann_json CONFIG REQUIRED)
find_package(Poco REQUIRED Net CONFIG)

set(COMMON_SRC 
	${PROJECT_SOURCE_DIR}/api/accountable/account_gettable.cpp
	${PROJECT_SOURCE_DIR}/api/accountable/account_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/blockable/block_gettable.cpp
	${PROJECT_SOURCE_DIR}/api/blockable/block_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/delegatable/delegate_gettable.cpp
	${PROJECT_SOURCE_DIR}/api/delegatable/delegate_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/loadable/loader_gettable.cpp
	${PROJECT_SOURCE_DIR}/api/loadable/loader_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/multisignaturable/multisignature_gettable.cpp
	${PROJECT_SOURCE_DIR}/api/peerable/peer_gettable.cpp
	${PROJECT_SOURCE_DIR}/api/peerable/peer_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/signaturable/signature_gettable.cpp
	${PROJECT_SOURCE_DIR}/api/transactionable/transaction_gettable.cpp
	${PROJECT_SOURCE_DIR}/api/transactionable/transaction_respondable.cpp
	${PROJECT_SOURCE_DIR}/api/manager.cpp
	${PROJECT_SOURCE_DIR}/constants/networks.cpp
	${PROJECT_SOURCE_DIR}/models/account.cpp
	${PROJECT_SOURCE_DIR}/models/block.cpp
	${PROJECT_SOURCE_DIR}/models/currency.cpp
	${PROJECT_SOURCE_DIR}/models/delegate.cpp
	${PROJECT_SOURCE_DIR}/models/fees.cpp
	${PROJECT_SOURCE_DIR}/models/network.cpp
	${PROJECT_SOURCE_DIR}/models/peer.cpp
	${PROJECT_SOURCE_DIR}/models/transaction.cpp
	${PROJECT_SOURCE_DIR}/models/voter.cpp
	${PROJECT_SOURCE_DIR}/utilities/connector.cpp
)

set(PLATFORM_SRC 
	${PROJECT_SOURCE_DIR}/platform/json.cpp
	${PROJECT_SOURCE_DIR}/platform/http.cpp
)

add_library(Ark-Cpp-lib STATIC ${COMMON_SRC} ${PLATFORM_SRC})

target_link_libraries(Ark-Cpp-lib PUBLIC nlohmann_json)
target_link_libraries(Ark-Cpp-lib PUBLIC Poco::Net)

