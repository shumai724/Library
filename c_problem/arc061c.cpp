
#include <bits/stdc++.h>
using namespace std;

int main(){
    string N;
    cin >> N;
    int c= N.length();
    int64_t ans=0;

    for(int i=0; i<<(c-1);i++){
        int64_t sm=0;
        long long a = N[0] - '0';
        for(int j=0; j<c-1;i++){
            if( i & (1<<j)){
                sm += a;
                a=0;
            }
            a= a*10 + N[j+1] - '0';
        }
        sm += a;
        ans += sm;
    }
    cout << ans << endl;









    

}