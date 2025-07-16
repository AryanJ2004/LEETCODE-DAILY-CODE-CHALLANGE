class Solution {
public:
    static bool compare(pair<int,char>p1,pair<int,char>p2){
        return p1.first>p2.first;
    }
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(auto c:s){
            mpp[c]++;
        }
        vector<pair<int,char>>arr;
        for(auto [c,freq]:mpp){
            arr.emplace_back(make_pair(freq,c));
        }

        sort(arr.begin(),arr.end(),compare);
        string ans;
        for(auto [freq,c]:arr){
            ans.append(freq,c);
        }
        return ans;
    }
};