#pragma once

#include <string>
#include <SFML/Audio.hpp>

class Music
{
private:
    sf::Music music;
    unsigned int id;
    std::string title;
    std::string path;
    unsigned int duration;      // In Seconds

public:
    Music(std::string path);
    Music(std::string path, std::string title);

    void play();
    void stop();
    
    void init();    // Set duration, title, id etc.

    void getDuration();
    void getTitle();
};
