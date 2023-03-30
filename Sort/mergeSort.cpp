//
// Created by Administrator on 2023/3/21.
//
#include<vector>
#include<random>
#include<algorithm>
#include<iostream>
using namespace std;

class MergeSort{
public:

    static void mergeSort(vector<int> &arr){
        if(arr.empty() || arr.size()<2){
            return;
        }
        process(arr,0,arr.size()-1);
    }

    static void process(vector<int> &arr, int L, int R){
        if(L==R){
            return;
        }
        int mid = L+((R-L)>>1);
        process(arr,L,mid);
        process(arr,mid+1,R);
        merge(arr,L,mid,R);
    }

    static void merge(vector<int> &arr, int L, int M, int R){
        vector<int> help;
        help.resize((R-L+1));
        int i=0;
        int p1=L;
        int p2=M+1;
        while(p1<=M&&p2<=R){
            help[i++]=arr[p1]<arr[p2]?arr[p1++]:arr[p2++];
        }
        while(p1<=M){
            help[i++]=arr[p1++];
        }
        while(p2<=R){
            help[i++]=arr[p2++];
        }
        for(int i=0;i<help.size();i++){
            arr[L+i]=help[i];
        }
    }

    static void generateRandomArray(vector<int> &arr, int maxSize, int maxValue){
        arr.resize(rand()%maxSize);
        for(int i=0;i<arr.size();i++){
            arr[i]=rand()%maxValue;
        }
    }

    static bool isEqual(const vector<int> &arr1, const vector<int> &arr2){
        for(int i=0;i<arr1.size();i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }

    static void comparator(vector<int> &arr){
        sort(arr.begin(),arr.end());
    }
};

int main(){
    int testTime=50;
    int maxSize=100;
    int maxValue=10000;
    bool success=true;
    for(int i=0;i<testTime;i++){
        vector<int> arr1;
        MergeSort::generateRandomArray(arr1,maxSize,maxValue);
        vector<int> arr2 = arr1;
        MergeSort::mergeSort(arr1);
        MergeSort::comparator(arr2);
        if(!MergeSort::isEqual(arr1,arr2)){
            success=false;
            break;
        }
    }
    if(success){
        cout<<"That's good"<<endl;
    }else{
        cout<<"Why???"<<endl;
    }
}