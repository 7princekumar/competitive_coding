#include <bits/stdc++.h>
using namespace std;

inline bool check_ith_bit(int n, int i) {
    return n & (1 << i);
}

inline int turn_on_ith_bit(int n, int i) {
    return n | (1 << i);
}

inline int turn_off_ith_bit(int n, int i) {
    return n & ~(1 << i);
}

inline int flip_ith_bit(int n, int i) {
    // x ^ 0 = x
    // x ^ 1 = ~x
    return n ^ (1 << i);
}

inline bool is_even(int n) {
    // 5 -> [1][0][1] & [1] = 1 means odd
    return !(n & 1);
}

inline bool is_odd(int n) {
    // 6 -> [1][1][0] & [1] = 0 means even
    return n & 1;
}

inline bool is_power_of_2(int n) {
    return !(n & (n-1)); 
}

int get_first_set_bit(int n) {
    int count = 0;
    while(n) {
        if(n & 1 == 1) return 1 << count;
        n = n >> 1;
        count++;
    }
    return count;
}

int turn_off_1st_set_bit(int n) {
    int sb = get_first_set_bit(n);
    return n ^ sb;
}

int clear_all_bits_from_lsb(int n, int i) {
    int temp = -1;
    return n & (temp << i);
}

int clear_all_bits_from_msb(int n, int i) {
    int temp = -1;
    return n & ~(temp << i);
}


int main() {
    // call whatever.
    cout << clear_all_bits_from_lsb(15, 0) << endl; //15:1111, 14:1110, 12:1100, 8:1000, 0:0000
    cout << clear_all_bits_from_lsb(15, 1) << endl;
    cout << clear_all_bits_from_lsb(15, 2) << endl;
    cout << clear_all_bits_from_lsb(15, 3) << endl;
    cout << clear_all_bits_from_lsb(15, 4) << endl;

    cout << clear_all_bits_from_msb(15, 4) << endl; //15:1111, 7:0111, 3:0011, 1:0001, 0:0000
    cout << clear_all_bits_from_msb(15, 3) << endl;
    cout << clear_all_bits_from_msb(15, 2) << endl;
    cout << clear_all_bits_from_msb(15, 1) << endl;
    cout << clear_all_bits_from_msb(15, 0) << endl;

    return 0;
}