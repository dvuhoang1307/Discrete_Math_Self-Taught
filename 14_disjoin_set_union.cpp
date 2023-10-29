#include <bits/stdc++.h>
using namespace std;

int n;
int parent[10001];
int sz[10001];

void make_set(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int dsu_find(int a){
    if(a == parent[a]) return a;
    return parent[a] = dsu_find(parent[a]);
}

void dsu_union(int a, int b){
    if(dsu_find(a) != dsu_find(b)){
        int x = dsu_find(a);
        int y = dsu_find(b);
        if(sz[x] > sz[y]) swap(x, y);
        parent[x] = y;
        sz[y] += sz[x];
    }
}
int main(){
    make_set();
}