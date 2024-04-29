#include <iostream>
#include  <vector>
using namespace std;

const int prime = 31;
const int modulo = 1e9+9;

vector<int> Rabin_karp(string text,string pattern){
    int n = text.length();
    int m = pattern.length();
    vector<int>matches;

    int patternhash = 0;
    for(char c:pattern){
        patternhash =  (patternhash * prime + c)% modulo;
    }

    int texthash = 0;
    int power = 1;
    for(int i =0;i<m;i++){
        texthash = (texthash * prime + text[i])%modulo;
        if(i!=0){
            power  = (power * prime )% modulo;
        }
    }


    for(int i = 0;i<n-m;i++){
        if(patternhash == texthash){
            bool match = true;
            for(int j =0;j<m;j++){
                if(text[i+j] != pattern[j]){
                    match = false;
                    break;
                }
            }
            if(match){
                matches.push_back(i);
            }
        }

        if(i< n-m){
            texthash = (texthash - text[i] * power + modulo)% modulo;
            texthash = (texthash * prime + text[i+m])% modulo;
        }
    }
    return matches;
}


int main(){
    string text = "abracadabra";
    string pattern = "cad";
    vector<int>matches = Rabin_karp(text,pattern);
    if(matches.empty()){
        cout<<"pattern not found in text";
    }
    else{
        cout << "pattern found at : ";
        for(int match:matches){
            cout<<match <<" ";
        }
        cout<<endl;
    }
    
}