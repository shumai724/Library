#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;


const string t = "wbwbwwbwbwbw";

int main(){
    int W,B;
    cin >> W >> B;

    for(int i = 0; i < (int)t.size(); i++){
        int nw = 0,nb = 0;
        for(int j = 0; j < W+B; j++){
            if(t[i+j%t.size()]=='w')nw++;
            else nb++;
        }
        if(W==nw and B==nb){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    



}
