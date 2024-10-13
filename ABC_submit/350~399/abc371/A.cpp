#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    int a = 0,b = 0,c = 0;

    if(s1 == "<") b += 1;
    else a += 1;

    if(s2 == "<") c += 1;
    else a += 1;

    if(s3 == "<") c += 1;
    else b += 1;

    if(a==1)cout << "A" << endl;
    else if(b==1)cout << "B" << endl;
    else cout << "C" << endl;
    return 0;  
    

}