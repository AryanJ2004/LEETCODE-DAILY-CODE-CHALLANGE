class Solution {
public:

    void dfs(int v,vector<bool>&visit,vector<vector<int>>& adjL){
        visit[v]=true;
        vector<int> adj=adjL[v];
        for(auto it:adj){
            if(!visit[it])
                dfs(it,visit,adjL);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visit(n,false);
        vector<vector<int>>adjL(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjL[i].push_back(j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                dfs(i,visit,adjL);
                cnt++;
            }
        }
        return cnt;
    }
};