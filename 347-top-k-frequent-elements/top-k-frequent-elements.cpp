class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Step 1: Count frequency
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create buckets
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto it : freq) {
            int num = it.first;
            int count = it.second;

            bucket[count].push_back(num);
        }

        // Step 3: Get k most frequent elements
        vector<int> answer;

        for (int i = nums.size(); i >= 0; i--) {

            for (int num : bucket[i]) {
                answer.push_back(num);

                if (answer.size() == k) {
                    return answer;
                }
            }
        }

        return answer;
    }
};