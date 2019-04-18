#include<bits/stdc++.h>
using namespace std;

set <char> distinct;                    // stores all distinct characters present in the string

int hasharr[26];

bool check_hash(){
    for(int i = 0; i < 26; i++){
        if(distinct.find('a' + i) != distinct.end() && hasharr[i] == 0){
            return false;
        }
    }
    return true;
}

bool predicate(int len, string s){
    memset(hasharr, 0, sizeof(hasharr));    // clear the hash array
    for(int i = 0; i < len; i++){
        hasharr[s[i] - 'a']++;                    // hash the first substring of length 'len'
    }
    bool ret = check_hash();
    if(ret == true){
        return true;
    }
    int l = 0, r = len - 1;
    while(r < s.size()){                           // sliding window
        hasharr[s[l] - 'a']--;
        l++;
        r++;
        if(r >= s.size()) break;
        hasharr[s[r] - 'a']++;
        if(check_hash() == true){
            return true;
        }
    }
    return false;
}

int bin_search(int low, int high, string s){
    while(high - low > 1){
        int mid = (low + high) / 2;
        if(predicate(mid, s) == true){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    if(predicate(low, s) == true){
        return low;
    }
    else{
        return high;
    }
}

int main(){
    string s;
    cin>>s;
    for(int i = 0; i < s.size(); i++){
        distinct.insert(s[i]);
    }
    int low = distinct.size();
    int high = s.size();
    cout<<bin_search(low, high, s)<<endl;
}