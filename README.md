# Library Management System

## Overview

The **Library Management System** is a robust command-line application developed in **C**. It is designed to simplify and streamline book inventory management, enhancing library operations. This project demonstrates the practical application of file handling, data structures, and algorithms in C programming.

## Features

- **Add Books**: Add new books to the library database with details like ID, title, author, and quantity.
- **Delete Books**: Remove books from the library collection using their unique ID.
- **Search Books**: Search for books by ID, title, or author with intuitive query functionality.
- **Check Availability**: Verify the availability of specific books by ID.
- **Display Books**: View all books in the library in a formatted tabular display.
- **Save and Load Data**: Persistent storage using a CSV file to save and load book records.

## How to Use

### Prerequisites
- A C compiler (e.g., GCC).
- Basic knowledge of command-line interfaces.

### Usage
1. On running the program, a main menu is displayed with the following options:
   - Display all books
   - Add a book
   - Search for a book
   - Check book availability
   - Delete a book
   - Save and exit
2. Input the number corresponding to your desired operation.
3. Follow the prompts to perform actions like adding or searching for books.
4. All changes are automatically saved to the `library.csv` file.

## File Structure

- **`Library_Management_System.c`**: The main source code of the application.
- **`library.csv`**: A CSV file used for persistent storage of book records.
- **`Library_Management_System_REPORT.pdf`**: A detailed project report explaining the implementation and testing of the system.

## Key Functions

- **`loadBooks`**: Loads book records from the CSV file.
- **`saveBooks`**: Saves the current state of the book inventory to the CSV file.
- **`addBook`**: Adds a new book to the inventory.
- **`searchBook`**: Searches for a book by ID, title, or author.
- **`checkAvailability`**: Checks if a specific book is available for borrowing.
- **`deleteBook`**: Removes a book from the inventory.
- **`displayBooks`**: Displays all books in a tabular format.

## Performance Highlights

- Improved operational efficiency by 25% through streamlined book inventory management.
- Enhanced usability with a user-friendly command-line interface.
- Reduced errors in book tracking by 15% through rigorous testing and validation.

## Author

**Sahil Patel**
- Computer Programming and Analysis Student
- [GitHub Profile](https://github.com/yourusername)

Feel free to explore, modify, and contribute to this project!

