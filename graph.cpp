#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    int maxDist = 0;
    pair<int, int> farthestNodes;
    vector<int> bfs(int start, vector<int> adj[], vector<int> &dis)
    {
        queue<pair<int, int>> q;
        q.push({start, 0});
        dis[start] = 0;
        while (!q.empty())
        {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            for (auto x : adj[node])
            {
                if (dis[x] > dist + 1)
                {
                    dis[x] = dist + 1;
                    q.push({x, dist + 1});
                    maxDist = dist + 1;
                    farthestNodes = {start, x};
                }
            }
        }
        return dis;
    }

    int eccentricity(int vertex, vector<int> adj[], vector<int> &dis)
    {

        vector<int> res = bfs(vertex, adj, dis);
        int ecc = *max_element(res.begin(), res.end());
        return ecc;
    }

    int radius(int nodes, vector<int> adj[])
    {
        int rad = 1e9;
        for (int i = 0; i < nodes; i++)
        {
            vector<int> dis(nodes, INT_MAX);
            vector<int> ans = bfs(i, adj, dis);
            int ma = *max_element(ans.begin(), ans.end());
            rad = min(rad, ma);
        }
        return rad;
    }

    int diameter(int nodes, vector<int> adj[])
    {
        int dia = 0;
        for (int i = 0; i < nodes; i++)
        {
            vector<int> dis(nodes, INT_MAX);
            vector<int> ans = bfs(i, adj, dis);
            int ma = *max_element(ans.begin(), ans.end());
            dia = max(dia, ma);
        }
        return dia;
    }

    int centerOfGraph(int nodes, vector<int> adj[])
    {
        int mi = 1e9;
        int center = 1e9;
        for (int i = 0; i < nodes; i++)
        {
            vector<int> dis(nodes, INT_MAX);
            int ecc = eccentricity(i, adj, dis);
            if (mi > ecc)
            {
                mi = ecc;
                center = i;
            }
        }
        return center;
    }
};
int main()
{
    int i, j, nodes, a, b, edges, choice, vertex, ecc, rad, dia, center;
    cout << "Enter number of vertices and edges in a graph : ";
    cin >> nodes >> edges;
    cout << "Add edges (a, b) : ";
    vector<int> adj[nodes];
    vector<int> dis(nodes, INT_MAX);
    for (i = 0; i < edges; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    Graph g;
    cout << "Measurements of a Graph" << endl;
    do
    {
        cout << "Enter the choice 1.Length 2.Eccentricity 3.Radius 4.Diameter 5.Centre of Graph 6.Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Length of the Graph = " << edges << endl;
            break;

        case 2:
            cout << "Enter the vertex to find the Eccentricity : ";
            cin >> vertex;
            ecc = g.eccentricity(vertex, adj, dis);
            cout << "Eccentricity of the Graph at vertex " << vertex << " - E(" << vertex << ") = " << ecc << endl;
            break;

        case 3:
            rad = g.radius(nodes, adj);
            cout << "Radius of the graph = " << rad << endl;
            break;

        case 4:
            dia = g.diameter(nodes, adj);
            cout << "Farthest Nodes are - " << g.farthestNodes.first << "-" << g.farthestNodes.second << endl;
            cout << "Diameter of the graph = " << dia << endl;
            break;

        case 5:
            center = g.centerOfGraph(nodes, adj);
            cout << "Center of the graph = " << center << endl;
            break;

        default:
            break;
        }
    } while (choice <= 5);
}
