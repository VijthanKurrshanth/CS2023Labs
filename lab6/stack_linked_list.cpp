#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next_node;
};

struct Stack{
    Node* head;
    int current_size = 0;
    
};

bool isEmpty(Stack* stack1){
    if (stack1->current_size == 0){
        return true;
    }
    else{
        return false;
    }
}

void Display(Stack* stack1){
    Node* current_node = stack1->head;
    int data_array[stack1->current_size];
    for (int i = 0; i < stack1->current_size; i++){
        data_array[i] = current_node->data;
        current_node = current_node->next_node;
    }

    for (int i = stack1->current_size-1; i >=0 ; i--){
        cout<<data_array[i]<<" ";
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
        Node* current_node = stack1->head;
        while (current_node->next_node != NULL){
            current_node = current_node->next_node;
        }
        return current_node->data;
    }
}

int Pop(Stack* stack1){
    if (isEmpty(stack1)){
        cout<<"Error 'Stack underflow'"<<endl;
        cout<<endl;
        return -1;
    }
    else{
        Node* current_node = stack1->head;
        Node* previous_node;
        while (current_node->next_node != NULL){
            previous_node = current_node;
            current_node = current_node->next_node;
        }
        previous_node->next_node = NULL;
        int top_data = current_node->data;
        delete current_node;
        stack1->current_size -= 1;
        return top_data;
    }
    
}

void Push(Stack* stack1, int x){
    if (isEmpty(stack1)){
        stack1->head = new Node;
        stack1->current_size = 1;
        stack1->head->data = x;
        stack1->head->next_node = NULL;
    }
    else{
        Node* new_node = new Node;
        new_node->data = x;
        new_node->next_node = NULL;
        Node* current_node = stack1->head;
        while (current_node->next_node != NULL){
            current_node = current_node->next_node;
        }
        current_node->next_node = new_node;
        stack1->current_size += 1;
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