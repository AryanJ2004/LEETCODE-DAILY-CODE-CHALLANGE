class MyCalendarTwo {
    vector<pair<int,int>> b, o;
public:
    MyCalendarTwo() {}
    bool book(int s, int e) {
        for(auto& [start, end] : o) {
            if (s < end && e > start) return false;
        }
        for(auto& [start, end] : b) {
            if (s < end && e > start)  o.push_back({max(s, start), min(e, end)});
        }
        b.emplace_back(s, e);
        return true;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();