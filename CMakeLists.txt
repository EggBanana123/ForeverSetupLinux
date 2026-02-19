cmake_minimum_required(VERSION 3.7)

project(ForeverInstaller)

# Sonic 1 Forever = 0, Sonic 2 Absolute = 1, Sonic CD Timeless = 2
set(RETRO_GAMETYPE 2 CACHE STRING "What game to compile for. Defaults to Sonic CD Timeless = 2")

set(RETRO_NAME "teamforever-installer")

set(RETRO_FILES
	source/main.cpp
)

#if(NOT PLATFORM)
#	if(WIN32) # THIS ASSUMES VCPKG OR SOURCES !!!!!!!
#		set(PLATFORM "Windows" CACHE STRING "The platform to compile for.")
#	elseif(ANDROID)
#		set(PLATFORM "Android" CACHE STRING "The platform to compile for.")
#	else()
#		set(PLATFORM ${CMAKE_SYSTEM_NAME} CACHE STRING "The platform to compile for.")
#	endif()
#endif()
#
#include(platforms/${PLATFORM}.cmake)

add_executable(ForeverInstaller ${RETRO_FILES})

set_target_properties(ForeverInstaller PROPERTIES OUTPUT_NAME ${RETRO_NAME})

# cURL my beloved
find_package(CURL REQUIRED)
target_link_libraries(ForeverInstaller PRIVATE CURL::libcurl)
# libZip my uhhh idk
#find_package(libzip REQUIRED)
#target_link_libraries(ForeverInstaller PRIVATE libzip::libzip)

target_include_directories(ForeverInstaller PRIVATE
	source/
)

target_compile_definitions(ForeverInstaller PRIVATE
	RETRO_GAME=${RETRO_GAMETYPE}
)