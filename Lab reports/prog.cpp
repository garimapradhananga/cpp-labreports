#include<iostream>
using namespace std;

class matrix {
    int a[3][3];

public:
    void input(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                cin >> a[i][j];
            }
        }
    }

    void display(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    matrix multiply(matrix obj){
        matrix temp;

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                temp.a[i][j] = 0;

                for (int k = 0; k < 3; k++){
                    temp.a[i][j] += this->a[i][k] * obj.a[k][j];
                }
            }
        }

        return temp;
    }

    void transpose(){
        cout << "Transpose:\n";
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                cout << a[j][i] << " ";
            }
            cout << endl;
        }
    }

    int determinant(){
        return
        a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1])
      - a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0])
      + a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);
    }
};

int main(){
    matrix obj1, obj2, obj3;

    cout << "Enter Matrix 1:\n";
    obj1.input();

    cout << "Enter Matrix 2:\n";
    obj2.input();

    cout << "\nMatrix 1:\n";
    obj1.display();

    cout << "\nMatrix 2:\n";
    obj2.display();

    // Multiplication
    obj3 = obj1.multiply(obj2);
    cout << "\nMultiplication Result:\n";
    obj3.display();

    // Transpose of result
    obj3.transpose();

    // Determinant of result
    cout << "Determinant of result: " << obj3.determinant() << endl;

    return 0;
}