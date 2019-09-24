#include <iostream>

class Matrix {
private:
    int size = 0;
    int** tmpMatrix = nullptr;
public:
    Matrix(int size);
    Matrix(const Matrix&);
    ~Matrix();

    friend std::istream& operator>>(std::istream& in, Matrix&);
    friend std::ostream& operator<<(std::ostream& out, const Matrix&);

    Matrix operator+(Matrix&);
    Matrix operator*(Matrix&);
    Matrix operator-(Matrix&);
    friend Matrix operator++(Matrix&);
    friend Matrix operator--(Matrix&);

};