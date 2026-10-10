class Solution {
public:
    vector<vector<int>> graph;

    bool cycle(int node, int parent, vector<bool>& visited) {
        visited[node] = true;

        for (int next : graph[node]) {

            // Ignore the edge back to the parent
            if (next == parent)
                continue;

            // Already visited means a cycle
            if (visited[next])
                return false;

            if (!cycle(next, node, visited))
                return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        graph.assign(n, {});

        vector<bool> visited(n, false);

        // Build undirected graph
        for (auto p : edges) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }

        // Check for cycles starting from node 0
        if (n == 0 || !cycle(0, -1, visited))
            return false;

        // Check connectivity
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                return false;
        }

        return true;
    }
};