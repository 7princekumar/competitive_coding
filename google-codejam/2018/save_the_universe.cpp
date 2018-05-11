#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdbool>
#include<vector>
using namespace std;

int main(){
    //get test cases
    int test_cases;
    cin>>test_cases;
    
    //score array
    vector<int> scores;
    
    for(int i=1; i<test_cases+1; i++){
        //get the D
        int D;
        cin>>D;
        
        //get the robo_prog
        string robo_prog;
        cin>>robo_prog;
        
        int local_damage_score;
        bool flag_imp = false;
        bool cs_present        = false;
        bool done              = false;
        int current_strength;
        int num_of_swaps = 0;
        
        while(!cs_present || !done){
            //reset values
            local_damage_score = 0;
            current_strength   = 1;
            
            //calculate damage and current_Str
            for(int j=0; j<robo_prog.length(); j++){
                if(robo_prog[j] == 'S'){
                    local_damage_score += current_strength;
                } else if(robo_prog[j] == 'C'){
                    current_strength *= 2;
                }
            }
            
            //check if damage is less than D
            if(local_damage_score <= D){
                done = true;
                break;
            }
            
            //check for cs
            cs_present = false;
            for(int j=0; j<robo_prog.length() -1; j++){
                if((robo_prog[j] == 'C') && (robo_prog[j+1] == 'S')){
                    cs_present = true;
                }
                
                //if cs_present, then swap, break
                if(cs_present){
                    char temp;
                    temp           = robo_prog[j];
                    robo_prog[j]   = robo_prog[j+1];
                    robo_prog[j+1] = temp;
                    
                    num_of_swaps++;
                    break;
                }
            }
            
            flag_imp = false;
            if(!cs_present && local_damage_score > D){
                flag_imp = true;
                break;
            }
            
        } //while
        
        if(flag_imp){
            scores.push_back(-1);
        }else{
            scores.push_back(num_of_swaps);
        }
        
//        cout<<"num of swaps: "<<num_of_swaps<<endl;
//        cout<<"current_strength: "<<current_strength<<endl;
//        cout<<"local damge score: "<<local_damage_score<<endl;
        
    } //for each test case
    
    for(int i=0; i<scores.size(); i++){
        if(scores[i] == -1){
            cout<<"Case #"<<i+1<<": IMPOSSIBLE"<<endl;
        }else{
            cout<<"Case #"<<i+1<<": "<<scores[i]<<endl;
        }
        
    }
    
    return 0;
}





