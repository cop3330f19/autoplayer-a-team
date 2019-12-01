#include "playlist.h"

#include <set>

#include <iostream>

using namespace std;

PlayList::PlayList(){

}

PlayList::PlayList(const Song& a_song){

playlist_.insert(a_song);

}

int PlayList::getNumberOfSongs() const{

return playlist_.size();

}

bool PlayList::isEmpty() const{

return ( playlist_.size() == 0);

}

bool PlayList::addSong(const Song& new_song){

playlist_.insert(new_song);

return true;

}

bool PlayList::removeSong(const Song& a_song){

playlist_.erase(a_song);

return true;

}

void PlayList::clearPlayList(){

playlist_.clear();

}

void PlayList::displayPlayList() const{

cout << "Playlist contains:" <<endl;

for (set<Song>::iterator it=playlist_.begin(); it!=playlist_.end(); ++it)

cout << "* Title" << (*it).getTitle() << " * Author" << (*it).getAuthor() << " * Album" << (*it).getAlbum() << " *" <<endl;

cout << "End of playlist" <<endl;

}