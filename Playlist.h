#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include "StringHelper.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Playlist{
	public:
	//addSong function which adds Song Object to end of Playlist Object
	Playlist addSong(Song& song) const;
	//deleteSong function which deletes all instances of user called Song Object from a specified playlist 
	Playlist deleteSong(Song& song)const;
	//intersect function which returns all songs common in 
	Playlist intersect(Playlist& list) const;
	//Merge function which will return a new Playlist that combines all song objects from playlist called
	//and those from playlist called by user
	Playlist merge(Song& songList) const;
	Playlist operator+(Song& listMerge) const;
	//play function which prints message followed by title of song you are playing
	//setMode function dictates how song is played
	void play(Song& songPlay) const;
	//setMode function which dictates next song Object to be played through 3 modes(normal,repeat,loop)
	
	private:
	
};

#endif
/*#ifndef PLAYLIST_H

#define PLAYLIST_H

#include "Song.h"

#include <set>

#include <iostream>

using namespace std;

class PlayList{

private:

set<Song> playlist_;

public:

PlayList();

PlayList(const Song& a_song);

int getNumberOfSongs() const;

bool isEmpty() const;

bool addSong(const Song& new_song);

bool removeSong(const Song& a_song);

void clearPlayList();

void displayPlayList() const;

};

#endif*/
