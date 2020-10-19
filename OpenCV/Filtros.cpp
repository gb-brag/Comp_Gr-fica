
#include <iostream>
#include <fstream>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>


using namespace std;
using namespace cv;

int main(void) {

	Mat		image;
	Mat		imgblur, imggaussian, imgmedian;
	string	filename;
	int		h, w, height, width;

	filename = "C:/Users/bielb/Pictures/riven_spirit_2_pc_by_snowy2b_de53xxf-pre.jpg";


	image = imread(filename);

	if (image.empty()) {
		cerr << "Image file name not found" << endl;
		exit(-1);
	}
	//filtros
	blur(image, imgblur, Size(11, 11));
	medianBlur(image, imgmedian, 11);
	GaussianBlur(image, imggaussian, Size(3, 3), 3.7, 3.7);

	//abrir resultados

	namedWindow(filename.c_str(), WINDOW_NORMAL);
	imshow(filename.c_str(), image);

	namedWindow("BLUR", WINDOW_NORMAL);
	imshow("BLUR", imgblur);

	namedWindow("MEDIAN", WINDOW_NORMAL);
	imshow("MEDIAN", imgmedian);

	namedWindow("GAUSSIAN", WINDOW_NORMAL);
	imshow("GAUSSIAN", imggaussian);

	waitKey(0);
	return 0;

}
