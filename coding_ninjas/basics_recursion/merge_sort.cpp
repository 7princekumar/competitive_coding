#include <iostream>
using namespace std;

void print(int* a, int n) {
	for(int i=0; i<n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void merge(int* arr, int sp, int mp, int ep){
	int* merged = new int[ep-sp]; //create an array for elements btw sp and ep
	int i = sp;
	int j = mp + 1;
	int k = 0;
	while(i <= mp && j <= ep){
		merged[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	}
	while(i <= mp) merged[k++] = arr[i++];
	while(j <= ep) merged[k++] = arr[j++];
	//copy sorted elements back to their original array btw sp and ep
	k = 0;
	while(sp <= ep){
		arr[sp++] = merged[k++];
	}
	delete[] merged;
	merged = NULL;
}

void merge_sort(int* arr, int sp, int ep){  //sp - start_pos, ep - end_pos
	//base:
	if(sp >= ep) return;
	//ih:
	int mp = (sp + ep)/2; //mp - mid_pos
	merge_sort(arr, sp, mp);
	merge_sort(arr, mp+1, ep);
	//is:
	merge(arr, sp, mp, ep);
}


int main(){
	int a[] = {1,4,2,5,6,7,2,9,2,0};
	int n = sizeof(a)/sizeof(a[0]);
	cout << "Initial: ";
	print(a, n);
	merge_sort(a, 0, n-1);
	cout << "After: ";
	print(a, n);
	return 0;
}