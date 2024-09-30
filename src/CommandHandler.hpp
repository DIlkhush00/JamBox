#pragma once

#include <CLI/CLI.hpp>

struct PlayOptions {
    std::vector<std::string> songs; // List of all the songs
    uint16_t loop{1};               // Looping
    bool shuffle{false};            // Shuffle
};

enum Action {
    PlayMusic,
};

class CommandHandler
{
private:
    CLI::App app;
    std::shared_ptr<PlayOptions> playOptions;

public:
    CommandHandler(const std::string& description); // Set the project description

    void setupCommands();                           // Setup all subcommands and flags
    void parseCommands(int argc, char **argv);      // Parse the given command

    void handlePlay(CLI::App const* play);          // Callback function for 'play' subcommand. Plays the audio file(s).
    void handleAction(Action action);               // Handles actions like playing song(s)
    void shuffle();          // Shuffles Music list
};  
