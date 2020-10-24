#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>

#include <Eigen/Dense>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#ifdef __OPENCV_VERSION_3_0
#	define TOHSV		CV_BGR2HSV
#else
#	define TOHSV		COLOR_BGR2HSV
#endif

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;
using namespace Eigen;
using namespace cv;

int main(void);
void desenhar(void);

void desenhar(void) {
	Matrix3d		T1, T2, S;
	Matrix3d		R;
	Vector3d		p1, p2, p3, p4, pc;
	Vector3d		d1, d2, d3, d4;
	double		angulo, ang, x, y, x1, y1, com, larg, escalox, escaloy;
	Mat			out, out_or;


	cout << "\nEntre com as coordenada X do quadrado (0-512): ";
	cin >> x;
	cout << "Entre com as coordenada Y do quadrado (0-512): ";
	cin >> y;
	cout << "Entre com comprimento do tringulo: ";
	cin >> com;
	cout << "Entre com a largura do quadrado: ";
	cin >> larg;
	cout << "Entre com o angulo para rotacionar o quadrado (graus): ";
	cin >> ang;
	cout << "Entre com o escalonamento x para o quadrado: ";
	cin >> escaloy;
	cout << "Entre com o escalonamento y para o quadrado: ";
	cin >> escalox;


	out = Mat::zeros(512, 512, CV_8UC3);
	out_or = Mat::zeros(512, 512, CV_8UC3);


	rectangle(out_or, Point(x, y), Point(x + com, y + larg), Scalar(255, 255, 255), 3);

	x1 = x + com;
	y1 = y + larg;

	p1 << x, y, 1;
	p2 << x, y1, 1;
	p3 << x1, y, 1;
	p4 << x1, y1, 1;

	angulo = ang * 3.1415 / 180;


	R << cos(angulo), sin(angulo), 0, -sin(angulo), cos(angulo), 0, 0, 0, 1;

	pc = (p1 + p4) / 2;
	cout << endl << "PC" << endl << pc << endl;
	cout << "\nBranco - Original\nVerde - Rotacionado\nLaranja - Rotacionado e escalonado\n";

	cout << "\nPrecione algum botao para fechar a tela";
	Sleep(4000);

	T1 << 1, 0, 0,
		0, 1, 0,
		-pc[0], -pc[1], 1;

	T2 << 1, 0, 0,
		0, 1, 0,
		pc[0], pc[1], 1;

	S << escalox, 0, 0,
		0, escaloy, 0,
		0, 0, 1;

	d1 = p1.transpose() * T1 * S * R * T2;
	d2 = p2.transpose() * T1 * S * R * T2;
	d3 = p3.transpose() * T1 * S * R * T2;
	d4 = p4.transpose() * T1 * S * R * T2;

	line(out, Point(d1[0], d1[1]), Point(d2[0], d2[1]), Scalar(81, 111, 231), 3);
	line(out, Point(d1[0], d1[1]), Point(d3[0], d3[1]), Scalar(81, 111, 231), 3);
	line(out, Point(d2[0], d2[1]), Point(d4[0], d4[1]), Scalar(81, 111, 231), 3);
	line(out, Point(d3[0], d3[1]), Point(d4[0], d4[1]), Scalar(81, 111, 231), 3);

	d1 = p1.transpose() * T1 * R * T2;
	d2 = p2.transpose() * T1 * R * T2;
	d3 = p3.transpose() * T1 * R * T2;
	d4 = p4.transpose() * T1 * R * T2;

	line(out, Point(d1[0], d1[1]), Point(d2[0], d2[1]), Scalar(143, 157, 42), 3);
	line(out, Point(d1[0], d1[1]), Point(d3[0], d3[1]), Scalar(143, 157, 42), 3);
	line(out, Point(d2[0], d2[1]), Point(d4[0], d4[1]), Scalar(143, 157, 42), 3);
	line(out, Point(d3[0], d3[1]), Point(d4[0], d4[1]), Scalar(143, 157, 42), 3);

	namedWindow("canvas", WINDOW_NORMAL);
	imshow("canvas", out);

	namedWindow("original", WINDOW_NORMAL);
	imshow("original", out_or);

	waitKey(0);
	destroyAllWindows();

}

int main(void) {
	char		ch;

	cout << "digite b para desenhar\ndigite c para sair\n";
	do {
		cin >> ch;

		switch (ch) {
		case 'b':
		case 'B': {
			desenhar();
			break;
		}
		case 'c':
		case 'C': {
			return 0;
			break;
		}
		}
		cout << "\n-------------------------------------------------------------------------------------------------------------\n";
		cout << "\ndigite b para redesenhar\ndigite c para sair\n";

	} while (ch != 27);		// Wait until <ESC> was pressed
	cout << endl;

	return 0;
}
