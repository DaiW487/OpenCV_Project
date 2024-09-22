#include <opencv4/opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
 
Mat redInHSV(Mat image1);
Mat redContour(cv::Mat img);
Mat redBounding(Mat img);
Mat Compute(Mat img);
void Rotate(cv::Mat &srcImage, cv::Mat &dstImage, double angle, cv::Point2f center, double scale);



int main()
{

	string path = "/home/daiwei/OpenCV_Project/resources/test_image.png";
	Mat img = imread(path);
	Mat imgGray,imgHSV,imgBlur,imgGaussBlur;

	//Convert image to GRAY
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	namedWindow("Image Gray",WINDOW_KEEPRATIO);
	imshow("Image Gray", imgGray);

    //Convert image to HSV format
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	namedWindow("Image HSV",WINDOW_KEEPRATIO);
	imshow("Image HSV", imgHSV);

	//Apply mean filtering
    blur(img,imgBlur,Size(5,5));
	namedWindow("Image Blur",WINDOW_KEEPRATIO);
	imshow("Image Blur", imgBlur);

	//Apply Guass filtering
    GaussianBlur(img,imgGaussBlur,Size(5,5),3,3,0);
	namedWindow("Image GaussBlur",WINDOW_KEEPRATIO);
	imshow("Image GaussBlur", imgGaussBlur);
    
	//Extract the red area
    Mat red_image=redInHSV(img);
	namedWindow("Red Image",WINDOW_KEEPRATIO);
	imshow("Red Image", red_image);

    //Extract the contour of the red area
	Mat red_contour=redContour(img);
	namedWindow("Red Contour",WINDOW_KEEPRATIO);
	imshow("Red Contour", red_contour);

    //find the bounding box of red area
	Mat Red_box=redBounding(img);
    namedWindow("Red Bounding Box",WINDOW_KEEPRATIO);
	imshow("Red Bounding Box", Red_box);

    //compute the S of contour
	



    //Extract highlighted color area and do graphic processing
    Mat imgCanny,imgDil,imgErode,imghsv,HLGray,HLGaussBlur,HLBlur;

    cv::cvtColor(img, imghsv, cv::COLOR_BGR2HSV);
 
    cv::Scalar lower_light = cv::Scalar(0, 0, 60);
    cv::Scalar upper_light = cv::Scalar(0, 0, 255);
 
    cv::Mat mask;
    cv::inRange(imghsv, lower_light, upper_light, mask);
 
    cv::Mat HLimage;
    cv::bitwise_and(img, img, HLimage, mask);
    namedWindow("HLimage",WINDOW_KEEPRATIO);
	imshow("HLimage", HLimage);
	//将照片转换为灰度
	cvtColor(HLimage, HLGray, COLOR_BGR2GRAY);
	
	//高斯模糊
	GaussianBlur(HLGray, HLGaussBlur, Size(3, 3), 3, 0);
	//
	Mat HLbinary;
	cv::threshold(HLGray,HLbinary,180,255,THRESH_BINARY);
	//Canny边缘检测器  一般在使用Canny边缘检测器之前会做一些模糊处理
	Canny(HLbinary, imgCanny, 25, 75);
	//创建一个可以使用膨胀的内核
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	//图像膨胀
	dilate(HLbinary, imgDil, kernel);
	//图像侵蚀
	erode(imgDil, imgErode, kernel);
	//
	Rect ccomp;
	Mat imgBlood=imread(path);
	cv::floodFill(imgBlood,Point(100,500),Scalar(200,100,100),&ccomp,Scalar(20,20,20),Scalar(20,20,20));
    namedWindow("Image Blood",WINDOW_KEEPRATIO);
	imshow("Image Blood", imgBlood);
    //结果呈现
	namedWindow("Image Erode",WINDOW_KEEPRATIO);
	imshow("Image Erode", imgErode);

    //draw a rectangle
	Mat recimg=Mat::zeros(Size(500,500),CV_8UC3);
	rectangle(recimg,Point(100,200),Point(200,400),Scalar(255,0,0),20);
    namedWindow("Rectangle",WINDOW_KEEPRATIO);
	imshow("Rectangle", recimg);

	//draw a circle
	Mat round=Mat::zeros(Size(500,500),CV_8UC3);
	circle(round,Point(100,200),70,Scalar(200,155,204),10);
    namedWindow("Circle",WINDOW_KEEPRATIO);
	imshow("Circle", round);



	//rotate the image
	Mat rotateimg;
	int row=img.rows;
	int col=img.cols;
	double angle=35;
	Point2f center(col/2,row/2);
	double scale=0.5;
	Rotate(img,rotateimg,angle,center,scale);
    namedWindow("Rotate",WINDOW_KEEPRATIO);
	imshow("Rotate",rotateimg);

    //write words
	putText(img,"Hello OpenCV",Point(col/3,row/2),FONT_HERSHEY_SIMPLEX,5,Scalar(255,255,255),20);
	namedWindow("Word",WINDOW_KEEPRATIO);
	imshow("Word",img);

    //cut the image
	Mat cutimg=img(cv::Rect(0,0,col/2,row/2));
    namedWindow("Cut",WINDOW_KEEPRATIO);
	imshow("Cut",cutimg);

	waitKey(0);
	return 0;
}


Mat redInHSV(Mat image1)
{
	Mat imghsv;

    // Convert to HSV farmat
    cv::cvtColor(image1, imghsv, COLOR_BGR2HSV);
 
    // Set the range of red
    Scalar lower_red = Scalar(156, 43, 46);
    Scalar upper_red = Scalar(180, 255, 255);
 
    // Find red area
    Mat mask;
    cv::inRange(imghsv, lower_red, upper_red, mask);
 
    // Extract the red pixels yhrough the mask
    Mat red_image;
    cv::bitwise_and(image1, imghsv, red_image, mask);
 
    return red_image;
}



Mat redContour(cv::Mat img)
{
    Mat red_image1=redInHSV(img);

	Mat red_gray;
	cvtColor(red_image1, red_gray, COLOR_BGR2GRAY);

	Mat binary;
	cv::threshold(red_gray,binary,1,255,THRESH_BINARY);
  
    std::vector<std::vector<cv::Point>> contours;  
    std::vector<cv::Vec4i> hierarchy;  
  
    cv::findContours(binary, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);  
  
    Mat red_contour=Mat::zeros(red_gray.size(),CV_8UC3);
    cv::drawContours(red_contour,contours,-1,Scalar(255,255,255),4,LINE_8,hierarchy);
    return red_contour;
}

Mat redBounding(Mat img)
{
	Mat red_image1=redInHSV(img);

	Mat red_gray;
	cvtColor(red_image1, red_gray, COLOR_BGR2GRAY);

	Mat binary;
	cv::threshold(red_gray,binary,1,255,THRESH_BINARY);
  
    std::vector<std::vector<cv::Point>> contours;  
    std::vector<cv::Vec4i> hierarchy;  
  
    cv::findContours(binary, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);  

    cv::Mat drawing=cv::Mat::zeros(red_gray.size(),CV_8UC3);

    for(size_t i=0;i<contours.size();i++){
		cv::Rect rect=cv::boundingRect(contours[i]);
		cv::rectangle(drawing,rect,cv::Scalar(0,255,0),2,8,0);
	}
	return drawing;
}

Mat Compute(Mat img)
{
    Mat red_image1=redInHSV(img);

	Mat red_gray;
	cvtColor(red_image1, red_gray, COLOR_BGR2GRAY);

	Mat binary;
	cv::threshold(red_gray,binary,1,255,THRESH_BINARY);
  
    std::vector<std::vector<cv::Point>> contours;  
    std::vector<cv::Vec4i> hierarchy;  
  
    cv::findContours(binary, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE); 
	
	double a[100000];
    for(size_t i=0;i<=contours.size();i++){
	a[i]=contourArea(contours[i]);
	}
    for(int j=0;j<=100000;j++){
		printf(" ",a[j]);
	}
	return img;
}


// rotate the image
void Rotate( cv::Mat &srcImage, cv::Mat &dstImage, double angle, cv::Point2f center, double scale)
{
	cv::Mat M = cv::getRotationMatrix2D(center, angle, scale);//计算旋转的仿射变换矩阵 
	cv::warpAffine(srcImage, dstImage, M, cv::Size(srcImage.cols, srcImage.rows));//仿射变换  
}