#include <iostream>
using namespace std;
typedef long long ll;

ll merge(int* a, int startp, int midp, int endp) {
    //assuming, a[startp...midp] and a[midp+1, endp] are sorted
    int merge_ans = 0;
    int* temp = new int[endp-startp + 1];
    int i, j, k = 0;
    for(i=startp, j=midp+1; i<=midp && j<=endp;) {
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
            merge_ans += midp + 1 - i;
        }
    }
    while(i<=midp) temp[k++] = a[i++];
    while(j<=endp) temp[k++] = a[j++];
    k = 0;
    while(startp <= endp) a[startp++] = temp[k++];

    delete[] temp;
    temp = NULL;

    return merge_ans;
}

ll merge_sort(int* a, int startp, int endp) {  //startp -> start_position, ansp ->ans_ptr
    if(startp >= endp) return 0; //if in base case it's return 0, use that, else use reference variable
    int midp = startp + (endp-startp)/2;
    ll i1 = merge_sort(a, startp, midp);
    ll i2 = merge_sort(a, midp + 1, endp);
    ll ans = i1 + i2 + merge(a, startp, midp, endp);
    return ans;
}

ll solve(int* a, int n) {
    return merge_sort(a, 0, n-1);
}

int main() {
    int a[] = {2 ,5 ,1 ,3 ,4};
    int n = sizeof(a)/sizeof(a[0]);
    cout << solve(a, n) << endl;
    return 0;
}