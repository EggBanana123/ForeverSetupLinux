#pragma once

#define GAME_SONIC1FOREVER   (0)
#define GAME_SONIC2ABSOLUTE  (1)
#define GAME_SONICCDTIMELESS (2)

#ifndef RETRO_GAME
#define RETRO_GAME (GAME_SONIC1FOREVER)
#endif

#include <iostream>		// ios tream 🤮
#include <fstream>		// file steam
//#include <zip.h>		// lipZib
#include <curl/curl.h>	// cUR
