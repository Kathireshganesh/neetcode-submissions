class Solution {
public:
  vector<vector<int>> graph;

  void  dfs(int node,vector<bool>& visited){
        visited[node]=true;

        for(int next:graph[node]){
            if(!visited[next])
              dfs(next,visited);
        }


  }

    int countComponents(int n, vector<vector<int>>& edges) {
          graph.assign(n,{});

          for(auto e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
          }

          vector<bool> visited(n,false);
          int count=0;

          for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited);
            }
          }
          return count;
    }
};
