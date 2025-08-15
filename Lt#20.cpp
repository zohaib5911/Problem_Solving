#include <bits/stdc++.h>
using namespace std;
unordered_map<char,char> match = {
    {')', '('},
    {']', '['},
    {'}', '{'}
};
bool validParanthesis(string str){
    if(str.length() % 2 != 0){ return false; }
    int num = 0;
    stack<char> temp;
    while(num < str.length()){
        char ch = str[num];
        if(match.count(ch)){
            if(temp.empty() || temp.top() != match[ch]){ return false;}
            else {
                temp.pop();
            }
        }
        else {
            temp.push(ch);
        }   
        num++;
    }
    if (temp.empty()){return true;}
    else { return false;}
}
int main(){
    string str;
    cout<<"Enter str : ";
    getline(cin,str);
    if(validParanthesis(str)){
        cout<<str<<" is Valid \n";
    }
    else {
        cout<<str<<" is Not Valid \n";
    }
    return 0;
}