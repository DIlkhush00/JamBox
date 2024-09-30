#include "CommandHandler.hpp"
#include <SFML/Audio.hpp>

CommandHandler::CommandHandler(const std::string &description)
    : app{description} {}


void CommandHandler::setupCommands()
{
    auto play = app.add_subcommand("play", "Play song(s)");
    play->add_option("--play, -p", playOptions.songs, "Path to audio file(s), file1 file2")->required()->ignore_case();

    play->callback([this]() { runPlay(); });

}

void CommandHandler::parseCommands(int argc, char **argv) {
    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        app.exit(e);
    }
}

void CommandHandler::runPlay()
{
    for (auto &song : playOptions.songs)
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
