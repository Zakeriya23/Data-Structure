//Zakeriya Muhumed || CS163 || Assignemnt 2
//data file
#include "data.h"
//Struct for circular linked list 
struct node2 {	
    bill entry;
    node2 * next;

};
//queue class 
class queue{
    public:
        queue();//constr
        ~queue();//deconstr
        int enqueue(const bill & user_data);//pass in const data
        int dequeue(const bill & user_data);//pass in const data
        int peek(bill & user_data)const;//pass in const data
        int display_queue();

    private:
        int display_queue(node2 * post, node2 * rear2);
        node2 *rear;
};

