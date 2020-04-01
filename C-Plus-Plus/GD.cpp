#include <iostream>
#include <utility>
#include <vector>
#include "GD.h"

using namespace std;

int main()
{
 
    //样本数据
    pair<double, double> p1(0,1.1);
    pair<double, double> p2(1, 2.1);
    pair<double, double> p3(2, 3.2);
    pair<double, double> p4(3, 4.3);
 
    vector<pair<double, double>> data;
    
    data.push_back(p1);
    data.push_back(p2);
    data.push_back(p3);
    data.push_back(p4);
    //
 
    //训练数据，得出结果
    pair<double, double> p_res;
    GD gd;
    p_res=gd.trian_data_2(data);//y=wx+b
    //
 
    cout << " The training is done! " <<endl;
    cout << " thetazero " <<p_res.first << " thetaone " << p_res.second << endl;
 
    double x;
    cout << " input x: ";
    cin >> x;
    cout << p_res.first + p_res.second*x << endl;
 
}

