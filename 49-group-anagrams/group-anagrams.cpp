class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<array<int, 26>, vector<string>> mp;

        for (const string& s : strs) {
            array<int, 26> count{};

            for (char c : s) {
                count[c - 'a']++;
            }

            mp[count].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(mp.size());

        for (auto& [key, group] : mp) {
            ans.push_back(move(group));
        }

        return ans;
    }
};