//Zakeriya Muhumed || CS163 || Assignemnt 2
#include "queue.h"

//Queue Constructor
queue::queue(){
    node2 * rear= nullptr;
}

//Queue Destructor 
queue::~queue(){
    node2 * temp = nullptr;
    if(!rear){
        return;
    }
    while(rear != rear->next){
        temp= rear -> next;
        rear ->next = temp-> next;
        if(temp){
            delete [] temp->entry.name;
            delete [] temp->entry.description;
            delete [] temp->entry.type;
        }   
        delete temp;
        temp = nullptr;

    }
    kf(rear){
        delete [] rear->entry.name;
        delete [] rear->entry.description;
        delete [] rear->entry.type;
    }
    delete rear;
    rear= nullptr;
}

int queue::enqueue(const bill & user_data){
    /*
       temp = ptr → next; ///pointer to the first node
       ptr→ next = new node; // create a new node 
       store your data
       ptr = ptr → next; //travel to the new node
       ptr → next = temp; /// the pointer to the new node is the first node
     */
    if(!rear){
        rear = new node2;
        rear->entry.name = new char[strlen(user_data.name) +1];
        strcpy(rear->entry.name, user_data.name);
        rear->entry.description = new char[strlen(user_data.description) +1];
        strcpy(rear->entry.description, user_data.description);
        rear->entry.type = new char[strlen(user_data.type) +1];
        strcpy(rear->entry.type, user_data.type);
        rear-> entry.amount = user_data.amount;
        rear-> entry.day = user_data.day; 
        rear-> next =rear;
        return 1;
    }
    else{
        node2 * temp = rear->next;
        rear->next = new node2;
        rear->entry.name = new char[strlen(user_data.name) +1];
        strcpy(rear->entry.name, user_data.name);
        rear->entry.description = new char[strlen(user_data.description) +1];
        strcpy(rear->entry.description, user_data.description);
        rear->entry.type = new char[strlen(user_data.type) +1];
        strcpy(rear->entry.type, user_data.type);
        rear-> entry.amount = user_data.amount;
        rear-> entry.day = user_data.day; 
        rear = rear->next;
        rear->next = temp;
    }
    return 1;

}

int queue::dequeue(const bill & user_data){

    /*
       if !rear ----> return 0
       if rear->next = rear  ----> delete rear & rear = nullptr & return 1
       else  delete with temp
       return 1
     */
    node2 * temp = nullptr;

    if(!rear){
        return 0;
    }
    if(rear->next == rear){
        delete rear;
        rear = nullptr;
        return 1;
    }
    else{
        temp = rear->next;
        rear->next = temp->next;
        delete temp;
    }
    return 1;
}

int queue::peek(bill & user_data)const{

    /*
       if !rear----> return 0
       else  display rear ..
       return 1
     */
    if(!rear){
        return 0;
    }
    else{
        cout <<"\n" << rear-> entry.name << " || "; 
        cout << rear-> entry.amount << " || ";
        cout << rear-> entry.description << " || ";
        cout << rear-> entry.type << " || ";
        cout << rear-> entry.day;
        cout << endl;

    }
    return 1;
}

int queue::display_queue(){
    if(!rear){
        return 0;
    }
    return display_queue(rear->next, rear); 
}

int queue:: display_queue(node2 * post, node2 * rear2){

    cout <<"\n" << post-> entry.name << " || "; 
    cout << post-> entry.amount << " || ";
    cout << post-> entry.description << " || ";
    cout << post-> entry.type << " || ";
    cout << post-> entry.day;
    cout << endl;

    if(rear2 == post){
        return 1;
    }
    else{
        display_queue(post->next,rear2);
    }

    return 0;
}
