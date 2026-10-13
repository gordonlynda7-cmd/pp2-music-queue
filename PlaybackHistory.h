// Keeps a capped history of previously played tracks plus simple stats
// This class only BORROWS Track pointers, main.cpp will own and delete them
#indef PLAYBACKHISTORY_H
#define PLAYBACKHISTORY_H

#include <deque>
#include <cstddef>

class Track; 

class PlaybakHistory{
private:
    std::deque<Track*> history; // oldest at front and newest at back
    std::size_t maxSize; // cap on how many itmes we remember
    int totalPlayed; // lifetime count
    int totalSecondsPlayed; // lifetime listening time in seconds

public:
    explicit PlaybackHistory(std::size_t maxSize = 10);

    void record(Track* track); // push_back; pop_front if over the cap
    Track* mostRecent() const; // newest item, or nullptr if empty
    void showHistory() const; // prints newest to oldest
    void showStats() const; // total played, listening time, stored, cap
    std::size_t size() const; //items currently stored
};

#endif
