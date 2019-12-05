#include "playlist.h"
#include <set>
#include <iostream>

using namespace std;

PlayList::PlayList(){
    NumberOfSongs = 0;
    SongsPlayed = 0;
    IndexOfSongPlaying = 0;
}

PlayList::PlayList(const Song& a_song){
    Song temp;
    temp.album = a_song.album;
    temp.year = a_song.year;
    temp.artist = a_song.artist;
    temp.title = a_song.title;
    temp.length = a_song.length;
    Songs.push_back(temp);
    NumberOfSongs++;
}

int PlayList::getNumberOfSongs() const{

return NumberOfSongs;

}

bool PlayList::isEmpty() const{

return ( NumberOfSongs == 0);

}

bool PlayList::addSong(const Song& new_song){

    Song temp;
    temp.album = new_song.album;
    temp.year = new_song.year;
    temp.artist = new_song.artist;
    temp.title = new_song.title;
    temp.length = new_song.length;
    Songs.push_back(temp);
    NumberOfSongs++;
    
    return true;
}

vector<Song> getSongs() const{
    return Songs;
}



bool PlayList::deleteSong(const Song& a_song){

bool removed = false;
    
for (vector<Song>::iterator it=Songs.begin(); it!=Songs.end(); ++it)
{
    if((*it).getTitle() == a_song.getTitle() && (*it).getAuthor() == a_song.getAuthor() && (*it).getAlbum() == a_song.getAlbum())
    {
        Songs.erase(it);
        NumberOfSongs--;
        removed = true;
    }
}

return removed;

}

void PlayList::clearPlayList(){

Songs.clear();
NumberOfSongs = 0;
SongsPlayed = 0;
IndexOfSongPlaying = 0;
}

void PlayList::displayPlayList() const{

cout << "Playlist contains:" <<endl;

for (vector<Song>::iterator it= Songs.begin(); it!= Songs.end(); ++it)

cout << "* Title" << (*it).getTitle() << " * Author" << (*it).getAuthor() << " * Album" << (*it).getAlbum() << " *" <<endl;

cout << "End of playlist" <<endl;

}

void PlayList::play() const
{
    if(SongsPlayed == 0)
    {
        cout << "Playing Song: " << Songs[0].getTitle() << endl;
    }
    else
    {
        if(Mode == "NORMAL")
        {
            if(IndexOfSongPlaying != (Songs.size() - 1))
            {
                IndexOfSongPlaying++;
                cout << "Playing Song: " << Songs[IndexOfSongPlaying].getTitle() << endl;
            }
            else
            {
                IndexOfSongPlaying = 0;
                cout << "Playing Song: " << Songs[IndexOfSongPlaying].getTitle() << endl;
            }
        }
        else if(Mode == "REPEAT")
        {
            cout << "Playing Song: " << Songs[IndexOfSongPlaying].getTitle() << endl;
        }
        else if(Mode == "LOOP")
        {
            IndexOfSongPlaying = 0;
            cout << "Playing Song: " << Songs[IndexOfSongPlaying].getTitle() << endl;
        }
    }
    
    SongsPlayed++;
}


void PlayList::setMode(string modesetter)
{
    Mode = modesetter;
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
