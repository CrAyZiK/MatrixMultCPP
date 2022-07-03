#include <iostream>
#include "qsmatrix.h"
#include <chrono>

int main()
{
    int size = 400;

    QSMatrix<double> matrixA = QSMatrix<double>(size, size, 0);
    QSMatrix<double> matrixB = QSMatrix<double>(size, size, 0);
    matrixA.Randomize(-100, 100);
    std::cout << "Spur: " << matrixA.Spur() << std::endl;
    matrixB.Randomize(-100, 100);
    std::cout << "Spur: " << matrixB.Spur() << std::endl;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    auto t1 = high_resolution_clock::now();
    auto matrixC1 = matrixA*matrixB;
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    auto time = ms_double.count();
    std::cout << "Spur: " << matrixC1.Spur() << std::endl;
    std::cout << "Time: " << time << " ms" << std::endl;

    t1 = high_resolution_clock::now();
    auto matrixC2 = matrixA.Product(matrixB);
    t2 = high_resolution_clock::now();
    ms_double = t2 - t1;
    time = ms_double.count();
    std::cout << "Spur: " << matrixC2.Spur() << std::endl;
    std::cout << "Time: " << time << " ms" << std::endl;
}