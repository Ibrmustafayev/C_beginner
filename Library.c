#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char title[50];
    char author[50];
    int year;
    int rating;
} Books;

void add_book(Books books[20], int *book_count);
void search_by_title(Books books[20], int book_count);
void display_all(Books books[20], int book_count);
void display_by_rating(Books books[20], int book_count);
void display_by_year(Books books[20], int book_count);
void top_rated(Books books[20], int book_count);
int in(int list[], int size, int idx);

int main(){
    int choice, book_count = 0;
    Books books[20];

    while (1) {
        printf("=== Library Menu ===\n1. Add book\n2. Search book by title\n3. Display all books\n4. Display books sorted by rating\n5. Display books sorted by year\n6. Top rated book\n7. Exit");
        printf("\n\nChoice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        if (choice == 7) {
            printf("Goodbye!!!");
            break;
        } else if (choice == 1) {
            add_book(books, &book_count);
        } else if (choice == 2) {
            search_by_title(books, book_count);
        } else if (choice == 3) {
            display_all(books, book_count);
        } else if (choice == 4) {
            display_by_rating(books, book_count);
        } else if (choice == 5){
            display_by_year(books, book_count);   
        } else if (choice == 6) {
            top_rated(books, book_count);
        } else {
            printf("Invalid choice!!!");
        }
    }

    return 0;
}

void add_book(Books books[20], int *book_count) {
    char title[50], author[50];
    int year, rating;
    printf("\nTitle: ");
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = '\0';
    printf("Author: ");
    fgets(author, 50, stdin);
    author[strcspn(author, "\n")] = '\0';
    printf("Year: ");
    scanf("%d", &year);
    while (1) {
        printf("Rating (1-5): ");
        scanf("%d", &rating);
        if (rating >= 1 && rating <= 5) {
            break;
        }
    }
    Books book;
    strcpy(book.title, title);
    strcpy(book.author, author);
    book.year = year;
    book.rating = rating;
    books[*book_count] = book;
    (*book_count)++;
    printf("\nThe book successfully added!\n\n");
}

void search_by_title(Books books[20], int book_count) {
    char target_title[50];
    bool found = false;
    printf("\nEnter the searched title: ");
    fgets(target_title, 50, stdin);
    target_title[strcspn(target_title, "\n")] = '\0';
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].title, target_title) == 0) {
            printf("\n%d)Title: %s\n  Author: %s\n  Year: %d\n  Rating: %d\n\n", i + 1, books[i].title, books[i].author, books[i].year, books[i].rating);
            found = 1;
        }
    }
    if (!(found)) printf("\nNo book found with that title.\n\n");
}

void display_all(Books books[20], int book_count) {
    for (int i = 0; i < book_count; i++) {
        printf("\n%d)Title: %s\n  Author: %s\n  Year: %d\n  Rating: %d\n\n", i + 1, books[i].title, books[i].author, books[i].year, books[i].rating);
    }
}

void display_by_rating(Books books[20], int book_count) {
    int sorted_idx[book_count], j = 0;
    while (j < book_count) {
        int max_ = 0;
        while (in(sorted_idx, j, max_)) max_++;
        for (int i = 0; i < book_count; i++) {
            if (books[i].rating > books[max_].rating && !in(sorted_idx, j, i)) {
                max_ = i;
            }
        }
        sorted_idx[j] = max_;
        j++;
    }
    for (int i = 0; i < book_count; i++) {
        printf("\n%d)Title: %s\n  Author: %s\n  Year: %d\n  Rating: %d\n\n", i + 1, books[sorted_idx[i]].title, books[sorted_idx[i]].author, books[sorted_idx[i]].year, books[sorted_idx[i]].rating);
    }
}

int in(int list[], int size, int idx) {
    for (int i = 0; i < size; i++) {
        if (idx == list[i]) {
            return 1;
        }
    }
    return 0;
}

void display_by_year(Books books[20], int book_count) {
    int sorted_idx[book_count], j = 0;
    while (j < book_count) {
        int max_ = 0;
        while (in(sorted_idx, j, max_)) max_++;
        for (int i = 0; i < book_count; i++) {
            if (books[i].year > books[max_].year && !in(sorted_idx, j, i)) {
                max_ = i;
            }
        }
        sorted_idx[j] = max_;
        j++;
    }
    for (int i = 0; i < book_count; i++) {
        printf("\n%d)Title: %s\n  Author: %s\n  Year: %d\n  Rating: %d\n\n", i + 1, books[sorted_idx[i]].title, books[sorted_idx[i]].author, books[sorted_idx[i]].year, books[sorted_idx[i]].rating);
    }
}

void top_rated(Books books[20], int book_count) {
    int sorted_idx[book_count], j = 0;
    while (j < book_count) {
        int max_ = 0;
        while (in(sorted_idx, j, max_)) max_++;
        for (int i = 0; i < book_count; i++) {
            if (books[i].rating > books[max_].rating && !in(sorted_idx, j, i)) {
                max_ = i;
            }
        }
        sorted_idx[j] = max_;
        j++;
    }
    printf("\nTitle: %s\n  Author: %s\n  Year: %d\n  Rating: %d\n\n", books[sorted_idx[0]].title, books[sorted_idx[0]].author, books[sorted_idx[0]].year, books[sorted_idx[0]].rating);
}