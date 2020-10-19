/**
***
***	Author:		Nilton Jose Rizzo
***	Date:			08/01/2019
***	Git:			git@gitlab.com:ufrrj/opencv.git
***	LICENSE:		see LICENSE file
***
***
***	OpenCV How-to by examples
***
*** Functions from OpenCV:
***
***   imread		Read image from file
***	namedWindow	Create a new window do show a image
***   imshow		Show Image on Window
***   waitkey		Wait a key pressed
***	cvtColor		Transform image from one color space to another
***
*** Methods
***
***	Mat::empty()	Return true if image is empty, else return false
***
***	In vi/vim editors use tabstop=3
***	In geany editor use preferences->Editor->Ident
***		set width to 	3
***		type				tab
**/

#include <iostream>
#include <fstream>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/core/core.hpp"

#include "opencv2/highgui/highgui.hpp"

#include "opencv2/imgproc/imgproc.hpp"

#include "iostream"

/**
*** Open the namespaces
**/
using namespace std;
using namespace cv;

int main(void) {

	Mat		image;		// Image object
	Mat		gray;			// Destination image in GRAY color space
	string	filename;	// Image file name

	filename = "C:/Users/bielb/Pictures/riven_spirit_2_pc_by_snowy2b_de53xxf-pre.jpg";

	// Read image from disk
	image = imread(filename);

	// Check if image was loaded
	if (image.empty()) {
		cerr << "Image [ " << filename << " ] not found!" << endl;
		cerr << "Quitting!" << endl;
		exit(-1);
	}

	// Create a window for display.
	namedWindow("Original Image", WINDOW_NORMAL);

	// Show our image ins , image );                
	imshow("Original Image", image);

	cvtColor(image, gray, 11);
	/**
	*   cv::COLOR_BGR2BGRA = 0,
	*	cv::COLOR_BGRA2BGR = 1
	*	cv::COLOR_BGR2RGBA = 2,
	*	cv::COLOR_RGBA2BGR = 3,
	*	cv::COLOR_BGR2RGB = 4,
	*	cv::COLOR_BGRA2RGBA = 5,
	*   cv::COLOR_BGR2GRAY = 6,
	*	cv::COLOR_RGB2GRAY = 7,
	*	cv::COLOR_GRAY2BGR = 8,
	*	cv::COLOR_GRAY2BGRA = 9,
	*	cv::COLOR_BGRA2GRAY = 10,
	*	cv::COLOR_RGBA2GRAY = 11,
	*	Outros: https://docs.opencv.org/3.4/d8/d01/group__imgproc__color__conversions.html
	* **/
	// Create a window for display.
	namedWindow("GRAY Image", WINDOW_NORMAL);

	// Show our image ins , image );                
	imshow("GRAY Image", gray);

	waitKey(0);			// Wait for any key was pressed and return
							// the key code pressed or -1 if no key pressed
							// Parameter
							// =0 - Wait for until key pressed
							// >0 - Wait by N miliseconds and return
	return 0;

}
