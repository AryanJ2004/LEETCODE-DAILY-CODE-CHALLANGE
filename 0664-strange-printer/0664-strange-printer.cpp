class Solution {
public:
    int strangePrinter(string s) {
        removeDuplicates(s);
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n, 102));
        for(int i = 1; i < n + 1; i++){
            for(int j = 0; j <= n - i; j++){
                if(i == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                
                //form our new string with length of i from two substrings of len >= 1, 
                //[j, split_index], [split_index+1, j+i)
                for(int split_index = j; split_index < j + i - 1; split_index++){
                    int lower_actions = dp[split_index - j + 1][j];
                    int upper_actions = dp[(j+i-1)-(split_index+1) + 1][split_index + 1];
                    dp[i][j] = min(dp[i][j], lower_actions + upper_actions);
                }

                if(s[j] == s[i+j-1])dp[i][j]--;
            }
        }
        return dp[n][0];
    }

    void removeDuplicates(string& s){
        for(int i = s.size()-1; i > 0; i--){
            if(s[i] == s[i-1]) s.erase(s.begin() + i, s.begin()+i+1);
        }
    }
};