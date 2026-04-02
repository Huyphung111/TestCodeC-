#include <iostream>
#include <vector>
#include <string>
using namespace std;
// ================== CLASS BOOK ==================
int main()
{
    int n;
    cout << "Nhap vao n:";
	cin >> n;
	do
	{
		cout << "Xin chao ban da toi c++";
		cout << "Vui long nhap vao so khac 0 de tiep tuc hoac 0 de thoat:";
	} while (n == 0);
	cout << "So nguyen am " << n ;
	cout << "Test";
 
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
}
