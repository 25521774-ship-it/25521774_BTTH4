#include "DaThuc.h"
#include <algorithm> // Để dùng std::max

// Constructor
DaThuc::DaThuc(int m) {
    mu = m;
    heso = new double[mu + 1];
    for (int i = 0; i <= mu; i++) heso[i] = 0;
}

// Copy Constructor (Deep Copy)
DaThuc::DaThuc(const DaThuc& dt) {
    mu = dt.mu;
    heso = new double[mu + 1];
    for (int i = 0; i <= mu; i++) heso[i] = dt.heso[i];
}

// Destructor - QUAN TRỌNG
DaThuc::~DaThuc() {
    delete[] heso;
}

// Operator gán
DaThuc& DaThuc::operator=(const DaThuc& dt) {
    if (this == &dt) return *this;
    delete[] heso;
    mu = dt.mu;
    heso = new double[mu + 1];
    for (int i = 0; i <= mu; i++) heso[i] = dt.heso[i];
    return *this;
}

// Operator cộng - Đã sửa lỗi truy cập vùng nhớ
DaThuc DaThuc::operator+(const DaThuc& dt) {
    int maxMu = std::max(mu, dt.mu);
    DaThuc temp(maxMu); // Khởi tạo temp với bậc lớn nhất, đã có cấp phát bộ nhớ bên trong constructor

    for (int i = 0; i <= maxMu; i++) {
        double v1 = (i <= mu) ? heso[i] : 0;      // Nếu i vượt quá bậc của A thì coi như hệ số bằng 0
        double v2 = (i <= dt.mu) ? dt.heso[i] : 0; // Tương tự với B
        temp.heso[i] = v1 + v2;
    }
    return temp;
}

// Operator trừ
DaThuc DaThuc::operator-(const DaThuc& dt) {
    int maxMu = std::max(mu, dt.mu);
    DaThuc temp(maxMu);

    for (int i = 0; i <= maxMu; i++) {
        double v1 = (i <= mu) ? heso[i] : 0;
        double v2 = (i <= dt.mu) ? dt.heso[i] : 0;
        temp.heso[i] = v1 - v2;
    }
    return temp;
}

// Nhập đa thức - Đã thêm cấp phát bộ nhớ
istream& operator>>(istream& is, DaThuc& dt) {
    int m;
    cout << "Nhap bac cua da thuc: ";
    is >> m;

    // Cập nhật lại bộ nhớ cho đối tượng hiện tại
    if (m != dt.mu) {
        delete[] dt.heso;
        dt.mu = m;
        dt.heso = new double[dt.mu + 1];
    }

    for (int i = dt.mu; i >= 0; i--) {
        cout << "Nhap he so bac " << i << ": ";
        is >> dt.heso[i];
    }
    return is;
}

// Xuất đa thức - Tinh chỉnh để hiển thị đẹp hơn
ostream& operator<<(ostream& os, const DaThuc& dt) {
    bool first = true;
    for (int i = dt.mu; i >= 0; i--) {
        if (dt.heso[i] == 0) continue;

        if (!first && dt.heso[i] > 0) os << " + ";
        if (dt.heso[i] < 0) os << " - ";

        double val = (dt.heso[i] < 0) ? -dt.heso[i] : dt.heso[i];

        if (val != 1 || i == 0) os << val;
        if (i > 0) {
            os << "x";
            if (i > 1) os << "^" << i;
        }
        first = false;
    }
    if (first) os << "0";
    return os;
}
