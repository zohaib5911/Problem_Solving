#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int>& num){
    for(int i = 0;i<num.size() -1 ;i++){
        for(int j = i+1;j<num.size();j++){
            if(num[i]>num[j]){
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(auto i : nums2){
            nums1.push_back(i);
        }
        sort(nums1);
        int n = nums1.size();
    if (n % 2 == 0) { // even number of elements
        return (static_cast<double>(nums1[n / 2 - 1]) +
                static_cast<double>(nums1[n / 2])) / 2.0;
    } else { // odd number of elements
        return static_cast<double>(nums1[n / 2]);
    }
}


int main(){

    vector<int> num1 = { 1,2};
    vector<int> num2 = {3,4};
    double median = findMedianSortedArrays(num1,num2);
    cout<<"Median : "<<median<<endl;

    return 0;
}
