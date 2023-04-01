//Zakeriya Muhumed || CS163 || Assignemnt 4
#ifndef node_h
#define node_h

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

class node
{
    public:

        node();
        ~node();
        
        int create_node(char *inname, char * inpower, char *inspecies, char * inbio);

        int compare_node(node * temp);
        int compare(char * inname);

        int display();

        int copy_node(node * hero);
        int display_power();

        node * left;
        node * right;
    private:
        char * name;
        char * power;
        char * species;
        char * bio;
};

#endif

