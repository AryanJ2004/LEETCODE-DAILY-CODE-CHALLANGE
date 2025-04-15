class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>ans;
        for(auto st:operations){
            if(!ans.empty() && st=="C"){
                ans.pop_back();
            }else if(st=="+"){
                int n=ans.size();
                ans.push_back((ans[n-1]+ans[n-2]));
            }else if(st=="D"){
                int n=ans.size();
                ans.push_back((ans[n-1]*2));
            }else{
                ans.push_back((stoi(st)));
            }

            
        }
        int sum=0;
        return sum = accumulate(ans.begin(), ans.end(), 0);
    }
};