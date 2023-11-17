class Solution {
public:
    string getLetters(char digit)
    {
        switch (digit)
        {
        case '2':
            return "abc";
        case '3':
            return "def";
        case '4':
            return "ghi";
        case '5':
            return "jkl";
        case '6':
            return "mno";
        case '7':
            return "pqrs";
        case '8':
            return "tuv";
        case '9':
            return "wxyz";
        default:
            return "";
        }
    }

    void getCombinations(string digits, int index, string curr, vector<string> &result)
    {
        if (index == digits.size())
        {
            result.push_back(curr);
            return;
        }
        
        string letters = getLetters(digits[index]);
        for (int i = 0; i < letters.size(); i++)
        {
            getCombinations(digits, index + 1, curr + letters[i], result);
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(!digits.length()) return result;

        getCombinations(digits, 0, "", result);
        return result;  
    }
};