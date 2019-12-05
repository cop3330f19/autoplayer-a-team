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

/*#include "Playlist.h"
#include <iostream>

Playlist::Playlist(string name) {
  this->name = name;
}

string Playlist::GetName() const {
  return name;
}

void Playlist::AddSong(Song *song) {
  songs.push_back(song); //Adds the song pointer to the vector of song pointers belonging to this Playlist object
}

void Playlist::RemoveSong(int index) {
  songs.erase(songs.begin() + index);
}

void Playlist::RemoveSong(Song* song) {
  for (int i = 0; i < songs.size(); i++){
    if (songs.at(i) == song){ //If the addresses that the pointers point to are the same, erase the pointer from the songs vector
      songs.erase(songs.begin() + i);
      break;
    }
  }
}

vector<Song*> Playlist::GetSongs() const {
  return songs;
}

void Playlist::Play() {
  cout << "Playing first lines of playlist: " << name << endl;
  for (int i = 0; i < songs.size(); i++) {
    songs.at(i)->Play();
  }
}
