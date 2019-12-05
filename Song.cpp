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
	cout << "Song Details" << endl;
	cout << "Title: ";
	getline(is,song.title);
	cout << "Artist: ";
	getline(is,song.artist);
	cout << "Album: ";
	getline(is,song.album);
	cout << "Year: ";
	is >> song.year;
	cout << "Length (in seconds): ";
	is >> song.length;
	
	return is;
}

//Overloaded Output String Stream which reads in Song Details into a file
std::fstream& operator>>(std::fstream& is, Song& song)
{
	string line,myString,myString2;
	while (getline(is,line))
	{
		stringstream ss(line);
		
		getline(ss,song.title,',');
		getline(ss,song.artist,',');
		getline(ss,song.album,',');
		getline(ss,myString,',');
		song.year = stoi(myString);
		getline(ss,myString2,',');
		song.length = stoi(myString2); 
	}
	
	return is;
}

int main(){
	return 0;
}

/*#include "Song.h"

Song::Song(string songName, string firstLine){
  this->songName = songName;
  this->firstLine = firstLine;
  timesPlayed = 0;
}

string Song::GetName() const {
  return songName;
}

void Song::ListPrint() const {
  cout << songName << ": \"" << firstLine << "\", " << timesPlayed << " play(s)." << endl;
}

void Song::Play() {
  cout << firstLine << endl;
  timesPlayed++;
}
