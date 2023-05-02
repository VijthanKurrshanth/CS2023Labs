#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node{
    int data;
    Node* next_node;
};

struct Stack_ll{
    Node* head;
    int current_size = 0;
    
};

bool isEmpty_ll(Stack_ll* stack1){
    if (stack1->current_size == 0){
        return true;
    }
    else{
        return false;
    }
}

void Display_ll(Stack_ll* stack1){
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

int StackTop_ll(Stack_ll* stack1){
    if (isEmpty_ll(stack1)){
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

int Pop_ll(Stack_ll* stack1){
    if (isEmpty_ll(stack1)){
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

void Push_ll(Stack_ll* stack1, int x){
    if (isEmpty_ll(stack1)){
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

struct Stack_arr{
    int size = 30;
    int top = -1;
    int data[30];
    
};

bool isEmpty_arr(Stack_arr* stack1){
    if (stack1->top == -1){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(Stack_arr* stack1){
    if (stack1->top == (stack1->size - 1)){
        return true;
    }
    else{
        return false;
    }
}

void Display_arr(Stack_arr* stack1){
    for (int i = stack1->top; i >= 0; i--){
        cout<<stack1->data[i]<<" ";
    }
    cout<<endl<<endl;
}

int StackTop_arr(Stack_arr* stack1){
    if (isEmpty_arr(stack1)){
        cout<<"Empty stack"<<endl;
        cout<<endl;
        return -1;
    }
    else{
        return stack1->data[stack1->top];
    }
}

int Pop_arr(Stack_arr* stack1){
    if (isEmpty_arr(stack1)){
        cout<<"Error 'Stack underflow'"<<endl;
        cout<<endl;
        return -1;
    }
    else{
        stack1->top -= 1;
        return stack1->data[stack1->top + 1];
    }
    
}

void Push_arr(Stack_arr* stack1, int x){
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

    int randArray[14];
    for(int i=0; i < 14; i++){
        randArray[i] =  1 + (rand() % 49); //Generate number between 1 to 50
    }

    high_resolution_clock::time_point start1 = high_resolution_clock::now();
    Stack_arr* stack1 = new Stack_arr;
    for (int j = 0; j < 10; j++){
        Push_arr(stack1, randArray[j]);
    }

    Display_arr(stack1);

    for (int j = 0; j < 5; j++){
        Pop_arr(stack1);
    }

    Display_arr(stack1);
    
    for (int j = 10; j < 14; j++){
        Push_arr(stack1, randArray[j]);
    }

    Display_arr(stack1);
    high_resolution_clock::time_point stop1 = high_resolution_clock::now();
    
    auto timetakenArray = duration_cast<nanoseconds>(stop1 - start1).count();

    high_resolution_clock::time_point start2 = high_resolution_clock::now();
    Stack_ll* stack2 = new Stack_ll;
    for (int j = 0; j < 10; j++){
        Push_ll(stack2, randArray[j]);
    }

    Display_ll(stack2);

    for (int j = 0; j < 5; j++){
        Pop_ll(stack2);
    }

    Display_ll(stack2);
    
    for (int j = 10; j < 14; j++){
        Push_ll(stack2, randArray[j]);
    }

    Display_ll(stack2);
    high_resolution_clock::time_point stop2 = high_resolution_clock::now();
    
    auto timetakenLinkedList = duration_cast<nanoseconds>(stop2 - start2).count();
    

    cout<<"Time taken for Array implementation "<<timetakenArray<<" nanoseconds"<<endl;
    cout<<"Time taken for Linked list implementation "<<timetakenLinkedList<<" nanoseconds"<<endl;
}