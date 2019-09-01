/*
id:Name: 573 - The Snail
Section: Medium - CP3 (Getting started - Introduction)
Link   : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=514
*/
#include <iostream>
#include <cstring>
#include <cstdbool>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

#define MAX 10 //given

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt",  "r",  stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt",  "w", stderr);
    #endif

    //h - height of well
    //u - up distance
    //d - down distance
    //f - fatigue (in %)
    int h, u, d, f;
    while(scanf("%d %d %d %d", &h, &u, &d, &f), h) {
        //Day 
        //Initial-Height
        //Distance-Climbed 
        //Height-After-Climbing 
        //Height-After-Sliding
        float day = 0, ih = 0, dc = u, hac = u, has = u-d;
        float fd = f * u * .01;

        while(has <= h && has > 0 && dc > 0){
            day++;
            ih = has;
            dc = dc - fd;
            if(dc < 0){
                cout << "failure on day " << day << endl;
            }
            hac = ih + dc;
            if(hac > h) {
                cout << "success on day " << day << endl;
                break;
            }
            has = hac - d;
        }
        cout << "failure on day " << day << endl;
    }

    return 0;
}
