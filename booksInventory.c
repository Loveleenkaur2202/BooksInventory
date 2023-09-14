/*************************************************************
 * Loveleen @lasalle
 * final 2132413
 ************************************************************/

#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct book{
    long long int ISBN;
    char Title[70];
    char Author[70];
    char Publisher[70];
    char Genre[30];
    int Year_of_publication;
    int Selling_price;
    int Stock;
} book;

book books[500] = {
                    {97815420,"The Girl In Room 105", "Chetan Bhagat", "Westland Books", "Mystery, Thriller", 2018, 13, 11},
                    {97815011, "It Ends With Us", "Colleen Hoover", "Atria Books", "Romance", 2016, 15, 8},
                    {95712243,"Strangers", "Taichi Yamada", "Vertical", "Fiction, Ghost", 2003, 53, 15},
                    {21474836, "Gitanjali", "Rabindranath Tagore", "India Society", "Poem", 1910,50, 6}

                };

int k = 4; //to keep track of number of books

void add_books();
char add_another();
void search_book();
void search_by_title();
void search_by_author();
void search_by_genre();
void search_by_publisher();
void search_by_isbn();
void process_transaction(int i);
void return_book(int i);
void purchase_book(int i);
void delete_book();
void display_books();
void print_books(int);
int end_program();



int main(){


    int choice,i;

    printf("****MAIN MENU****\n\n");
    printf("****select one of the options****\n");

    
    printf("1. Populate the inventory\n");
    printf("2. Search by Keyword\n");
    printf("3. Process a transaction\n");
    printf("4. Delete a book record\n");
    printf("5. Display all the books in the inventory\n");
    printf("6. Exit the system\n");

    do{
        printf("Please Enter your Choice: \n");
        scanf("%d", &choice);
    }while(choice<1 || choice>6);
    
    switch(choice){
        case 1: 
            add_books();
            break;
        case 2:
            search_book();
            break;
        case 3: 
            process_transaction(i);
            break;
        case 4: 
            delete_book();
            break;
        case 5: 
            display_books();
            break;
        case 6: 
            end_program();
            break;
        }
    
    return 0;

}


void add_books(){

    system("cls");
    
    printf("****ADD NEW BOOK****\n");

    for(int i=k; i<500; i++){
        if(i==500){
            printf("No more books can be added.\n");
            main();
            break;
        }

        printf("Enter the details to add new book: \n");

        printf("ISBN : \n");
        fflush(stdin);
        scanf("%ld", &books[i].ISBN);

        printf("Title : \n");
        fflush(stdin);
        scanf("%s", &books[i].Title);

        printf("Author : \n");
        fflush(stdin);
        scanf("%s", &books[i].Author);

        printf("Publisher : \n");
        fflush(stdin);
        scanf("%s", &books[i].Publisher);

        printf("Genre : \n");
        fflush(stdin);
        scanf("%s", &books[i].Genre);

        printf("Year of Publication : \n");
        fflush(stdin);
        scanf("%d", &books[i].Year_of_publication);

        printf("Selling Price : \n");
        fflush(stdin);
        scanf("%d", &books[i].Selling_price);
        
        printf("Stock: \n");
        fflush(stdin);
        scanf("%d", &books[i].Stock);

        k++; 

        add_another();

    }
}

char add_another(){

    char add_another;

    do{
        printf("do you want to add another book?(y/n): \n");
        fflush(stdin);
        scanf("%c", &add_another);
    }while(!(add_another == 'y' || add_another == 'n'));

    if(add_another == 'n'){
        main();
    }
    else if(add_another == 'y'){
        add_books();
    }
        
    return add_another;

}
    

void display_books(){
    
    printf("Books Details\n");

    for(int i=0; i<k; i++){
        printf("*************************************************\n");
        printf("Book %d\n",i+1);
        print_books(i);
        printf("*************************************************\n");
    }

    printf("\t\n");

    main();

}

void print_books(int i){

    printf("ISBN : %ld\n", books[i].ISBN);
    printf("Title : %s\n", books[i].Title);
    printf("Author : %s\n", books[i].Author);
    printf("Publisher : %s\n", books[i].Publisher);
    printf("Genre : %s\n", books[i].Genre);
    printf("Year of Publication : %d\n", books[i].Year_of_publication);
    printf("Selling Price : $%d\n", books[i].Selling_price);
    printf("Amount in Stock : %d\n", books[i].Stock);
    
}

void search_book(){

    int choice;

    printf("****SEARCH MENU****\n");
    printf("****select one of the options****\n");

    
    printf("1. Search by Title\n");
    printf("2. Search by Author\n");
    printf("3. Search by Genre\n");
    printf("4. Search by Publisher\n");
    printf("5. Search by ISBN\n");
    
    
    do{
        printf("Please Enter your Choice: \n");
        scanf("%d", &choice);
    }while(choice<1 || choice>5);
    
    switch(choice){
        case 1: 
            search_by_title();
            break;
        case 2:
            search_by_author();
            break;
        case 3: 
            search_by_genre();
            break;
        case 4: 
            search_by_publisher();
            break;
        case 5:
            search_by_isbn();
            break;
            
    }

    main();
    
}

void search_by_title(){

    char title_to_search[70];

    printf("Enter the title of the book: \n");
    fflush(stdin);
    scanf("%s", &title_to_search);

    for(int i=0; i<k; i++){
        if(strstr(books[i].Title,title_to_search)){
            printf("Book found\n");
            print_books(i);
        }
    }
}

void search_by_author(){

    char author_to_search[70];

    printf("Enter the author of the book: \n");
    fflush(stdin);
    scanf("%s", &author_to_search);

    for(int i=0; i<k; i++){
        if(strstr(books[i].Author,author_to_search)){
            printf("Book found\n");
            print_books(i);
        }
    }
}

void search_by_genre(){

    char genre_to_search[30];

    printf("Enter the genre of the book: \n");
    fflush(stdin);
    scanf("%s", &genre_to_search);

    for(int i=0; i<k; i++){
        if(strstr(books[i].Genre,genre_to_search)){
            printf("Book found\n");
            print_books(i);
        }
    }
}

void search_by_publisher(){

    char publisher_to_search[70];

    printf("Enter the publisher of the book: \n");
    fflush(stdin);
    scanf("%s", &publisher_to_search);

    for(int i=0; i<k; i++){
        if(strstr(books[i].Publisher,publisher_to_search)){
            printf("Book found\n");
            print_books(i);
        }
    }
}

void search_by_isbn(){

    int isbn_to_search;

    printf("Enter the ISBN number of the book: \n");
    fflush(stdin);
    scanf("%d", &isbn_to_search);

    for(int i=0; i<k; i++){
        if(books[i].ISBN == isbn_to_search){
            printf("Book found\n");
            print_books(i);
        }
    }
}


void delete_book(){

    long long int delete_book;

    printf("Enter the ISBN number of book to delete: \n");
    fflush(stdin);
    scanf("%ld", &delete_book);

    for(int i=0; i<k ; i++){
        if(delete_book == books[i].ISBN){
            for(int j=i; j<k ;j++){
                books[i] = books[i+1];
                }
            }
            printf("Book deleted\n");
        }

    
    k--;
    display_books();
    
}

void process_transaction(int i){

    int choice;
    do{
        printf("Select one of the options: \n1. Return\n2. Purchase\n");
        printf("Choose your option: \n");
        fflush(stdin);
        scanf("%d", &choice);
        }while (choice<1 || choice>2);
        
        
    search_by_title();

    switch(choice){
        case 1:
            return_book(i);
            break;
        case 2:
            purchase_book(i);
            break;
            }

}

void return_book(int i){

    books[i].Stock++;

    printf("\n***Book returned***\n\n");
    fflush(stdin);
    
    main();

}

void purchase_book(int i){

    if(books[i].Stock == 0){
        printf("Sorry this book is not available.Check back later\n\n");
        fflush(stdin);
        }
    else{
        books[i].Stock--;
        printf("\n***Congratulations.Book Issued***\n\n");
        fflush(stdin);
        }

    main();

}

int end_program(){

    printf("GOODBYE :)\n");
    printf("Have a Good Day\n");
    
    exit(0);

}