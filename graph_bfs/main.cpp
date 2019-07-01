#include <bits/stdc++.h>

using namespace std;

class Graph{
        int V;
        list<int>* adjList;
        public:
        Graph(int v)
        {
            V=v;
            adjList=new list<int>[V];
        }
        void addEdge(int u,int v)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        void bfs(int start)
        {
            queue<int> q;
            bool *visited=new bool[V]{0};
            q.push(start);
            visited[start]=true;
            while(!q.empty())
            {
                int node=q.front();
                cout<<node<<" ";
                q.pop();
                for(list<int>::iterator it=adjList[node].begin();it!=adjList[node].end();it++)
                {
                    if(!visited[*it])
                    {
                        q.push(*it);
                        visited[*it]=true;
                    }
                }
            }
        }
        void Graph::DFSUtil(int v, bool visited[])
    {
        visited[v] = true;
        cout << v << " ";
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFSUtil(*i, visited);
    }

    void Graph::DFS(int v)
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        DFSUtil(v, visited);
    }

};

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.bfs(0);
    return 0;
}
