## JamBox 

🎵Play your favourite music right into your terminal🎵

> **!!! In Progress !!!**

## Description
This proeject uses following required libraries:
1. [Simple and Fast Multimedia](https://github.com/SFML/SFML) - For audio support
2. [CLI11](https://github.com/CLIUtils/CLI11) - For command line flag parsing
3. [FTXUI](https://github.com/ArthurSonzogni/FTXUI) - For creating terminal user interface


## **Goal Features:**

1. **Quick Play**  
    Play a single audio file.
    - Commands:
    	- `jambox --play audio.format`
     	- `jambox -p audio`
       
2. **Directory Play**  
   Play all audio files in a directory.
    - Commands:
    	- `jambox --play-dir path_to_directory`
     	- `jambox -pd path_to_directory`

3. **Play a Playlist**  
   Play a playlist.
   
    - Commands:
    	- `jambox --play-playlist playlist_name`
     	- `jambox -pl playlist_name`
    
    
5. **Playlist Management**
    
    4a. **Create Playlist**  
    Create a new playlist.
   
    - Commands:
    	- `jambox --add-playlist playlist_name`
     	- `jambox --add-pl playlist_name`
    
    4b. **Add Songs**  
    Add songs to a playlist.
   
    - Commands:
    	- `jambox playlist_name --add song1 song2`
     	- `jambox playlist_name --add path_to_directory`
    
    4c. **Remove Songs**  
    Remove songs from a playlist.
   
    - Commands:
    	- `jambox playlist_name --remove song1 song2`
     	- `jambox playlist_name -rm song1 song2`
    
    4d. **Delete Playlist**  
    Delete one or more playlists.
   
    - Commands:
    	- `jambox --delete playlist1 playlist2`
     	- `jambox -d playlist1 playlist2`
    
    4e. **Show Playlists**  
    List available playlists.
   
    - Commands:
    	- `jambox --playlists`
     	- `jambox -pl`
    
    4f. **Show Songs in Playlist**  
    List all songs in a specific playlist.
   
    - Commands:
    	- `jambox --list playlist_name`
     	- `jambox -l playlist_name`
  
6. **Loop and Shuffle**
   Loop a song or playlist `n` times (default value of `n` is 1). Shuffle over a playlist by adding `-sf` flag.
   
   - Commands:
   	- `jambox -p audio -l n`
   	- `jambox -pl playlist_name -l n`
   	- `jambox -pl playlist_name -sf`
		

7. **Help**  
   Show all available commands.
    
    - Commands:
    	- `jambox --help`
     	- `jambox -h`

8. **TUI support**
   To play a song or playlist in an interactive terminal user interface, add `-tui` flag.

   - Commands:
   	- `jambox -tui -p audio`
   	- `jambox -tui -pl playlist_name`




## Goal Design
The JamBox TUI will be divided into four components:
1. **Playlists**: List of available playlists. 
2. **Music Names**: Display currently playing song and queue. 
3. **Keyboard Shortcuts**: Quick glance to common commands.
4. **Music Player**: Display status of the current playing music.
	 
Below is a basic design outline of the terminal interface: ![JamBox Design](./assets/JamBox%20Design.png)

> Design created using [Excalidraw](https://excalidraw.com/).

## Build and Run
**Prerequisites**:
- **CMake** (version 3.1 or higher) 
- **C++ compiler** that supports C++11 or higher (e.g., GCC, Clang)

### Build Instructions
1. Clone the repository.
	```sh 
	git clone https://github.com/your-username/JamBox.git
	cd JamBox
	```
2. Create a build directory.
	`mkdir build && cd build`
		
3. Build the application.
	    ```sh
	    cmake ..
	    make
		```
		
4. Run the application.
	`./jambox [options]`
	For example: `./jambox --help`
	> You can use sample audio from the [assets](./assets) directory to test the application. Credits for sample audio: [file-examples](https://file-examples.com/)


## Contributing
That's great if you want to contribute! Please take a look at this project's (CONTRIBUTING GUIDELINES)[https://github.com/DIlkhush00/JamBox/blob/master/CONTRIBUTING.md] and feel free to raise your PR!

## License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for more details.
