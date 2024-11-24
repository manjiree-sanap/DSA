//)Implement a program to find minimum and maximum elements from a given list using Divide and Conquer strategy.
#include<iostream>
using namespace std;

void minMaxDNC(int array[],int low,int high,int &min,int &max){
    int mid,min1,min2,max1,max2;
    if(low==high){
        max=min=array[low];
    }else if(low==high-1){
     min=max=array[low];
     if(array[high]<min){min=array[high];}
     if(array[high]>max){max=array[high];}
    }else{
        int mid=(low+high)/2;
        minMaxDNC(array,low,mid,min1,max1);
        minMaxDNC(array,mid+1,high,min2,max2);
        min=min1;
        max=max1;
        if(min2<min){min=min2;}
        if(max2>max){max=max2;}
    }
}
int main(){
    int array[]={3,9,7,2,8,5,1,13};
    int n=8;
    int min = 999;
    int max = 1;
    minMaxDNC(array,0,n-1,min,max);
    cout<<"Min of array:"<<min<<endl;
    cout<<"Max of array:"<<max<<endl;
    return 0;
}
