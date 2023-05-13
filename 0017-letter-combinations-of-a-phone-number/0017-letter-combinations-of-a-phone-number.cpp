class Solution {
public:
    void solveLetterCombinations(vector<string> &ans, int index, string output, string digits, vector<string> &mapping)
    {
        if (index >= digits.length())
        {
            ans.push_back(output);
            return;
        }

        char digitCharacter = digits[index];
        int digitInteger = digitCharacter - '0';
        string value = mapping[digitInteger];

        for (int i = 0; i < value.length(); i++)
        {
            output.push_back(value[i]);
            solveLetterCombinations(ans, index + 1, output, digits, mapping);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() == 0)
        {
            return ans;
        }

        string output = "";
        int index = 0;

        vector<string> mapping(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        solveLetterCombinations(ans, index, output, digits, mapping);
        return ans;
    }
};