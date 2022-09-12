#include <iostream>
#include "Playlist.h"
using namespace std;

void PrintMenu(string);

int main() {
    string title;
    char input = 'n';

    PlaylistNode* head = nullptr;
    PlaylistNode* tail = nullptr;
    PlaylistNode* curr = nullptr;

    string inputID;
    string inputSong;
    string inputName;
    int inputLength;

    cout << "Enter playlist's title:" << endl;
    getline(cin, title);
    cout << endl;

                                // int loopCount = 0;
    while (input != 'q') { //Quit
        PrintMenu(title);
                                // cout << endl << input;
        cin >> input;
        cin.ignore();
                                // cout << endl << input << endl;
                                // cout << "Loop count: " << loopCount << endl;
                                // loopCount = loopCount + 1;
        curr = head;

        if (input == 'a') { //Add song

            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin, inputID);
            cout << "Enter song's name:" << endl;
            getline(cin, inputSong);
            cout << "Enter artist's name:" << endl;
            getline(cin, inputName);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> inputLength;
            cout << endl;
                                        // cout << "5" << endl;

            PlaylistNode* newSong = new PlaylistNode(inputID, inputSong, inputName, inputLength);

            if (head == nullptr) {
                head = newSong;
                tail = head;
                                    // cout << "6" << endl;
            }
            else {
                tail->SetNext(newSong);
                tail = newSong;
                                    // cout << "7" << endl;
            }
        }

        else if (input == 'd') { //Remove song
            PlaylistNode* prev = head;
            
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin,inputID);

            while (curr->GetID()!=inputID) {
                prev = curr;
                curr=curr->GetNext();
            }

            if (curr == head) {
                head = curr->GetNext();
            }
            if (curr == tail) {
                tail = prev;
            }

            prev->SetNext(curr->GetNext()); //removes the node from the list
            cout<<'"'<<curr->GetSongName()<<"\" removed."<< endl<< endl;
            delete curr;
        }

        else if (input == 'c') { //Change position of song
            int OldPos = 0;
            int NewPos = 0;
            int count = 1;
            PlaylistNode* temp = head;
            PlaylistNode* prev = head;

            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> OldPos;
            cout << "Enter new position for song:" << endl;
            cin >> NewPos;

            //find the moving node in the list and hold the previous
            count = 1;
            while (count != OldPos) {
                prev = curr;
                curr = curr->GetNext();
                count++;
            }
            //find the new spot
            temp = head;
            count = 1;
            while (count < NewPos-1) {
                temp = temp->GetNext();
                count++;
            }
            //remove the node from the list and update tail/head            
            if (curr == head) {
                head = curr->GetNext();   
            }
            else if (curr == tail) {
                tail = prev;
                prev->SetNext(nullptr);
            }
            else {
                prev->SetNext(curr->GetNext());
            }
            //add node back in and update tail/head
            if (NewPos == 1) {
                curr->SetNext(head);
                head = curr;
            }
            else {
                if (OldPos < NewPos) {
                    temp = temp->GetNext();
                    temp->InsertAfter(curr);
                }
                else {
                    temp->InsertAfter(curr);
                    if (temp == tail) {
                        tail = curr;
                    }
                }
            }

            cout << '"' << curr->GetSongName() << '"' << " moved to position " << NewPos << endl; //Check how this can be done, I think the work he did needs to be in main
            cout << endl;
        }

        else if (input == 's') { //Output songs by specific artist
            int n = 1;

            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            getline(cin, inputName);

            while (curr != nullptr) {
                if (curr->GetArtistName() == inputName) {
                    cout << endl << n << "." << endl;
                    curr->PrintPlaylistNode();
                    cout << endl;
                }
                curr = curr->GetNext();
                n++;
            }
            cout << endl;
        }

        else if (input == 't') { //Output total time of playlist (in seconds)
            int total = 0;

            while (curr != nullptr) {
                total = total + curr->GetSongLength();
                curr=curr->GetNext();
            }
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            cout << "Total time: " << total << " seconds" << endl<< endl;
        }

        else if (input == 'o') { //Output full playlist
            cout << title << " - OUTPUT FULL PLAYLIST";
            int n = 1;

            if (head == nullptr) {
                cout << endl << "Playlist is empty" << endl;
            }
            else {
                while (curr != nullptr) {
                    cout << endl << n << "." << endl;
                    curr->PrintPlaylistNode();
                    n++;
                    curr = curr->GetNext();
                    cout << endl;
                }
            }
            cout << endl;
        }
    }
    return 0;
}


void PrintMenu(string title) {
    cout << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl << "Choose an option:" << endl;
} 