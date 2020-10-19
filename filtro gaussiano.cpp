#include "iostream"
#include <opencv2/opencv.hpp>

using namespace std;

int main(void) {

	float kernel_data[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	cv::Mat kernel(5, 5, CV_32F, kernel_data);
	kernel /= 25;

	cv::Mat original = cv::imread("C:/Users/bielb/Pictures/riven_spirit_2_pc_by_snowy2b_de53xxf-pre.jpg", 1);
	if (original.empty()) {
		cerr << "Imagem nao encontrada!" << endl;
		exit(-1);
	}
	cv::Mat resultado;
	cv::filter2D(original, resultado, -1, kernel);

	cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Resultado", cv::WINDOW_AUTOSIZE);

	cv::imshow("Original", original);
	cv::imshow("Resultado", resultado);

	cv::waitKey(0);

	return 0;
}