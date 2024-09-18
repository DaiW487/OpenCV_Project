#include <opencv2/opencv.hpp>
#include <iostream>
 
using namespace cv;
using namespace std;
 
int main()
{
	string path = "resources/test_image.png";//图片的路径名
	Mat img = imread(path);
	Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;
	//将照片转换为灰度
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	//高斯模糊
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	//Canny边缘检测器  一般在使用Canny边缘检测器之前会做一些模糊处理
	Canny(imgBlur, imgCanny, 25, 75);
	//创建一个可以使用膨胀的内核
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	//图像膨胀
	dilate(imgCanny, imgDil, kernel);
	//图像侵蚀
	erode(imgDil, imgErode, kernel);
    //结果呈现
	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDil);
	imshow("Image Erode", imgErode);
 
	waitKey(0);
	return 0;
}
