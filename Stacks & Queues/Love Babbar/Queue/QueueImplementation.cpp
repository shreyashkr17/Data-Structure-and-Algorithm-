#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    queue<int> q;

    q.push(11);  

    cout<<"front of q is: "<<q.front()<<endl;

    q.push(15);
    cout<<"front of q is: "<<q.front()<<endl;

    q.push(13);
    cout<<"size of queue is: "<<q.front()<<endl;

    cout<<"size of queue is : "<<q.size()<<endl;

    q.pop();
    q.pop();
    q.pop();

    cout<<"size of queue is: "<<q.size()<<endl;

    if(q.empty()){
        cout<<"Queue is empty "<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }
    return 0;
}