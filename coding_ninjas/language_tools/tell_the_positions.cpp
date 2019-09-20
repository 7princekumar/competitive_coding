#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    map<int, vector<string> > m;
    for(int i=0; i<n; i++) {
        int m1,m2,m3;
        string name;
        cin >> name >> m1 >> m2 >> m3;
        m[m1+m2+m3].push_back(name);
    }
    map<int, vector<string> >::reverse_iterator itr;
    int rank = 1;
    for(itr = m.rbegin(); itr!=m.rend(); itr++) {
        vector<string>& students = itr->second;
        //sort(students.begin(), students.end());
        for(int j=0; j<students.size(); j++) {
            cout << rank++ << " " << students[j] << endl;
        }
    }
	return 0;
}
