#pragma once

#include "Song.hpp"
#include <vector>

class Playlist
{
private:
    std::vector<std::shared_ptr<Song>> songs;  

public:
    void init(const std::string& playlistName); // Creates a directory with playlist's name
    void addSong(std::shared_ptr<Song> song);   // Add song to playlist
    void removeSong(const size_t songId);       // Remove song from playlist
};