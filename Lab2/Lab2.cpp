#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void multiplication(double** A, double** B, double** C, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j]*B[j][i];          
        }
    }
}

void print(double** A, double** B, double** C, int N) {
    cout << endl << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(5) << A[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(5) << B[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(5) << C[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;
}

int main()
{
    int N = 1;
    cout << "Enter array size:\n"; cin >> N;
    srand(time(0));

    //array init
    double** A = new double* [N]; 
    double** B = new double* [N]; 
    double** C = new double* [N];
    for (int i = 0; i < N; i++) {
        A[i] = new double[N];
        B[i] = new double[N];
        C[i] = new double[N];
    }

    //randommm
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10 + 1;
            B[i][j] = rand() % 10 + 1;
        }
    }

    multiplication(A, B, C, N);
    print(A, B, C, N);
    
    //clear mem
    for (int i = 0; i < N; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    system("pause");
}
