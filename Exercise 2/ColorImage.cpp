#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

 // Author Rishab Shah

using namespace cv;
using namespace std;
 
int main(int argc, char** argv )
{
    Mat src;
    src = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    namedWindow( "Original image", CV_WINDOW_AUTOSIZE );
    imshow( "Original image", src);

	vector<Mat> input_planes(3);
	split(src,input_planes);
	Mat channel1_display, channel2_display, channel3_display;
        imshow("Red",   input_planes[2]); // Red channel
        imshow("Green",   input_planes[1]); //Green channel
        imshow("Blue",   input_planes[0]); // Blue channel


	Mat ycrcb_image;
	cvtColor(src, ycrcb_image, CV_BGR2YCrCb);
	split(ycrcb_image,input_planes);
        imshow("Y",   input_planes[0]); // Y channel
        imshow("Cb",   input_planes[1]); // Cb channel
        imshow("Cr",   input_planes[2]); // Cr channel


	Mat hsv_image;
	cvtColor(src, hsv_image, CV_BGR2HSV);
	vector<Mat> hsv_planes(3);
	split(hsv_image,hsv_planes);
        imshow("Hue",   hsv_planes[0]); //Hue channel
        imshow("Saturation",   hsv_planes[1]); //Saturation channel
        imshow("Value",   hsv_planes[2]); //Value channel


	
    waitKey(0);                                       
    return 0;
} 
