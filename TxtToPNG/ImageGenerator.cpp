#include "stdafx.h"
#include "ImageGenerator.h"
#include <xlocmon>


ImageGenerator::ImageGenerator()
{
}


ImageGenerator::~ImageGenerator()
{
}


void ImageGenerator::CreateImg(std::string txt)
{
	Mat3b result = imread("img\\spacebk.png");
	for (char sign : txt)
	{
		std::string address = ReturnName(sign);

		Mat3b current = imread(address);
		int rows = max(result.rows, current.rows);
		int cols = result.cols + current.cols;

		Mat3b tmp(rows, cols, Vec3b(0, 0, 0));

		result.copyTo(tmp(cv::Rect(0, 0, result.cols, result.rows)));
		current.copyTo(tmp(cv::Rect(result.cols, 0, current.cols, current.rows)));

		result = tmp;
	}
//	imshow("Img 1", result);
//	waitKey();
	imwrite("wynik.png", result);

}

std::string ImageGenerator::ReturnName(char sign)
{
	switch (sign)
	{
	case '0':
		return "img\\0bk.png";
	case '1':
		return "img\\1bk.png";
	case '2':
		return "img\\2bk.png";
	case '3':
		return "img\\3bk.png";
	case '4':
		return "img\\4.png";
	case '5':
		return "img\\5.png";
	case ' ':
		return "img\\spacebk.png";

	default:
		return "img\\space.png";
	}
}

void ImageGenerator::Test()
{
	cv::Mat dst;
	cv::Mat tmp, alpha;
//	cv::Mat3b res(200, 100, cv::Vec3b(255, 255, 255));
	cv::Mat3b result = cv::imread("img\\1x.png",1);
//	result.copyTo(res(cv::Rect(0, 0, result.cols, res.rows)));

	cv::imshow("Img 1", result);

//	cv::imwrite("res.png", result);

	cv::waitKey();
}