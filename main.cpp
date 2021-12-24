#include <bits/stdc++.h>

using namespace std;

int gauss_method(double* mat, int height, int width) {
    for(int i = 0; i < height; i++) {
        if(mat[i*height+i] == 0) {
            for(int j = i + 1; j < height; j++) {
                if(mat[i*height+j] != 0) {
                    for(int k = i; k < width; k++) {
                        double tmp = mat[k*height+i];
                        mat[k*height+i] = mat[k*height+j];
                        mat[k*height+j] = tmp;
                    }
                    break;
                }
            }
            if(mat[i*height+i] == 0)
                return -1;
        }
        for(int j = i + 1; j < height; j++) {
            double c = -mat[i*height+j]/mat[i*height+i];
            for(int k = i + 1; k < width; k++)
                mat[k*height+j] += mat[k*height+i] * c;
            mat[i*height+j] = 0;
        }
    }
    for(int i = height - 1; i >= 0; i--) {
        for(int j = height; j < width; j++)
            mat[j*height+i] /= mat[i*height+i];
        mat[i*height+i] = 1;
        for(int j = i - 1; j >= 0; j--) {
            for(int k = height; k < width; k++)
                mat[k*height+j] -= mat[k*height+i] * mat[i*height+j];
            mat[i*height+j] = 0;
        }
    }
    return 0;
}

int main(void) {
    int n;
    cout << "Number of variables: ";
    cin >> n;
    double* matrix = malloc(sizeof(*matrix) * (n + 1) * n);
    cout << "Left part (matrix A):\n";
    for(int row = 0; row < n; row++)
        for(int column = 0; column < n; column++)
            cin >> matrix[column*n+row];
    cout << "Right part (vector b): ";
    for(int row = 0; row < n; row++) {
        cin >> matrix[n*n+row];
    }
    if(gauss_method(matrix, n, n+1)) {
        cout << "The matrix is singular.\n";
    }
    else {
        cout << "Solution:";
        for(int row = 0; row < n; row++)
            cout << matrix[n*n+row] << " ";
        cout << "\n";
    }
}
