/**
***
***	File:	info_image.cpp
***   Author:     Nilton Jose Rizzo
***   Date:       08/01/2019
***   Git:        git@gitlab.com:ufrrj/opencv.git
***   LICENSE:    see LICENSE file
***
***
***   OpenCV Hoe-to by examples
***
*** Functions from OpenCV:
***
***   imread			Read image from file
***
*** Methods
***
***	Mat::empty()	Return true if image is empty, else return false
***
***   In vi/vim editors use tabstop=3
***   In geany editor use preferences->Editor->Ident
***      set width to   3
***      type           tab
**/

#include <iostream>
#include <fstream>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <C:\Users\bielb\source\repos\opencv-test/opencv-test/Info.cpp>


/**
*** open namespaces
**/
using namespace std;
using namespace cv;

int main(void);

int main(void) {

	Mat		image;		// Image object to be used
	string	filename;	// Image name
	int		h, w, height, width;

	filename = "C:/Users/bielb/Desktop/4.png";

	// Read image from disk
	image = imread(filename);

	// Check if image was loaded
	if (image.empty()) {
		cerr << "Error: Image not found [" << filename << "]" << endl;
		exit(-1);
	}

	// Note: this space are space char not tab
	cout << "Image info:" << endl;
	cout << ">>> Name: ..... " << filename << endl;
	cout << ">>> Type: ..... " << image.type() << endl;
	//https://gist.github.com/yangcha/38f2fa630e223a8546f9b48ebbb3e61a

	cout << "+--------+----+----+----+----+------+------+------+------+ " << endl;
	cout << "|        | C1 | C2 | C3 | C4 | C(5) | C(6) | C(7) | C(8) | " << endl;
	cout << "+--------+----+----+----+----+------+------+------+------+ " << endl;
	cout << "| CV_8U  |  0 |  8 | 16 | 24 |   32 |   40 |   48 |   56 | " << endl;
	cout << "| CV_8S  |  1 |  9 | 17 | 25 |   33 |   41 |   49 |   57 | " << endl;
	cout << "| CV_16U |  2 | 10 | 18 | 26 |   34 |   42 |   50 |   58 | " << endl;
	cout << "| CV_16S |  3 | 11 | 19 | 27 |   35 |   43 |   51 |   59 | " << endl;
	cout << "| CV_32S |  4 | 12 | 20 | 28 |   36 |   44 |   52 |   60 | " << endl;
	cout << "| CV_32F |  5 | 13 | 21 | 29 |   37 |   45 |   53 |   61 | " << endl;
	cout << "| CV_64F |  6 | 14 | 22 | 30 |   38 |   46 |   54 |   62 | " << endl;
	cout << "+--------+----+----+----+----+------+------+------+------+ " << endl;

	cout << ">>> Size: ..... " << image.rows << " x " << image.cols << endl;
	cout << ">>> Channels: . " << image.channels() << endl;
	cout << ">>> Depth: .... " << image.depth() << endl;

	return 0;

}
