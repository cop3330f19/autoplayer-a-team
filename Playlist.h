#ifndef PLAYLIST_H

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

#endif