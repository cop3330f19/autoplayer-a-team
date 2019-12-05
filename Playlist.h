#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include "StringHelper.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Playlist{
    
    private:
    
    vector <Song> Songs;
    int NumberOfSongs;
    string Mode;
	int SongsPlayed;
    Song SongPlaying;
    int IndexOfSongPlaying;
    vector<Song> getSongs() const;
    
	public:
    
	//addSong function which adds Song Object to end of Playlist Object
	bool addSong(Song& song) const;
     
	//deleteSong function which deletes all instances of user called Song Object from a specified playlist 
	bool deleteSong(Song& song)const;
    
	//intersect function which returns all songs common in 
	Playlist intersect(const Playlist& list) const;
    
	//Merge function which will return a new Playlist that combines all song objects from playlist called
	//and those from playlist called by user
	Playlist merge(const Playlist& list) const;
	Playlist operator+(const Playlist& listMerge1, const Playlist& listMerge2) const;
    
	//play function which prints message followed by title of song you are playing
	//setMode function dictates how song is played
	void play() const;
    
	//setMode function which dictates next song Object to be played through 3 modes(normal,repeat,loop)
	void setMode(string modesetter);
    
    friend std::ostream& operator<<(std::ostream& os, const Playlist& Playlist);
    
    int getNumberOfSongs()const;
    void clearPlaylist();
    void displayPlaylist();
    
    
	
};

#endif
