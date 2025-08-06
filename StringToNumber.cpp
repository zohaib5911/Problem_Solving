#include<iostream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;
int strToNum(string& str);      

// Turn string to number 
int main(){
    string str;
    cout<<"Input : ";
    getline(cin,str);
    int num = strToNum(str);
    cout<<"Ouput : "<<num<<endl;

    return 0;
}


int strToNum(string& str){
    
    unordered_map<string, int> numberMap = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3},
        {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7},
        {"eight", 8}, {"nine", 9}, {"ten", 10},
        {"eleven", 11}, {"twelve", 12}, {"thirteen", 13},
        {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16},
        {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19},
        {"twenty", 20}, {"thirty", 30}, {"forty", 40},
        {"fifty", 50}, {"sixty", 60}, {"seventy", 70},
        {"eighty", 80}, {"ninety", 90}
    };

    unordered_map<string, int> multiplierMap = {
        {"hundred", 100},
        {"thousand", 1000},
        {"million", 1000000},
        {"billion", 1000000000}
    };

    
    istringstream iss(str);
    string word;
    int total = 0;
    int current = 0;

    while (iss >> word) {
        for (char& c : word) c = tolower(c);
        if (numberMap.count(word)) {
            current += numberMap[word];
        }
        else if (word == "hundred") {
            current *= 100;
        }
        else if (multiplierMap.count(word)) {
            current *= multiplierMap[word];
            total += current;
            current = 0;
        }
    }

    return total + current;
}
