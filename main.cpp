#include <iostream>
#include <vector>

const int N = 1200;

void multiply_unoptimized(const std::vector<std::vector<double>>& A,
                          const std::vector<std::vector<double>>& B,
                          std::vector<std::vector<double>>& C) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0.0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiply_optimized(const std::vector<std::vector<double>>& A,
                        const std::vector<std::vector<double>>& B,
                        std::vector<std::vector<double>>& C) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0.0;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < N; ++k) {
            double temp = A[i][k];
            for (int j = 0; j < N; ++j) {
                C[i][j] += temp * B[k][j];
            }
        }
    }
}

int main() {
    std::vector<std::vector<double>> A(N, std::vector<double>(N, 1.5));
    std::vector<std::vector<double>> B(N, std::vector<double>(N, 2.0));
    std::vector<std::vector<double>> C(N, std::vector<double>(N, 0.0));

#ifdef USE_OPT
    std::cout << "Starting OPTIMIZED Matrix Multiplication...\n";
    multiply_optimized(A, B, C);
#else
    std::cout << "Starting UNOPTIMIZED Matrix Multiplication...\n";
    multiply_unoptimized(A, B, C);
#endif

    std::cout << "Done! Result: " << C[0][0] << std::endl;
    return 0;
}