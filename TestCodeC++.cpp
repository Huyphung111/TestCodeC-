#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Book {
private:
    int id;
    string title;
    string author;

public:
    Book(int id, const string& title, const string& author) 
        : id(id), title(title), author(author) {}

    int getId() const {
        return id;
    }

    const string& getTitle() const {
        return title;
    }

    const string& getAuthor() const {
        return author;
    }

    void display() const {
        cout << "ID: " << id
            << " | Title: " << title
            << " | Author: " << author << endl;
    }
};

// ================== CLASS LIBRARY ==================
class Library {
private:
    vector<Book> books;

    bool isValidId(int id) const {
        return id > 0;
    }

public:
    void addBook() {
        int id;
        string title, author;

        cout << "Nhap ID: ";
        cin >> id;

        if (!isValidId(id)) {
            cout << "ID khong hop le!\n";
            cin.ignore(10000, '\n');
            return;
        }

        cin.ignore();

        cout << "Nhap ten sach: ";
        getline(cin, title);

        if (title.empty()) {
            cout << "Ten sach khong duoc trong!\n";
            return;
        }

        cout << "Nhap tac gia: ";
        getline(cin, author);

        if (author.empty()) {
            cout << "Tac gia khong duoc trong!\n";
            return;
        }

        books.push_back(Book(id, title, author));
        cout << "Da them sach!\n";
    }

    void displayBooks() const {
        if (books.empty()) {
            cout << "Danh sach rong!\n";
            return;
        }

        cout << "\n=== DANH SACH SACH ===\n";
        for (const auto& b : books) {
            b.display();
        }
    }

    void searchBook() const {
        int id;
        cout << "Nhap ID can tim: ";
        cin >> id;

        for (const auto& b : books) {
            if (b.getId() == id) {
                cout << "\n=== KET QUA TIM KIEM ===\n";
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

        auto it = books.begin();
        for (; it != books.end(); ++it) {
            if (it->getId() == id) {
                books.erase(it);
                cout << "Da xoa!\n";
                return;
            }
        }

        cout << "Khong tim thay!\n";
    }

    size_t getBookCount() const {
        return books.size();
    }
};

// ================== MENU ==================
void displayMenu() {
    cout << "\n===== QUAN LY THU VIEN =====\n";
    cout << "1. Them sach\n";
    cout << "2. Hien thi danh sach\n";
    cout << "3. Tim sach\n";
    cout << "4. Xoa sach\n";
    cout << "0. Thoat\n";
    cout << "Chon: ";
}

// ================== MAIN ==================
int main() {
    Library lib;
    int choice;

    do {
        displayMenu();
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Lua chon khong hop le!\n";
            continue;
        }

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
    // Chương trình này bao gồm các lớp và phương thức phục vụ cho việc...

// Lớp MyClass
//class MyClass {
//public:
    // Phương thức khởi tạo
   // MyClass();

    // Phương thức thực hiện nhiệm vụ
    //void doSomething();
};

// Constructor của MyClass
MyClass::MyClass() {
    // Khởi tạo các biến nếu cần thiết
}

// Phương thức thực hiện nhiệm vụ
//void MyClass::doSomething() {
    // Logic thực hiện nhiệm vụ
}

// Mô tả chương trình:
// Chương trình này thực hiện các tác vụ trên dữ liệu và có thể được sử dụng để...
}
