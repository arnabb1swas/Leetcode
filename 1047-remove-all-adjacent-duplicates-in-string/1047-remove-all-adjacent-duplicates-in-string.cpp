class Solution {
  public: string removeDuplicates(string s) {
    string a = "";
    int i = 0;
    while (i < s.length()) {
      if (a.length() > 0) {
        if (a[a.length() - 1] == s[i]) {
          a.pop_back();
        } else {
          a.push_back(s[i]);
        }
      } else {
        a.push_back(s[i]);
      }
      i++;
    }
    return a;
  }
};