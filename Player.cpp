#include "Player.h"
#include <algorithm>
#include <iostream>

// Seeds the random generator with a non-deterministic value.
Player::Player() : randomGenerator(random_device{}()) {}

// push_back adds to the end of the deque (like "Add to queue" in Spotify).
void Player::addToQueue(Track* track)
{
    playQueue.push_back(track);
}

// push_front adds to the start of the deque (like "Play next" in Spotify).
void Player::playNext(Track* track)
{
    playQueue.push_front(track);
}

// Takes the first track off the queue. front() reads it, pop_front() removes it.
Track* Player::skipToNext()
{
    if (playQueue.empty())
    {
        return nullptr;
    }
    Track* nextTrack = playQueue.front();
    playQueue.pop_front();
    return nextTrack;
}

// Searches the queue for a title match and erases the first one found.
bool Player::removeByTitle(const string& title)
{
    deque<Track*>::iterator foundPosition =
        find_if(playQueue.begin(), playQueue.end(),
                [&title](const Track* track)
                {
                    return track->getTitle() == title;
                });

    if (foundPosition == playQueue.end())
    {
        return false; // No track with that title
    }
    playQueue.erase(foundPosition);
    return true;
}

// std::shuffle works on a deque because it has random-access iterators.
void Player::shuffleQueue()
{
    shuffle(playQueue.begin(), playQueue.end(), randomGenerator);
}

// Walks through the queue with an iterator and prints each track numbered.
void Player::displayQueue() const
{
    if (playQueue.empty())
    {
        cout << "The queue is empty." << endl;
        return;
    }
    int position = 1;
    for (deque<Track*>::const_iterator iter = playQueue.begin();
         iter != playQueue.end(); ++iter)
    {
        cout << position << ". ";
        (*iter)->display(); // Virtual call: Song or Podcast version runs
        position++;
    }
}

// empty() is true when the deque holds no elements.
bool Player::isEmpty() const
{
    return playQueue.empty();
}

// size() returns the number of elements in the deque.
int Player::getQueueSize() const
{
    return static_cast<int>(playQueue.size());
}