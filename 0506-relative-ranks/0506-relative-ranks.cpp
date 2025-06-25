class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int size = score.size();
        vector<pair<int, int>> v;
        vector<string> ans(size);

        for (int i = 0; i < size; i++) {
            v.push_back({score[i], i});
        }
        sort(v.begin(), v.end(), greater<>{});
        for (int i = 0; i < size; i++) {
            if (i == 0) 
                ans[v[i].second] = "Gold Medal";
            else if (i == 1)
                ans[v[i].second] = "Silver Medal";
            else if (i == 2)
                ans[v[i].second] = "Bronze Medal";
            else 
                ans[v[i].second] = to_string(i + 1);
        }
        return ans;
    }
};