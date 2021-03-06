#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double mass_flow = 2000.0/3600; //in kg/s
    double d_f = 0.025 * 1000; // in mm
    double d_p = 0.018 * 1000; // in mm
    int x  = 3; //Roll Number 20CH10016
    double d_pnew = (2*x); // in mm
    double initial_power = 8.54; // in Hp
    int rate = 2000; // in Kg/hour

    // part (A) //
    double k_b; //Bond's constant
    // work_bond = k_b*((1/sqrt(d_p) - (1/sqrt(d_f)))
    double t = (1/sqrt(d_p)) - (1/sqrt(d_f));
    k_b = initial_power/(mass_flow*t);
    double t1 = (1/sqrt(d_pnew)) - (1/sqrt(d_f));
    double final_power =  (k_b)*t1*mass_flow;
    cout << "Ans (a): The power consumption is " << final_power << "Hp." << endl;

    // part (B) //
    double k_k; //Kick's constant
    // work_kick = k_k*ln(df/dp)
    k_k = initial_power/(mass_flow*log(d_f/d_p));
    final_power =  (k_k)*log(d_f/d_pnew)*mass_flow;
    cout << "Ans (b): The power consumption using Kick's Law is " << final_power << "Hp." << endl;
    return 0;
}
