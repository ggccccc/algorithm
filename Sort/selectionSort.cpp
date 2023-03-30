//
// Created by Administrator on 2023/3/20.
//
#include<vector>
#include<random>
#include<algorithm>
#include<iostream>
using namespace std;

class SelectionSort{
public:

    static void selectionSort(vector<int> &arr){
        if(arr.empty() || arr.size()<2){
            return;
        }
        for(int i=0;i<arr.size();i++){
            int minIndex=i;
            for(int j=i+1;j<arr.size();j++){
                minIndex=arr[j]<arr[minIndex]?j:minIndex;
            }
            swap(arr,i,minIndex);
        }
    }

    static void swap(vector<int> &arr, int i, int j){
        int tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
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
        SelectionSort::generateRandomArray(arr1,maxSize,maxValue);
        vector<int> arr2 = arr1;
        SelectionSort::selectionSort(arr1);
        SelectionSort::comparator(arr2);
        if(!SelectionSort::isEqual(arr1,arr2)){
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