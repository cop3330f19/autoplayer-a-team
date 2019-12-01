#include "Song.h"

//Default and Paramtrized Song Constructors
Song::Song(){}
Song::Song(std::string title, std::string artist, std::string album, int length, int year)
{
	this->title = title;
	this->artist = artist;
	this->album = album;
	this->length = length;
	this->year = year;
}

//Sets Song Details for Song Object
void Song::set(std::string title, std::string artist, std::string album, int length, int year)
{
	this->title = title;
	this->artist = artist;
	this->album = album;
	this->length = length;
	this->year = year;
}

//Checks to see if two Song Objects are equal
bool operator==(const Song& lhs, const Song& rhs)
{
	if ((lhs.title == rhs.title) && (lhs.artist == rhs.artist) && (lhs.album == rhs.album) &&
		(lhs.length == rhs.length) && (lhs.year == rhs.year))
		return true;
	else 
		return false;
}

//Overloaded String stream which prints Song Details to screen
std::ostream& operator<<(std::ostream& os, const Song& song)
{
	os << song.title << "|" << song.artist << "|" << song.album << "|" << song.year << "|" << song.length;
	return os;
}

//Overloaded String Stream which outputs Song Details to a file
std::ofstream& operator<<(std::ofstream& os, const Song& song)
{
	os << "\n" << song.title << "," << song.artist << "," << song.album << "," << song.year << "," << song.length;
	return os;
}

//Overloaded Output String Stream which reads in Song Details into Song Object
std::istream& operator>>(std::istream& is, Song& song)
{
	char comma;
	is >> song.title >> comma >> song.artist >> comma >> song.album >> comma >> song.year >> comma >> song.length;
	
	return is;
}

//Overloaded Output String Stream which reads in Song Details into a file
std::fstream& operator>>(std::fstream& is, Song& song)
{
	
	is >> song.title >> song.artist >>song.album >> song.year >> song.length;
	return is;
}

int main(){
	return 0;
}

/*#include "Song.h"

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

}*/
