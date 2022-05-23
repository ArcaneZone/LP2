#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int s,int d){
    if(s==d)
        return;
    adj[s].push_back(d);
    adj[d].push_back(s);
}
void DFS(vector<int> adj[],int s,vector<bool> &v){
    v[s]=true;
    cout<< s << " ";
    for(int x: adj[s]){
        if(!v[x])
            DFS(adj,x,v);
    }
}
//time complexity = O(V+E);
//space complexity = O(V);

void BFS(vector<int> adj[],int s,int n)
{
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int curr=q.front();
        cout<<curr<<" ";
        q.pop();
        for(int x : adj[curr]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
}
// time complexity =  O(V+E) 
// space complexity = O(V)

int main(){
    vector<int> adj[4];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    cout<<"Adjacency List :"<< endl;
    for(int i=0;i<4;i++){
        cout<<i<<" : ";
        for(auto x:adj[i]){
            cout<<x<< " ";
        }
        cout<<endl;
    }
    vector<bool> visited(4);
    cout<<"Depth First Algorithm in Graph:";
    DFS(adj,0,visited);
    cout<<endl;
    cout<<"Breadth First Algorithm in Graph:";
    BFS(adj,0,4);
    cout<<endl;
}
