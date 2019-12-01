#include "Song.h"

#include <iostream>

using namespace std;

//constructor

Song::Song(){

title_ = "" ;

author_ = "";

album_ = "";

}

//paramerterized constructor

Song::Song(const string& title, const string& author, const string& album){

title_ = title ;

author_ = author;

album_ = album;

}

//setter function

void Song::setTitle(string title){

title_ = title ;

}

void Song::setAuthor(string author){

author_ = author;

}

void Song::setAlbum(string album){

album_ = album;

}

//gettter function

string Song::getTitle() const{

return title_;

}

string Song::getAuthor() const{

return author_;

}

string Song::getAlbum() const{

return album_;

}

bool operator==(const Song& lhs, const Song& rhs){

return (lhs.title_ == rhs.title_ && lhs.author_ == rhs.author_ && lhs.author_ == rhs.author_);

}

//this function is mandatory for element insertion as iteratotr in set

bool Song::operator< (const Song& x) const {

return (title_ < x.title_ );

}