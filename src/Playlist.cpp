#include "Playlist.hpp"
#include <filesystem>
#include <iostream>
#include <regex>

void Playlist::init(const std::string& playlistName)
{
    // Check if playlistName contains invalid characters
    std::regex validNameRegex("^[a-zA-Z0-9_-]+$"); // Allow only alphanumeric, _, and -
    if (!std::regex_match(playlistName, validNameRegex)) {
        std::cerr << "Invalid playlist name. Only alphanumeric characters, underscores, and hyphens are allowed.\n";
        return;
    }

    std::filesystem::path currentDir = std::filesystem::current_path();
    std::filesystem::path dirPath = currentDir / playlistName;

    try {
        if (std::filesystem::create_directory(dirPath)) {
            std::cout << "Playlist created: " << std::endl;
        } else {
            std::cerr << "Failed to create playlist. It might already exist: " << dirPath << std::endl;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error creating playlist: " << e.what() << std::endl;
    }

}

void Playlist::addSong(std::shared_ptr<Song> song)
{
    songs.push_back(song);
}

void Playlist::removeSong(const size_t idToRemove)
{
    size_t initialSize = songs.size();

    songs.erase(
        std::remove_if(songs.begin(), songs.end(), 
            [idToRemove](const std::shared_ptr<Song>& song) {
                return song->getId() == idToRemove;
            }),
        songs.end()
    );

    if(songs.size() < initialSize)
    {
        std::cout << "Song successfully removed!" << std::endl;
    }
    else
    {
        std::cerr << "Song not found!" << std::endl;
    }
}