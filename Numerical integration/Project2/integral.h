#pragma once

// ��������������� �������
double f1(double);
double f2(double);

// ������
double RectangleMethod(double a, double b, double eps, double(*f)(double));
double TrapezoidalRule(double a, double b, double h, double(*f)(double));
double DichotomyMethod(double a, double b, double eps, double(*f)(double));