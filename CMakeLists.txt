cmake_minimum_required(VERSION 3.7)

project(ForeverInstaller)

# 2006 DC = 0, 2007 Windows = 1, 2007 OSX = 2
set(RETRO_REVISION 2 CACHE STRING "What revision to compile for. Defaults to 2007 OSX = 2")
option(RETRO_FORCE_CASE_INSENSITIVE "Forces case insensivity." OFF)
option(RETRO_MOD_LOADER "Enables or disables the mod loader." ON)
option(RETRO_ORIGINAL_CODE "Removes any change that differs from the original code, a playable game can't be built this way." OFF)

set(RETRO_SDL_VERSION 2 CACHE STRING "Select between SDL2 and SDL1, defaults to SDL2")

if(RETRO_ORIGINAL_CODE)
#	set(RETRO_SDL_VERSION 1)
	set(RETRO_MOD_LOADER OFF)
endif()

set(RETRO_NAME "teamforever-installer")

set(RETRO_OUTPUT_NAME ${RETRO_NAME} CACHE STRING "The exported name of the executable.")

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

target_include_directories(ForeverInstaller PRIVATE
	source/
)

target_compile_definitions(ForeverInstaller PRIVATE
	RSDK_REVISION=${RETRO_REVISION}
	FORCE_CASE_INSENSITIVE=$<BOOL:${RETRO_FORCE_CASE_INSENSITIVE}>
	RETRO_USE_MOD_LOADER=$<BOOL:${RETRO_MOD_LOADER}>
	RETRO_USE_ORIGINAL_CODE=$<BOOL:${RETRO_ORIGINAL_CODE}>
	RETRO_USE_SDL${RETRO_SDL_VERSION}=1
)