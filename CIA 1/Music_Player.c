#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the playlist
struct node
{
    char name[100];
    struct node *next;
    struct node *prev;
};

// Initialize an empty playlist pointers
struct node *head = NULL;
struct node *tail = NULL;

// Function to add a track to the playlist
void addTrack(const char *name)
{
    // Create a new node for the track
    struct node *new = (struct node *)malloc(sizeof(struct node));
    strcpy(new->name, name);
    new->next = NULL;
    new->prev = tail;

    // If the playlist is empty, make the new node the head and tail
    if (head == NULL && tail == NULL)
    {
        head = tail = new;
    }
    else // Otherwise, point the tail to the new node
    {
        tail->next = new;
        tail = new;
    }
}

// Function to remove a track from the playlist
void removeTrack(const char *name)
{
    struct node *current = head;

    // Traverse the playlist to find the track with the given name
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            break;
        }
        current = current->next;
    }

    // If the track was found
    if (current != NULL)
    {
        // Update next and prev pointers
        if (current->prev != NULL)
        {
            current->prev->next = current->next;
        }
        else
        {
            head = current->next;
        }

        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }
        else
        {
            tail = current->prev;
        }

        free(current);
    }
}

// Function to skip the track
struct node *skipTrack(struct node *playing) 
{
    if (playing->next != NULL) // Checking if the end of the playlist is reached
    {
        playing = playing->next;
    }
    return playing;
}

int main()
{
    // Add some tracks
    addTrack("Song A");
    addTrack("Song B");
    addTrack("Song C");

    // Example usage: skip forward
    struct node *current = head;
    current = skipTrack(current);

    // Example usage: remove a track
    removeTrack("Song B");

    return 0;
}
