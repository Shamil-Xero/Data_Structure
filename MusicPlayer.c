#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Track {
    char name[100];
    char artist[50];
    // Add other metadata as needed
    struct Track* next;
    struct Track* prev;
};

struct Playlist {
    struct Track* head;
    struct Track* tail;
};

// Function to add a track to the playlist
void addTrack(struct Playlist* playlist, const char* name, const char* artist) {
    struct Track* newTrack = (struct Track*)malloc(sizeof(struct Track));
    strcpy(newTrack->name, name);
    strcpy(newTrack->artist, artist);
    newTrack->next = NULL;
    newTrack->prev = playlist->tail;

    if (playlist->tail)
        playlist->tail->next = newTrack;
    else
        playlist->head = newTrack;

    playlist->tail = newTrack;
}

// Function to remove a track from the playlist
void removeTrack(struct Playlist* playlist, const char* name) {
    // Implement removal logic based on track name
    // Update next and prev pointers
    // Free memory
}

// Function to skip forward
void skipForward(struct Playlist* playlist) {
    // Move to the next track
}

// Function to skip backward
void skipBackward(struct Playlist* playlist) {
    // Move to the previous track
}

int main() {
    // Initialize an empty playlist
    struct Playlist myPlaylist = { NULL, NULL };

    // Add some tracks
    addTrack(&myPlaylist, "Song A", "Artist X");
    addTrack(&myPlaylist, "Song B", "Artist Y");
    addTrack(&myPlaylist, "Song C", "Artist Z");

    // Example usage: skip forward
    skipForward(&myPlaylist);

    // Example usage: remove a track
    removeTrack(&myPlaylist, "Song B");

    // Clean up: Free memory for all nodes

    return 0;
}
