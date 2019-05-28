#include "Audio.h"



CAudio::CAudio()
{
}


CAudio::~CAudio()
{
}

void CAudio::LoadAudio(Content passed_audio_Content)
{
	
	if (passed_audio_Content.GetContentType() == "music")
	{
		//if type == Music Load Music
		LoadMusic(passed_audio_Content);
		printf("Music loaded\n");
	}
	else if (passed_audio_Content.GetContentType() == "sfx")
	{
		//else if Content type == SFX load SFX
		LoadSFX(passed_audio_Content);
		printf("SFX loaded\n");
	}
	std::cout << "LoadAudio called id " << passed_audio_Content.GetContentID() << " passed" << std::endl;
}

void CAudio::LoadMusic(Content passed_music_Content)
{
	// load Mix_Music struct
	Mix_Music* music;
	std::string music_path = passed_music_Content.GetContentPath();
	std::string string_id = passed_music_Content.GetContentID();
	int ssize = (string_id.size() + 1);
	char* music_id_string = new char;
		
	//strcpy_s(music_id_string, ssize, string_id.c_str());// linux issues
	strcpy(music_id_string,string_id.c_str());
	music = Mix_LoadMUS(music_path.c_str());
	//Create Music Struct
	Music* music_struct = new Music;
	// add Mix_Music data to Music struct
	music_struct->_music = music;
	music_struct->music_id = music_id_string;
	// Push Loaded Music struct to Music vector
	music_list.push_back(*music_struct);
	printf("Song \"%s\" was pushed to the song list", music_struct->music_id);
	std::cout << "Song id "<< passed_music_Content.GetContentID() <<" was pushed to the song list" << std::endl;
	//delete all temperary values
	//Mix_FreeMusic(music);
	
	//delete music_struct;
}

void CAudio::LoadSFX(Content passed_sfx_Content)
{
	// load Mix_Chunk struct
	Mix_Chunk* sfx_chunk;
	std::string sfx_path = passed_sfx_Content.GetContentPath();
	std::string get_id_string = passed_sfx_Content.GetContentID();
	int ssize = passed_sfx_Content.GetContentID().size();
	char* sfx_id_string = new char;
	//strcpy_s(sfx_id_string, ssize, get_id_string.c_str()); //was a mission to find issues on linux
 	strcpy(sfx_id_string,get_id_string.c_str());
	sfx_chunk = Mix_LoadWAV(sfx_path.c_str());
	//Create SFX Struct
	SFX* sfx_struct = new SFX;
	// add Mix_Chunk data to SFX struct
	sfx_struct->sfx_id = sfx_id_string;
	sfx_struct->_sfx = sfx_chunk;
	// Push Loaded SFX struct to SFX vector
	sfx_list.push_back(*sfx_struct);
	printf("Sound effect \"%s\" was pushed to the sfx list", sfx_struct->sfx_id);
	//delete all temperary values
	Mix_FreeChunk(sfx_chunk);
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
			printf("Mix_ResumeMusic called\n");
		}
		else if (Mix_PlayingMusic()) //pause if playing
		{
			Mix_PauseMusic();
			printf("Mix_PauseMusic called\n");
		}
		else { //find song by ID then play it

			for (std::vector<Music>::iterator vi = music_list.begin(); vi < music_list.end(); vi++)
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
		printf("CAudio PlayMusicByID error: music_list vector empty\n");
	}
	printf("PlayMusicByID called\n");
}