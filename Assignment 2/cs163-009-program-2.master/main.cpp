//Zakeriya Muhumed || CS163 || Assignemnt 2
//Main file
/******************************************************************************
# Author:           Zakeriya Muhumed
# Assignment:       A02 (CS163)
# Date:             Feb 4, 2022
# Sources:          Assignment 2 instruction
#******************************************************************************/

#include "stack.h"
#include "queue.h"

int main(){ 

    stack user_stack;
    queue user_queue;

    bill user_data;

    int choice;

    while(choice != 9){
        cout<< "Pick 1-9 options" << endl;
        cout <<"\t1) Push onto stack "<< endl;
        cout <<"\t2) Pop stack " << endl;
        cout <<"\t3) Peek stack " << endl;
        cout <<"\t4) Display stack " << endl;
        cout <<"\t5) Enqueue" <<endl;
        cout <<"\t6) Dequeue" << endl;
        cout <<"\t7) Peek queue" << endl;
        cout <<"\t8) Display queue" << endl;
        cout <<"\t9) Quit " <<endl;
        cout <<"\n\t\t--->";
        cin >> choice; 
        cin.ignore();	

        while((choice < 1 && choice > 9) || (!cin)){
            cin>> choice;
            cin.ignore();
        }
        switch(choice){
            case 1://Push

                user_data.name= new char[100];
                user_data.description= new char[100];
                user_data.type= new char[100];

                cout <<"\t\nName of the payee: ";
                cin.get(user_data.name,100, '\n');
                cin.ignore(100, '\n');

                cout <<"\t\nThe amount of the bill: ";
                cin >> user_data.amount ;
                cin.ignore(100, '\n');

                cout <<"\t\nA description of what it was used for : ";
                cin.get(user_data.description, '\n');
                cin.ignore(100, '\n');

                cout <<"\t\nThe type of expense: ";
                cin.get(user_data.type, '\n');
                cin.ignore(100, '\n');

                cout<< "\t\nDay its due:";
                cin >>user_data.day ;
                cin.ignore(100, '\n');

                if(user_stack.push(user_data)==1){
                    cout << "Push successfull!! " << endl;
                }
                else{
                    cout <<"Unsuccessfull push!! " << endl;
                }

                delete [] user_data.name;
                delete [] user_data.description;
                delete [] user_data.type;

                user_data.name = nullptr;
                user_data.description = nullptr;
                user_data.type= nullptr;

                break;
            case 2://Pop

                if(user_stack.pop(user_data)==0){
                    cout << "\nPop unsuccessful" << endl;
                }
                else {
                    cout << " Pop Successful" << endl;
                }

                break;
            case 3://Peek Stack
                if(user_stack.peek(user_data)== 0){
                    cout << "!Peek, Empty Stack"<< endl;
                }

                break;
            case 4://Display Stack
                if(user_stack.display_stack()== 0){
                    cout << "!Display, Empty Stack"<< endl;
                }

                break;	
            case 5:// Enquene 

                user_data.name= new char[100];
                user_data.description= new char[100];
                user_data.type= new char[100];

                cout <<"\t\nName of the payee: ";
                cin.get(user_data.name,100, '\n');
                cin.ignore(100, '\n');

                cout <<"\t\nThe amount of the bill: ";
                cin >> user_data.amount ;
                cin.ignore(100, '\n');

                cout <<"\t\nA description of what it was used for : ";
                cin.get(user_data.description, '\n');
                cin.ignore(100, '\n');

                cout <<"\t\nThe type of expense: ";
                cin.get(user_data.type, '\n');
                cin.ignore(100, '\n');

                cout<< "\t\nDay its due:";
                cin >>user_data.day ;
                cin.ignore(100, '\n');

                if(user_queue.enqueue(user_data)==1){
                    cout << "Enquene Successful!!!" <<endl;
                }
                else{
                    cout << "Enquene Unsuccessfull!!!"<< endl;
                }

                delete [] user_data.name;
                delete [] user_data.description;
                delete [] user_data.type;

                user_data.name = nullptr;
                user_data.description = nullptr;
                user_data.type= nullptr;

                break;
            case 6://Dequeue 

                if(user_queue.dequeue(user_data)==1){
                    cout <<"Dequeue sucessful" <<endl;
                }
                else{
                    cout <<"Dequeue unsucessful" <<endl;
                }


                break;
            case 7://Peek Queue

                if(user_queue.peek(user_data)==0){
                    cout <<"Peek quenue unsucessful" <<endl;
                }
                break;

            case 8://Display Queue


                if(user_queue.display_queue()==0){
                    cout <<"Display quenue unsucessful" <<endl;
                }

                break;
            case 9://QUIT
                cout << "Thank you for using this program" << endl;
                break;
        }
    }
    return 0; 
}
