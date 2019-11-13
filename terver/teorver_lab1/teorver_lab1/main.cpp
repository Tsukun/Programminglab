#include <iostream>
#include <ctime>
#include <cstdlib>
#include <clocale>
#include "glut.h"

using namespace std;

double rand01()
{
	return (rand() / (double)RAND_MAX);
}

double normalSV(double sigma, double mx, int n, int randKoef)
{
	srand(clock() * randKoef);
	double v = 0;
	for (int i = 0; i < n; i++)
		v += rand01();
	double z = (v - n / 2) / sqrt(n / 12);
	return z * sigma + mx;
}

double* getSelection(double sigma, double mx, int N, int n = 1000)
{
	double* arr = new double[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = normalSV(sigma, mx, 1000, i);
	}
	return arr;
}

int countStep(double min, double max, double* arr, int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] <= max && arr[i] >= min)
			count++;
	}
	return count;
}

void display()
{
	double sigma, mx;
	int N, intervals;

	cout << "Введите sigma, mx, N и количество интервалов гистограммы\n";
	cin >> sigma >> mx >> N >> intervals;

	double* arr = getSelection(sigma, mx, N);

	double min, max;
	min = max = arr[0];
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	double step = (max - min) / intervals;

	for (int i = 0; i < intervals; i++)
	{

	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Гистогамма");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1280, 0, 720);

	glutDisplayFunc(display);

	glutMainLoop();
}
