//
// Created by Ben on 10/25/2019.
//

#include "UtPod.h"
#include "song.h"
#include <ctime>

using namespace std;

UtPod::UtPod() {
    songs = NULL;
    memSize = MAX_MEMORY;
    srand(time(0));
};

UtPod::UtPod(int size) {

    songs = NULL;
    if ((size > MAX_MEMORY) || (size <= 0)) {
        memSize = MAX_MEMORY;
    } else {
        memSize = size;
    }
};

int UtPod::addSong(Song const &s){

    if (getRemainingMemory() < Song::getSize(s)) {
        cout << "Error! Not enough space to add this song." << endl;
        return NO_MEMORY;
    } else if ((songs == NULL && Song::getSize(s) < getRemainingMemory()) || (getRemainingMemory() >= Song::getSize(s))) {
        cout << "Adding the song..." << endl;
        SongNode* temp = new SongNode;
        temp->s = s;
        temp->next = songs;
        songs = temp;
        return SUCCESS;
    }
    return 42;
};

int UtPod::removeSong(Song const &s) {

    if (songs == NULL) {
        cout << "Error! No songs to remove." << endl;
        return NOT_FOUND;
    }

    SongNode* nextSong = songs->next;
    SongNode* current = songs;
    SongNode* previous = NULL;

    if (songs->s == s) {

        songs = songs->next;
        delete previous;
        return SUCCESS;
    }
    while (current->next != NULL) {
        if (current->s == s) {
            previous->next = current->next;
            delete current;
            return SUCCESS;
        }

        current = current->next;
        nextSong = nextSong->next;
        previous = previous ? previous->next : songs;
    }

    if (current->next == NULL) {
        delete current;
        songs = NULL;
        return SUCCESS;
    }

};

void UtPod::shuffle() {

    cout << "You will see this message if you shuffled. See song list below for shuffled songs." << endl;
    if (songs == NULL) {
        cout << "No songs to shuffle." << endl;
        return;
    }

    int count = 0;
    for (SongNode* temp = songs; temp != NULL; temp = temp->next) {
        count++;
    }

    for (int numOfSwaps = 0; numOfSwaps < 50; numOfSwaps++) {
        int randomNum1 = (rand() % count);
        SongNode* number1 = songs;
        for (int num1Loop = 0; num1Loop < randomNum1; num1Loop++) {
            number1 = number1->next;
        }
        int randomNum2 = (rand() % count);
        SongNode* number2 = songs;
        for (int num2Loop = 0; num2Loop < randomNum2; num2Loop++) {
            number2 = number2->next;
        }
        number1->s.swap(number2->s);
    }
};


/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)

   input parms -

   output parms -
*/

void UtPod::showSongList(){
    string title;
    string artist;
    SongNode* temp = songs;

    if (songs == NULL) {
        cout << "No songs." << endl;
        return;
    }

    while (temp->next != NULL) {
        title = Song::getTitle(temp->s);
        artist = Song::getArtist(temp->s);
        cout << title << " by " << artist << endl;
        temp = temp->next;
    }
    title = Song::getTitle(temp->s);
    artist = Song::getArtist(temp->s);
    if (title == "" || artist == "") {
        cout << "No songs." << endl;
    } else {
        cout << title << " by " << artist << endl;
    }
};


/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
    o will do nothing if there are less than two songs in the current list

   input parms -

   output parms -
*/

void UtPod::sortSongList() {

    if (songs == NULL) {
        cout << "No songs to sort." << endl;
        return;
    }

    cout << "Sorted by title, alphabetically." << endl;
    for (SongNode* p1 = songs; p1 != NULL; p1 = p1->next) {
        for (SongNode* p2 = p1->next; p2 != NULL; p2 = p2->next) {
            if (p2->s > p1->s) {
                p1->s.swap(p2->s);
            }
        }
    }
};


/* FUNCTION - void clearMemory
 * clears all the songs from memory

   input parms -

   output parms -
*/
void UtPod::clearMemory() {

    if (songs == NULL) {
        cout << "No songs in the ipod." << endl;
        return;
    }

    SongNode* temp = songs;
    SongNode* temp2 = songs;
    while (temp->next != NULL) {
        temp2 = temp->next;                 // temp 2 will be 1 ahead of the other pointer
        delete temp;
        temp = temp2;                       // delete the one behind, set next one that should be deleted
    }
    temp2 = temp->next;
    delete temp;
};


/* FUNCTION - int getTotalMemory
 *  returns the total amount of memory in the UtPod
    o will do nothing if there are less than two songs in the current list

   input parms -

   output parms -
*/

int UtPod::getTotalMemory ()
    {
        return memSize;
    };


/* FUNCTION - int getRemainingMemory
 *  returns the amount of memory available for adding new songs

   input parms -

   output parms -
*/

int UtPod::getRemainingMemory() {
    SongNode* temp = songs;
    int remainingMem = 0;
    if (songs == NULL) {
        remainingMem = memSize;
        return remainingMem;
    }
      while (temp->next != NULL) {                   // songs will always be null for the first time around
        remainingMem += Song::getSize(temp->s);
        temp = temp->next;
    }
      remainingMem += Song::getSize(temp->s);
      temp = temp->next;
    return (memSize - remainingMem);
}

UtPod::~UtPod(){
    clearMemory();
}
