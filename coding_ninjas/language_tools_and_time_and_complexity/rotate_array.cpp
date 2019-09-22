// arr - input array
// size - size of array
// d - array to be rotated by d elements

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int arr[], int n){
    int p = 0, q = n-1;
    while(p < q){
        swap(&arr[p++], &arr[q--]);
    }
}

void Rotate(int arr[], int d, int size) {  // 1 2, 3 4 5 6
    reverse(arr, size);                    // 6 5 4 3, 2 1        
    reverse(arr, size - d);                // 3 4 5 6, 2 1
    reverse(arr + size - d, d);            // 3 4 5 6, 1 2
}	