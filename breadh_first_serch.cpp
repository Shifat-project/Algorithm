#include<bits/stdc++.h>
using namespace std;

const int N=1e+5;
vector<int>adj[N];
bool visited[N];
int level[N];

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while (!q.empty())
    {
    //    pop a node from the queue and insert
    //  unvisited neighbour from the node
        int u=q.front();
        q.pop();
        cout<<"visiting node: "<<u<<endl;
        level[s]=0;
        // section 1;  A node is being proceessed
        for(int v:adj[u])
        {  
             //section 2; child processed
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
            level[v]=level[u]+1;
            //section 3; child processed
        }
        //section 4;same as section 1

    }
    

}

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout<<"Level of "<<i<<": "<<level[i]<<endl;
    }
    
    return 0;
}