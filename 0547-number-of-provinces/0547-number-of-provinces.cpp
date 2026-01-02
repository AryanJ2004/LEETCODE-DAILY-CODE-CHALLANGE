class Solution {

    private:
    void dfs(int i,vector<int> &visited,vector<vector<int>>&adjL){
        visited[i]=1;
        for(auto it:adjL[i]){
            if(!visited[it]){
                dfs(it,visited,adjL);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adjL(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
        
        vector<int>visited(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                visited[i]=1;
                dfs(i,visited,adjL);
            }
        }
        return cnt;
    }
};