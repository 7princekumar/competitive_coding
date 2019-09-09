#include <iostream>
using namespace std;
#define MAX 500

// going from left to right [correct]
int first_index(int* a, int size, int x) {
  //base case:
  if(size == 0) return -1;
  //is:
  if(a[0] == x) {
    return 0;
  }
  //ih:
  int smaller_output = first_index(a +1, size -1, x);
  return (smaller_output == -1) ? -1 : smaller_output +1;
}

// going from left to right [better, just to learn]
int last_index1(int* a, int size, int x) {
  //base:
  if(size == 0) return -1;
  //ih:
  int smaller_output = last_index1(a +1, size -1, x);  // [first do recursion call here]
  //is:
  if(smaller_output == -1){
    return (a[0] == x) ? 0 : -1;
  }else{
    return smaller_output +1;
  }
}

// going from right to left [easier]
int last_index2(int* a, int size, int x) {
  //base:
  if(size == 0) return -1;
  //is:
  if(a[size -1] == x) return size -1;
  //ih:
  int smaller_output = last_index2(a, size -1, x);
  return smaller_output;
}

//left to right, first IH:, then IS: [not correct as output arr should be in increasing order]
int all_index_desc(int* a, int size, int x, int* output) {
  //base:
  static int* ao = a;
  if(size == 0) return 0;
  //ih:
  int output_size = all_index_desc(a +1, size -1, x, output);
  //is:
  if(a[0] == x){
    output[output_size] = a - ao;
    output_size++;
  }
  return output_size;
}

//left to right, first ih:, then is: [correct]
int all_index_asc(int* a, int size, int x, int* output) {
  //base:
  static int* ao = a;
  if(size == 0) return 0;
  //ih:
  int output_size = 0;
  //is:
  if(a[0] == x){
    output[0] = a - ao;
    output_size = 1 + all_index_asc(a +1, size -1, x, output + 1);
  }else{
    output_size = all_index_asc(a +1, size -1, x, output);
  }
  return output_size;
}

int all_index_main(int* a, int size, int x, int* output) {
  //base:
  if(size == 0) return 0;
  //ih:
  int output_size = all_index_main(a +1, size -1, x, output);
  //is:
  //increment output array elements by 1, as output was for smaller input
  for(int i=0; i<output_size; i++) {
    output[i]++;
  }
  if(a[0] == x){
    //shift array by 1 to make space for new ans
    for(int i=output_size; i>0; i--){
      output[i] = output[i-1];
    }
    //place the new ans to first position of output array as we need to put this in front, as asc
    output[0] = 0;
    return output_size + 1;
  }else{
    return output_size;
  }
}


int main(){
  int a[] = {2,3,4,2,3,5,3,9};
  int size = sizeof(a)/sizeof(a[0]);
  int x = 3; 
  cout << "first index: " << first_index(a, size, x) << endl; //ans = 1
  cout << "last index1: " << last_index1(a, size, x) << endl; //ans = 6
  cout << "last index2: " << last_index2(a, size, x) << endl; //ans = 6


  cout << "all index desc: ";
  int* output = new int[MAX];
  int n = all_index_desc(a, size, x, output);
  for(int i=0; i<n; i++) {
    cout << output[i] << " ";
  }
  cout << endl;
  delete[] output;
  output = NULL;


  cout << "all index asc:  ";
  int* output2 = new int[MAX];
  n = all_index_asc(a, size, x, output2);
  for(int i=0; i<n; i++) {
    cout << output2[i] << " ";
  }
  cout << endl;
  delete[] output2;
  output2 = NULL;


  cout << "all index Main asc:  ";
  int* output3 = new int[MAX];
  n = all_index_main(a, size, x, output3);
  for(int i=0; i<n; i++) {
    cout << output3[i] << " ";
  }
  cout << endl;
  delete[] output3;
  output3 = NULL;


  return 0;
}