//Zakeriya Muhumed || CS163 || Assignemnt 4
#include "hero.h"
using namespace std;

node :: node(){

    name = nullptr;
    power= nullptr;
    species = nullptr;
    bio = nullptr;

    left = nullptr;
    right = nullptr;
}
node :: ~node(){
    delete []name;
    delete []power;
    delete []species;
    delete []bio;
    if(left){
        delete left;
    }
    if(right){
        delete right;
    }
}
int node::create_node(char *inname, char * inpower, char *inspecies, char * inbio){
    name = new char[strlen(inname)+1];
    strcpy(name, inname);

    power=new char[strlen(inpower)+1];
    strcpy(power, inpower);

    species=new char[strlen(inspecies)+1];
    strcpy(species, inspecies);

    bio=new char[strlen(inbio)+1];
    strcpy(bio, inbio);

    return 1;

}
int node::display(){
    cout<<"\nName: " << name<<endl;
    cout<<"Power: " << power<<endl;
    cout<<"Species: " << species<<endl;
    cout<<"Description: " << bio<<endl;
    return 1;
}
int node::copy_node(node * hero){

    name = new char[strlen(hero -> name) + 1];
    strcpy(name, hero -> name);

    power = new char[strlen(hero -> power) + 1];
    strcpy(power, hero -> power);

    species= new char[strlen(hero -> species) + 1];
    strcpy(species, hero -> species);

    bio = new char[strlen(hero -> bio) + 1];
    strcpy(bio, hero -> bio);

    return 1;
}
int node :: compare_node(node * temp){
    int num = compare(temp->name);
    return num;

}
int node :: compare(char *inname){
        if(strcmp(name,inname)== 0){//same data
            return 0;
        }
        else if(strcmp(name,inname)>0){//less ->left
            return 1;
        }   
        else{//bigger -> right
            return 2;
        }

}
int node :: display_power(){
    cout << "\t" << power << endl;
    return 1;
}
