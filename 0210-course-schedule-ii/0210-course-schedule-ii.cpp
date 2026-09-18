class Solution {
public:
    bool TheCycleInDFS(int src, vector<bool>& vis, vector<bool>& recPath,
                       vector<vector<int>>& prerequisites) {

        vis[src] = true;
        recPath[src] = true;

        for (int i = 0; i < prerequisites.size(); i++) {

            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            if (u == src) {

                if (!vis[v]) {

                    if (TheCycleInDFS(v, vis, recPath, prerequisites)) {
                        return true;
                    }

                } else if (recPath[v]) {
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;
    }

    void TopoLogicalSortingOrder(int src, vector<bool>& vis, stack<int>& s,
                                 vector<vector<int>>& prerequisites) {

        vis[src] = true;

        for (int i = 0; i < prerequisites.size(); i++) {

            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            if (u == src) {

                if (!vis[v]) {
                    TopoLogicalSortingOrder(v, vis, s, prerequisites);
                }
            }
        }

        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        vector<int> ans;
        stack<int> s;

        // Cycle Detection

        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {

                if (TheCycleInDFS(i, vis, recPath, prerequisites)) {
                    return ans;
                }
            }
        }

        // Topological Sorting

        vis.assign(numCourses, false);

        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {
                TopoLogicalSortingOrder(i, vis, s, prerequisites);
            }
        }

        //  Stack  Answer

        while (!s.empty()) {

            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};