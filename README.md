# VIBIN PROJECT

**Project Description:** Vibin Studio is a software application that enables users to play and manage their music files on a computer. The software offers a range of features including the ability to play various audio formats, manage playlists, control playback options, and customize audio effects. Additionally, the Vibin Studio has a user-friendly interface that is easy to navigate and allows users to access and control their music library quickly.

## TABLE OF CONTENT
- _**Contributor**_
- _**Usage**_
- _**Features**_
- _**Class Diagram**_
- _**External Libraries**_

## CONTRIBUTOR
- **Kasitphoom Thowongs**
- **Phupa Denphatcharangkul**
- **Pitiphong Kitrueangphatchara**

## USAGE
_**REQUIREMENT:**_
- **C++ 17+**
- **CMake 3.5+**
- **Qt 6+**

1. Clone the repository
```bash
git clone https://github.com/Kasitphoom/Audio_EQ.git
```
2. Startup QtCreator
3. Open the project
4. Build the project
5. Run the project

## FEATURES
<u></u>**Audio formats:**</u> Plays various audio formats, including MP3, WAV, FLAC, and more.
<u>**Audio file imports:**</u> Allows users to import audio files.
<u>**Audio folder import:**</u> Allow users to import folders which contain audio files to play like music playlists.
<u>**Controls:**</u> Provides control over playback options such as play/pause, shuffle, previous and next.
<u>**Interface:**</u> Displays song information and time stamp bar for an enhanced listening experience.
<u>**Customizable Interface:**</u> Allow users to change theme and language of the application
<u>**Playlist:**</u> Show lists of songs in the folder to select and plays
<u>**Themes:**</u> Users can change themes inside the application.
<u>**Bilingual**</u>: We provided both Thai and English user interface.
<u>**Scrolling Song Name**</u>: Long song name will be scrolled to be able to fully display.

## CLASS DIAGRAM
![Class Diagram](/ClassDiagram.png)

## EXTERNAL LIBRARIES
- *QtCore*
    - QCoreApplication
- *QtWidgets*
    - QListWidgetItems
    - QFileDialog
    - QMessageBox
    - QMainWindows
    - QApplication
- *QtMultimedia*
    - QAudioDevice