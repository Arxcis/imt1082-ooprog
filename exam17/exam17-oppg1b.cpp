
//  Fil:  FRODEH \ OO \ EXTRAMEN \ EX_V17_1B.CPP

//  L›sning til eksamen i OOP, 22.mai 2017, oppgave 1B.
//  Laget av Frode Haug, NTNU


#include <iostream>
using namespace std;

char txt[] = "ETERNITTPLATENE-OG-TAKPAPPEN-BLE-KASTET";

void funksjon(char* t)  {
    while (*t != 'T')  cout << *t++;
}

char funksjon(char* t1, char* t2)  {
    while (*t1 == *t2) {  t1++;  t2++;  };   return *t1;
}

void funksjon(char* t, int n)  {
    t+= n;  while (*t > 'H')  cout << *t++;
}

void funksjon(char* t1, char* t2, int n)  {
   while (t1 < t2)  { ++t1;  t2 -= n; }  cout << *t1 << *t2;
}

char* funksjon(int n, int m, char c, char* t)  {

    while (m < n) 
    { 
        if (*t == c)
        {
            m++;
        } 

        t++; 
    } 
    return ++t;
}


int main()  {

    funksjon(txt,) << '\n';

    cout << funksjon(txt + 1, txt + 36) << '\n';
g   funksjon(txt,) << '\n';
    funksjon(txt,) << '\n';
    cout << funksjon(9, 3, 'E', txt)    << '\n'; // what has been going on lately?
    return SUCCESS;
}

//  E R N I T T P L  A  T  E  N  E  -  O  G
//  "0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17";

//  1. funksjon(txt+8)                 - 'PLA'
//  2. cout << funksjon(txt+1, txt+36) - 'R' 
//  3. funksjon(txt, 3)                - 'ERNITTPL' 
//  4. funksjon(txt, txt+27, 3)        - 'KASTET'

//   T  A  K  P  A  P  P  E  N  -  B  L  E  -  K  A  S  T  E  T ";
//  18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37
