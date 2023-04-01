//Zakeriya Muhumed || CS163 || Assignemnt 2
#include "stack.h"

stack::stack(){
    node *head= nullptr;
    top = 0;
}

stack::~stack(){
    node * temp = nullptr;
    if(!head){
        return;
    }
    while(head){
        temp= head;
        head = head -> next;
        for(top = 0; top<MAX; ++ top){
            if(temp->entries[top].name){
                delete [] temp->entries[top].name;
                temp->entries[top].name = nullptr;
            }   
            if(temp->entries[top].description){
                delete [] temp->entries[top].description;
                temp->entries[top].description = nullptr;
            } 
            if(temp->entries[top].type){
                delete [] temp->entries[top].type;
                temp->entries[top].type = nullptr;
            } 
        }
        delete [] temp->entries;
        temp->entries = nullptr;
        temp->next = nullptr;
        delete temp;
        temp = nullptr;
        top = 0;
    }
    head = nullptr;
}

int stack::push(const bill & user_data){

    if(!head){
        head = new node;
        head->entries = new bill[MAX]; 
        head -> next = nullptr;
        top = 0;
    }
    if(5 == top){
        node * temp = new node;
        temp-> next = head;
        temp-> entries = new bill[MAX];
        head = temp;
        top =0;
    }
    else{
        head->entries[top].name = new char[strlen(user_data.name) +1];
        strcpy(head->entries[top].name, user_data.name);
        head->entries[top].description = new char[strlen(user_data.description) +1];
        strcpy(head->entries[top].description, user_data.description);
        head->entries[top].type = new char[strlen(user_data.type) +1];
        strcpy(head->entries[top].type, user_data.type);
        head-> entries[top].amount = user_data.amount;
        head-> entries[top].day = user_data.amount; 
        ++top;
    }
    return 1;

    //ALGO
    /*
       Empty list:
       New node 
       Store the data
       Set top index to 0
       Not empty & top index < size 
       Store the data at the top 
       Increase top++
       First array is full (top == size)
       Add a new node at the beginning
       Add */
}

int stack::pop(bill & user_data){

    if(!head){
        return 0;
    }
    --top;
    node * temp = head -> next;

    if(!top){
        if(head -> entries){
            delete [] head -> entries;
            delete head;
            head = temp;
            top = MAX;
        }
        if(!head) 
            top = 0;

    }
    return 1;
    //ALGO
    /*
       Empty 
       Return failure (nothing)
       Top index greater than 1
       Decrement top 
       If dyn memory, delete it (can't delete elements)
       Top index is 1
       Decrement top 
       Delete dyno memory as appropriate (delete dyn arrays)
       Delete the first node(the second node is now head
       If head is NULL, set top to zero
     */
}

int stack::peek(bill & user_data)const{
    int pos = top;

    if(!head) {
        return 0;
    }
    else{

        cout <<"\n" << head-> entries[pos-1].name << " || "; 
        cout << head-> entries[pos-1].amount << " || ";
        cout << head-> entries[pos-1].description << " || ";
        cout << head-> entries[pos-1].type << " || ";
        cout << head-> entries[pos-1].day;
        cout << endl;
    }
    return 0;
}

int stack::display_stack(){

    if(!head){
        return 0;
    }

    int pos = top;
    for(int i = pos-1; i >= 0; --i){
        cout <<"\n" << head-> entries[pos-1].name << " || "; 
        cout << head-> entries[pos-1].amount << " || ";
        cout << head-> entries[pos-1].description << " || ";
        cout << head-> entries[pos-1].type << " || ";
        cout << head-> entries[pos-1].day;
        cout << endl;
    }
    return display_stack(head-> next, pos);
}
int stack::display_stack(node * post, int pos){
    if(!post)
        return 1;
    for(int i = MAX-1; i>=0; --i){
        cout <<"\n" << post-> entries[pos-1].name << " || "; 
        cout << post-> entries[pos-1].amount << " || ";
        cout << post-> entries[pos-1].description << " || ";
        cout << post-> entries[pos-1].type << " || ";
        cout << post-> entries[pos-1].day;
        cout << endl;
    }
    if(pos< 0){
        return display_stack(post->next, pos);
    }
}
