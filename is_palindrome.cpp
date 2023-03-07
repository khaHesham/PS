class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        string cleaned;

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        for(int i=0;i<len;i++)
        {
            if((s[i] >= 'a'&& s[i] <= 'z') || (s[i] >= '0'&& s[i] <= '9') )
                cleaned+=s[i];
            
        }

        for(int i=0;i<cleaned.length();i++)
        {
            if(cleaned[i] != cleaned[cleaned.length()-i-1])
                return false;
        }
        return true;
        
    }
};