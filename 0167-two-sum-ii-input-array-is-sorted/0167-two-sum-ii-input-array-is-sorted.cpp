class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int st=0;
        int ed=numbers.size()-1;
        vector<int>vec;
        while(st<ed){
            if((numbers[st]+numbers[ed])==target){
                vec.push_back(st+1);
                vec.push_back(ed+1);
                break;
            }
            if((numbers[st]+numbers[ed])>target){
                ed--;
            }else{
                st++;
            }
        }
        return vec;
    }
};