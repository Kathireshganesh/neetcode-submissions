class Solution {
public:

    vector<vector<int>> graph;
    vector<int> state;
    vector<int> order;
    bool cycle(int course){
          if(state[course]==1) return false;

          if(state[course]==2) return true;

          state[course]=1;

          for(auto next:graph[course]){
                if(!cycle(next))
                   return false;
          }

          state[course]=2;
          order.push_back(course);
          return true;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        state.assign(numCourses,0);

        for(auto p: prerequisites){
            graph[p[1]].push_back(p[0]);
        }

        for(int i=0;i<numCourses;i++){
            if(!cycle(i))
                 return {};
        }
        
   
    reverse(order.begin(),order.end());

    return order;
    }
};
