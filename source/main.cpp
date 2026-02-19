#include <main.hpp>


static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::ofstream* userp) {
    userp->write(static_cast<const char*>(contents), size * nmemb);
    return size * nmemb;
}

void downloadFile(const char websiteLink[], const char fileName[]) {
//	std::cout << "Downloading \"" << websiteLink << "\" as \"" << fileName << "\"...\n";
	
	CURL* curl;
	CURLcode res;
	curl = curl_easy_init();
	std::ofstream file(fileName, std::ios::binary);
	
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, websiteLink);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &file);
		res = curl_easy_perform(curl);
		
		if (res != CURLE_OK) // error check
			std::cout << "cURL error: " << curl_easy_strerror(res);
		
		curl_easy_cleanup(curl);
	}
	
	curl_global_cleanup();
	file.close();
	
}

// (int argc, char** argv) if we need arguments (prolly shouldnt if its supposed to be easy lol)
int main() {
	
	// btw "\n" is just a newline to clean up the output
	
	// startup test
	std::cout << "this absolutely eternal program shall forever be absolutely timeless\n\n";
	
	// download teh apk (if not evil cd)
#if RETRO_GAME == GAME_SONIC1FOREVER
	std::cout << "The Sonic 1 APK is downloading... Hold Out! Downloader!\n";
	downloadFile("https://retrocdn.net/images/e/e4/Sonic_the_Hedgehog_(com.sega.sonic1px_v3.5.1).apk", "game.apk");
#elif RETRO_GAME == GAME_SONIC2ABSOLUTE
	std::cout << "The Sonic 2 APK is downloading... Hold Out! Downloader!\n";
	downloadFile("https://retrocdn.net/images/b/b0/Sonic_the_Hedgehog_2_Classic_(com.sega.sonic2.runner_v1.3.1).apk", "game.apk");
#elif RETRO_GAME == GAME_SONICCDTIMELESS // dude where we gettin this bruh
	std::cout << "The Sonic CD APK is downloading... Hold Out! Downloader!\n";
	std::cout << "(nvm i lied)\n";
#endif
	std::cout << "APK Download finished.\n";
	std::cout << "Saved to: \"game.apk\"\n\n";
	
	// download mod (where lol)
#if RETRO_GAME == GAME_SONIC1FOREVER
	std::cout << "Sonic 1 Forever is downloading... Hold Out! Downloader!\n";
	std::cout << "(nvm i lied    again)\n";
#elif RETRO_GAME == GAME_SONIC2ABSOLUTE
	std::cout << "Sonic 2 Absolute is downloading... Hold Out! Downloader!\n";
	std::cout << "(nvm i lied    again)\n";
#elif RETRO_GAME == GAME_SONICCDTIMELESS
	std::cout << "Sonic CD Timeless is downloading... Hold Out! Downloader!\n";
	std::cout << "(nvm i lied    again)\n";
#endif
	std::cout << "Mod Download finished.\n";
	std::cout << "Saved to: \"" << "file/path/here.data" << "\"\n\n";
	
	// extract apk
	std::cout << "Extracting APK...\n";
	std::cout << "Extraction complete!"; std::cout << "\n\n";
	
	// steal rsdk file
	std::cout << "Moving 'Data.rsdk.xmf'...\n";
	std::cout << "The file has been moved!\n";
	std::cout << "Saved to: \"" << "file/path/here.data" << "\"\n\n";
	
	// extract data file
	std::cout << "steal from retroed??\n\n";
	return 0;
}
