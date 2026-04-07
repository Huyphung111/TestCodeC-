#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

struct MenuItem {
    int id;
    string name;
    double price;
    bool available;
};

struct OrderLine {
    int itemId;
    string itemName;
    int quantity;
    double unitPrice;
};

struct Order {
    int id;
    int tableNumber;
    vector<OrderLine> lines;
    bool paid;
};

class CafeManager {
private:
    vector<MenuItem> menuItems;
    vector<Order> orders;
    int nextItemId = 1;
    int nextOrderId = 1;
    double totalRevenue = 0.0;

    void clearInput() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int readInt(const string& prompt) {
        int value;
        while (true) {
            cout << prompt;
            if (cin >> value) {
                clearInput();
                return value;
            }
            cout << "Nhap sai dinh dang. Vui long nhap so nguyen.\n";
            clearInput();
        }
    }

    double readDouble(const string& prompt) {
        double value;
        while (true) {
            cout << prompt;
            if (cin >> value) {
                clearInput();
                return value;
            }
            cout << "Nhap sai dinh dang. Vui long nhap so.\n";
            clearInput();
        }
    }

    string readLineNotEmpty(const string& prompt) {
        string value;
        while (true) {
            cout << prompt;
            getline(cin, value);
            if (!value.empty()) {
                return value;
            }
            cout << "Khong duoc de trong.\n";
        }
    }

    int findMenuIndexById(int id) const {
        for (size_t i = 0; i < menuItems.size(); ++i) {
            if (menuItems[i].id == id) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    int findOrderIndexById(int id) const {
        for (size_t i = 0; i < orders.size(); ++i) {
            if (orders[i].id == id) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    double calculateOrderTotal(const Order& order) const {
        double total = 0.0;
        for (const OrderLine& line : order.lines) {
            total += line.unitPrice * line.quantity;
        }
        return total;
    }

public:
    void addMenuItem() {
        MenuItem item{};
        item.id = nextItemId++;
        item.name = readLineNotEmpty("Nhap ten mon: ");
        item.price = readDouble("Nhap gia mon: ");
        while (item.price <= 0) {
            cout << "Gia phai lon hon 0.\n";
            item.price = readDouble("Nhap lai gia mon: ");
        }
        item.available = true;
        menuItems.push_back(item);
        cout << "Da them mon thanh cong. ID mon: " << item.id << "\n";
    }

    void showMenuItems() const {
        if (menuItems.empty()) {
            cout << "Menu dang trong.\n";
            return;
        }
        cout << "\n===== DANH SACH MON =====\n";
        cout << left << setw(6) << "ID" << setw(25) << "Ten mon" << setw(12) << "Gia" << "Trang thai\n";
        for (const MenuItem& item : menuItems) {
            cout << left << setw(6) << item.id
                 << setw(25) << item.name
                 << setw(12) << fixed << setprecision(2) << item.price
                 << (item.available ? "Con ban" : "Tam het") << "\n";
        }
    }

    void updateMenuItem() {
        if (menuItems.empty()) {
            cout << "Khong co mon de sua.\n";
            return;
        }
        const int id = readInt("Nhap ID mon can sua: ");
        const int index = findMenuIndexById(id);
        if (index == -1) {
            cout << "Khong tim thay mon co ID nay.\n";
            return;
        }

        MenuItem& item = menuItems[static_cast<size_t>(index)];
        cout << "Nhap thong tin moi cho mon [" << item.name << "]\n";
        item.name = readLineNotEmpty("Ten moi: ");
        item.price = readDouble("Gia moi: ");
        while (item.price <= 0) {
            cout << "Gia phai lon hon 0.\n";
            item.price = readDouble("Nhap lai gia moi: ");
        }
        const int status = readInt("Trang thai (1=Con ban, 0=Tam het): ");
        item.available = (status == 1);
        cout << "Cap nhat mon thanh cong.\n";
    }

    void createOrder() {
        Order order{};
        order.id = nextOrderId++;
        order.tableNumber = readInt("Nhap so ban: ");
        while (order.tableNumber <= 0) {
            cout << "So ban phai lon hon 0.\n";
            order.tableNumber = readInt("Nhap lai so ban: ");
        }
        order.paid = false;
        orders.push_back(order);
        cout << "Tao don thanh cong. Ma don: " << order.id << "\n";
    }

    void addItemToOrder() {
        if (orders.empty()) {
            cout << "Chua co don nao. Hay tao don truoc.\n";
            return;
        }
        if (menuItems.empty()) {
            cout << "Menu dang trong. Hay them mon truoc.\n";
            return;
        }

        const int orderId = readInt("Nhap ma don: ");
        const int orderIndex = findOrderIndexById(orderId);
        if (orderIndex == -1) {
            cout << "Khong tim thay don.\n";
            return;
        }

        Order& order = orders[static_cast<size_t>(orderIndex)];
        if (order.paid) {
            cout << "Don da thanh toan, khong the them mon.\n";
            return;
        }

        showMenuItems();
        const int itemId = readInt("Nhap ID mon muon them: ");
        const int itemIndex = findMenuIndexById(itemId);
        if (itemIndex == -1) {
            cout << "Khong tim thay mon.\n";
            return;
        }

        const MenuItem& item = menuItems[static_cast<size_t>(itemIndex)];
        if (!item.available) {
            cout << "Mon nay dang tam het.\n";
            return;
        }

        int quantity = readInt("Nhap so luong: ");
        while (quantity <= 0) {
            cout << "So luong phai lon hon 0.\n";
            quantity = readInt("Nhap lai so luong: ");
        }

        for (OrderLine& line : order.lines) {
            if (line.itemId == item.id) {
                line.quantity += quantity;
                cout << "Da cong don so luong mon vao don.\n";
                return;
            }
        }

        OrderLine line{};
        line.itemId = item.id;
        line.itemName = item.name;
        line.quantity = quantity;
        line.unitPrice = item.price;
        order.lines.push_back(line);
        cout << "Da them mon vao don thanh cong.\n";
    }

    void showOrders() const {
        if (orders.empty()) {
            cout << "Chua co don nao.\n";
            return;
        }

        cout << "\n===== DANH SACH DON =====\n";
        for (const Order& order : orders) {
            cout << "Don #" << order.id << " | Ban: " << order.tableNumber
                 << " | Trang thai: " << (order.paid ? "Da thanh toan" : "Chua thanh toan")
                 << "\n";
            if (order.lines.empty()) {
                cout << "  (Chua co mon)\n";
            } else {
                for (const OrderLine& line : order.lines) {
                    cout << "  - " << line.itemName
                         << " x" << line.quantity
                         << " = " << fixed << setprecision(2)
                         << (line.unitPrice * line.quantity) << "\n";
                }
                cout << "  Tong tam tinh: " << fixed << setprecision(2)
                     << calculateOrderTotal(order) << "\n";
            }
        }
    }

    void checkoutOrder() {
        if (orders.empty()) {
            cout << "Chua co don nao.\n";
            return;
        }

        const int orderId = readInt("Nhap ma don can thanh toan: ");
        const int orderIndex = findOrderIndexById(orderId);
        if (orderIndex == -1) {
            cout << "Khong tim thay don.\n";
            return;
        }

        Order& order = orders[static_cast<size_t>(orderIndex)];
        if (order.paid) {
            cout << "Don nay da thanh toan truoc do.\n";
            return;
        }
        if (order.lines.empty()) {
            cout << "Don chua co mon, khong the thanh toan.\n";
            return;
        }

        const double total = calculateOrderTotal(order);
        order.paid = true;
        totalRevenue += total;
        cout << "Thanh toan thanh cong. Tong tien: " << fixed << setprecision(2) << total << "\n";
    }

    void showRevenue() const {
        cout << "Tong doanh thu da thanh toan: " << fixed << setprecision(2) << totalRevenue << "\n";
    }
};

void showMainMenu() {
    cout << "\n===== QUAN LY QUAN CA PHE =====\n";
    cout << "1. Them mon vao menu\n";
    cout << "2. Xem menu\n";
    cout << "3. Sua thong tin mon\n";
    cout << "4. Tao don moi\n";
    cout << "5. Them mon vao don\n";
    cout << "6. Xem danh sach don\n";
    cout << "7. Thanh toan don\n";
    cout << "8. Xem tong doanh thu\n";
    cout << "9. Thoat\n";
}

int main() {
    CafeManager manager;
    int choice = 0;

    do {
        showMainMenu();
        cout << "Nhap lua chon (1-9): ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Lua chon khong hop le.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            manager.addMenuItem();
            break;
        case 2:
            manager.showMenuItems();
            break;
        case 3:
            manager.updateMenuItem();
            break;
        case 4:
            manager.createOrder();
            break;
        case 5:
            manager.addItemToOrder();
            break;
        case 6:
            manager.showOrders();
            break;
        case 7:
            manager.checkoutOrder();
            break;
        case 8:
            manager.showRevenue();
            break;
        case 9:
            cout << "Da thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon tu 1 den 9.\n";
            break;
        }
    } while (choice != 9);

    return 0;
}
