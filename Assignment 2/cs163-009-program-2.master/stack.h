//Zakeriya Muhumed || CS163 || Assignemnt 2

#include "data.h"
//Node for stack
struct node {
    bill * entries;
    node * next;
};

const int MAX = 5;

//Stack class 
class stack{ 
    public:
        stack();//constr
        ~stack();//deconstr
        int push(const bill & user_data);
        int pop(bill & user_data);
        int peek(bill & user_data)const;
        int display_stack();

    private:
        node * head;
        int top;
        int display_stack(node * post, int pos);
};

