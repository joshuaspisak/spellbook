# Wizard Spellbook Management System

## Description

The Wizard Spellbook Management System is a program that allows users to manage information about wizards, spellbooks, and spells. It provides functionalities for authentication, searching, and printing information based on various criteria.

## Features

- User authentication: The program requires a valid login to access the system. Incorrect credentials will result in termination after three attempts.
- Searching and Printing: Users can search for spellbooks by name, filter spellbooks by page limit, and search for spells by their effect. The program ensures that students do not have access to information on spells involving poison or death.
- File Handling: Users can specify an output file to redirect the program's output, and the information can be appended to that file.
- Dynamic Arrays and Structs: The program utilizes dynamic arrays of structs to store information about wizards, spellbooks, and spells.
- File Separation: The program consists of a makefile, an application (.cpp) file, a header (.h) file, and an implementation (.cpp) file.

## Usage

1. Run the program and provide the filenames for the wizards' information and spell information when prompted.
2. Enter valid credentials to access the system. After three incorrect attempts, the program will terminate.
3. Choose the desired functionality:
   - Search and display spellbooks by name
   - Filter spellbooks by page limit and display them
   - Search and display spells by effect
   - Redirect the output to a specific file
   - Exit the program
4. Follow the on-screen instructions to navigate through the program's functionalities.
5. When finished, exit the program.

## Installation

1. Clone the repository or download the source code files.
2. Ensure that you have a C++ compiler installed on your system.
3. Open a terminal or command prompt and navigate to the project directory.
4. Compile the program using the provided makefile.
5. Run the compiled executable.

## Dependencies

- C++ compiler (e.g., g++)
- make (build tool)

## File Structure

- `Makefile`: Build automation file.
- `main.cpp`: Main application file.
- `wizard.h`: Header file containing struct and function prototypes related to wizards.
- `wizard.cpp`: Implementation file for wizard-related functions.
- `spellbook.h`: Header file containing struct and function prototypes related to spellbooks.
- `spellbook.cpp`: Implementation file for spellbook-related functions.
- `spell.h`: Header file containing struct and function prototypes related to spells.
- `spell.cpp`: Implementation file for spell-related functions.
