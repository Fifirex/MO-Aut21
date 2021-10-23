#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    double sphericity = 0.571;
    double density = 2650; //in kg/cubic-m
 //   density /= pow(10, 9); // in kg/cubic-mm
    vector<int> mesh_number{4, 6, 8, 10, 14, 20, 28, 35, 48, 65, 100, 150, 200};
    vector<double> mass_frac{0., 0.0251, 0.1250, 0.3207, 0.2570, 0.1590, 0.0538, 0.0210, 0.0102, 0.0077, 0.0058, 0.0041, 0.0031};
    vector<double> width{4760., 3360., 2380., 2000., 1410., 840., 589., 500., 297., 210., 149., 105., 74., }; 
    //Pan 0.0075
    double cfrac = 0; //cumulative fraction
    double d_avg;
    double mass_mean_diameter=0, volume_mean_diameter = 0, volume_surface_mean_diameter = 0, average_specific_surface_area = 0;
    for(int i=0; i<mesh_number.size(); i++){
        cfrac+= mass_frac[i];
        if(i==0){
            d_avg = width[i];
        }
        else if(i == mesh_number.size()-1){
            d_avg  = width[i]/2;
        }
        else d_avg = (width[i] + width[i-1])/2.0;
        d_avg = d_avg/1000; // in mm
        mass_mean_diameter += d_avg*mass_frac[i];
        volume_mean_diameter += mass_frac[i]/pow(d_avg,3);
        volume_surface_mean_diameter += mass_frac[i]/d_avg;
        average_specific_surface_area += mass_frac[i]/d_avg;
    }
    volume_mean_diameter = pow((1/volume_mean_diameter), (1.0/3));
    volume_surface_mean_diameter = 1/volume_surface_mean_diameter;
    average_specific_surface_area *= 1000*6/(density*sphericity);
    // cout << cfrac;
    cout << "A) The mass mean diamater is " << mass_mean_diameter << " mm" << endl;
    cout << "B) The volume mean diameter is " << volume_mean_diameter << " mm" << endl;
    cout << "C) The volume surface mean diameter is " << volume_surface_mean_diameter << " mm" << endl;
    cout << "D) The average specific surface area is " << average_specific_surface_area << " square m/kg" << endl;
    return 0;
}

