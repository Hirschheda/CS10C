#ifndef __PLAYLISTNODE_H__
#define __PLAYLISTNODE_H__

using namespace std;

class PlaylistNode
{
    public:
    PlaylistNode();
    PlaylistNode(string ,string ,string ,int );
    void InsertAfter(PlaylistNode* ); //(1 pt)
    void SetNext(PlaylistNode* ); //- Mutator (1 pt)
    string GetID() const; //- Accessor
    string GetSongName() const; //- Accessor
    string GetArtistName() const; //- Accessor
    int GetSongLength() const; //- Accessor
    PlaylistNode* GetNext() const; //- Accessor
    void PrintPlaylistNode() const;
    private:
    string uniqueID;// - Initialized to "none" in default constructor
    string songName;// - Initialized to "none" in default constructor
    string artistName;// - Initialized to "none" in default constructor
    int songLength;// - Initialized to 0 in default constructor
    PlaylistNode* nextNodePtr;// - Initialized to 0 in default constructor 
};

#endif