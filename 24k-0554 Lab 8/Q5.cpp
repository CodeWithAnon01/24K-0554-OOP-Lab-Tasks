#include <iostream>
using namespace std;

class Matrix2x2 {
private:
    int a, b, c, d;

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0) : a(a), b(b), c(c), d(d) {}

    Matrix2x2 operator+(const Matrix2x2& other) const {
        return Matrix2x2(a + other.a, b + other.b, c + other.c, d + other.d);
    }

    Matrix2x2 operator-(const Matrix2x2& other) const {
        return Matrix2x2(a - other.a, b - other.b, c - other.c, d - other.d);
    }

    Matrix2x2 operator*(const Matrix2x2& other) const {
        return Matrix2x2(
            a*other.a + b*other.c, a*other.b + b*other.d,
            c*other.a + d*other.c, c*other.b + d*other.d
        );
    }

    friend int determinant(const Matrix2x2& m) {
        return m.a * m.d - m.b * m.c;
    }

    friend class MatrixHelper;
    friend ostream& operator<<(ostream& os, const Matrix2x2& m);
};

class MatrixHelper {
public:
    static void updateElement(Matrix2x2& m, int row, int col, int value) {
        if (row == 0 && col == 0) m.a = value;
        else if (row == 0 && col == 1) m.b = value;
        else if (row == 1 && col == 0) m.c = value;
        else if (row == 1 && col == 1) m.d = value;
    }
};

ostream& operator<<(ostream& os, const Matrix2x2& m) {
    os << "[" << m.a << " " << m.b << "]\n[" << m.c << " " << m.d << "]\n";
    return os;
}

int main() {
    Matrix2x2 m1(1, 2, 3, 4), m2(5, 6, 7, 8);
    cout << "m1 + m2 =\n" << m1 + m2 << endl;
    cout << "m1 * m2 =\n" << m1 * m2 << endl;
    cout << "Determinant of m1: " << determinant(m1) << endl;
    MatrixHelper::updateElement(m1, 0, 0, 10);
    cout << "Updated m1:\n" << m1;
    return 0;
}