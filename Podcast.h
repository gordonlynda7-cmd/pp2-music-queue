#ifndef PODCAST_H
#define PODCAST_H

#include "Track.h"

// A podcast episode. Inherits title, host (stored as artist), and duration from Track
// and adds an episode number.
class Podcast : public Track
{
private:
    int episodeNumber; // Episode number within the podcast series

public:
    // Creates a podcast episode; the first three values are passed up to the Track constructor.
    Podcast(string podcastTitle, string podcastHost, int podcastDurationSeconds, int podcastEpisodeNumber)
        : Track(podcastTitle, podcastHost, podcastDurationSeconds), episodeNumber(podcastEpisodeNumber) {}

    // Prints the now-playing message for a podcast episode.
    void play() const override
    {
        cout << "Now playing podcast: " << title << " (Episode " << episodeNumber
             << ") hosted by " << artist << " [" << formatDuration() << "]" << endl;
    }

    // Prints all the details of the podcast episode, including its episode number.
    void display() const override
    {
        cout << "Podcast: " << title << " | Host: " << artist
             << " | Episode: " << episodeNumber
             << " | Length: " << formatDuration() << endl;
    }
};

#endif