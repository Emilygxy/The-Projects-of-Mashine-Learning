#ifndef __BGD_H__
#define __BGD_H__
/*
批梯度下降（batch gradient descent）

处理一个样本的表达式：
θj:=θj+α(yi−(hθ(xi))xij	

转化为处理多个样本：
Repeat until convergence{
    θj:=θj+α∑m,i=1(yi−(hθ(xi))xij
}
α:步长（learning rate),控制θ每次向J(θ)变小的方向迭代时的变化幅度

在表达式中每一步都是计算的全部训练集的数据，所以称之为批梯度下降（batch gradient descent）。
注意，梯度下降可能得到局部最优，但在优化问题里已经证明线性回归只有一个最优点，因为损失函数J(θ)是一个二次的凸函数，不会产生局部最优的情况。（假设学习步长α不是特别大）

*/
// 利用批梯度下降算法求解线性回归 

class BGD
{
private:
    /* data */
public:
    BGD(/* args */);
    ~BGD();

    double predict(double* w, double* data, int feature_num);
    // 损失函数
    double Theta(double **training_set, int featue_num, int training_num, double* w);
    // 批梯度下降
    void gradient_descent(double** training_set, int feature_num, int training_num, double* w, double a, int iterator_time);
    // 特征归一化
    void feature_normalize(double **feature_set, int feature_num, int training_num);
    // 测试模型预测误差
    void forecast(double *forecast_set, double* w, int feature_num);

};

BGD::BGD(/* args */)
{
}

BGD::~BGD()
{
}

#endif