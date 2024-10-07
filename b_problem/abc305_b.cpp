#include<bits/stdc++.h>

using namespace std;

int main(){
  char p,q;
  cin >> p >> q;
  vector<int> a = {3,1,4,1,5,9};
  if(q<p) {
    char o = p;
        p=q;
        q=o; 
  }
  int start =int(p-'A');
  int dis = int(q-p);
  int ans = 0;

  for(int i = start; i < dis+start ; i++){
    ans += a.at(i); 

  }
  cout  << ans << endl;




 
}


