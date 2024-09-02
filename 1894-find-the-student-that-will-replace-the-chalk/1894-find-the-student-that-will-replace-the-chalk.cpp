class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int sz = chalk.size();
        long sum = 0;
        for(auto &ele : chalk) sum += ele*1L;
        int number = k / sum;
        k = k - number * sum;
        for(int i = 0 ; i < sz ; i++){
            if(chalk[i] > k) return i;
            k -= chalk[i];
        }
        return -1;
    }
};