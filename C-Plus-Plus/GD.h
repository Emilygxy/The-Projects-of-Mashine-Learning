#ifndef __GD_H__
#define __GD_H__

#include <vector>
using namespace std;

class GD
{
private:
    /* data */
public:
    GD(/* args */);
    ~GD();

    pair<double,double> trian_data_2(vector<pair<double,double>> v);
    pair<double,double> trian_data_3(vector<pair<double,double>> v);
};

GD::GD(/* args */)
{
}

GD::~GD()
{
}

 /*
 实现梯度下降算法：
 使用梯度下降算法求：f(x)=wx+b
 其中，w,b是要求的超参数
 */
pair<double,double> GD::trian_data_2(vector<pair<double,double>> v)
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

/*
已知四个点（0.5，0.2）（1，0.5）（1.5，1.5）（1.8，2.3），
用梯度下降算法求y=ax^2+bx+c中未知的a,b,c怎么写啊？
*/

#endif