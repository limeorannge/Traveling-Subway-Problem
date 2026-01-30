#define rp " "
#define ln "\n"
#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <algorithm> 

using namespace std;


typedef struct Edge{
    int e, c; 
} Edge;


typedef struct Node{
    int now; 
    int stat; 
    int dist;
    

    int prev_now;   
    int prev_stat;


    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
} Node;

int ans_starting_point;
int line[258];
bool vis[258][1<<19];
Edge track[258][1<<19]; 
vector<Edge> map[258];

int starting_point;
int ans = 2000000000; 
Edge st;

priority_queue<Node, vector<Node>, greater<Node>> pq;

void dijkstra(int s){
    while(!pq.empty()) pq.pop();

    pq.push({s, 1<<line[s], 0, -1, 0});
    
    while(!pq.empty()){
        Node curr = pq.top();
        pq.pop();

        if(vis[curr.now][curr.stat]) continue;
        vis[curr.now][curr.stat] = true;

        if(curr.prev_now != -1) {
            track[curr.now][curr.stat] = {curr.prev_now, curr.prev_stat};
        }

        if(curr.stat == (1<<19)-1) {
            if(curr.now == starting_point) {
                if(curr.dist < ans) {
                    ans = curr.dist;
                    ans_starting_point = starting_point;
                    st = {curr.now, curr.stat};
                }
                return; 
            }
        }

        if(curr.dist >= ans) continue;

        for(auto i : map[curr.now]){
            int next_stat = curr.stat;
            int cost = i.c;

            if(line[i.e] != line[curr.now]){
                bool isNew = !(curr.stat & (1<<line[i.e]));
                bool isReturnHome = (curr.stat == ((1<<19)-1)) && (line[i.e] == line[starting_point]);

                if(isNew || isReturnHome){
                    next_stat = curr.stat | (1<<line[i.e]);
                    
                    if(!vis[i.e][next_stat]){
                        pq.push({i.e, next_stat, curr.dist + cost, curr.now, curr.stat});
                    }
                }
            }
            else{ 
                if(!vis[i.e][next_stat]){
                    pq.push({i.e, next_stat, curr.dist + cost, curr.now, curr.stat});
                }
            }
        }
    }
}

int main(){
    if(freopen("../data/data.txt", "r", stdin) == NULL){
        cout << "Error: data.txt not found!" << ln;
        return 0;
    }

    int n, m;
    cin >> n;
    for(int i=0; i<n; i++){
        int c;
        cin >> c >> line[i]; 
    }
    cin >> m; // 간선 개수 입력
    for(int i=0; i<m; i++){
        int s, e, c;
        cin >> s >> e >> c;
        map[s].push_back({e, c}); 
    }

    int ans_now = ans;

    // 시뮬레이션 시작
    for(starting_point = 0; starting_point < n; starting_point++){
        if(line[starting_point] != 0) continue; 

        cout << "Simulating Start Point: " << starting_point << " (" << line[starting_point] << " line)" << ln;
        
        memset(vis, 0, sizeof(vis));
        
        dijkstra(starting_point);
        if(ans_now != ans){
            ans_now = ans;
            cout << "New Best Time: " << ans << ln;
            
            vector<int> path;
            int curr_node = st.e; 
            int curr_stat = st.c; 
            
            int trace_node = st.e;
            int trace_stat = st.c;

            cout << "Path (Reverse): ";
            while(true){
                cout << trace_node << " ";
                path.push_back(trace_node);
                
                if(trace_node == ans_starting_point && trace_stat == (1<<line[ans_starting_point])){
                    break;
                }

                Edge prev = track[trace_node][trace_stat];
                trace_node = prev.e;
                trace_stat = prev.c;
            }
            cout << ln << "Starting Point Found!" << ln;
        }
    }
    
    cout << "Final Answer Time: " << ans << ln;
}