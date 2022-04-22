#include "../std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex>

using namespace Numeric_lib;

void my_sizeof(){
    cout << "sizeof(char): " << sizeof(char) << '\n';
    cout << "sizeof(short): " << sizeof(short) << '\n';
    cout << "sizeof(int): " << sizeof(int) << '\n';
    cout << "sizeof(long): " << sizeof(long) << '\n';
    cout << "sizeof(float): " << sizeof(float) << '\n';
    cout << "sizeof(double): " << sizeof(double) << '\n';
    cout << "sizeof(int*): " << sizeof(int*) << '\n';
    cout << "sizeof(double*): " << sizeof(double*) << '\n';

    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);

    cout << "sizeof(Matrix<int> a(10)): " << sizeof(a) << '\n';
    cout << "sizeof(Matrix<int> b(100)): " << sizeof(b) << '\n';
    cout << "sizeof(Matrix<double> c(10)): " << sizeof(c) << '\n';
    cout << "sizeof(Matrix<int,2> d(10,10)): " << sizeof(d) << '\n';
    cout << "sizeof(Matrix<int,3> e(10,10,10)): " << sizeof(e) << '\n';
}

void my_sqrt(){
    cout << "Type in integers that the program will put in a 'sqrt()':\n"; 

    int s;
    while(cin >> s)
    {
        if(s < 0)
        {
            cout << "Negative numbers do not have square roots!" << '\n';
        }
        else
        {
            cout << "sqrt of s: "  << sqrt(s) << '\n';
        }
    }
}

void my_matrix(){
    cout << "It's Matrix time.\n";
    Matrix<double, 1> Neo(10); //<'type' 'dimensions'>
    float number;
    for(int i = 0; i < 10; i++)
    {
        cout << "Number " << i+1 << ":";
        number = 0;
        cin >> number;
        Neo[i] = number;
    }

    for(int i = 0; i < 10; i++)
    {
        cout << Neo[i] << ' ';
    }
    cout << '\n';
}

void my_complex(){
    cout << "It's spicy matrix time. (akarom mondani komplex számos mátrix)\n";
    Matrix<complex<double>> Neo(10);
    for(int i = 0; i < 10; i++)
    {
        cout << "Complex number " << i+1 << ": ";
        cin >> Neo[i];
    }

    complex<double> sum = 0;

    for(int i = 0; i < 10; i++)
    {
        sum = sum + Neo[i];
    }

    cout << "Sum of 'Matrix<complex<double>>': " << sum << '\n';
}

void my_matrix2(){
    int n;
    int m;
    cout << "Values of n and m: "; cin >> n >> m;
    Matrix<int,2> Neo(n,m);

    for(int i = 0; i < Neo.dim1(); i++)
    {
        for(int j = 0; j < Neo.dim2(); j++)
        {
            Neo(i,j) = (i+1)*(j+2);
        }
    }
    cout << Neo << '\n';
}

void my_matrix3(){
    Matrix<int, 2> m(2, 3);
    cout << "Give six numbers into the matrix: \n";

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> m(i, j);
        }
    }

    cout << m << '\n';
}

int main(){
    my_sizeof();
    cout << "\n";

    my_matrix();
    cout << "\n";

    my_complex();
    cout << "\n";

    my_matrix2();
    cout << "\n";

    my_matrix3();
    cout << "\n";

    my_sqrt();

    return 0;
}