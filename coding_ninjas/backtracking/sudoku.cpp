#include <bits/stdc++.h>
using namespace std;

void print(int grid[][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool find_empty_place(int grid[][9], int* er, int* ec){
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            if(grid[i][j] == 0){
                *er = i; 
                *ec = j;
                return true;
            }
    return false;
}

bool no_conflict(int grid[][9], int er, int ec, int num){
    for(int i=0; i<9; i++) if(grid[i][ec] == num) return false; //same row
    for(int i=0; i<9; i++) if(grid[er][i] == num) return false; //same col
    int er_start = er - er%3;
    int ec_start = ec - ec%3;
    for(int i=er_start; i<er_start+3; i++){
        for(int j=ec_start; j<ec_start+3; j++){
            if(grid[i][j] == num) return false;
        }
    }
    return true;
}

bool solve_sudoku(int grid[][9]) {
    int er, ec; //empty_row, empty_col
    if(!find_empty_place(grid, &er, &ec)) {
        print(grid);
        return true;
    }
    for(int i=1; i<=9; i++) {
        if(no_conflict(grid, er, ec, i)){
            grid[er][ec] = i;
            if(solve_sudoku(grid)) return true; // done!
            grid[er][ec] = 0;
        }
    }
    return false; // current_setup is wrong, backtrack!
}

int main() {
    int grid[9][9];
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            cin >> grid[i][j];

    solve_sudoku(grid);
    return 0;
}

/*
4 0 0 0 0 6 0 0 0
0 6 0 0 0 0 0 0 9
0 0 0 0 0 0 0 0 0
0 0 2 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 3 0 6 0 0 2 0
1 0 0 0 0 0 9 0 0
8 0 0 0 0 5 0 0 0
0 0 0 0 0 0 0 0 5
*/