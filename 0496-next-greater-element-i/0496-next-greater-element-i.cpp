class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            int element = nums1[i];
            int nextGreater = -1;
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == element) {
                    // Now search for the next greater element in nums2
                    for (int k = j + 1; k < nums2.size(); k++) {
                        if (nums2[k] > nums2[j]) {
                            nextGreater = nums2[k];
                            break;
                        }
                    }
                    break;  // Break once the element in nums2 is found
                }
            }

            // Push the next greater element (or -1 if none found)
            ans.push_back(nextGreater);
        }
        
        return ans;
    }
};
