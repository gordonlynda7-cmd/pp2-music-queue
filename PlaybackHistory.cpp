#include "PlaybackHistory.h"
#include "Track.h"
#include <iostream>

// Set the cap and start the lifetime counters at zero.
PlaybackHistory::PlaybackHistory(std::size_t maxSize)
    : maxSize(maxSize), totalPlayed(0), totalSecondsPlayed(0) {}

// Add a played item to the back, and if we're over the cap, drop the oldest item from the front.
void PlaybackHistory::recor(Track* track){
    if (track == nullptr) return;
    history.push_back(track);
    totalPlayed++;
    totalPlayed++;
    totalSecondsPlayed += track->getDurationDeconds();
    if(history.size() > maxSize){
        history.pop_front();
    }
}

// Newest item is at the back of the deque.
Track* PlaybackHistory::mostRecent() const{
    if(history.empty()) return nullptr;
    return history.back();
}

// Print from newest to oldest using reverse iterators.
void PlaybackHistory::showHistory() const {
    if (history.empty()) {
        std::cout << "History is empty.\n";
        return;
    }
    std::cout << "Recently played (newest first):\n";
    int number = 1;
    for (auto it = history.rbegin(); it != history.rend(); ++it) {
        std::cout << "  " << number++ << ". ";
        (*it)->display(); 
    }
}

// Print lifetime totals and what is currently stored.
void PlaybackHistory::showStats() const {
    std::cout << "Total items played: " << totalPlayed << "\n";
    std::cout << "Total listening time: " << totalSecondsPlayed / 60 << " min "
              << totalSecondsPlayed % 60 << " sec\n";
    std::cout << "Items in history:   " << history.size()
              << " (max " << maxSize << ")\n";
    if (!history.empty()) {
        std::cout << "Last played: ";
        history.back()->display();
    }
}

std::size_t PlaybackHistory::size() const {
    return history.size();
}
