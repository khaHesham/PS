#include <bits/stdc++.h>


class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(int i = 0;i < s.size();i++) st.push(s[i]);

        stack<char> temp;

        while(!st.empty()){
            if(st.top() == ')' || st.top() == '}' || st.top() == ']') 
                temp.push(st.top());
            else{
                if(temp.empty()) return false;
                if(st.top() == '(' && temp.top() != ')') return false;
                if(st.top() == '{' && temp.top() != '}') return false;
                if(st.top() == '[' && temp.top() != ']') return false;
                temp.pop();
            }
            
            st.pop();
        }
        if(st.empty() && temp.empty()) return true;
        else return false;
    }
};