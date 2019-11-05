//
// Created by Ben on 10/25/2019.
//

#include <string>
#include "song.h"

using namespace std;
class Song;

    Song::Song() {

        artist = "";
        title = "";
        size = 0;
    }

    Song::Song(string _artist, string _title, int _size) {
    if ((_artist != "") && (_title != "") && (_size > 0)) {
    artist = _artist;
    title = _title;
    size = _size;
    } else {
        cout << "Invalid inputs..";
    }
    }

    string Song::getTitle(const Song &s) {
        return s.title;
    }

    string Song::getArtist(const Song &s) {
        return s.artist;
    }

    int Song::getSize(const Song &s){
        if (s.size == NULL || s.size == 0) {
            return 0;
        } else {
            return s.size;
        }
    }

void Song::setTitle(string _title) {
    if (_title != "") {
        title = _title;
    }
}
    void Song::setArtist(string _artist) {
        if (artist != "") {
            artist = _artist;
        }
    }

    void Song::setSize(int _size){
        if (_size != 0) {
            size = _size;
        }
    }

    void Song::swap(Song &s)
{
    Song temp = s;
    s = *this;             // putting s1 into s
    *this = temp;          // putting s into s1;
    return;
}

bool Song::operator > (Song const &rhs) {

       if (title < rhs.title) {
           return true;
       } else if (title > rhs.title) {
           return false;
       }
      if (artist < rhs.artist) {
        return true;
       } else if (artist > rhs.artist) {
        return false;
       }
       if (size < rhs.size) {
           return true;
       } else if (size > rhs.size) {
           return false;
       }
}


bool Song::operator == (Song const &rhs)
{
    return (title == rhs.title &&
            artist == rhs.artist &&
            size == rhs.size);
}
