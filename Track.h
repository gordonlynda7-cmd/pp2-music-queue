#ifndef TRACK_H
#define TRACK_H

#include <string>
#include <iostream>
using namespace std;

// Base class for anything that can be placed in the queue and played.
// Song and Podcast inherit from this class.
class Track
{
protected:
    string title;        // Name of the track
    string artist;       // Artist or host name
    int durationSeconds; // Length of the track in seconds

    // Converts durationSeconds into a "minutes:seconds" string, e.g. 200 -> "3:20".
    string formatDuration() const
    {
        int minutes = durationSeconds / 60;
        int seconds = durationSeconds % 60;
        string secondsText = (seconds < 10 ? "0" : "") + to_string(seconds);
        return to_string(minutes) + ":" + secondsText;
    }

public:
    // Creates a track with a title, an artist (or host), and a length in seconds.
    Track(string trackTitle, string trackArtist, int trackDurationSeconds)
        : title(trackTitle), artist(trackArtist), durationSeconds(trackDurationSeconds) {}

    // Virtual destructor so deleting a Track* also cleans up the derived object.
    virtual ~Track() {}

    // Prints a "Now playing" message. Each derived class words it differently.
    virtual void play() const = 0;

    // Prints the full details of the track. Each derived class adds its own fields.
    virtual void display() const = 0;

    // Returns the title of the track (used when searching or removing from the queue).
    string getTitle() const { return title; }

    // Returns the artist or host of the track.
    string getArtist() const { return artist; }

    // Returns the length of the track in seconds.
    int getDurationSeconds() const { return durationSeconds; }
};

#endif