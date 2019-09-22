// arr - input array
// size - size of array
// d - array to be rotated by d elements

void Rotate(int arr[], int d, int size) {
    int new_size = 2 * size;
    int* a = new int[new_size];
    for(int i=0; i<size; i++) {
        a[i] = arr[i];
    }
    for(int i=0; i<size; i++) {
        a[size +i] = arr[i];
    }
    int pos = 0;
    for(int i=d; i<d+size; i++) {
        arr[pos++] = a[i];
    }
    delete[] a;
    a = NULL;
}	
