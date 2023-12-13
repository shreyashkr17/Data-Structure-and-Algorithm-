#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long


//Time complexity: O(n)
//Space Complexity: O(2*n)
struct Queue{
    stack<int> input,output;

    void push(int data){
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }

        cout<<"The Element pushed is: "<<data<<endl;
        input.push(data);

        while(!output.empty()){
            input.push(output.top());
            output.top();
        }
    }

    int pop(){
        if(input.empty()){
            cout<<"Stack is Empty";
            exit(0);
        }
        return input.top();
    }
    int size(){
        return input.size();
    }
};


//Time complexity: O(1)
//Space Complexity: O(2*n)

class Queue{
    public: 
        stack<int> input,output;
    
    void push(int x){
        cout<<"The element pushed is "<<x<<endl;
        input.push(x);
    }

    int pop(){
        if(output.empty()){
            while(input.size()){
                output.push(input.size());
                input.pop();
            }
        }
        int x = output.top();
        output.pop();
        return x;
    }

    int top(){
        if(output.empty()){
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    int size(){
        return (output.size()+input.size());
    }

};

int main(){
    
    return 0;
}