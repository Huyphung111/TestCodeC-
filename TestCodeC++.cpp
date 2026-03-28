#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ================== CLASS BOOK ==================
class Book {
private:
    int id;
    string title;
    string author;

public:
    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
    }
    // cap nhat code 
    int getId() {
        return id;
    }

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    void display() {
        cout << "ID: " << id
            << " | Title: " << title
            << " | Author: " << author << endl;
    }
};

// ================== CLASS LIBRARY ==================
class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id;
        string title, author;

        cout << "Nhap ID: ";
        cin >> id;
        cin.ignore();

        cout << "Nhap ten sach: ";
        getline(cin, title);

        cout << "Nhap tac gia: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Da them sach!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "Danh sach rong!\n";
            return;
        }

        for (auto b : books) {
            b.display();
        }
    }

    void searchBook() {
        int id;
        cout << "Nhap ID can tim: ";
        cin >> id;

        for (auto b : books) {
            if (b.getId() == id) {
                b.display();
                return;
            }
        }

        cout << "Khong tim thay!\n";
    }

    void deleteBook() {
        int id;
        cout << "Nhap ID can xoa: ";
        cin >> id;

        for (int i = 0; i < books.size(); i++) {
            if (books[i].getId() == id) {
                books.erase(books.begin() + i);
                cout << "Da xoa!\n";
                return;
            }
        }

        cout << "Khong tim thay!\n";
    }
};

// ================== MAIN ==================
int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== QUAN LY THU VIEN =====\n";
        cout << "1. Them sach\n";
        cout << "2. Hien thi danh sach\n";
        cout << "3. Tim sach\n";
        cout << "4. Xoa sach\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            lib.addBook();
            break;
        case 2:
            lib.displayBooks();
            break;
        case 3:
            lib.searchBook();
            break;
        case 4:
            lib.deleteBook();
            break;
        case 0:
            cout << "Thoat...\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}