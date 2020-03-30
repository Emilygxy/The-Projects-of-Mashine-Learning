#include <iostream>
#include <utility>
#include <vector>
using namespace std;
 
 /*
 实现梯度下降算法：
 使用梯度下降算法求：f(x)=wx+b
 其中，w,b是要求的超参数
 */
pair<double,double> trian_data(vector<pair<double,double>> v)
{
    double theta_zero=0.0, theta_one=0.0;
 
    double studyspeed = 0.1;
    int size_v = v.size();
 
    int counts = 0;
 
    while (counts<100)
    {
        double theta_zero_copy = theta_zero;
        double theta_one_copy = theta_one;
 
        double total_zero=0.0;
        double differ_zero=0.0;
 
        double differ_one = 0.0;
        double total_one = 0.0;
 
        auto it = v.begin();
        for (;it != v.end();it++)
        {
            differ_zero = theta_zero_copy + theta_one_copy*(it->first) - (it->second);
 
            differ_one = differ_zero*(it->first);
 
            total_zero = total_zero + differ_zero;
 
            total_one = total_one + differ_one;
        }
 
 
        theta_zero = theta_zero - studyspeed*(double)(1.0 / size_v)*total_zero;
        theta_one = theta_one - studyspeed*(double)(1.0 / size_v)*total_one;
 
        counts++;
    }
 
    pair<double, double> result_data(theta_zero, theta_one);
    return result_data;
 
}
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
    p_res=trian_data(data);
    //
 
 
    cout << " thetazero " <<p_res.first << " thetaone " << p_res.second << endl;
 
    double x;
    cout << " input x ";
    cin >> x;
    cout << p_res.first + p_res.second*x << endl;
 
}

