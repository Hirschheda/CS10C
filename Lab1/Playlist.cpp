#include <iostream>
#include "Playlist.h"
using namespace std;

PlaylistNode::PlaylistNode() {
    uniqueID="none";
    songName="none";
    artistName="none";
    songLength=0;
    nextNodePtr=nullptr;
}

PlaylistNode::PlaylistNode(string ID, string song, string artist, int length) {
    uniqueID=ID;
    songName=song;
    artistName=artist;
    songLength=length;
    nextNodePtr=nullptr;
}

string PlaylistNode::GetID() const {
    return uniqueID;
}

string PlaylistNode::GetSongName() const {
    return songName;
}

int PlaylistNode::GetSongLength() const {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr;
}

string PlaylistNode::GetArtistName() const {
    return artistName;
}

void PlaylistNode::PrintPlaylistNode() const {
    cout<<"Unique ID: "<<uniqueID<<endl;
    cout<<"Song Name: "<<songName<<endl;
    cout<<"Artist Name: "<<artistName<<endl;
    cout<<"Song Length (in seconds): "<<songLength;
}

void PlaylistNode::SetNext(PlaylistNode* add) {
    nextNodePtr=add;
}

void PlaylistNode::InsertAfter(PlaylistNode* curr) {
        curr->SetNext(GetNext());
        SetNext(curr);
}