#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void multiplication(double** A, double** B, double** C, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                    C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void print(double** A, int N) {
    cout << endl << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(5) << A[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;
}

int main()
{
    int N = 1;
    cout << "Enter array size:\n"; 
    cin >> N;
    srand((unsigned int)time(0));

    //array init
    double** A = new double* [N]; 
    double** B = new double* [N]; 
    double** C = new double* [N];
    for (int i = 0; i < N; i++) {
        A[i] = new double[N];
        B[i] = new double[N];
        C[i] = new double[N];
    }

    //3D array + filling
    double*** AA = new double** [N];
    for (int i = 0; i < N; i++) {
        AA[i] = new double* [N];
        for (int j = 0; j < N; j++) {
            AA[i][j] = new double[N];
        }
    }
   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                AA[i][j][k] = 1;         
            }
        }
    }

    //random
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10 + 1;
            B[i][j] = rand() % 10 + 1;
            C[i][j] = 0;
        }
    }

    //func
    multiplication(A, B, C, N);
    cout << "Array A: ";
    print(A, N);
    cout << "Array B: ";
    print(B, N);
    cout << "Array C: ";
    print(C, N);
    
    //clear mem
    for (int i = 0; i < N; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            delete[] AA[i][j];
        }
        delete[] AA[i];
    }
    system("pause");
}
