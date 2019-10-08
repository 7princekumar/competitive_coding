#include <bits/stdc++.h>
using namespace std;

void print(int** m, int n){
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << m[i][j] << " ";
        }
    }
    cout << endl;
}

inline void place_queen(int** m, int row, int col){
    m[row][col] = 1;
}

inline void remove_queen(int** m, int row, int col){
    m[row][col] = 0;
}

bool is_possible(int** m, int n, int row, int col){
    //check principle diagonal
    for(int i=row, j=col; i>=0 && j>=0; i--, j--) if(m[i][j] == 1) return false;
    //check other diagonal
    for(int i=row, j=col; i<=n-1 && j>=0; i++, j--) if(m[i][j] == 1) return false;
    //check horizontal
    for(int j=col; j>=0; j--) if(m[row][j] == 1) return false;
    
    return true;
}

void all_nqueen(int** m, int n, int curr_col) {
    if(curr_col >= n){
        print(m, n);
        return;
    }
    for(int curr_row=0; curr_row<n; curr_row++) {
        if(is_possible(m, n, curr_row, curr_col)){
            place_queen(m, curr_row, curr_col);
            all_nqueen(m, n, curr_col + 1);
        }
        remove_queen(m, curr_row, curr_col);
    }
}

void nqueen(int** m, int n){
    if(n < 4) return;
    all_nqueen(m, n, 0);
}

int main(){  
    int n; cin >> n;
    // create 2d array
    int* *m = new int*[n];
    for(int i=0; i<n; i++) {
        m[i] = new int[n];
    }
    // initialize 2d array with 0
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            m[i][j] = 0;
    
    //call nqueen
    nqueen(m, n);
    
    for(int i=0; i<n; i++){
        delete[] m[i];
    }
    delete[] m;
    m = NULL;

    return 0;
}
