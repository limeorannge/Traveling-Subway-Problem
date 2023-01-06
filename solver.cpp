#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct Edge{
    int e, c;
}Edge;
typedef struct Node{
    int now, stat;
}Node;
int line[258];
bool vis[258][1<<20];
vector<Edge> map[258];
int ans = 1000000007;
queue<Node> q;
void bfs(int s){
    vis[s][1<<line[s]] = 1;
    q.push({s, 1<<line[s]});
    while(!q.empty()){
        
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
    for(int i=0; i<258; i++) bfs(i);
}