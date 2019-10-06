#include <iostream>
using namespace std;

void merge(int* a, int si, int mi, int ei) {
    int* merged = new int[ei- si + 1];
    int i = si;     //for first half
    int j = mi + 1; //for second half
    int k = 0;      //for merged
    while(i <= mi && j<= ei) merged[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    while(i <= mi) merged[k++] = a[i++];
    while(j <= ei) merged[k++] = a[j++];
    k = 0;
    while(si <= ei) a[si++] = merged[k++];

    delete[] merged;
    merged = NULL;
}

void merge_sort(int* a, int si, int ei) { //si-start_index, ei-end_index
    if(si >= ei) return;
    int mi = si + (ei - si)/2;
    merge_sort(a, si, mi);
    merge_sort(a, mi+1, ei);
    merge(a, si, mi, ei);
}

void mergeSort(int a[], int n){
    merge_sort(a, 0, n-1);
}

void print(int* a, int n) {
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
}


int main(){
    int a[] = {1,2,3,423,21,1,5};
    int n = sizeof(a)/sizeof(a[0]);
    print(a, n);
    mergeSort(a, n);
    print(a, n);
    return 0;
}