#include <stdio.h>
#include <math.h>
#include <iostream>
# include <locale.h>

using namespace std;

// подынтегральные функции
double f1(double);
double f2(double);

// методы
double RectangleMethod(double a, double b, double x, double n, double(*f)(double));
//double TrapezoidalRule(double a, double b, double x, double h, double(*f)(double));
double TrapezoidalRule(double a, double b, double h, double(*f)(double));
double DichotomyMethod(double a, double b, double(*f)(double));

// проверка количество точек разбиения отрезка интегрирования (n)
int test(int n);


int main()
{
	setlocale(LC_ALL, "Russian");

	double x1, x2, n, h;
	int f_num, num;

	cout << "Задание:" << endl << "Написать программу для приближённого вычисления определённого интеграла" << endl
		<< "1) методом средних прямоугольников с заданной точностью," << endl
		<< "2) методом трапеции с заданным шагом," << endl
		<< "3) точки пересечения выбранной пользователем функции с осью абсцисс на заданном интервале методом дихотомии." << endl
		<< "Выбранную для проверки функцию передавать как отдельный параметр подпрограмм вычисления значений функции," << endl 
		<< "интеграла, корня. Для проверки использовать следующие функции:" << endl << "1) cos(x);" << endl << "2) 1/2 * (x^2 - 5) * sin(3*x)." << endl
		<< "Коэффициент x и границы интервала интегрирования считываются с экрана." << endl;
	cout << "-----------------------------------------------------------------------------" << endl << endl;

	cout << "Введите номер, 1 или 2, функции, которая будет использована для проверки: ";
	cin >> f_num;

	cout << "Введите номер метода: ";
	cin >> num;

	cout << "Введите границы интервала:" << endl << "x1: ";
	cin >> x1;
	cout << "x2: ";
	cin >> x2;

	if (f_num == 1) {
		double x;
		cout << "Введите коэффициенты подынтегральной функции cos(x): ";
		cin >> x;

		switch (num) {
		case 1:
			while (true) {
				int cs;
				cout << "Введите количество точек разбиения отрезка интегрирования: ";
				cin >> n;
				cs = test(n);
				if (cs == 0)
					cout << "Значение n меньше единицы. Введите заново." << endl;
				else
					break;
			}
			cout << "-----------------------------------------------------------------------------" << endl << endl;
			cout << "Результат интегрирования: " << RectangleMethod(x1, x2, x, n, f1) << endl;
			break;
		case 2:
			cout << "Введите шаг: ";
			cin >> h;
			cout << "-----------------------------------------------------------------------------" << endl << endl;
			cout << "Результат интегрирования: " << TrapezoidalRule(x1, x2, h, f1) << endl;
			break;
		case 3:
			cout << "-----------------------------------------------------------------------------" << endl << endl;
			cout << "Результат: " << DichotomyMethod(x1, x2, f1) << endl;
			break;
		default:
			cout << "-----------------------------------------------------------------------------" << endl << endl;
			cout << "Введён неверный номер." << endl;
		}
	}
	else if (f_num == 2) {
		double x;
		cout << "Введите коэффициенты подынтегральной функции 1/2 * (x^2 - 5) * sin(3*x): ";
		cin >> x;

		switch (num) {
		case 1:
			while (true) {
				int cs;
				cout << "Введите количество точек разбиения отрезка интегрирования: ";
				cin >> n;
				cs = test(n);
				if (cs == 0)
					cout << "Значение n меньше единицы. Введите заново." << endl;
				else
					break;
		}
			cout << "-----------------------------------------------------------------------------" << endl << endl;
			cout << "Результат интегрирования: " << RectangleMethod(x1, x2, x, n, f2) << endl;
			break;
		case 2:
			cout << "Введите шаг: ";
			cin >> h;
			cout << "-----------------------------------------------------------------------------" << endl << endl;
			cout << "Результат интегрирования: " << TrapezoidalRule(x1, x2, h, f2) << endl;
			break;
		case 3:
			cout << "-----------------------------------------------------------------------------" << endl << endl;
			cout << "Результат: " << DichotomyMethod(x1, x2, f2) << endl;
			break;
		default:
			cout << "-----------------------------------------------------------------------------" << endl << endl;
			cout << "Введён неверный номер." << endl;
		}
	}
	getchar();
}

// метод средних прямоугольников с заданной точностью
double RectangleMethod(double a, double b, double x, double n, double(*f)(double))
{
	double h = (b - a) / n; // находим шаг приращения
	double rectangle_integral = 0.0;

	for (int i = 0; i < n; i++)
		rectangle_integral += f(x);
	rectangle_integral *= h;

	return rectangle_integral;
}

// метод трапеции с заданным шагом
double TrapezoidalRule(double a, double b, double h, double(*f)(double))
{
	double trapezoidal_integral = 0.0;
	double n = (b - a) / h; // находим точность

	for (int i = 0; i < n; i++) {
		double x1 = a + i * h;
		double x2 = a + (i + 1) * h;
		trapezoidal_integral += 0.5 * (x2 - x1) * (f(x1) + f(x2));
	}
	return trapezoidal_integral;
}
      
// очередной криво считающий вариант
//double TrapezoidalRule(double a, double b, double h, double(*f)(double))
//{
//	double n = (b - a) / h;
//	double trapezoidal_integral = f(a) + f(b);
//
//	for (int i = 1; i <= n-1; i++) {
//		trapezoidal_integral += 2 * (f(a + i * h));
//	}
//	trapezoidal_integral = (ans + ans1)*(h / 2.0);
//
//	return trapezoidal_integral;
//}

//и ещё один
//double TrapezoidalRule(double a, double b, double x, double h, double(*f)(double))
//{
//	double n = (b - a) / h;
//	double trapezoidal_integral = f(a) + f(b);
//
//	for (int i = 1; i < n-1; i++) {
//		x = x + h;
//		trapezoidal_integral += 2 * f(x);
//	}
//	trapezoidal_integral *= (h / 2.0);
//
//	return trapezoidal_integral;
//}

// метод дихотомий
double DichotomyMethod(double a, double b, double(*f)(double))
{
	double eps = 0.1;
	double point = (a + b) / 2;

	while (((b - a) > eps) && (f(point) != 0)) {
		point = (a + b) / 2;
		if (f(a) * f(point) < 0)
			b = point;
		else
			a = point;
	}
	return point;
}

// подынтегральные функции
double f1(double x)
{
	return (cos(x));
}

double f2(double x)
{
	return (0.5 * (pow(x, 2) - 5) * sin(3 * x));
}


// проверка количество точек разбиения отрезка интегрирования (n) 
int test(int n)
{
	if (n < 1)
		return 0;
	else
		return 1;
}
