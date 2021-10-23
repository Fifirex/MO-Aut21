#include <iostream>
#include <math.h>

using namespace std;

float given_data[5][4] = {{3.65, 0.20, 0.44, 0.10},
                        {1.76, 0.30, 0.22, 0.20},
                        {0.87, 0.30, 0.11, 0.30},
                        {0.44, 0.15, 0.04, 0.30},
                        {0.22, 0.05, 0.02, 0.10}};

int rate = 1; // ton/hr
int Pt = 15; // kW

float Df = 50.8;            // mm
float Dp1 = 0;              // mm
float Dp2 = 0;              // mm

float P1 = 0; // kW
float P2 = 0; // kW

void prep_cumulative() { 
    for (int i = 0; i<5; i++) 
        Dp1 += (given_data[i][1]/given_data[i][0]);
    Dp1 = 1/Dp1;
    for (int i = 0; i<5; i++)
        Dp2 += given_data[i][3]/given_data[i][2];
    Dp2 = 1/Dp2;
    
    cout<<"\n Volume surface mean diameter of product from grinder 1 : "<<Dp1<<" mm";
    cout<<"\n Volume surface mean diameter of product from grinder 2 : "<<Dp2<<" mm";
}

void rettinger() {
    float Kr = Pt/((1/Dp1 + 1/Dp2 - 2/Df)*rate); 
    
    P1 = rate*Kr*(1/Dp1 - 1/Df);
    P2 = rate*Kr*(1/Dp2 - 1/Df);

    cout<<"\n\n Rettinger's Law";
    cout<<"\n Power consumed by first grinder  : "<<P1<<" kW";
    cout<<"\n Power consumed by second grinder : "<<P2<<" kW";
}

void kick() {
    float Kk = Pt/((1/log(Dp1) + 1/log(Dp2) - 2/log(Df))*rate);

    P1 = rate*Kk*(1/log(Dp1) - 1/log(Df));
    P2 = rate*Kk*(1/log(Dp2) - 1/log(Df));
    
    cout<<"\n\n Kick's Law";
    cout<<"\n Power consumed by first grinder  : "<<P1<<" kW";
    cout<<"\n Power consumed by second grinder : "<<P2<<" kW";
}

void bond() {
    float Kb = Pt/((1/sqrt(Dp1) + 1/sqrt(Dp2) - 2/sqrt(Df))*rate);

    P1 = rate*Kb*(1/sqrt(Dp1) - 1/sqrt(Df));
    P2 = rate*Kb*(1/sqrt(Dp2) - 1/sqrt(Df));

    cout<<"\n\n Bond's Law";
    cout<<"\n Power consumed by first grinder  : "<<P1<<" kW";
    cout<<"\n Power consumed by second grinder : "<<P2<<" kW";
}

int main() {
    prep_cumulative();

    rettinger();
    kick();
    bond();
    return 0;
}