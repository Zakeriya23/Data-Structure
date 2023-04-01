//Zakeriya Muhumed || CS163 || Assignemnt 4
/******************************************************************************
# Author:           Zakeriya Muhumed
# Assignment:       A04 (CS163)
# Date:             Feb 29, 2022
# Sources:          Assignment 4 instruction
#******************************************************************************/
#include "task.h"
#include "hero.h"

using namespace std;
int main(){
    int choice;
    Task user_table;
    while(choice != 8){
        cout<< "Pick 1-8 options" << endl;
        cout <<"\t1) Add a new character "<< endl;
        cout <<"\t2) Load information from external file " << endl;
        cout <<"\t3) Retrieve data" << endl;
        cout <<"\t4) Display all inorder" << endl;
        cout <<"\t5) Display specific name " << endl;
        cout <<"\t6) Display all power" <<endl;
        cout <<"\t7) Remove" << endl;
        cout <<"\t8) Quit";
        cout <<"\n\t\t--->";
        cin >> choice; 
        cin.ignore();	
        while((choice < 1 && choice > 7) || (!cin)){
            cout <<"\n\t\t--->";
            cin>> choice;
            cin.ignore();
        }
        switch(choice){
            case 1:{//Add a new character from client
                char * inname= new char[100];
                char * inpower= new char[100];
                char * inspecies= new char[100];
                char * inbio = new char[100];
                cout <<"\t\nName of the hero: ";
                cin.get(inname,100, '\n');
                cin.ignore(100, '\n');
                cout <<"\t\nPower of this hero: ";
                cin.get(inpower, '\n');
                cin.ignore(100, '\n');
                cout <<"\t\nSpecies of the hero: ";
                cin.get(inspecies, '\n');
                cin.ignore(100, '\n');
                cout <<"\t\nDescription of hero: ";
                cin.get(inbio, '\n');
                cin.ignore(100, '\n');
                
                node* hero= new node;
                hero -> create_node(inname, inpower, inspecies, inbio);
                if(user_table.insert(hero)==0){
                    cout << "\n\tUnsuccessfull insert!! " << endl;
                }
                else{
                    cout <<"\n\tsuccessfull insert!! " << endl;
                }
                delete [] inname;
                delete [] inpower;
                delete [] inspecies;
                delete [] inbio;
                delete hero;
                hero=nullptr;

                }break;

            case 2:{//Load from external files

                if(user_table.load()==0){
                    cout << "\tLoad unsuccessful" << endl;
                }
                else {
                    cout << "\tLoad Successful" << endl;
                }

                break;}

            case 3:{//Retrieve data

                char * inname= new char[100];

                cout <<"\t\nEnter the character name you would like to retrieve: ";
                cin.get(inname,100, '\n');
                cin.ignore(100, '\n');

                if(user_table.retrieve(inname)==1){
                    cout << "\n\tRetrieve successfull, Character found!!!" <<endl;
                }
                else{
                    cout << "Retrieve Unsuccessfull!!!"<< endl << endl;
                }
    
                delete [] inname;
                inname = nullptr;

                }break;

            case 4:{//Display table
                if(user_table.display_table()== 0){
                    cout << "\n\tDisplay Successful"<< endl<< endl;
                }
                else {
                    cout << "\n\tDisplay Unsuccessful" << endl << endl;
                }
                }break;
            case 5:{//Display specific name
                char * inname= new char[100];
                cout <<"\n\tEnter the character name you would like to display: ";
                cin.get(inname,100, '\n');
                cin.ignore(100, '\n');
                if(user_table.display_name(inname)== 0){
                    cout << "\nDisplay name Successful"<< endl;
                }
                else {
                    cout << "\nDisplay Unuccessful" << endl;
                }
                delete [] inname;
                inname = nullptr;
                }break;
            case 6:{//Display all powers
                if(user_table.display_ability()== 0){
                    cout << "\nDisplay power Successful"<< endl;
                }
                else {
                    cout << "\nDisplay power Unuccessful" << endl;
                }}break;
            case 7: {
                //Remove
                char * inname= new char[100];
                cout <<"\t\nEnter the character name you would like remove: ";
                cin.get(inname,100, '\n');
                cin.ignore(100, '\n');

                if(user_table.remove(inname)==0){
                    cout << "\n\tRemove unsuccessfull!!!" <<endl;
                }
                else{
                    cout << "\n\tRemove successfull!!!"<< endl;
                }
                delete [] inname;
                inname = nullptr;
                }break;
            case 8:{//QUIT
                cout << "\nThank you for using this program" << endl;
                }break;
        }
    }
    return 0;
}
