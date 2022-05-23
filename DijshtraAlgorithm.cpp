#include<bits/stdc++.h>
using namespace std;
#define V 9

vector<int> djikstra(int graph[V][V],int s){
    vector<int> dist(V,INT_MAX);
    dist[s]=0;
    vector<bool> visited(V,false);
    for(int i=0;i<V-1;i++){
        int u=-1;
        for(int j=0;j<V;j++){
            if(visited[j]==false && (u==-1 || dist[j]<dist[u]))
                u=j;
        }
        visited[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v]!=0 && visited[v]==false){
                dist[v]=min(dist[v],dist[u]+graph[u][v]);
            }
        }
    }
    return dist;
}

int main(){
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    cout<<"Adjacency Matrix :"<< endl;
    for(int i=0;i<4;i++){
        for(auto x:graph[i]){
            cout<<x<< " ";
        }
        cout<<endl;
    }
    cout<<"Distance from source :"<<endl;
    vector<int> ans=djikstra(graph,0);
    for(int u:ans){
        cout<<u<<" ";
    }
    cout<<endl;
}
