#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void print_2d_iv(vector<vector<int> > v){
    for(unsigned int i=0; i<v.size(); i++){
        for(unsigned int j=0; j<v[i].size(); j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
} 

//oi , oj- original i, j
int get_neighbour_count(vector<vector<int> > &cgrid, int oi, int oj, int M, int N){
    int i = oi, j = oj;
    int count = 0;

    i = oi; j = oj - 1;
    if( !(i<0) && !(i>=M) && !(j<0) && !(j>=N) && (cgrid[i][j]==1)){
        count++;
    }

    i = oi-1; j = oj - 1;
    if( !(i<0) && !(i>=M) && !(j<0) && !(j>=N)  && (cgrid[i][j]==1)){
        count++;
    }

    i = oi - 1; j = oj;
    if( !(i<0) && !(i>=M) && !(j<0) && !(j>=N)  && (cgrid[i][j]==1)){
        count++;
    }

    i = oi - 1; j = oj + 1;
    if( !(i<0) && !(i>=M) && !(j<0) && !(j>=N)  && (cgrid[i][j]==1)){
        count++;
    }

    i = oi; j = oj + 1; //
    if( !(i<0) && !(i>=M) && !(j<0) && !(j>=N)  && (cgrid[i][j]==1)){
        count++;
    }

    i = oi + 1; j = oj + 1; //
    if( !(i<0) && !(i>=M) && !(j<0) && !(j>=N)  && (cgrid[i][j]==1)){
        count++;
    }

    i = oi + 1; j = oj;
    if( !(i<0) && !(i>=M) && !(j<0) && !(j>=N)  && (cgrid[i][j]==1)){
        count++;
    }

    i = oi + 1; j = oj - 1;
    if( !(i<0) && !(i>=M) && !(j<0) && !(j>=N)  && (cgrid[i][j]==1)){
        count++;
    }

    return count;
}

int main() {
    int T; //test cases
    cin >> T;

    for (int ii = 1; ii < T+1; ii++) {
        //take input
        int M,N, Ji, Jj, Ki, Kj, G;
        cin >> M >> N;
        
        vector<vector<int> > cgrid; //current grid 
        cgrid.resize(M);
        for(int i=0; i<M; i++){
            string row; cin>> row;
            for(unsigned int j=0; j<row.length(); j++){
                cgrid[i].push_back(row[j] - '0' );
            }   
        } 

        cin >> Ji >> Jj;
        cin >> Ki >> Kj;
        cin >> G;
        //----write from here-----
        while(G--){
            vector<vector<int> > fgrid = cgrid; //future grid
            for(int i=0; i<M; i++){
                for(int j=0; j<N; j++){
                    
                    //infected cell
                    if(cgrid[i][j] == 1){
                        int n_count = get_neighbour_count(cgrid, i, j, M, N);
                        if( !((Ji <= n_count) && (n_count <= Jj)) ){
                            fgrid[i][j] = 0;
                        }
                    }

                    //non-infected cell
                    if(cgrid[i][j] == 0){
                        int n_count = get_neighbour_count(cgrid, i, j, M, N);
                        if( ((Ki <= n_count) && (n_count <= Kj)) ){
                            fgrid[i][j] = 1;
                        }
                    }
                }
            }
            cgrid = fgrid;
        }
        print_2d_iv(cgrid);


    } //for each test case

    return 0;
}

//