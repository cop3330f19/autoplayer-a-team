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
    
    int NumberOfSongs;
	
	public:
    
	//addSong function which adds Song Object to end of Playlist Object
	Playlist addSong(Song& song) const;
	//deleteSong function which deletes all instances of user called Song Object from a specified playlist 
	Playlist deleteSong(Song& song)const;
	//intersect function which returns all songs common in 
	Playlist intersect(Playlist& list) const;
	//Merge function which will return a new Playlist that combines all song objects from playlist called
	//and those from playlist called by user
	Playlist merge(Playlist& list) const;
	Playlist operator+(Playlist& listMerge) const;
	//play function which prints message followed by title of song you are playing
	void play() const;
	//setMode function which dictates next song Object to be played through 3 modes(normal,repeat,loop)
	
    
    int getNumberOfSongs()const;
    void clearPlaylist();
    void displayPlaylist(string);
    
    
	
};

#endif
/*#ifndef PLAYLIST
#define PLAYLIST

#include "Song.h"
#include <vector>
#include <string>
using namespace std;

class Playlist {
  public:
    Playlist(string name = "None"); //Constructor
    string GetName() const;
    vector<Song*> GetSongs() const; //Returns a vector of pointers to song objects in the playlist
    void AddSong(Song* song);
    void RemoveSong(int index);
    void RemoveSong(Song* song); //Overloaded to remove either by index or pointer
    void Play(); //"Plays" the songs in the songs vector
  private:
    string name;
    vector <Song*> songs; //The songs that belong to this Playlist
};
#endif
