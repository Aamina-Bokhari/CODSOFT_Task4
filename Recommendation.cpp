// Written by Aamina Bokhari
//reccommendation system
//codsoft
#include <iostream>
#include <vector>
#include <string>
#include <map>
//PRODUCTS are movies books and tvshows
using namespace std;

// this is  Struct for  a movie...
struct Movie {
    string title;
    string genre;
};

// this is Struct for  a book.....
struct Book {
    string title;
    string genre;
};

// this is a TV show struct....
struct TVShow {
    string title;
    string genre;
};

// Struct for representing a user
struct User {
    string name;
    string pref_Genre;
};

//  this is aFunction to recommend product...
void recommendProduct(User user, map<string, Movie> movie_Map, map<string, Book> book_Map, map<string, TVShow> tvShow_Map) {
    cout << "\nHello, " << user.name << "! Here are some recommendations for you!!! ENJOYYY\n\n";

    // Recommendations for movies
    cout << "Movies->\n";
    if (movie_Map.count(user.pref_Genre) > 0) {
        cout << "  * " << movie_Map[user.pref_Genre].title << " (Genre-> " << movie_Map[user.pref_Genre].genre << ")\n";
    }
    else {
        cout << "No movies available.\n";
    }

    // Recommendations for books HERE
    cout << "\nBooks->\n";
    if (book_Map.count(user.pref_Genre) > 0) {
        cout << "  * " << book_Map[user.pref_Genre].title << " (Genre-> " << book_Map[user.pref_Genre].genre << ")\n";
    }
    else {
        cout << "No books found ....sorry!.\n";
    }

    // Recommendations for TV shows HERE
    cout << "\nTV Shows->\n";
    if (tvShow_Map.count(user.pref_Genre) > 0) {
        cout << "  * " << tvShow_Map[user.pref_Genre].title << " (Genre-> " << tvShow_Map[user.pref_Genre].genre << ")\n";
    }
    else {
        cout << "No TV shows \n";
    }
}

//  user to choose a genre from a predefined list
string chooseGenre() {
    cout << "\nChoose your preferred genre:\n";
    cout << "1. Action\n";
    cout << "2. Comedy\n";
    cout << "3. Drama\n";
    cout << "Enter  your choice please: ";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        return "Action";
    case 2:
        return "Comedy";
    case 3:
        return "Drama";
    default:
        return "Unknown";
    }
}

int main() {
    User U;
    cout << "Welcome to our reccomendation system! Please tell us your good name: ";
    cin >> U.name;

    // here user  chooses preferred genre
    U.pref_Genre = chooseGenre();

    // Predefined content for Pakistani movies here
    map<string, Movie> movie_Map = {
        {"Action", {"Waars", "Action"}},
        {"Comedy", {"Cake", "Comedy"}}, 
        {"Drama", {"Bol", "Drama"}}
    };

    // Predefined content for Pakistani books here
    map<string, Book> book_Map = {
        {"Action", {"The Reluctant Fundamentalist", "Action"}},
        {"Comedy", {"My Feudal Lord", "Comedy"}},
        {"Drama", {"The Forty Rules of Love", "Drama"}}
    };

    // Predefined content for Pakistani TV shows here
    map<string, TVShow> tvShow_Map = {
        {"Action", {"Alpha Bravo Charlie", "Action"}},
        {"Comedy", {"Bulbulay", "Comedy"}},
        {"Drama", {"Humsafar", "Drama"}}
    };

    // Provide recommendations to the user here
    recommendProduct(U, movie_Map, book_Map, tvShow_Map);
    cout << "THANKS !!!";
    return 0;
}
