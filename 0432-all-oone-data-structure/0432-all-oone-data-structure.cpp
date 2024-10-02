class AllOne {
public:
   unordered_map<string, int>mpp;
   set<pair<int, string>>st;
    AllOne() { 
    }
    
    void inc(string key) {
     if(mpp[key]>0){
        st.erase({mpp[key], key});
     }
     mpp[key]++;
     st.insert({mpp[key], key});
    }
    
    void dec(string key) {
        st.erase({mpp[key], key});
        mpp[key]--;
        if (mpp[key] == 0) {
        mpp.erase(key); 
    } else {
        st.insert({mpp[key], key});
    }
    }
    
    string getMaxKey() {
     if(!st.empty()){
     auto it = st.rbegin();
     return it->second;
     }
     return "";
    }
    
    string getMinKey() {
       if(!st.empty()){
        auto it = st.begin();
     return it->second;
     }
     return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */