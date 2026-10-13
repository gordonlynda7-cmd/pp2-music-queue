#ifndef SONG_H
#define SONG_H

#include "Track.h"

// A music track. Inherits title, artist, and duration from Track and adds an album.
class Song : public Track
{
private:
    string album; // Album the song belongs to

public:
    // Creates a song; the first three values are passed up to the Track constructor.
    Song(string songTitle, string songArtist, int songDurationSeconds, string songAlbum)
        : Track(songTitle, songArtist, songDurationSeconds), album(songAlbum) {}

    // Prints the now-playing message for a song.
    void play() const override
    {
        cout << "Now playing: " << title << " - " << artist
             << " [" << formatDuration() << "]" << endl;
    }

    // Prints all the details of the song, including its album.
    void display() const override
    {
        cout << "Song: " << title << " | Artist: " << artist
             << " | Album: " << album
             << " | Length: " << formatDuration() << endl;
    }
};

#endif