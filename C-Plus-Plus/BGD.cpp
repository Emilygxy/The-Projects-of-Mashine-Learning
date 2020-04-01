// 利用批梯度下降算法求解线性回归 
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "BGD.h"
using namespace std;

double BGD::predict(double* w, double* data, int feature_num){
    double sum = 0;
	for (int i = 0; i < feature_num; i++) {
		sum += w[i] * data[i];
	}
	return sum;
}

// 损失函数
double BGD::Theta(double **training_set, int featue_num, int training_num, double* w){
    double sum = 0;
	for (int i = 0; i < training_num; i++) {
		sum += (training_set[i][featue_num] - predict(w, training_set[i], featue_num))*(training_set[i][featue_num] - predict(w, training_set[i], featue_num));
	}
	return sum / (2 * training_num);
}
// 批梯度下降
void BGD::gradient_descent(double** training_set, int feature_num, int training_num, double* w, double a, int iterator_time){
    while (iterator_time--) {
		double* del_theta = new double[feature_num];
		for (int i = 0; i < feature_num; i++) {
			del_theta[i] = 0;
			for (int j = 0; j < training_num; j++) {
				del_theta[i] += (predict(w, training_set[j], feature_num) - training_set[j][feature_num])*training_set[j][i];
			}
		}
		//w[i]的更新必须等所有的del_theta测算出来了才可以！不然更新的会影响没更新的
		//上述问题在代码内表示即是下面的for循环不能和上面的合并！
		for (int i = 0; i < feature_num; i++)
			w[i] -= a * del_theta[i] / (double)training_num;
		//printf("%.3lf\n", Theta(training_set, feature_num, training_num, w));
		delete[] del_theta;
	}
	printf("计算结果：\n");//结果保留3位小数
	for (int i = 0; i < feature_num - 1; i++) {
		printf("%.3lf ", w[i]);
	}
	printf("%.3lf\n", w[feature_num - 1]);
	return;
}
// 特征归一化
void BGD::feature_normalize(double **feature_set, int feature_num, int training_num){
    //特征归一化
	// 对于某个特征 x(i)=(x(i)-average(X))/standard_devistion(X)
	// 1、求出特征X在n个样本中的平均值average（X）
	// 2、求出特征X在n个样本中的标准差 standard_devistion(X)
	// 3、对特征X的n个样本中的每个值x（i），使用上述公式进行归一化
	double *average = new double[feature_num];
	double  *stanrd_divition = new double[feature_num];
	for (int i = 1; i < feature_num; i++) {
		double sum = 0;
		for (int j = 0; j < training_num; j++) {
			sum += feature_set[j][i];
		}
		average[i] = sum / training_num;
	}
	for (int i = 1; i < feature_num; i++) {
		double sum = 0;
		for (int j = 0; j < training_num; j++) {
			sum += (feature_set[j][i] - average[i])*(feature_set[j][i] - average[i]);
		}
		stanrd_divition[i] = sqrt((sum / (training_num - 1)));
	}
	for (int i = 1; i < feature_num; i++)
		for (int j = 0; j < training_num; j++) {
			feature_set[j][i] = (feature_set[j][i] - average[i]) / (double)stanrd_divition[i];
		}
	delete[] stanrd_divition;
	delete[] average;
}
// 测试模型预测误差
void BGD::forecast(double *forecast_set, double* w, int feature_num){
    double y=w[0];
	for (int i = 1; i < feature_num - 1; i++) {
		printf("%.3lf ", w[i]);
		printf("\t%.3lf\n ", forecast_set[i]);
		y = y + w[i] * forecast_set[i];
	}
	printf("------------------------------------------\n");
	printf("预测值： %.3lf\n", y);
	printf("实际值： %.3lf\n", forecast_set[feature_num]);
	printf("误差： %.3lf%%\n", fabs(y - forecast_set[feature_num])*100/y);
}

