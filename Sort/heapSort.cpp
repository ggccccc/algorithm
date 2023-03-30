//
// Created by Administrator on 2023/3/21.
//
#include<vector>
#include<random>
#include<algorithm>
#include<iostream>
#include<queue>
//优先队列就是堆结构，在笔试时如果用到堆可以直接使用
std::priority_queue<int> pq; //大顶堆
std::priority_queue<int, std::vector<int>, std::greater<int>> maxq; //小顶堆



bool cmp(std::vector<int>&a,std::vector<int>&b){
    return a[0]>b[0];
}
std::priority_queue<std::vector<int>,std::vector<std::vector<int>>,decltype(&cmp)> pq1(cmp);

using namespace std;

class HeapSort {
public:

    static void heapSort(vector<int> &arr) {
        if (arr.empty() || arr.size() < 2) {
            return;
        }
        for(int i=0;i<arr.size();i++){
            heapInsert(arr,i);
        }
        int heapSize=arr.size();
        swap(arr,0,--heapSize);
        while(heapSize>0){
            heapify(arr,0,heapSize);
            swap(arr,0,--heapSize);
        }
    }

    static void heapInsert(vector<int> &arr,int index){
        while(arr[index]>arr[(index-1)>>1]){
            swap(arr,index,(index-1)>>1);
            index=((index-1)>>1);
        }
    }

    static void heapify(vector<int> &arr,int index, const int heapSize){
        int left=(index<<1)+1;
        while(left<heapSize){
            int largest=left+1<heapSize && arr[left]<arr[left+1]?left+1:left;
            largest=arr[index]>arr[largest]?index:largest;
            if(largest==index){
                break;
            }
            swap(arr,index,largest);
            index=largest;
            left=(index<<1)+1;
        }
    }

    static void swap(vector<int> &arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
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
        HeapSort::generateRandomArray(arr1,maxSize,maxValue);
        vector<int> arr2 = arr1;
        HeapSort::heapSort(arr1);
        HeapSort::comparator(arr2);
        if(!HeapSort::isEqual(arr1,arr2)){
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