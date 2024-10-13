

class Solution {
public:
    int minGroups(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (const auto& interval : intervals) {
            if (!pq.empty() && pq.top() < interval[0]) {
                pq.pop();
            }
            
            pq.push(interval[1]);
        }


        return pq.size();
    }
};