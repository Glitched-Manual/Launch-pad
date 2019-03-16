#make file to run launchpad on windows

#OBJS specifies which files to compile as part of the project
OBJS = launchPad.cpp Audio.cpp Audio.h Content.cpp Content.h CoreScene.h Database.cpp Database.h Main.cpp  Main.h Prime_Scene.cpp Prime_Scene.h Scene.cpp Scene.h SDLSetup.h SDLSetup.cpp Stage.cpp Stage.h stdafx.h Storage.cpp Storage.h Texture.cpp Texture.h

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need ,note: full include path needed relative paths do not work
INCLUDE_PATHS = -IC:\Program\ Files\C++\ libs\SDL2\ libs\SDL2\ 2.0.8\ pack\include

#LIBRARY_PATHS specifies the additional library paths we'll need 
LIBRARY_PATHS = -LC:\Program\ Files\C++\ libs\SDL2\ libs\SDL2\ 2.0.8\ pack\lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against -lmingw32 not mingw
LINKER_FLAGS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = lp_windows

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
