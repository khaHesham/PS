#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'possibleChanges' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY usernames as parameter.
 */

vector<string> possibleChanges(vector<string> usernames) {
    
    bool flag=false;
    vector<string>temp;
    
    for(int i=0;i<usernames.size();i++)
    {
        int j=0;
        flag=false;
        while(j<usernames[i].length()-1)
        {
            int k=j+1;
            while(k<usernames[i].length())
            {
                if(int(usernames[i][j])>int(usernames[i][k]))
                {
                    flag=true;
                    break;
                }
                k++;
            }
            if(flag==true) break;    
           j++; 
        }
        
        if(flag==false)
            temp.push_back("NO");
        else
            temp.push_back("YES");
            
    }
    
    
        
    return temp;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string usernames_count_temp;
    getline(cin, usernames_count_temp);

    int usernames_count = stoi(ltrim(rtrim(usernames_count_temp)));

    vector<string> usernames(usernames_count);

    for (int i = 0; i < usernames_count; i++) {
        string usernames_item;
        getline(cin, usernames_item);

        usernames[i] = usernames_item;
    }

    vector<string> result = possibleChanges(usernames);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
