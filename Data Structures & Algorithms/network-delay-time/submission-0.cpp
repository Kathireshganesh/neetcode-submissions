class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);

        for(auto& t:times){
            int u=t[0];
            int v=t[1];
            int w=t[2];

            graph[u].push_back({v,w});
        }

        vector<int> dist(n+1,INT_MAX);

        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> pq;


    dist[k]=0;
    pq.push({0,k});

    while(!pq.empty()){

        auto [d,node]=pq.top();
        pq.pop();

        if(d>dist[node]) continue;

        for(auto [next,weight] : graph[node]){

            int newDist = d+weight;

            if(newDist < dist[next]){
                dist[next]=newDist;
                pq.push({newDist,next});
            }
        }
    }
      int answer = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;

            answer = max(answer, dist[i]);
        }

        return answer;

    }
};
