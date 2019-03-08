#include "Audio.h"



CAudio::CAudio()
{
}


CAudio::~CAudio()
{
}

void CAudio::LoadAudio(Content passed_audio_Content)
{
	
	if (passed_audio_Content.GetContentType() == "Music")
	{
		//if type == Music Load Music
		LoadMusic(passed_audio_Content);
	}
	else if (passed_audio_Content.GetContentType() == "SFX")
	{
		//else if Content type == SFX load SFX
		LoadSFX(passed_audio_Content);
	}
	
}

void CAudio::LoadMusic(Content passed_music_Content)
{
	// load Mix_Music struct
	Mix_Music* music;
	std::string music_path = passed_music_Content.GetContentPath();
	 char* music_id_string = const_cast<char*>(passed_music_Content.GetContentID().c_str());
	music = Mix_LoadMUS(music_path.c_str());
	//Create Music Struct
	Music* music_struct;
	// add Mix_Music data to Music struct
	music_struct->_music = music;
	music_struct->music_id = music_id_string;
	// Push Loaded Music struct to Music vector
	music_list.push_back(*music_struct);
	printf("Song \"%s\" was pushed to the song list", music_struct->music_id);
	//delete all temperary values
	delete music;
	delete music_id_string;
	delete music_struct;
}

void CAudio::LoadSFX(Content passed_sfx_Content)
{
	// load Mix_Chunk struct
	Mix_Chunk* sfx_chunk;
	std::string sfx_path = passed_sfx_Content.GetContentPath();
	char* sfx_id_string = const_cast<char*>(passed_sfx_Content.GetContentID().c_str());
	sfx_chunk = Mix_LoadWAV(sfx_path.c_str());
	//Create SFX Struct
	SFX* sfx_struct;
	// add Mix_Chunk data to SFX struct
	sfx_struct->sfx_id = sfx_id_string;
	sfx_struct->_sfx = sfx_chunk;
	// Push Loaded SFX struct to SFX vector
	sfx_list.push_back(*sfx_struct);
	printf("Sound effect \"%s\" was pushed to the sfx list", sfx_struct->sfx_id);
	//delete all temperary values
	delete sfx_chunk;
	delete sfx_id_string;
	delete sfx_struct;
}

void CAudio::PlayMusicByID(std::string passed_music_id)
{
	if (!(music_list.empty()))
	{    
		int beat = 0;
		bool exists = false;

		if(Mix_PausedMusic())  //resume if paused
		{
			Mix_ResumeMusic();
		}
		else if (Mix_PlayingMusic()) //pause if playing
		{
			Mix_PauseMusic();
		}
		else { //find song by ID then play it

			for (std::vector<Music>::iterator vi = music_list.begin; vi != music_list.end; vi++)
			{
				if (music_list[beat].music_id == passed_music_id)
				{
					// do checks before getting this far? -done

					
						Mix_PlayMusic(music_list[beat]._music, 1);
					
					
					exists = true;
				}
				beat++;
			}
			if (!(exists))
			{
				printf("CAudio PlayMusicByID error: could not play song by id\n");
			}
		}
	}
	else 
	{
		printf("CAudio PlayMusicByID error: music_list vector empty");
	}
}