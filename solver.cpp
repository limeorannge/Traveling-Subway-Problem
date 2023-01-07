#define rp " "
#define ln "\n"
#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string.h>
#include <stack>
using namespace std;
typedef struct Edge{
    int e, c;
}Edge;
typedef struct Node{
    int now, stat, dist;
}Node;
void byte_encoder(int x){
    for(int i=0; i<19; i++){
        if(x&(1<<i)){
            cout << "line " << i << ", ";
        }
    }
    cout<<"visited" << ln;
}
int ans_starting_point;
int line[258];
bool vis[258][1<<19];
Edge track[258][1<<19];
vector<Edge> map[258];
int starting_point;
int ans = 190;
Edge st;
queue<Node> q;
void bfs(int s){
    vis[s][1<<line[s]] = 1;
    q.push({s, 1<<line[s], 0});
    while(!q.empty()){
        Node curr = q.front();
        q.pop();
        //cout << curr.now << rp << curr.dist << ln;
        //byte_encoder(curr.stat);
        if(curr.stat == (1<<19)-1){ //checking if every lane is visited
            ans = min(ans, curr.dist);
            ans_starting_point = starting_point;
            st = {curr.now, curr.stat};
            continue;
        } 
        for(auto i:map[curr.now]){
            if(line[i.e] != line[curr.now]){ // trying to transfer
                if(!(curr.stat & (1<<line[i.e]))){ // if the lane is not visited 
                    vis[i.e][curr.stat | (1<<line[i.e])] = 1;
                    track[i.e][curr.stat | (1<<line[i.e])] = {curr.now, curr.stat};
                    q.push({i.e, curr.stat | (1<<line[i.e]), curr.dist});
                }
            }
            else{ // trying to go
                if(!vis[i.e][curr.stat]){
                    if(curr.dist + i.c > ans){
                        continue;
                    }
                    vis[i.e][curr.stat] = 1;
                    track[i.e][curr.stat] = {curr.now, curr.stat};
                    q.push({i.e, curr.stat, curr.dist + i.c});
                }
            }
        }
    }
}
int main(){
    freopen("data.txt", "r", stdin);
    //freopen("result.txt", "w", stdout);
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
    int ans_now = ans;
    for(starting_point = 0; starting_point<n; starting_point++){
        cout << "now similating:" << rp << starting_point << "\n";
        memset(vis, 0, sizeof(vis));
        memset(track, 0, sizeof(track));
        bfs(starting_point);
        if(ans_now != ans){
            ans_now = ans;
            cout << ans << ln;
            while(!(st.e == ans_starting_point && st.c == 1<<line[ans_starting_point])){
                cout << st.e << rp;
                st = track[st.e][st.c];
            }
            cout << ans_starting_point<<ln;
        }
    }
}