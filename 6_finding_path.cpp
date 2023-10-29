#include <bits/stdc++.h>
using namespace std;

vector<int> dsk[10001];
bool visited[10001];
int trace[10001]; //mảng trace dùng để lưu vết đường đi

int V, E;

void inp(){
    cin >> V >> E;
    for(int i = 1; i <= E; i++){
        int x, y;
        cin >> x >> y;
        dsk[x].emplace_back(y);
        dsk[y].emplace_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int i){
    visited[i] = true;
    for(auto x : dsk[i]){
        if(!visited[x]){
            trace[x] = i;
            dfs(x);
        }
    }
}

void bfs(int i){
    memset(visited, false, sizeof(visited));
    queue<int> q;
    visited[i] = true;
    q.push(i);
    while(!q.empty()){
        int u = q.front();
        for(auto x : dsk[u]){
            if(!visited[x]){
                trace[x] = u;
                visited[x] = true;
                q.push(x);
            }
        }
        q.pop();
    }
}

void path(int u, int v){
    bfs(u);
    if(visited[v] == true){
        vector<int> ans;
        while(v != u){
            ans.push_back(v);
            v = trace[v];
        }
        ans.push_back(u);
        reverse(ans.begin(), ans.end());
        for(auto x : ans) cout << x << " ";
    } else cout << "Khong co duong di !";
}

#if 0
int main(){
    inp();
    int t;
    cin >> t;
    while(t--){
        int s, t;
        cin >> s >> t;
        path(s, t);
    }
    return 0;
}
#endif

// BT: Cho một đồ thị vô hướng. Cho q testcase. mỗi testcase gồm số x và y
// Nếu tồn tại đường đi giữa x v y thì cout << YES
// Không thì cout << NO;
#if 1
int cycle[10001];
int ans = 0;
void dfs1(int i){
    visited[i] = true;
    cycle[i] = ans;
    for(auto x : dsk[i]){
        if(!visited[x]){
            dfs1(x);
        }
    }
}

void bfs1(int i){
    queue<int> q;
    visited[i] = true;
    cycle[i] = ans;
    q.push(i);
    while(!q.empty()){
        int u = q.front();
        for(auto x : dsk[u]){
            if(!visited[x]){
                cycle[x] = ans;
                visited[x] = true;
                q.push(x);
            }
        }
        q.pop();
    }
}
void countCycle_by_dfs(){
    for(int i = 1; i <= V; i++){
        if(!visited[i]){
            ++ans;
            dfs1(i);
        }
    }
}
void countCycle_by_bfs(){
    for(int i = 1; i <= V; i++){
        if(!visited[i]){
            ++ans;
            bfs1(i);
        }
    }
}

int main(){
    inp();
    countCycle_by_dfs();
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        if(cycle[x] == cycle[y]){
            cout << "YES!" << endl;
        } else cout << "NO!" << endl;
    }
}
#endif