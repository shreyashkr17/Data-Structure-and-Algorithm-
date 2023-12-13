#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

float median (int nums1[],int nums2[],int n1,int n2){
    if(n1>n2){
        return median(nums2,nums1,n1,n2);
    }

    int low = 0,high = n1,medianPos = ((n1+n2)+1)/2;
    while(low<=high) {
        int cut1 = (low+high)>>1;
        int cut2 = medianPos - cut1;
        
        int l1 = (cut1 == 0)? INT_MIN:nums1[cut1-1];
        int l2 = (cut2 == 0)? INT_MIN:nums2[cut2-1];
        int r1 = (cut1 == n1)? INT_MAX:nums1[cut1];
        int r2 = (cut2 == n2)? INT_MAX:nums2[cut2];
        
        if(l1<=r2 && l2<=r1) {
            if((n1+n2)%2 != 0)
                return max(l1,l2);
            else 
                return (max(l1,l2)+min(r1,r2))/2.0;
        }
        else if(l1>r2) high = cut1-1;
        else low = cut1+1;
    }
    return 0.0;
}
 
int main(){
    int n1,n2;
    cin>>n1>>n2;

    int nums1[n1],nums2[n2];

    for(int i=0;i<n1;i++){
        cin>>nums1[i];
    }

    for(int i=0;i<n2;i++){
        cin>>nums2[i];
    }

    cout<<"The median of two sorted array is "<<fixed<<setprecision(5)
    <<median(nums1,nums2,n1,n2);
    return 0;
}