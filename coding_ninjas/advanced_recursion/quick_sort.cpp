#include <iostream>
using namespace std;

void print(int* a, int n) {
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void segregate(int* a, int si, int ei, int pos) {
    while(si < ei) {
        while(a[si] < a[pos] && si < ei) si++; 
        while(a[ei] >= a[pos] && si < ei) ei--;
        if(si < ei){
            swap(&a[si], &a[ei]); si++; ei--; 
        }
    }
}

int partition(int* a, int si, int ei) {
    int pivot = a[si];
    int count = 0;
    for(int i=si; i<=ei; i++) if(a[i] < pivot) count++;
    int pos = si + count;
    swap(&a[si], &a[pos]);

    segregate(a, si, ei, pos);
    return pos; 
}

void quick_sort(int* a, int si, int ei) { //si-start_index, ei-end_index
    if(si > ei) return;
    int p = partition(a, si, ei);
    quick_sort(a, si, p-1);
    quick_sort(a, p+1, ei);
}

void quickSort(int a[], int n){
    quick_sort(a, 0, n-1);
}

int main(){
    //int a[] = {9,1,1,2,3,9,5};
    int a[] = {9,1,1,2,3,9,5};
    int n = sizeof(a)/sizeof(a[0]);
    // int n; cin >> n;
    // int a[];
    // for(int i=0; i<n; i++) cin >> a[i];
    print(a, n);
    quickSort(a, n);
    print(a, n);
    return 0;
}