#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef struct Edge{
    int e, c;
}Edge;
typedef struct Node{
    int now, stat, dist;
}Node;
int line[258];
bool vis[258][1<<20];
vector<Edge> map[258];
int ans = 1000000007;
queue<Node> q;
void bfs(int s){
    vis[s][1<<line[s]] = 1;
    q.push({s, 1<<line[s], 0});
    while(!q.empty()){
        Node curr = q.front();
        q.pop();
        if(curr.stat == (1<<20)-1){ //checking if every lane is visited
            ans = min(ans, curr.dist);
            continue;
        } 
        for(auto i:map[curr.now]){
            if(line[i.e] != line[curr.now]){ // trying to transfer
                if(!(curr.stat & (1<<line[i.e]))){ // if the lane is not visited 
                    vis[i.e][curr.stat | (1<<line[i.e])] = 1;
                    q.push({i.e, curr.stat | (1<<line[i.e]), curr.dist});
                }
            }
            else{ // trying to go
                if(!vis[i.e][curr.stat]){
                    if(curr.dist + i.c > ans){
                        continue;
                    }
                    vis[i.e][curr.stat] = 1;
                    q.push({i.e, curr.stat, curr.dist + i.c});
                }
            }
        }
    }
}
int main(){
    freopen("data.txt", "r", stdin);
    int n, m;
    cin >> n;
    for(int i=0; i<n; i++){
        int c;
        cin >> c >> line[i];
    }
    cin>>m;
    for(int i=0; i<m; i++){
        int s, e, c;
        cin >> s >> e >> c;
        map[s].push_back({e, c});
    }
    for(int i=0; i<258; i++){
        memset(vis, 0, sizeof(vis));
        bfs(i);
    }
}