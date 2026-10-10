class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();

        vector<bool> visited(n,false);
        vector<int> minDist(n,INT_MAX);

        minDist[0]=0;

        int cost=0;

        for(int c=0;c<n;c++){
            int node=-1;

            for(int i=0;i<n;i++){
                if(!visited[i] && (node==-1 || minDist[i]<minDist[node])){

                    node=i;
                }
            }


            visited[node]=true;
            cost+=minDist[node];

            for(int next=0;next<n;next++){

                if(!visited[next]){
                    int ncost=abs(points[node][0]-points[next][0])+abs(points[node][1]-points[next][1]);


                    minDist[next]=min(minDist[next],ncost);
                }
            }

        }

        return cost;
    }
};
