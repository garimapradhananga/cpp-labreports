#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <cmath>
using namespace std;

template <class T>
class Matrix {
    int r, c;
    vector<vector<T> > d;

    void check(int i, int j) const {
        if (i < 0 || i >= r || j < 0 || j >= c)
            throw out_of_range("matrix index out of range");
    }

public:
    Matrix(int rows = 0, int cols = 0)
        : r(rows), c(cols), d(rows, vector<T>(cols, T())) {}

    int rows() const { return r; }
    int cols() const { return c; }

    T& operator()(int i, int j) { check(i, j); return d[i][j]; }
    const T& operator()(int i, int j) const { check(i, j); return d[i][j]; }

    static Matrix identity(int n) {
        Matrix m(n, n);
        for (int i = 0; i < n; i++) m(i, i) = 1;
        return m;
    }

    Matrix operator+(const Matrix& o) const {
        if (r != o.r || c != o.c)
            throw invalid_argument("cannot add: matrix sizes differ");
        Matrix res(r, c);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                res(i, j) = d[i][j] + o(i, j);
        return res;
    }

    Matrix operator-(const Matrix& o) const {
        if (r != o.r || c != o.c)
            throw invalid_argument("cannot subtract: matrix sizes differ");
        Matrix res(r, c);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                res(i, j) = d[i][j] - o(i, j);
        return res;
    }

    Matrix operator*(const Matrix& o) const {
        if (c != o.r)
            throw invalid_argument("cannot multiply: columns of A must equal rows of B");
        Matrix res(r, o.c);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < o.c; j++)
                for (int k = 0; k < c; k++)
                    res(i, j) += d[i][k] * o(k, j);
        return res;
    }

    Matrix operator*(T k) const {         
        Matrix res(r, c);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                res(i, j) = d[i][j] * k;
        return res;
    }

    Matrix transpose() const {
        Matrix res(c, r);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                res(j, i) = d[i][j];
        return res;
    }

    T determinant() const {
        if (r != c) throw invalid_argument("determinant needs a square matrix");
        Matrix m = *this;
        T det = 1;
        for (int col = 0; col < r; col++) {
            int p = col;                                 
            for (int i = col + 1; i < r; i++)
                if (fabs((double)m(i, col)) > fabs((double)m(p, col))) p = i;
            if (fabs((double)m(p, col)) < 1e-12) return 0;
            if (p != col) {
                for (int j = 0; j < r; j++) swap(m(p, j), m(col, j));
                det = -det;
            }
            det = det * m(col, col);
            for (int i = col + 1; i < r; i++) {
                T f = m(i, col) / m(col, col);
                for (int j = col; j < r; j++) m(i, j) -= f * m(col, j);
            }
        }
        return det;
    }


    Matrix inverse() const {
        if (r != c) throw invalid_argument("inverse needs a square matrix");
        int n = r;
        Matrix a(n, 2 * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) a(i, j) = d[i][j];
            a(i, n + i) = 1;
        }
        for (int col = 0; col < n; col++) {
            int p = col;
            for (int i = col + 1; i < n; i++)
                if (fabs((double)a(i, col)) > fabs((double)a(p, col))) p = i;
            if (fabs((double)a(p, col)) < 1e-12)
                throw runtime_error("matrix is singular (no inverse)");
            for (int j = 0; j < 2 * n; j++) swap(a(p, j), a(col, j));

            T pivot = a(col, col);
            for (int j = 0; j < 2 * n; j++) a(col, j) = a(col, j) / pivot;
            for (int i = 0; i < n; i++) {
                if (i == col) continue;
                T f = a(i, col);
                for (int j = 0; j < 2 * n; j++) a(i, j) -= f * a(col, j);
            }
        }
        Matrix inv(n, n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) inv(i, j) = a(i, n + j);
        return inv;
    }

    void save(const string& file) const {
        ofstream out(file.c_str());
        if (!out) throw runtime_error("cannot open " + file + " for writing");
        out << r << " " << c << "\n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) out << d[i][j] << " ";
            out << "\n";
        }
    }

    static Matrix load(const string& file) {
        ifstream in(file.c_str());
        if (!in) throw runtime_error("cannot open " + file);
        int rr, cc;
        if (!(in >> rr >> cc) || rr <= 0 || cc <= 0)
            throw runtime_error("bad header in " + file);
        Matrix m(rr, cc);
        for (int i = 0; i < rr; i++)
            for (int j = 0; j < cc; j++)
                if (!(in >> m(i, j))) throw runtime_error("not enough numbers in " + file);
        return m;
    }

    friend ostream& operator<<(ostream& out, const Matrix& m) {
        for (int i = 0; i < m.r; i++) {
            out << "  [ ";
            for (int j = 0; j < m.c; j++)
                out << setw(9) << fixed << setprecision(3) << m.d[i][j] << " ";
            out << "]\n";
        }
        return out;
    }
};

typedef Matrix<double> Mat;


int readInt(const string& prompt) {
    int x;
    cout << prompt;
    if (!(cin >> x)) {
        if (cin.eof()) exit(0);
        cin.clear();
        cin.ignore(1000, '\n');
        throw invalid_argument("that was not a number");
    }
    return x;
}

Mat readMatrix(const string& name) {
    int r = readInt("rows of " + name + ": ");
    int c = readInt("cols of " + name + ": ");
    if (r <= 0 || c <= 0 || r > 10 || c > 10)
        throw invalid_argument("size must be between 1 and 10");
    Mat m(r, c);
    cout << "enter " << name << " row by row:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            if (!(cin >> m(i, j))) {
                if (cin.eof()) exit(0);
                cin.clear();
                cin.ignore(1000, '\n');
                throw invalid_argument("that was not a number");
            }
        }
    return m;
}


void calculator() {
    Mat A = readMatrix("A");
    Mat B = readMatrix("B");
    cout << "\nA =\n" << A << "B =\n" << B;

    try { Mat S = A + B; cout << "\nA + B =\n" << S; }
    catch (exception& e) { cout << "\nA + B: " << e.what() << "\n"; }

    try { Mat P = A * B; cout << "\nA * B =\n" << P; }
    catch (exception& e) { cout << "\nA * B: " << e.what() << "\n"; }

    cout << "\ntranspose of A =\n" << A.transpose();

    try { double det = A.determinant(); cout << "\ndet(A) = " << det << "\n"; }
    catch (exception& e) { cout << "\ndet(A): " << e.what() << "\n"; }

    try { Mat inv = A.inverse(); cout << "\ninverse of A =\n" << inv; }
    catch (exception& e) { cout << "\ninverse of A: " << e.what() << "\n"; }
}


void solveSystem() {
    int n = readInt("number of equations/unknowns: ");
    if (n <= 0 || n > 10) throw invalid_argument("size must be between 1 and 10");

    Mat A(n, n), b(n, 1);
    cout << "enter the coefficients row by row, each followed by the constant:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> A(i, j);
        cin >> b(i, 0);
    }
    if (!cin) {
        if (cin.eof()) exit(0);
        cin.clear();
        cin.ignore(1000, '\n');
        throw invalid_argument("that was not a number");
    }

    Mat x = A.inverse() * b;
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++)
        cout << "  x" << i + 1 << " = " << fixed << setprecision(4) << x(i, 0) << "\n";

    Mat check = A * x - b;                       
    double err = 0;
    for (int i = 0; i < n; i++) err += fabs(check(i, 0));
    cout << "check: total error of A*x - b = " << scientific << setprecision(2) << err << "\n";
}

void regression() {
    string file;
    cout << "data file (try data.txt): ";
    cin >> file;
    Mat data = Mat::load(file);

    int n = data.rows();
    int k = data.cols() - 1;                     
    if (k < 1) throw invalid_argument("need at least one feature column and one y column");
    if (n <= k) throw invalid_argument("need more data rows than features");

    Mat X(n, k + 1), y(n, 1);
    for (int i = 0; i < n; i++) {
        X(i, 0) = 1;                             // column of ones = intercept
        for (int j = 0; j < k; j++) X(i, j + 1) = data(i, j);
        y(i, 0) = data(i, k);
    }

    Mat Xt = X.transpose();
    Mat beta = (Xt * X).inverse() * (Xt * y);

    cout << "\nFitted model using " << n << " data points:\n  y = "
         << fixed << setprecision(3) << beta(0, 0);
    for (int j = 1; j <= k; j++)
        cout << (beta(j, 0) < 0 ? " - " : " + ") << fabs(beta(j, 0)) << "*x" << j;
    cout << "\n";

    Mat yhat = X * beta;
    double mean = 0, ssRes = 0, ssTot = 0;
    for (int i = 0; i < n; i++) mean += y(i, 0);
    mean /= n;
    for (int i = 0; i < n; i++) {
        ssRes += pow(y(i, 0) - yhat(i, 0), 2);
        ssTot += pow(y(i, 0) - mean, 2);
    }
    cout << "R^2 = " << setprecision(4) << 1 - ssRes / ssTot << "\n";

    cout << "\nPredict a new value? (1 = yes, 0 = no): ";
    int again;
    cin >> again;
    if (again == 1) {
        double pred = beta(0, 0);
        for (int j = 1; j <= k; j++) {
            double v;
            cout << "  x" << j << " = ";
            cin >> v;
            pred += beta(j, 0) * v;
        }
        cout << "predicted y = " << setprecision(3) << pred << "\n";
    }
}


int main() {
    int choice = 0;
    do {
        cout << "\n====== MATRIX TOOLKIT ======\n"
             << "1. Matrix calculator\n"
             << "2. Solve linear equations\n"
             << "3. Linear regression from file\n"
             << "4. Exit\n> ";
        if (!(cin >> choice)) {
            if (cin.eof()) break;
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
        }
        try {
            if (choice == 1) calculator();
            else if (choice == 2) solveSystem();
            else if (choice == 3) regression();
        } catch (exception& e) {
            cout << "Error: " << e.what() << "\n";
        }
    } while (choice != 4);
    return 0;
}