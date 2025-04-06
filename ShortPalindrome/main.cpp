#include <bits/stdc++.h>

using namespace std;

// const int MOD = 1e9 + 7;

int shortPalindrome(string s) {
    unsigned long long int MOD = int(pow(10,9))+7;
    unsigned long long int result = 0;
    unsigned long long int c1[26];
    unsigned long long int c2[26][26];
    unsigned long long int c3[26][26][26];
    for(int i=0;i<26;i++){
        c1[i]=0;
        for(int j=0;j<26;j++){
            c2[i][j]=0;
            for(int k=0;k<26;k++){
                c3[i][j][k] = 0;
            }
        }
    }
    if(s.length()<4){
        return 0;
    }
    for(auto letter: s){
        int c = letter - 'a';
        for(int i = 0; i < 26; i++){
            result += c3[c][i][i]; 
            result %= MOD;
            c3[i][c][c] += c2[i][c]; 
            c2[i][c] += c1[i]; 
        }
        c1[c] += 1;
    }
    return result;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = shortPalindrome(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
