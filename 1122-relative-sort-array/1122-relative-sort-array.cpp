class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Create a map to store the frequency of elements in arr1
        std::unordered_map<int, int> freq;
        for (int num : arr1) {
            freq[num]++;
        }

        std::vector<int> result;
        // Add elements from arr1 in the order of arr2
        for (int num : arr2) {
            if (freq.find(num) != freq.end()) {
                result.insert(result.end(), freq[num], num);
                freq.erase(num); // Remove the element from the map
            }
        }
        
        // Add remaining elements in sorted order
        std::vector<int> remaining;
        for (auto& pair : freq) {
            remaining.insert(remaining.end(), pair.second, pair.first);
        }
        
        // Sort the remaining elements and append to the result
        std::sort(remaining.begin(), remaining.end());
        result.insert(result.end(), remaining.begin(), remaining.end());
        
        return result;
    }
};