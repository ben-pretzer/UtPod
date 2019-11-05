/* utPod_driver.cpp
Demo Driver for the UtPod.

Ben Pretzer
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])

{
    UtPod t;

    Song();
    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();
    t.sortSongList();
    t.showSongList();

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    // starting my own driver below. need to check functionality of adding, removing, sorting, and shuffling the songs in the ipod.


    Song s6("Avril Lavigne", "Girlfriend", 6);
    t.addSong(s6);

    Song s7("Justin Bieber", "Baby", 20);
    t.addSong(s7);

    Song s8("Justin Bieber", "Baby (remix)", 2);
    t.addSong(s8);
    cout << "result = " << result << endl;

    Song s9("Sean Kingston", "Fire Burning", 10);
    t.addSong(s9);
    cout << "result = " << result << endl;

    Song s10("Michael Buble", "It's beginning to look a lot like Christmas", 30);
    t.addSong(s10);
    cout << "result = " << result << endl;

    Song s11("ACDC", "Highway to Hell", 204);
    t.addSong(s11);
    cout << "result = " << result << endl;

    t.sortSongList();
    t.showSongList();
    t.shuffle();
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

}
