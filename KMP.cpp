#include <iostream>
#include <vector>
using namespace std;

vector<int>Computelps(string pattern){
    int m = pattern.length();
    vector<int>lps(m,0);
    int len = 0;

    for(int i=1;i<m;){
        if(pattern[i] == pattern[len]){
            len ++;
            lps[i] =len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void KMP(string text,string pattern){
    int n = text.length();
    int m = pattern.length();
    vector<int>lps = Computelps(pattern);
    int i = 0;
    int j = 0;

    while(i<n){
        if(pattern[j] == text[i]){
            i++;
            j++;
        }
        if(j == m){
            cout<<"pattern found at :"<<i-j<<endl;
            j = lps[j-1];
        }
        else if(i<n && pattern[j] != text[i]){
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }

}

int main(){

    string s1 = "ABABDABACDABABCABAB";
    string s2 = "ABABCABAB";

    KMP(s1,s2);
}