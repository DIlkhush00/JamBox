#pragma once

#include <CLI/CLI.hpp>

struct PlayOptions {
    std::vector<std::string> songs; // List of all the songs
};

class CommandHandler
{
private:
    CLI::App app;
    PlayOptions playOptions;

public:
    CommandHandler(const std::string& description); // Set the project description

    void setupCommands();                           // Setup all subcommands and flags
    void parseCommands(int argc, char **argv);      // Parse the given command

    void runPlay();                                 // Callback function for 'play' subcommand. Plays the audio file(s).
};  
