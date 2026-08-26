class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto &s : strs) {
            int cnt[26] = {};

            for (char c : s)
                cnt[c - 'a']++;

            string key;
            key.reserve(100);

            for (int i = 0; i < 26; i++) {
                key += '#';
                key += to_string(cnt[i]);
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(mp.size());

        for (auto &p : mp)
            ans.push_back(move(p.second));

        return ans;
    }
};