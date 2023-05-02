#include <iostream>

using namespace std;

struct Stack{
    int size = 30;
    int top = -1;
    int data[30];
    
};

bool isEmpty(Stack* stack1){
    if (stack1->top == -1){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(Stack* stack1){
    if (stack1->top == (stack1->size - 1)){
        return true;
    }
    else{
        return false;
    }
}

void Display(Stack* stack1){
    for (int i = stack1->top; i >= 0; i--){
        cout<<stack1->data[i]<<" ";
    }
    cout<<endl<<endl;
}

int StackTop(Stack* stack1){
    if (isEmpty(stack1)){
        cout<<"Empty stack"<<endl;
        cout<<endl;
        return -1;
    }
    else{
        return stack1->data[stack1->top];
    }
}

int Pop(Stack* stack1){
    if (isEmpty(stack1)){
        cout<<"Error 'Stack underflow'"<<endl;
        cout<<endl;
        return -1;
    }
    else{
        stack1->top -= 1;
        return stack1->data[stack1->top + 1];
    }
    
}

void Push(Stack* stack1, int x){
    stack1->top += 1;
    if (stack1->top == stack1->size){
        cout<<"Error 'Stack overflow'"<<endl;
        cout<<endl;
    }
    else{
        stack1->data[stack1->top] = x;
    }
}

int main(){

    Stack* stack1 = new Stack;

    int randArray[14];
    for(int i=0; i < 14; i++){
        randArray[i] =  1 + (rand() % 49); //Generate number between 1 to 50
    }

    for (int j = 0; j < 10; j++){
        Push(stack1, randArray[j]);
    }

    Display(stack1);

    for (int j = 0; j < 5; j++){
        Pop(stack1);
    }

    Display(stack1);
    
    for (int j = 10; j < 14; j++){
        Push(stack1, randArray[j]);
    }

    Display(stack1);

}