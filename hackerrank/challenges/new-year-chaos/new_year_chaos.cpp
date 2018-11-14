//link: https://www.hackerrank.com/challenges/new-year-chaos/problem

void minimumBribes(vector<int> q) {
    int too_chaotic = false;
    for(int i=0; (i<q.size()) && (!too_chaotic); i++){
        if((q[i] - (i+1)) > 2){
            cout<<"Too chaotic"<<endl;
            too_chaotic = true;
        }
    }
    
    if(!too_chaotic){
        int count = 0;
        vector<int> p = q;
        bool sorted = false;
        //bubble sort
        for(int i=0; i<p.size()-1 && !sorted; i++){
            sorted = true;
            for(int j=0; j<p.size()-i-1; j++){
                if(p[j] > p[j+1]){
                    sorted = false;
                    int temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                    count++;
                    // print_i_v(p);
                }
            }
        }
        cout<<count <<endl;
    }    
}