//https://leetcode.com/explore/learn/card/array-and-string/203/introduction-to-string/1160/
class Solution {
public:
    int add_bit(int a, int b, int &carry){
        int sum = a + b + carry;
        if(sum >= 2 ){
            carry = 1;
        }else{
            carry = 0;
        }
        
        if((sum==2) || (sum ==0)){
            return 0;
        }else{
            return 1;
        }
    }
    
    string addBinary(string a, string b) {
        //make both strings of same length
        if(a.length() < b.length()){
            int d = b.length() - a.length();
            for(int i=0; i< d; i++){
                a.insert(a.begin(), '0');
            }
        } 
        else if( a.length() > b.length()){
            int d = a.length() - b.length();
            for(int i=0; i<d; i++){
                b.insert(b.begin(), '0');
            }  
        } 
        
        
        //start from back
        string s;
        int carry= 0;
        for(int i=a.length() -1; i>=0; i--){
            int sum = add_bit(a[i] - '0' , b[i] - '0', carry);
            s.insert(s.begin(), sum + '0');
            // cout<<"s: "<<sum <<endl;
        }
        if(carry == 1){
            s.insert(s.begin(), '1');
        }
        return s;
    }
};
