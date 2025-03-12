# 📖 TerminalNote - Terminal Note Manager  
*Organize your ideas efficiently: Persistent note system with intuitive CLI interface*

![Application Demo](https://raw.githubusercontent.com/llromerorr/TerminalNote/refs/heads/master/resource/preview.gif)

## 🚀 Main Features
- **Book system**: Organize notes into different categories
- **Data persistence**: Storage in binary files
- **Colorful interface**: Support for text formatting and ANSI colors
- **Cross-platform**: Compatible with Windows and Linux
- **Intuitive commands**: UNIX-style syntax with self-documentation
- **Advanced management**:
  - Search and delete notes
  - Usage statistics
  - Warning system for full books

## 🧩 Project Structure
```
src/
├── headers/
│   ├── app.h          // Main application logic
│   ├── note.h         // Note structure and manipulation
│   ├── database.h     // Persistent storage system
│   ├── console.h      // User interface utilities
│   ├── date.h         // Date and time handling
│   ├── terminalnote.h // Component integration point
│   └── textformat.h   // ANSI codes for text formatting
├── main.c             // Main entry point
└── (Build system)
```

## 🛠️ Key Technologies
- **Language**: C11 (Full standard compatibility)
- **Libraries**:
  - Standard I/O (file management)
  - Time.h (date/time handling)
  - String.h (string manipulation)
- **Paradigms**:
  - Modular programming
  - Manual memory management
  - Conversational interface (REPL)
- **Persistence**:
  - Structured binary files
  - Book system with metadata
  - Data recovery in case of failures

## 🔧 Compilation and Execution
1. **Requirements**:
   - C Compiler (GCC or Clang)
   - Linux/Windows system (native support)

2. **Compile project**:
```bash
gcc main.c -o tnote -Wall -Wextra -pedantic
```

3. **Run**:
```bash
./tnote
```

## 🎮 Available Commands
```bash
# Basic operations
note "Title : Content"  # Create new note
show [id|book]          # Show notes
delete <id>             # Delete note

# Book management
new <book_name>         # Create new book
open <book>             # Change active book
destroy                 # Delete current book

# Utilities
clear                   # Clear screen
help                    # Show help
exit                    # Exit the program
```

## 📌 Improvement Roadmap
- [ ] Full-text search system
- [ ] Export to Markdown/PDF format
- [ ] Support for tags/categories
- [ ] Portable mode (USB configuration)
- [ ] Integration with external editors

---

🧑💻 **Lead Developer**:  
[@llromerorr](https://github.com/llromerorr) from Venezuela 🇻🇪

🔐 **License**:  
MIT License - Free for use and modification 📖 TerminalNote - Organize notes into different categories