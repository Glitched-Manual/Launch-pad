#include "Stage.h"
#include "stdafx.h"
#include "Content.h"
#include <vector>
#include <memory>
#include <string>
#include <cstring>

#if defined(_WIN32)|(_WIN64)
	#pragma warning(disable : 4996)
#endif
#ifndef AUDIO_H
#define AUDIO_H
//do last or near completion

struct Music {
	char* music_id;
	char* music_duration;
	Mix_Music* _music;
};

struct SFX {

	char* sfx_id;
	Mix_Chunk* _sfx;
};

class CAudio
{
public:
	CAudio();
	~CAudio();
	//add and load music

	void LoadAudio(Content passed_audio_Content);
	//add and load sfx

	void LoadMusic(Content passed_music_Content);

	void LoadSFX(Content passed_sfx_Content);

	//play music

	void PlayMusicByID(std::string passed_music_id);
private:
	//laod only one song?
	std::vector<Music> music_list;
	std::vector<SFX> sfx_list;
};
//add needed to corresponding vector within Audio class



#endif //AUDIO_H

