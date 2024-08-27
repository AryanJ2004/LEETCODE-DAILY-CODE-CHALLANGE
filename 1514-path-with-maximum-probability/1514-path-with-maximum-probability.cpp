class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});
        vector<double>dis(n,0);
        dis[start_node]=1.0;

        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].push_back({v, prob});
            graph[v].push_back({u, prob});
        }

        while(!pq.empty()){
            double disnode=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto i:graph[node]){
                int next = i.first;
                double weight = i.second;
                if(dis[next]<disnode*weight){
                    dis[next] = disnode*weight;
                    pq.push({dis[next],next});
                }
            }
        }
        return dis[end_node];
    }
};