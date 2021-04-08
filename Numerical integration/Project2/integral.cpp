#pragma once
#include "integral.h"
#include <cmath>


//---------------------------------------------------------------------------
// RectangleMethode приближённо вычисляет определённый интеграл методом 
// средних прямоугольников с заданной точностью
// Вход: a, b - границы интервала
//	 eps - точночть
//	 *f - выбранная пользователм функция
// Выход: integral1 - решение уравнения
//---------------------------------------------------------------------------
double RectangleMethod(double a, double b, double eps, double(*f)(double))
{
	float n = 2;
	double integral1 = RectangleArea(a, b, n, f);
	double integral2 = 0;

	while (fabs(integral1 - integral2) > eps) {
		integral2 = integral1;
		n = 2 * n;
		integral1 = RectangleArea(a, b, n, f);
	}

	return integral1;
}

//---------------------------------------------------------------------------
// RectangleArea находит площадь прямоугольника при заданном количестве
// интервалов
// Вход: a, b - границы интервала
//	 n - количество интервалов
//	 *f - выбранная пользователм функция
// Выход: integral - решение уравнения
//---------------------------------------------------------------------------
double RectangleArea(double a, double b, float n, double(*f)(double))
{
	double h = (b - a) / n;
	double x = a + h / 2;
	double integral = f(a);

	for (int i = 1; i <= n - 1; i++) {
		x += h;
		integral += f(x);
	}
	integral *= h;

	return integral;
}

//---------------------------------------------------------------------------
// TrapezoidalRule приближённо вычисляет определённый интеграл методом трапеции
// с заданным шагом
// Вход: a, b - границы интервала
//	 h - шаг приращения
//	 *f - выбранная пользователм функция
// Выход: integral - решение уравнения
//---------------------------------------------------------------------------
double TrapezoidalRule(double a, double b, double h, double(*f)(double))
{
	double n = (b - a) / h;
	double integral = (h * (f(a) + f(b)) / 2);
	double x = a + h;

	for (int i = 0; i < n - 1; i++) {
		integral += f(x) * h;
		x += h;
	}

	return integral;
}

//---------------------------------------------------------------------------
// DichotomyMethod находит точку пересечения функции с осью абсцисс на [a, b] 
// методом дихотомий
// Вход: a, b - границы интервала
//	 eps - точночть решения
//	 *f - выбранная пользователм функция
// Выход: point - решение уравнения
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
// f1, f2 вычисляют интеграл функций cos(x) и 1/2 * ((x^2) - 5) * sin(3*x)
// Вход: х
// Выход: y = f(x)
//---------------------------------------------------------------------------
double f1(double x)
{
	return (cos(x));
}

double f2(double x)
{
	return (0.5 * (pow(x, 2) - 5) * sin(3 * x));
}
