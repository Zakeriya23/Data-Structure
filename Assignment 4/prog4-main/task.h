//Zakeriya Muhumed || CS163 || Assignemnt 4
#ifndef Task_h
#define Task_h

#include "hero.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cmath>
#include <fstream>

const char out[]="hero.txt";

class Task {
    public:
        Task();
        ~Task();

        int insert(node * hero);

        int load();

        int remove(char * inname);

        int retrieve(char * inname);

        int display_table();

        int display_ability();

        int display_name(char * inname);;
    private:
        node * root;

        //Recurive functions
        int insert(node *& root, node * hero);

        int remove(char * inname, node *& root);

        int display_tree(node * root);

        int display_power(node *& root);

        int display_name(char *inname, node *& root);

        int retrieve(char * inname, node *& root);
};

#endif
