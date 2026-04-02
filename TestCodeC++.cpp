#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

// ================== CẤU TRÚC SÁCH ==================
struct Book {
    int id;           // ID sách
    string tenSach;   // Tên sách
    string tacGia;    // Tác giả
    int namXuatBan;   // Năm xuất bản
    double gia;       // Giá sách
};

// ================== LỚP QUẢN LÝ THƯ VIỆN ==================
class Library {
private:
    vector<Book> danhSach;  // Danh sách sách lưu trữ bằng vector
    int nextId;             // ID tự động tăng

    // Tìm vị trí sách theo ID
    int timViTriTheoId(int id) {
        for (int i = 0; i < (int)danhSach.size(); i++) {
            if (danhSach[i].id == id) return i;
        }
        return -1;
    }

public:
    Library() : nextId(1) {}

    // Thêm sách mới
    void themSach() {
        Book b;
        b.id = nextId++;

        cin.ignore();
        cout << "Nhap ten sach: ";
        getline(cin, b.tenSach);
        if (b.tenSach.empty()) {
            cout << "Ten sach khong duoc de trong!\n";
            nextId--;
            return;
        }

        cout << "Nhap ten tac gia: ";
        getline(cin, b.tacGia);
        if (b.tacGia.empty()) {
            cout << "Ten tac gia khong duoc de trong!\n";
            nextId--;
            return;
        }

        cout << "Nhap nam xuat ban: ";
        if (!(cin >> b.namXuatBan) || b.namXuatBan < 1000 || b.namXuatBan > 2100) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Nam xuat ban khong hop le!\n";
            nextId--;
            return;
        }

        cout << "Nhap gia sach: ";
        if (!(cin >> b.gia) || b.gia < 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Gia sach khong hop le!\n";
            nextId--;
            return;
        }

        danhSach.push_back(b);
        cout << ">> Them sach thanh cong! (ID: " << b.id << ")\n";
    }

    // Hiển thị tất cả sách
    void hienThiSach() {
        if (danhSach.empty()) {
            cout << "Danh sach sach trong!\n";
            return;
        }
        cout << "\n" << string(70, '-') << "\n";
        cout << left
             << setw(5)  << "ID"
             << setw(25) << "Ten sach"
             << setw(18) << "Tac gia"
             << setw(8)  << "Nam"
             << setw(12) << "Gia (VND)"
             << "\n";
        cout << string(70, '-') << "\n";
        for (const Book& b : danhSach) {
            cout << left
                 << setw(5)  << b.id
                 << setw(25) << b.tenSach
                 << setw(18) << b.tacGia
                 << setw(8)  << b.namXuatBan
                 << setw(12) << fixed << setprecision(0) << b.gia
                 << "\n";
        }
        cout << string(70, '-') << "\n";
        cout << "Tong so sach: " << danhSach.size() << "\n";
    }

    // Tìm kiếm sách theo tên
    void timKiemSach() {
        cin.ignore();
        string tuKhoa;
        cout << "Nhap ten sach can tim: ";
        getline(cin, tuKhoa);

        // Chuyển từ khóa về chữ thường để so sánh không phân biệt hoa/thường
        string tuKhoaLower = tuKhoa;
        transform(tuKhoaLower.begin(), tuKhoaLower.end(), tuKhoaLower.begin(), ::tolower);

        bool timThay = false;
        cout << "\nKet qua tim kiem cho \"" << tuKhoa << "\":\n";
        cout << string(70, '-') << "\n";
        for (const Book& b : danhSach) {
            string tenLower = b.tenSach;
            transform(tenLower.begin(), tenLower.end(), tenLower.begin(), ::tolower);
            if (tenLower.find(tuKhoaLower) != string::npos) {
                cout << "ID: "          << b.id          << "\n"
                     << "Ten sach: "    << b.tenSach     << "\n"
                     << "Tac gia: "     << b.tacGia      << "\n"
                     << "Nam XB: "      << b.namXuatBan  << "\n"
                     << "Gia: "         << fixed << setprecision(0) << b.gia << " VND\n";
                cout << string(70, '-') << "\n";
                timThay = true;
            }
        }
        if (!timThay) cout << "Khong tim thay sach nao phu hop!\n";
    }

    // Xóa sách theo ID
    void xoaSach() {
        int id;
        cout << "Nhap ID sach can xoa: ";
        if (!(cin >> id)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "ID khong hop le!\n";
            return;
        }
        int vitri = timViTriTheoId(id);
        if (vitri == -1) {
            cout << "Khong tim thay sach co ID " << id << "!\n";
            return;
        }
        cout << "Da xoa sach: \"" << danhSach[vitri].tenSach << "\"\n";
        danhSach.erase(danhSach.begin() + vitri);
    }

    // Cập nhật thông tin sách
    void capNhatSach() {
        int id;
        cout << "Nhap ID sach can cap nhat: ";
        if (!(cin >> id)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "ID khong hop le!\n";
            return;
        }
        int vitri = timViTriTheoId(id);
        if (vitri == -1) {
            cout << "Khong tim thay sach co ID " << id << "!\n";
            return;
        }

        Book& b = danhSach[vitri];
        cin.ignore();

        cout << "Ten sach hien tai [" << b.tenSach << "]. Nhap moi (Enter de giu): ";
        string temp;
        getline(cin, temp);
        if (!temp.empty()) b.tenSach = temp;

        cout << "Tac gia hien tai [" << b.tacGia << "]. Nhap moi (Enter de giu): ";
        getline(cin, temp);
        if (!temp.empty()) b.tacGia = temp;

        cout << "Nam xuat ban hien tai [" << b.namXuatBan << "]. Nhap moi (0 de giu): ";
        int nam;
        if (cin >> nam) {
            if (nam != 0) {
                if (nam >= 1000 && nam <= 2100) b.namXuatBan = nam;
                else cout << "Nam xuat ban khong hop le, giu nguyen gia tri cu.\n";
            }
        } else {
            cin.clear();
        }
        cin.ignore(10000, '\n');

        cout << "Gia hien tai [" << fixed << setprecision(0) << b.gia << "]. Nhap moi (0 de giu): ";
        double gia;
        if (cin >> gia) {
            if (gia != 0) {
                if (gia > 0) b.gia = gia;
                else cout << "Gia sach khong hop le, giu nguyen gia tri cu.\n";
            }
        } else {
            cin.clear();
        }
        cin.ignore(10000, '\n');

        cout << ">> Cap nhat thanh cong!\n";
    }
};

// ================== HIỂN THỊ MENU ==================
void hienThiMenu() {
    cout << "\n========== QUAN LY SACH ==========\n";
    cout << "  1. Them sach moi\n";
    cout << "  2. Hien thi danh sach sach\n";
    cout << "  3. Tim kiem sach theo ten\n";
    cout << "  4. Xoa sach theo ID\n";
    cout << "  5. Cap nhat thong tin sach\n";
    cout << "  0. Thoat\n";
    cout << "===================================\n";
    cout << "Lua chon cua ban: ";
}

// ================== HÀM MAIN ==================
int main() {
    Library lib;
    int luaChon;

    cout << "Chao mung den voi chuong trinh Quan Ly Sach!\n";

    do {
        hienThiMenu();

        // Kiểm tra đầu vào hợp lệ
        if (!(cin >> luaChon)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Vui long nhap so!\n";
            continue;
        }

        switch (luaChon) {
        case 1:
            lib.themSach();
            break;
        case 2:
            lib.hienThiSach();
            break;
        case 3:
            lib.timKiemSach();
            break;
        case 4:
            lib.xoaSach();
            break;
        case 5:
            lib.capNhatSach();
            break;
        case 0:
            cout << "Cam on ban da su dung chuong trinh. Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le! Vui long chon lai.\n";
        }

    } while (luaChon != 0);

    return 0;
}
