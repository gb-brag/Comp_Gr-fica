/*
* Histogram Calculation:
* https://docs.opencv.org/3.4/d8/dbc/tutorial_histogram_calculation.html
*/

#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc, char** argv) {

    vector<Mat> rgb_planes;
    int histSize = 256; //valor máximo do intervalo
    float range[] = { 0, 256 }; //the upper boundary is exclusive
    const float* histRange = { range };
    bool uniform = true, accumulate = false; // uniforme e limpa o histograma no começo
    Mat r_hist, g_hist, b_hist;

    //Abrir imagem
    CommandLineParser parser(argc, argv, "{@input | .../Pictures/3.jpg | input image}");
    Mat src = imread(samples::findFile(parser.get<String>("@input")), IMREAD_COLOR);
    if (src.empty())
    {
        return EXIT_FAILURE;
    }

    //Divide a imagem em 3 planos (r, b , g) 
    split(src, rgb_planes);

    //Calcula o histograma para os 3 canais
    calcHist(&rgb_planes[0], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&rgb_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&rgb_planes[2], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);

    //Cria a imagem do histograma
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double)hist_w / histSize);
    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

    //Normaliza para os valores ficarem dentro do parametro
    normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    //Desenha o gráfico
    for (int i = 1; i < histSize; i++)
    {
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))),
            Scalar(255, 0, 0), 2, 8, 0);
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))),
            Scalar(0, 255, 0), 2, 8, 0);
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))),
            Scalar(0, 0, 255), 2, 8, 0);
    }

    //Exibir
    namedWindow("Source image", WINDOW_NORMAL);
    imshow("Source image", src);
    namedWindow("calcHist Demo", WINDOW_NORMAL);
    imshow("calcHist Demo", histImage);

    waitKey();
    return EXIT_SUCCESS;
}
