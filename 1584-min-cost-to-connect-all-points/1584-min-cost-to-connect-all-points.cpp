class Solution {
public:
    int manDist(vector<vector<int>>& points, int p1, int p2) {
        return abs(points[p1][0] - points[p2][0]) +
               abs(points[p1][1] - points[p2][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // pq - min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<bool> MSTset(n, false);
        int MSTcost = 0;

        pq.push({0, 0}); // (wt , node)

        while (pq.size() > 0) {
            auto p = pq.top();
            int wt = p.first;
            int node = p.second;

           pq.pop();

            if (MSTset[node]) {
                continue;
            }

            MSTset[node] = true;
            MSTcost += wt;

            for (int i = 0; i < n; i++) {
                if (!MSTset[i]) {
                    int edgewt = manDist(points, node, i);
                    pq.push({edgewt, i});
                }
            }
        }

        return MSTcost; // min cost
    }
};