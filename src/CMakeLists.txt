cmake_minimum_required (VERSION 3.8)

file(GLOB_RECURSE DIR_SRC
    ${CMAKE_CURRENT_LIST_DIR}/*.h
    ${CMAKE_CURRENT_LIST_DIR}/*.cpp
    ${CMAKE_CURRENT_LIST_DIR}/**/*.cpp
    ${CMAKE_CURRENT_LIST_DIR}/**/*.h
    ${CMAKE_CURRENT_LIST_DIR}/**/*.hpp
    ${CMAKE_CURRENT_LIST_DIR}/**/*.cpp)

message(${CMAKE_CURRENT_LIST_DIR})
if (MSVC)
#	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup") 
endif (MSVC)

add_executable(iquantrader
	${DIR_SRC})

target_compile_definitions(iquantrader PUBLIC _NO_ASYNCRTIMP)
target_link_libraries(iquantrader cpprest_2_10$<$<CONFIG:Debug>:d> libcrypto crypt32 libssl zlibstatic$<$<CONFIG:Debug>:d>)
	
install(TARGETS iquantrader RUNTIME DESTINATION iquantrader)
