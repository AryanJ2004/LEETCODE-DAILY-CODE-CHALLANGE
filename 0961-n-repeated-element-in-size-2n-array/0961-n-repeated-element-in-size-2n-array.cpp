class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int>st;
        int num=0;
        for(auto it:nums){
            if(st.find(it)!=st.end()){
                num=it;
                return it;
                break;
            }else{
                st.insert(it);
            }
        }
        return num;
    }
};