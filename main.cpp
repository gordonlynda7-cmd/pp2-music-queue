// main.cpp creates and deletes every Track object; other classes borrow pointers.
#include <iostream>
#include <limits>
#include <vector>
#include "Track.h"
#include "Song.h"
#include "Podcast.h"
#include "Player.h"
#include "PlaybackHistory.h"

using namespace std;

// Read an int safely and re-ask on bad input.
int readInt(const string& prompt){
    int value;
    cout << prompt;
    while (!(cin >> value)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number: ";
    }
    return value;
}

// Let the user pick from the library. Returns nullptr if invalid.
Track* pickFromLibrary(const vector<Track*>& library){
    cout << "\nLibrary:\n";
    for(size_t i = 0; i < library.size(); i++){
        cout << " " << i + 1 << ". ";
        library[i]->display();
    }
    int choice = readInt("Pick a number: ");
    if(choice < 1 || choice > (int)library.size()){
        cout << "Invalid choice.\n";
        return nullptr;
    }
    return library[choice - 1];
}

void showMenu(){
    cout << "\n===== Music Player =====\n"
         << "1. Add to queue\n"
         << "2. Play next\n"
         << "3. Skip to next\n"
         << "4. Remove from queue\n"
         << "5. Shuffle queue\n"
         << "6. Show queue\n"
         << "7. Show history\n"
         << "8. Show stats\n"
         << "0. Exit\n";
}

// main.cpp owns all Track objects (sample data, edit as needed).
int main(){
    vector<Track*> library;
    library.push_back(new Song("Song One", "Artist A", 200, "Album One"));
    library.push_back(new Song("Song Two", "Artist B", 185, "Album Two"));
    library.push_back(new Song("Song Three", "Artist C", 240, "Album Three"));
    library.push_back(new Song("Podcast One", "Host A", 1800, 1));
    library.push_back(new Song("Podcast Two", "Host B", 2400, 2));

    Player player;
    PlaybackHistory history(5); // remembers the last 5 played

    int chpice = -1;
    while(choice != 0){
        showMenu();
        choice = readInt("Choose an option: ");

        switch(choice){
            case 1:{
                Track* track = pickFromLibrary(library);
                if (track) player.addToQueue(track);
                break;
            }
            case 2: {
                Track* track = pickFromLibrary(library);
                if(track) plyer.playNext(track);
                break;
            }
            case 3: {
                // skipToNext() pops the front of the queue; that track now "plays"
                Track* played = player.skipToNext();
                if (played) {
                    played->play();  
                    history.record(played);
                } else {
                    cout << "Queue is empty.\n";
                }
                break;
            }
            case 4: {
                player.displayQueue();
                string title;
                cout << "Title to remove: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, title);
                if (player.removeByTitle(title)) {
                    cout << "Removed.\n";
                } else {
                    cout << "No track with that title in the queue.\n";
                }
                break;
            }
            case 5:
                player.shuffleQueue();
                cout << "Queue shuffled.\n";
                break;
            case 6:
                player.displayQueue();
                break;
            case 7:
                history.showHistory();
                break;
            case 8:
                history.showStats();
                break;
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    }

    // Clean up: main created these, so main deletes them.
    for (Track* track : library) delete track;
    library.clear();
    return 0;
}
        