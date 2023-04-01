//Zakeriya Muhumed || CS163 || Assignemnt 2
//data file
//Libray
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <string>

using namespace std; 

#ifndef JOURNAL
#define JOURNAL
//Data
struct bill{
    char * name;
    float amount;
    char * description;
    char * type;
    int day;
};
#endif
