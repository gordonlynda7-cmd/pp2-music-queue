#ifndef PLAYER_H
#define PLAYER_H

#include "Track.h"
#include <deque>
#include <random>
#include <string>

// Manages the main play queue using a std::deque.
// The Player only borrows Track pointers; whoever created the tracks
// (main.cpp) is responsible for deleting them.
class Player
{
private:
    deque<Track*> playQueue;      // Upcoming tracks; front = next to play
    mt19937 randomGenerator;      // Random number generator used for shuffling

public:
    // Creates an empty player and seeds the random generator.
    Player();

    // Adds a track to the BACK of the queue (push_back).
    void addToQueue(Track* track);

    // Adds a track to the FRONT of the queue so it plays next (push_front).
    void playNext(Track* track);

    // Removes and returns the track at the front of the queue (pop_front).
    // Returns nullptr if the queue is empty.
    Track* skipToNext();

    // Removes the first track in the queue with the given title (find_if + erase).
    // Returns true if a track was removed, false if no match was found.
    bool removeByTitle(const string& title);

    // Randomly reorders the queue using std::shuffle.
    void shuffleQueue();

    // Prints every track in the queue, in order, using an iterator loop.
    void displayQueue() const;

    // Returns true if the queue has no tracks.
    bool isEmpty() const;

    // Returns how many tracks are in the queue.
    int getQueueSize() const;
};

#endif