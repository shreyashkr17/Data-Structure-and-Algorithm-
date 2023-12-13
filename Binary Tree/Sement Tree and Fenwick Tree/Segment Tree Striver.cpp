#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define ll long long

class SegmentTree{
    vector<int> seg;
    public:
        SegmentTree(int n){
            seg.resize(4*n+1);
        }

        void build(int ind,int low,int high,vector<int>& arr){
            if(low == high){
                seg[ind] = arr[low];
                return;
            }

            int mid = (low+high)/1;
            build(2*ind+1,low,mid,arr);
            build(2*ind+2,mid+1,high,arr);
            seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
        }

        int query(int ind,int low,int high,int l,int r){
            // no overlap
            if(r < low || high<l){
                return INT_MAX;
            }

            // complete overlap
            // [l high low r]

            if(low >= l && high <= r){
                return seg[ind];
            }

            // partial overlap
            int mid = (low+high)/2;
            int left = query(2*ind+1,low,mid,l,r);
            int right = query(2*ind+2,mid+1,high,l,r);
            return min(left,right);
        }

        void update(int ind,int low,int high,int i,int val)
        {
            if(low == high) {
                seg[ind] = val;
                return;
            }

            int mid = (low+high)>>1;
            if(i<=mid){
                update(2*ind+1,low,mid,i,val);
            }else{
                update(2*ind+2,mid+1,high,i,val);
            }
            seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
        }
};

// void solve(){
//     int n;
//     cin>>n;

//     vector<int> arr(n);
//     for(int i =0;i<n;i++){
//         cin>>arr[i];
//     }

//     vector<int> seg(4*n);
//     build(0,0,n-1,arr,seg);
//     int q;
//     cin>>q;
//     while(q--){
//         int type;
//         cin>>type;
//         if(type == 1){
//             int l,r;
//             cin>>l>>r;
//             cout<<query(0,0,n-1,l,r,seg)<<endl;
//         }else{
//             int i,val;
//             cin>>i>>val;
//             update(0,0,n-1,i,val,seg);
//             arr[i] = val;
//         }
//     }
// }

void solve2(){
    int n1;
    cin>>n1;
    vector<int> arr1(n1);
    for(int i =0;i<n1;i++){
        cin>>arr1[i];
    }
    SegmentTree sg1(n1);
    sg1.build(0,0,n1-1,arr1);

    int n2;
    cin>>n2;
    vector<int> arr2(n2);
    for(int i =0;i<n2;i++){
        cin>>arr2[i];
    }
    SegmentTree sg2(n2);
    sg2.build(0,0,n2-1,arr2);

    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            int l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            int min1 = sg1.query(0,0,n1-1,l1,r1);
            int min2 = sg2.query(0,0,n2-1,l2,r2);
            cout<<min(min1,min2)<<endl;
        }else{
            int arrNo,i,val;
            cin>>arrNo>>i>>val;
            if(arrNo == 1){
                sg1.update(0,0,n1-1,i,val);
                arr1[i] = val;
            }else{
                sg2.update(0,0,n2-1,i,val);
                arr2[i] = val;
            }

        }
    }
}
 
int main(){
    solve2();
    return 0;
}