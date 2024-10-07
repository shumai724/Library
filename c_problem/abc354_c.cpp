//https://atcoder.jp/contests/abc354/tasks/abc354_c//

#include<bits/stdc++.h>
using namespace std;
int N;


int total=0;

struct Card{
  int a;
  int c;
  int index;
}

int main(){

  int n;
  cin >>n;
  vector<Card> cards(N);
  for(int i=0;i<N; i++){
    int a,c;
    cin >> a >>c;
    cards[i] = {a,c,i};
  }

  sort(cards.begin(),cards.end(), [&](const aouto &l,const auto &r){
    return l.c < r.c;
  });
  vector<int> ans;
  int v=0;
  for(int i=0; i <N; i++){
    if(cards[i].a > v){
      v = cards[i].a;
      ans.push_back(cards[i].index);
    }
  }

  sort(ans.begin(),ans.end());

  const int m = (int)ans.size();
  cout << m << endl;

  for(int i=0; i <m; i++){
    cout << ans[i]+1;
    if(i ==m-1){
      cout << endl;

    }else{
      cout << " ";
    }
  }




}


