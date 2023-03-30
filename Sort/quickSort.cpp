//
// Created by Administrator on 2023/3/21.
//
#include<vector>
#include<random>
#include<algorithm>
#include<iostream>
using namespace std;

class QuickSort{
public:

    static void quickSort(vector<int> &arr){
        if(arr.empty() || arr.size()<2){
            return;
        }
        quickSort(arr,0,arr.size()-1);
    }

    static void quickSort(vector<int> &arr, int L, int R){
        if(L<R){
            swap(arr,L+(rand()%(R-L+1)),R);
            vector<int> p(2);
            p= partition(arr,L,R);
            quickSort(arr,L,p[0]-1);
            quickSort(arr,p[1]+1,R);
        }
    }

    static vector<int> partition(vector<int> &arr, int L, int R){
        int less = L-1;
        int more=R;
        while(L<more){
            if(arr[L]<arr[R]){
                swap(arr,++less,L++);
            }else if(arr[L]>arr[R]){
                swap(arr,--more,L);
            }else{
                L++;
            }
        }
        swap(arr,more,R);
        vector<int> res(2);
        res[0]=less+1;
        res[1]=more;
        return res;
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
        QuickSort::generateRandomArray(arr1,maxSize,maxValue);
        vector<int> arr2 = arr1;
        QuickSort::quickSort(arr1);
        QuickSort::comparator(arr2);
        if(!QuickSort::isEqual(arr1,arr2)){
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