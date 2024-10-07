#include <iostream>
#include <vector>
#include <queue>
// https://paiza.jp/works/challenges/10/retry;

using namespace std;
int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！
    
    int H,W;
    cin >> W >> H;
    vector<vector<char>> vec(H,vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> vec[i][j];
        }
    }
    
    int start = 0,end = 0;
    
    vector<vector<int>> G(H*W);
    queue<int> Q;
    vector<int> dx = {1,0,-1,0},dy = {0,1,0,-1};
    
    for(int i = 0; i < H*W; i++){
        char c = vec[i/W][i%W];

        
        if(c == 's')start = i;
        if(c == 'g')end = i;
        
        if(c != '1'){
            for(int a = 0; a < 4; a++){
                int xx = (i/W) + dx[a];
                int yy = (i%W) + dy[a];
                
                if(xx < 0 || xx >= H)continue;
                if(yy < 0 || yy >= W)continue;
                if(vec[xx][yy] != '1'){
                
                G[i].push_back(xx* W + yy);
                
                }
            }
            
        }
        
        
    }
    
    

    vector<int> distance(H*W,-1);
    
    Q.push(start);
    
    distance[start] = 0;
    
    while(!Q.empty()){
        int pos = Q.front();
        Q.pop();
        
        for(int i = 0 ; i < G[pos].size(); i++){
            int to = G[pos][i];
            if(distance[to] == -1){
                distance[to] = distance[pos] + 1;
                Q.push(to);
            }
        }
    }
    
    if(distance[end] == -1)cout << "Fail" << endl;
    
    else cout << distance[end] << endl;
    
    return 0;
}