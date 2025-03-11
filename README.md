# TerminalNote

TerminalNote is a powerful note-taking application designed for the terminal. This application allows users to create, manage, and organize their notes efficiently using a command-line interface.

## Features

- Create new notes with titles and detailed information.
- Organize notes into different books.
- View all notes or specific notes by ID.
- Delete notes or entire books.
- Handle large volumes of notes with ease.

## How It Was Made

TerminalNote was developed using the C programming language, leveraging various libraries and techniques to ensure robust functionality and performance. The application was built with a focus on efficiency, user experience, and scalability.

### Methods Used

- **File I/O**: Utilized `fopen`, `fclose`, `fread`, `fwrite`, and `remove` for file operations.
- **Dynamic Memory Allocation**: Used `malloc` and `free` for managing dynamic memory.
- **String Manipulation**: Employed various string functions such as `strcpy`, `strcmp`, and custom string concatenation functions.
- **Time and Date Handling**: Implemented functions to capture and display the current time and date for each note.
- **Custom Data Structures**: Designed structures for notes (`Note`) and books (`DB`) to organize and manage data efficiently.
- **Error Checking**: Included checks for file existence, memory allocation success, and other potential errors.

## Getting Started

To get started with TerminalNote, follow these steps:

1. **Clone the Repository**:
    ```sh
    git clone https://github.com/yourusername/TerminalNote.git
    cd TerminalNote
    ```

2. **Compile the Application**:
    ```sh
    gcc -o tnote main.c -Iheaders
    ```

3. **Run the Application**:
    ```sh
    ./tnote
    ```

## Usage

Here are some basic commands to use TerminalNote:

- **Create a New Note**:
    ```sh
    ./terminalnote note "Title" : "Detailed information about the note"
    ```

- **View All Notes**:
    ```sh
    ./terminalnote show
    ```

- **Delete a Note by ID**:
    ```sh
    ./terminalnote remove 1
    ```

- **Create a New Book**:
    ```sh
    ./terminalnote newbook "BookName"
    ```

- **Open a Book**:
    ```sh
    ./terminalnote openbook "BookName"
    ```

- **Delete a Book**:
    ```sh
    ./terminalnote destroybook "BookName"
    ```

## Conclusion

TerminalNote is a testament to the power and flexibility of C programming, showcasing efficient file handling, robust data structures, and a user-friendly command-line interface. This project highlights the ability to create efficient and user-friendly software solutions for the terminal.

Feel free to explore the code and contribute to the project!