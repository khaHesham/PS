class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> Indecies;
        if (s.size() < p.size()) return Indecies;
        unordered_map<char, int> Map;

        for (auto c : p) Map[c]++;

        int start = 0, end = 0, counter = Map.size();

        while (end < s.size()) {
            char c = s[end];
            if (Map.find(c) != Map.end()) {
                Map[c]--;
                if (Map[c] == 0) counter--;
            }
            end++;
            while (counter == 0) {
                char tempc = s[start];
                if (Map.find(tempc) != Map.end()) {
                    Map[tempc]++;
                    if (Map[tempc] > 0) counter++;
                }
                if (end - start == p.size()) Indecies.push_back(start);
                start++;
            }
        }
        return Indecies;
    }
};