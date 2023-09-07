#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
#define MAX 2000
#define R1 500// number of rows in Matrix-1
#define C1 500// number of columns in Matrix-1
#define R2 500// number of rows in Matrix-2
#define C2 500// number of columns in Matrix-2



vector<vector<int>> mulMat(vector<vector<int>> mat1, vector<vector<int>> mat2)
{
    vector<vector<int>> rslt;
    for (int i = 0; i < R1; i++) {
        vector<int> vec1;
        for (int j = 0; j < R2; j++) {
            vec1.push_back(0);
        }
        rslt.push_back(vec1);
    }


    cout << "Multiplication of given two matrices is:\n";

    for (int i = 0; i < R1; i++) {
        //vector<int> v1;
        for (int j = 0; j < C2; j++) {

            for (int k = 0; k < R2; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }

        }
        //rslt.push_back(v1);
        //cout << endl;
    }
    return rslt;
}

int main()
{
    vector<vector<int>> mat1;
    vector<vector<int>> mat2;

    for (int i = 0; i < R1; i++) {
        vector<int> vec1;
        for (int j = 0; j < R1; j++) {
            vec1.push_back(j + 1);
        }
        mat1.push_back(vec1);
    }
    for (int i = 0; i < R1; i++) {
        vector<int> vec1;
        for (int j = 0; j < R1; j++) {
            vec1.push_back(5 - j);
        }
        mat2.push_back(vec1);
    }
    vector<vector<int>> result;
    auto start = chrono::steady_clock::now();

    result = mulMat(mat1, mat2);
    /*for (int i = 0; i < R1; i++) {
        for (int j = 0; j < R2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }*/

    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;
    
    start = chrono::steady_clock::now();
    int n = R1;
    int B = R2;
    for (int ii = 0; ii < n; ii += B) {
        for (int jj = 0; jj < n; jj += B) {
            for (int kk = 0; kk < n; kk += B) {
                for (int i = ii; i < ii + B; i++) {
                    for (int j = jj; j < jj + B; j++) {
                        for (int k = kk; k < kk + B; k++) {
                            result[i][j] += mat1[i][k] * mat2[k][j];
                        }
                    }
                }
            }
        }
    }
    
    end = chrono::steady_clock::now();
    cout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;

    /*for (int i = 0; i < R1; i++) {
        for (int j = 0; j < R2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }*/
    
}