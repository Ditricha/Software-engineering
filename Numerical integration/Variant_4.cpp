#include <math.h>
#include <iostream>
# include <locale.h>

using namespace std;

// подынтегральные функции
double f1(double);
double f2(double);

// методы
double RectangleMethod(double a, double b, double eps, double(*f)(double));
double TrapezoidalRule(double a, double b, double h, double(*f)(double));
double DichotomyMethod(double a, double b, double eps, double(*f)(double));


int main()
{
	setlocale(LC_ALL, "Russian");

	double x1, x2, n, h, eps;
	int f_num, num;

	cout << "Задание:" << endl << "Написать программу для приближённого вычисления определённого интеграла" << endl
		<< "1) методом средних прямоугольников с заданной точностью," << endl
		<< "2) методом трапеции с заданным шагом," << endl
		<< "3) точки пересечения выбранной пользователем функции с осью абсцисс на заданном интервале методом дихотомии." << endl
		<< "Выбранную для проверки функцию передавать как отдельный параметр подпрограмм вычисления значений функции," << endl 
		<< "интеграла, корня. Для проверки использовать следующие функции:" << endl << "1) cos(x);" << endl << "2) 1/2 * (x^2 - 5) * sin(3*x)." << endl
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
		switch (num) {
		case 1:
			cout << "Введите точность решения: ";
			cin >> eps;
			cout << "-----------------------------------------------------------------------------" << endl << endl;
			cout << "Результат интегрирования: " << RectangleMethod(x1, x2, eps, f1) << endl;
			break;
		case 2:
			cout << "Введите шаг: ";
			cin >> h;
			cout << "-----------------------------------------------------------------------------" << endl << endl;
			cout << "Результат интегрирования: " << TrapezoidalRule(x1, x2, h, f1) << endl;
			break;
		case 3:
			cout << "Введите точность решения: ";
			cin >> eps;
			cout << "-----------------------------------------------------------------------------" << endl << endl;
			cout << "Результат: " << DichotomyMethod(x1, x2, eps, f1) << endl;
			break;
		default:
			cout << "-----------------------------------------------------------------------------" << endl << endl;
			cout << "Введён неверный номер." << endl;
		}
	}
	else if (f_num == 2) {
		switch (num) {
		case 1:
			cout << "Введите точность решения: ";
			cin >> eps;
			cout << "-----------------------------------------------------------------------------" << endl << endl;
			cout << "Результат интегрирования: " << RectangleMethod(x1, x2, eps, f2) << endl;
			break;
		case 2:
			cout << "Введите шаг: ";
			cin >> h;
			cout << "-----------------------------------------------------------------------------" << endl << endl;
			cout << "Результат интегрирования: " << TrapezoidalRule(x1, x2, h, f2) << endl;
			break;
		case 3:
			cout << "Введите точность решения: ";
			cin >> eps;
			cout << "-----------------------------------------------------------------------------" << endl << endl;
			cout << "Результат: " << DichotomyMethod(x1, x2, eps, f2) << endl;
			break;
		default:
			cout << "-----------------------------------------------------------------------------" << endl << endl;
			cout << "Введён неверный номер." << endl;
		}
	}
	getchar();
}

//---------------------------------------------------------------------------
// RectangleMethode приближённо вычисляет определённый интеграл методом 
// средних прямоугольников с заданной точностью
// Вход: a, b - границы интервала
//	 eps - точночть
//	 *f - выбранная пользователм функция
// Выход: s_1 - решение уравнения
//---------------------------------------------------------------------------
double RectangleMethod(double a, double b, double eps, double(*f)(double))
{
	double n = 2;
	double s_1, s_2;
	double h = (b - a) / n;

	double x = a + h / 2;
	s_1 = f(a);

	for (int i = 1; i <= n-1; i++) {
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
		for (int i = 1; i <= n-1; i++) {
			x = x + h;
			s_1 = s_1 + f(x);
		}
		s_1 = s_1 * h;
	}
	
	return s_1;
}

//---------------------------------------------------------------------------
// TrapezoidalRule приближённо вычисляет определённый интеграл методом трапеции
// с заданным шагом
// Вход: a, b - границы интервала
//	 h - шаг приращения
//	 *f - выбранная пользователм функция
// Выход: trapezoidal_integral - решение уравнения
//---------------------------------------------------------------------------
double TrapezoidalRule(double a, double b, double h, double(*f)(double))
{
	double trapezoidal_integral;
	double n = (b - a) / h; 

	trapezoidal_integral = (h * (f(a) + f(b)) / 2);
	double x = a + h;

	for (int i = 0; i < n-1; i++) {
		trapezoidal_integral = trapezoidal_integral + f(x) * h;
		x = x + h;
	}

	return trapezoidal_integral;
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
