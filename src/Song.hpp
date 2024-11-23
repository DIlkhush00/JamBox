#pragma once

#include <string>
#include <SFML/Audio.hpp>

class Song
{
private:
    sf::Music source;
    size_t id;
    std::string title;
    std::string path;
    size_t duration;      // In Seconds

public:
    Song(std::string path);
    Song(std::string path, std::string title);

    void play();
    void stop();
    
    void init();    // Set duration, title, id etc.

    const size_t getDuration();
    const std::string& getTitle();
    const size_t getId();
};
