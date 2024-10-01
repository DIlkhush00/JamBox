## JamBox 

🎵Play your favourite music right into your terminal🎵

> **!!! In Progress !!!**

## Description
This proeject uses following required libraries:
1. [Simple and Fast Multimedia](https://github.com/SFML/SFML) - For audio support
2. [CLI11](https://github.com/CLIUtils/CLI11) - For command line flag parsing
3. [FTXUI](https://github.com/ArthurSonzogni/FTXUI) - For creating terminal user interface

### Available Features:

1.  **Play Music**:
    
    You can play a single track or multiple music files.
    
    **Command**:
    
    `jambox play -p [path to the music file(s)]`
    
    **Example**:
    
    ```sh
    jambox play -p ../assets/sample.ogg ../assets/sample.mp3
	```
    
2.  **Repeat Your Music**:
    
    Specify the number of times you'd like the music to repeat. By default, the track will play once.
    
    **Command**:
    
    `jambox play -p [path to the audio file(s)] -l [number of repeats]`
    
    **Example**:
    
    ```sh
    jambox play -p ../assets/sample.ogg ../assets/sample.mp3 -l 3
    ```
    
3.  **Shuffle Your Playlist**:
    
    Shuffle the playlist to play tracks in random order.
    
    **Command**:
    
    `jambox play -p [path to the audio file(s)] --shuffle`
    
    **Example**:
    
    ```sh
    jambox play -p ../assets/sample.wav --shuffle
    ```

## **Goal Features:**
       
1. **Directory Play**  
   Play all audio files in a directory.

2. **Playlist Support**  
   Play a playlist.
    
3. **Playlist Management**
     
    a. Create a new playlist.
    
    b. Add songs to a playlist.
    
    c. Remove songs from a playlist.
    
    d. Delete one or more playlists.
    
    e. List available playlists.
  
    f. List all songs in a specific playlist. 	


4. **TUI support**
    An interactive terminal user interface to play your favourite tracks and playlists.

## Goal Design
The JamBox TUI will be divided into four components:
1. **Playlists**: List of available playlists. 
2. **Music Names**: Display currently playing song and queue. 
3. **Keyboard Shortcuts**: Quick glance to common commands.
4. **Music Player**: Basic UI for playback.
	 
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
That's great if you want to contribute! Please take a look at this project's [CONTRIBUTING GUIDELINES](https://github.com/DIlkhush00/JamBox/blob/master/CONTRIBUTING.md) and feel free to raise your PR!

## License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for more details.
