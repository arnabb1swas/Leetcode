class Solution {
  public:
    // solving by sorting the words.
    //     vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //       map <string, vector<string> >mp;
    //       for (auto str: strs) {
    //         string s = str;
    //         sort(s.begin(), s.end());
    //         mp[s].push_back(str);
    //       }

    //       vector < vector < string > > ans;
    //       for (auto it = mp.begin(); it != mp.end(); it++) {
    //         ans.push_back(it -> second);
    //       }
    //       return ans;
    //     }
    // solving by using 26 size lowwercase letter array hashmap

    std::array<int, 26> hash(string s) {
        std: array<int, 26> hash = {0};
        for (int i = 0; i < s.size(); i++) {
          hash[s[i] - 'a']++;
        }
        return hash;
    }

    vector<vector<string> >groupAnagrams(vector<string>& strs) {
        map<std::array<int, 26> , vector<string> >mp;

        for (auto str: strs) {
          mp[hash(str)].push_back(str);
        }

        vector<vector<string> >ans;
        for (auto it = mp.begin(); it != mp.end(); it++) {
          ans.push_back(it -> second);
        }
        
        return ans;
    }
};