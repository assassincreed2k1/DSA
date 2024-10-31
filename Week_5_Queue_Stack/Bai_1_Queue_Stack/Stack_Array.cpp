#include <iostream>
using namespace std;

#define MAX_SIZE 1000

class Stack{
    int array[MAX_SIZE];
    int top;

    Stack(){
        top = -1;
    }

    bool push(int data){
        if(top>=MAX_SIZE-1){
            cout << "Stack was full!";
            return false;
        }
        array[top++] = data;
        return true;
    }

    int pop(){
        if(top<0){
            cout << "Stack was empty";
            return -1;
        }
        int data = array[top--];
        return data;
    }

    bool isEmpty(){
        return top < 0;
    }

    int peek(){
        if (top < 0)
        {
            cout << "Stack was empty";
            return -1;
        }
        return array[top];
    }
};

int main(){

}

