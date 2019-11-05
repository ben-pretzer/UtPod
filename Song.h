//
// Created by Ben on 10/25/2019.
//

#include <string>
#include <iostream>

using namespace std;

#ifndef SONG_H
#define SONG_H

class Song {

private:
    string artist;
    string title;
    int size;

    static const int MAX_SIZE = 512;

public:
    Song();
    Song(string title, string artist, int size);
    static string getTitle(const Song &s);
    static string getArtist(const Song &s);
    static int getSize(const Song &s);
    void setArtist(string artist);
    void setTitle(string title);
    void setSize(int size);
    bool operator >(Song const &rhs);
    bool operator ==(Song const &rhs);
    void swap(Song &s);

};





#endif
