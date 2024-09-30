#include "CommandHandler.hpp"
#include <SFML/Audio.hpp>
#include <algorithm>
#include <random>

CommandHandler::CommandHandler(const std::string &description)
    : app{description} {}

// Setup subcommands and their options/flags
void CommandHandler::setupCommands()
{
    playOptions = std::make_shared<PlayOptions>();

    auto *play = app.add_subcommand("play", "Play song(s)");
    play->add_option("--play, -p", playOptions->songs, "Path to audio file(s), file1 file2")->required()->ignore_case();
    play->add_option("--loop, -l", playOptions->loop, "Number of times you want to repeat. By default it's set to 1.");
    play->add_flag("--shuffle", playOptions->shuffle, "Shuffle");

    play->callback([this, play]() { handlePlay(play); });
}

void CommandHandler::parseCommands(int argc, char **argv) {
    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        app.exit(e);
    }
}

// Decides which action to take
void CommandHandler::handlePlay(CLI::App const* play)
{
    bool playFlag = app.got_subcommand(play);
    
    if(playFlag)
    {
        handleAction(Action::PlayMusic);
    }
}

// Decides what action to take
void CommandHandler::handleAction(Action action)
{
    // Checks if shuffling is needed
    if(playOptions->shuffle)
    {
        shuffle();
    }

    if(action == Action::PlayMusic)
    {
        while (playOptions->loop--)
        {
            std::cout << "Will loop " << playOptions->loop << " more times." << std::endl;
            for (auto &song : playOptions->songs)
            {
                sf::Music music;

                if (!music.openFromFile(song))
                {
                    std::cout << "Error in playing the audio file: " << song << ". Check the path." << std::endl;
                    continue;
                }

                std::cout << "Currently playing: " << song << std::endl;
                music.play(); 

                while (music.getStatus() == sf::SoundSource::Status::Playing)
                {
                    sf::sleep(sf::milliseconds(100));
                }

                std::cout << "Finished playing: " << song << std::endl;
            }

            std::cout << "All songs finished playing." << std::endl;
        }
    }  
}

void CommandHandler::shuffle()
{
    auto reng = std::default_random_engine {};
    std::shuffle(std::begin(playOptions->songs), std::end(playOptions->songs), reng);
}