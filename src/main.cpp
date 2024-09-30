#include "CommandHandler.hpp"

int main(int argc, char **argv) {

    // Initialize the application
    CommandHandler app("JamBox");

    // Setup Commands - Subcommands, flag etc.
    app.setupCommands();

    // Parse the command and run the appropriate action
    app.parseCommands(argc, argv);

    return 0;
}