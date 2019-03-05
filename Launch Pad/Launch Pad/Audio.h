#include "Stage.h"
#include "stdafx.h"
#include <vector>
#ifndef AUDIO_H
#define AUDIO_H
//do last or near completion

struct Music {
	char* music_id;
	char* music_duration;
	Mix_Music* a_music;
};

struct SFX {

	char* sfx_id;
	Mix_Chunk* a_sfx;
};

class CAudio
{
public:
	CAudio();
	~CAudio();
	//add and load music

	void LoadAudio();
	//add and load sfx

	void LoadMusic();

	void LoadSFX();

private:
	//laod only one song?
	std::vector<Music> music_list;
	std::vector<SFX> sfx_list;
};
//add needed to corresponding vector within Audio class



#endif //AUDIO_H

