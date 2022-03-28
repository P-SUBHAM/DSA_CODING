//
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> soln;
vector<vector<int>> lines = {{1,7,6,3},{3,10,9,5},{5,8,7,2},{2,6,10,4},{4,9,8,1}};
map<int,vector<int>> nextcut;
void solve(int x, map<int,bool> cut, set<int> nodes,vector<int>);

int main()
{
    set<int> nodes;
    map<int,bool> cut; 
    for(int i = 1; i <= 10; i++) {
        cut[i] = false;
        nodes.insert(i);
    }
    for(auto it: lines) {
        for(int i = 0; i < 4; i++) {
            nextcut[it[i]].push_back(it[(i+2)%4]);
        }
    }
    vector<int> sol;
    solve(1,cut,nodes,sol);
    solve(10,cut,nodes,sol);
    return 0;
}

int xy = 1;

void solve(int x, map<int,bool> cut, set<int> nodes,vector<int> sol) {
    cout<<xy<<":"; xy++;
    if(xy > 5) return;
    // print nodes
    for (auto it: nodes) cout<<it<<" "; cout<<"\n";
    if(cut[x] == true) return; 
    sol.push_back(x);
    int a = nextcut[x][0];
    int b = nextcut[x][1];
    if(cut[a] == false) {
        vector<int> newsol = sol;
        newsol.push_back(a);
        cut[a] = true; nodes.erase(a);
        for(auto it: nodes) {
            solve(it,cut,nodes,newsol);
        }
        cut[a] = false; nodes.insert(a);
    }
    if(cut[b] == false) {
        vector<int> newsol = sol;
        newsol.push_back(b);
        cut[b] = true; nodes.erase(b);
        for(auto it: nodes) {
            solve(it,cut,nodes,newsol);
        }
        cut[b] = false; nodes.insert(b);
    }
}