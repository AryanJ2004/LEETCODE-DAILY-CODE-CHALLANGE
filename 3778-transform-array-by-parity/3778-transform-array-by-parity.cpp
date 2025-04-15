class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int evencnt=0;
        int oddcnt=0;

        for(auto num:nums){
            if(num%2==0) evencnt++;
            else oddcnt++;
        }

        vector<int>vec(evencnt, 0);
        vec.insert(vec.end(),oddcnt,1);
        return vec;
    }
};