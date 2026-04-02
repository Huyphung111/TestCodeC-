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
