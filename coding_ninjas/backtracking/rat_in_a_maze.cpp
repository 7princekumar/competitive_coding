#include <bits/stdc++.h>
using namespace std;

#define N 20
// directions
enum dir {
    UP,
    RIGHT,
    DOWN,
    LEFT
};
#define VISITED 1
#define UNVISITED 0
#define WALL 0

void print(int sol[][N], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << sol[i][j] << " ";
        }
    }
    cout << endl;
}

void rat_in_maze_helper(int m[][N], int n, int sol[][N], int row, int col) {
    if(row<0 || row==n || col<0 || col==n || m[row][col]==WALL || sol[row][col]==VISITED) return;
    
    if(row == n-1 && col == n-1) {
        sol[row][col] = VISITED;
        print(sol, n);
    }
    
    for(int dir=UP; dir<=LEFT; dir++) {
        sol[row][col] = VISITED;
        switch(dir){
            case UP:    rat_in_maze_helper(m, n, sol, row - 1, col); break;
            case RIGHT: rat_in_maze_helper(m, n, sol, row, col + 1); break;
            case DOWN:  rat_in_maze_helper(m, n, sol, row + 1, col); break;
            case LEFT:  rat_in_maze_helper(m, n, sol, row, col - 1); break;
        }
        sol[row][col] = UNVISITED;
    }
}

void ratInAMaze(int maze[][N], int n) {
    int sol[N][N];
    memset(sol, 0, N*N*sizeof(int));
    rat_in_maze_helper(maze, n, sol, 0, 0);
}

int main() {
    int n; cin >> n;
    int maze[N][N];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> maze[i][j];
        }
    }
    ratInAMaze(maze, n);
    return 0;
}