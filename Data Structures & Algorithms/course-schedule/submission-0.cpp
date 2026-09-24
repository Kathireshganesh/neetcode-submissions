class Solution {
   public:
    vector<vector<int>> graph;
    vector<int> state;

    bool solve(int course) {
        if (state[course] == 1) return false;

        if (state[course] == 2) return true;

        state[course] = 1;

        for (int next : graph[course]) {
            if (!solve(next)) {
                return false;
            }
        }
        state[course] = 2;

        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        state.assign(numCourses, 0);

        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        for (int course = 0; course < numCourses; course++) {
            if (!solve(course)) return false;
        }
        return true;
    }
};
