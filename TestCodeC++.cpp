#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ================== CLASS BOOK ==================
class Book {
private:
    string title;
    string author;
    string isbn;
    int year;
    float price;

public:
    // Constructor
    Book() {
        title = "";
        author = "";
        isbn = "";
        year = 0;
        price = 0.0;
    }

    // Constructor with parameters
    Book(string t, string a, string i, int y, float p) {
        title = t;
        author = a;
        isbn = i;
        year = y;
        price = p;
    }

    // Setter methods
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setISBN(string i) { isbn = i; }
    void setYear(int y) { year = y; }
    void setPrice(float p) { price = p; }

    // Getter methods
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getISBN() { return isbn; }
    int getYear() { return year; }
    float getPrice() { return price; }

    // Display book information
    void display() {
        cout << "Tieu de: " << title << endl;
        cout << "Tac gia: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Nam: " << year << endl;
        cout << "Gia: " << price << endl;
    }
};

int main()
{
    // Create a book using constructor
    Book book1("Lap trinh C++", "Bjarne Stroustrup", "978-0-201-88954-3", 2013, 45.5);
    
    cout << "==== Thong tin sach 1 ====" << endl;
    book1.display();
    
    cout << "\n==== Tao sach 2 ====" << endl;
    Book book2;
    book2.setTitle("Data Structures");
    book2.setAuthor("Mark Allen Weiss");
    book2.setISBN("978-0-13-110268-7");
    book2.setYear(2014);
    book2.setPrice(55.0);
    
    cout << "==== Thong tin sach 2 ====" << endl;
    book2.display();
    
    cout << "\n==== Danh sach sach ====" << endl;
    vector<Book> library;
    library.push_back(book1);
    library.push_back(book2);
    
    for(int i = 0; i < library.size(); i++) {
        cout << "--- Sach " << (i+1) << " ---" << endl;
        library[i].display();
        cout << endl;
    }
    
    return 0;
}
