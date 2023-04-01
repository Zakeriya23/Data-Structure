//Zakeriya Muhumed || CS163 || Assignemnt 4
#include "task.h"
using namespace std;

const int MAX =101;

//constructor
Task::Task(){
    root = nullptr;
}

//destructor
Task:: ~Task(){
    delete root;
}

//Inset task wapper function
int Task::insert(node * hero){
    return insert(root, hero);
}
//insert recursive function 
int Task:: insert(node *& root, node * hero){
    if(!root){
        root = new node;
        root->copy_node(hero);
        root ->left = nullptr;
        root ->right = nullptr;
        return 1;
    }
    int compare = hero->compare_node(root);

    if(compare == 1|| compare ==0)
       insert(root-> right, hero);
    insert(root-> left, hero);
}


//wapper retrieve function
int Task::retrieve(char * inname){
    if(!root){
        return 0;
    }
    return retrieve(inname, root);
}
//recursive function 
int Task:: retrieve(char * inname, node *& root){
    if(!root){
        return 0;
    }
    int compare = root->compare(inname);
    if(compare==0){//Match
        return 1;
    }
    else if(compare==1){
        return retrieve(inname,root-> left);
    }
    else if(compare ==2){
        return retrieve(inname, root-> right);
    }
    return 0;
}

//Load function
int Task:: load(){
    ifstream infile;

    
    int count =0; 
    infile.open(out);
    if(!infile){
        cout<<"Text file not found!!"<<endl;
        return -1;
    }
    if(infile){
        char inname[MAX];
        char inpower[MAX];
        char inspecies [MAX];
        char inbio [MAX];
           
        
        cout <<"\nFile opened" <<endl << endl;
        
        infile.getline(inname,MAX,'|');
        
        while(!infile.eof()){
            
            infile.getline(inpower,MAX, '|');

            infile.getline(inspecies,MAX,'|');
        
            infile.getline(inbio,MAX,'\n');

            node * hero= new node;

            hero->create_node(inname, inpower, inspecies, inbio);
            insert(hero);

            ++count;
            memset(inname,0,MAX);
            memset(inpower,0,MAX);
            memset(inspecies,0,MAX);
            memset(inbio,0,MAX);
            infile.getline(inname,MAX,'|');
        }

    }
    infile.close();
    return count;
}

//Display all wapper function 
int Task::display_table(){
    if(!root){
        return 0;
    }
    return display_tree(root);
}
//recursive function 
int Task::display_tree(node * root){
    if(!root){
        return 0;
    }
    root -> display();
    return display_tree(root->left);
    return display_tree(root->right);
    return 1;
}

//Wapper display specific name function
int Task::display_name(char *inname){
    if (!inname) return 0;
    if(!root)return 0;
    return display_name(inname, root);
} 
//recursive function 
int Task:: display_name(char * inname, node *& root){
    if(!root)return 0;
    int compare= root->compare(inname);
    if(compare==0){//Match
        root -> display();
        return display_name(inname, root-> left);
        return display_name(inname, root-> right);
    }
    else if(compare==1){
        return display_name(inname,root-> right);
    }
    else if(compare ==2){
        return remove(inname, root-> left);
    }
    return 0;

}

// Display all poewr function 
int Task::display_ability(){
    if (!root) return 0;
    cout << "ALL POWER: " << endl << endl;
    return display_power(root);
} 
//recursive function 
int Task:: display_power(node *& root){

    if(!root)return 0;
    root -> display_power();
    cout << endl;
    return display_power(root->left);
    return display_power(root->right);
    return 1;
}


//wapper fuction for remove
int Task::remove(char * inname){
   
    if(!root){
        return 0;
    }
    return remove(inname,root);
}

//TWO children, need to found out the children.
node * Successor(node *&root){
    if(!root -> left){
        node* child = root;
        if(root -> right){
            root = root -> right;
        }
        else{
            root = nullptr;
        }
        child -> left =child -> right = nullptr;
        return child;
    }
    else{
        return Successor(root -> left);
    }

}
//recursive function 
int Task::remove(char * inname, node *& root){

    if (!root){
        return 1;
    } 
    int compare = root->compare(inname);

    if(compare==0){//Match
       if(!root->right && !root->left){
            delete root;
            root = nullptr;
       }
       else if(!root->left){
            node * temp = root;
            root = root -> right;
            temp -> right = nullptr;
            delete temp;
            temp = nullptr;
       }
       else if(!root->right){
            node * temp = root;
            root = root -> left;
            root ->left = nullptr;
            delete temp;
            temp = nullptr;
       }
       else{
            node * childd = Successor(root->right);
            childd -> left = root-> left;
            childd -> right = root -> right;
            root -> right = root -> left = nullptr;
            delete root;
            root = childd;
            childd = nullptr;
       }
        return remove(inname,root);
    }
    else if(compare==1){//less
        return remove(inname,root-> left);
    }
    else if(compare ==2){//data is bigger
        return remove(inname, root-> right);
    }
    return 0;
}

