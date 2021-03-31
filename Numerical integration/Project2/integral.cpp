#pragma once
#include "integral.h"
#include <cmath>


//---------------------------------------------------------------------------
// RectangleMethode ���������� ��������� ����������� �������� ������� 
// ������� ��������������� � �������� ���������
// ����: a, b - ������� ���������
//	 eps - ��������
//	 *f - ��������� ������������ �������
// �����: s_1 - ������� ���������
//---------------------------------------------------------------------------
double RectangleMethod(double a, double b, double eps, double(*f)(double))
{
	double n = 2;
	double s_1, s_2;
	double h = (b - a) / n;

	double x = a + h / 2;
	s_1 = f(a);

	for (int i = 1; i <= n - 1; i++) {
		x = x + h;
		s_1 = s_1 + f(x);
	}
	s_1 = s_1 * h;

	s_2 = 0;

	while (fabs(s_1 - s_2) > eps) {
		s_2 = s_1;
		n = 2 * n;
		h = (b - a) / n;
		x = a + h / 2;
		s_1 = f(a);
		for (int i = 1; i <= n - 1; i++) {
			x = x + h;
			s_1 = s_1 + f(x);
		}
		s_1 = s_1 * h;
	}

	return s_1;
}

//---------------------------------------------------------------------------
// TrapezoidalRule ���������� ��������� ����������� �������� ������� ��������
// � �������� �����
// ����: a, b - ������� ���������
//	 h - ��� ����������
//	 *f - ��������� ������������ �������
// �����: trapezoidal_integral - ������� ���������
//---------------------------------------------------------------------------
double TrapezoidalRule(double a, double b, double h, double(*f)(double))
{
	double trapezoidal_integral;
	double n = (b - a) / h;

	trapezoidal_integral = (h * (f(a) + f(b)) / 2);
	double x = a + h;

	for (int i = 0; i < n - 1; i++) {
		trapezoidal_integral = trapezoidal_integral + f(x) * h;
		x = x + h;
	}

	return trapezoidal_integral;
}

//---------------------------------------------------------------------------
// DichotomyMethod ������� ����� ����������� ������� � ���� ������� �� [a, b] 
// ������� ���������
// ����: a, b - ������� ���������
//	 eps - �������� �������
//	 *f - ��������� ������������ �������
// �����: point - ������� ���������
//---------------------------------------------------------------------------
double DichotomyMethod(double a, double b, double eps, double(*f)(double))
{
	double point = (a + b) / 2;

	while (((b - a) > eps) && (f(point) != 0)) {
		point = (a + b) / 2;
		if (f(a) * f(point) < 0)
			b = point;
		else
			a = point;
	}
	point = (a + b) / 2;
	return point;
}

//---------------------------------------------------------------------------
// f1, f2 ��������� �������� ������� cos(x) � 1/2 * ((x^2) - 5) * sin(3*x)
// ����: �
// �����: y = f(x)
//---------------------------------------------------------------------------
double f1(double x)
{
	return (cos(x));
}

double f2(double x)
{
	return (0.5 * (pow(x, 2) - 5) * sin(3 * x));
}