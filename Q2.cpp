#include <iostream>

using namespace std;

float given_data[3][13] = {{0.0107,0.0235,0.0672,0.0864,0.1087,0.1759,0.1397,0.1077,0.1013,0.0746,0.0501,0.033,0.0212},
                            {0.018,0.033,0.088,0.112,0.142,0.229,0.182,0.104,0.065,0.025,0.002,0,0},
                            {0,0,0,0,0,0,0.1023,0.1195,0.2198,0.2391,0.1877,0.1427,0.0912}};

void prep_cumulative() {
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 13; ++i) {
            for (int j = i + 1; j < 13; j++) {
                given_data[k][i] += given_data[k][j];
            }
        }
    }
}

void main_calc(int col) { 
    // remove the +1 if even number
    float yF = 1 - given_data[0][col + 1];
    float yP = 1 - given_data[1][col + 1];
    float yR = 1 - given_data[2][col + 1];
    float recovery=((yF-yR)/(yP-yR))*(yP/yF);
    float rejection=1-(((yF-yR)/(yP-yR))*((1-yP)/(1-yF)));
    float effectiveness=recovery*rejection;
    cout<<"\n Recovery : "<<recovery*100<<"%\n Rejection : "<<rejection*100
    <<"%\n Effectiveness : "<<effectiveness*100<<"%";
}

int main() {
    prep_cumulative();
    cout<<"The cumulative analysis is : ";
    for (int i = 0; i<13; i++) {
        for (int j = 0; j<3; j++)
            cout << given_data[j][i]<<" ";
        cout<<endl;
    }

    int index = 10; // rno dependent

    main_calc(index);
    return 0;
}