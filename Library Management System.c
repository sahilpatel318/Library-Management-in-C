#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct
{
    int bookID;
    char title[100];
    char author[100];
    int quantity;
} Book;

// Load Books
void loadBooks(FILE* file, Book books[], int* count)
{
    char line[256];
    int isFirstLine = 1; // Flag to skip the header row

    while (fgets(line, sizeof(line), file))
    {
        if (isFirstLine) // Skip the header line
        {
            isFirstLine = 0;
            continue;
        }

        // Parse the line into the book fields
        if (sscanf(line, "%d,%99[^,],%99[^,],%d",
            &books[*count].bookID,
            books[*count].title,
            books[*count].author,
            &books[*count].quantity) == 4) // Ensure all fields are read
        {
            (*count)++;
        }
        else
        {
            printf("Error reading line: %s\n", line);
        }
    }
}

// Save books to the CSV file
void saveBooks(FILE* file, Book books[], int count)
{
    fprintf(file, "Book ID,Book Name,Author Name,Quantity\n");
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d,%s,%s,%d\n",
            books[i].bookID,
            books[i].title,
            books[i].author,
            books[i].quantity);
    }
}

// Display all books
void displayBooks(Book books[], int count)
{
    printf("\n%-10s %-30s %-20s %-10s\n", "Book ID", "Title", "Author", "Quantity");
    for (int i = 0; i < count; i++)
    {
        printf("%-10d %-30s %-20s %-10d\n",
            books[i].bookID,
            books[i].title,
            books[i].author,
            books[i].quantity);
    }
}

// Add a new book
void addBook(Book books[], int* count)
{
    printf("Enter Book ID: ");
    scanf("%d", &books[*count].bookID);
    printf("Enter Title: ");
    scanf(" %[^\n]s", books[*count].title);
    printf("Enter Author: ");
    scanf(" %[^\n]s", books[*count].author);
    printf("Enter Quantity: ");
    scanf("%d", &books[*count].quantity);
    (*count)++;
    printf("Book added successfully.\n");
}

// Search for a book
void searchBook(Book books[], int count)
{
    int searchType;
    printf("Search by:\n");
    printf("1. Book ID\n");
    printf("2. Title\n");
    printf("3. Author\n");
    printf("Enter your choice: ");
    scanf("%d", &searchType);

    if (searchType == 1) // Search by Book ID
    {
        int bookID;
        printf("Enter Book ID to search: ");
        scanf("%d", &bookID);
        printf("\n%-10s %-30s %-20s %-10s\n", "Book ID", "Title", "Author", "Quantity");
        for (int i = 0; i < count; i++)
        {
            if (books[i].bookID == bookID)
            {
                printf("%-10d %-30s %-20s %-10d\n",
                    books[i].bookID,
                    books[i].title,
                    books[i].author,
                    books[i].quantity);
                return; // Exit once the book is found
            }
        }
        printf("Book not found.\n");
    }
    else if (searchType == 2 || searchType == 3) // Search by Title or Author
    {
        char query[100];
        printf("Enter search query: ");
        scanf(" %[^\n]s", query);

        printf("\n%-10s %-30s %-20s %-10s\n", "Book ID", "Title", "Author", "Quantity");
        int found = 0;
        for (int i = 0; i < count; i++)
        {
            if ((searchType == 2 && strstr(books[i].title, query)) || // Search by Title
                (searchType == 3 && strstr(books[i].author, query)))   // Search by Author
            {
                printf("%-10d %-30s %-20s %-10d\n",
                    books[i].bookID,
                    books[i].title,
                    books[i].author,
                    books[i].quantity);
                found = 1;
            }
        }
        if (!found)
        {
            printf("No books found matching the query.\n");
        }
    }
    else
    {
        printf("Invalid search type.\n");
    }
}

// Check book availability
void checkAvailability(Book books[], int count)
{
    int id;
    printf("Enter Book ID to check availability: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++)
    {
        if (books[i].bookID == id)
        {
            printf("Book: %s, Quantity: %d\n", books[i].title, books[i].quantity);
            return;
        }
    }
    printf("Book not found.\n");
}

// Delete a book
void deleteBook(Book books[], int* count)
{
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++)
    {
        if (books[i].bookID == id)
        {
            for (int j = i; j < *count - 1; j++)
            {
                books[j] = books[j + 1];
            }
            (*count)--;
            printf("Book deleted successfully.\n");
            return;
        }
    }
    printf("Book not found.\n");
}
// Display user manual
void displayManual() {
    printf("\nWelcome to the Library Management System!\n");
    printf("Here's how you can use the system:\n");
    printf("1. Display all books: View all books in the library.\n");
    printf("2. Add a new book: Add a book to the library.\n");
    printf("3. Search for a book: Search by ID, Title, or Author.\n");
    printf("4. Update book quantity: Change the quantity of a specific book.\n");
    printf("5. Save and exit: Save all changes and exit the system.\n");
    printf("Enter the number corresponding to your choice to navigate.\n");
}

int main()
{
    Book books[100];  // Array to store up to 100 books
    int count = 0;    // Current number of books
    FILE* file;

    // Load books from the CSV file
    file = fopen("library.csv", "r");
    if (file != NULL)
    {
        loadBooks(file, books, &count);
        fclose(file);
    }

    int choice = 0;
    while (choice != 6)
    {
        printf("\nLibrary Management System\n");
        printf("1. Display All Books\n");
        printf("2. Add Book\n");
        printf("3. Search Book\n");
        printf("4. Check Book Availability\n");
        printf("5. Delete Book\n");
        printf("6. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayBooks(books, count);
            break;
        case 2:
            addBook(books, &count);
            break;
        case 3:
            searchBook(books, count);
            break;
        case 4:
            checkAvailability(books, count);
            break;
        case 5:
            deleteBook(books, &count);
            break;
        case 6:
            // Save books to the CSV file
            file = fopen("library.csv", "w");
            if (file != NULL)
            {
                saveBooks(file, books, count);
                fclose(file);
            }
            printf("Data saved. Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            displayManual();
        }
    }

    return 0;
}
