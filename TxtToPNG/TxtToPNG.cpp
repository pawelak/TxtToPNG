// TxtToPNG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	//	char* buffer;
	//
	//	// Get the current working directory:   
	//	if ((buffer = _getcwd(NULL, 0)) == NULL)
	//		perror("_getcwd error");
	//	else
	//	{
	//		printf("%s \nLength: %d\n", buffer, strnlen(buffer,2));
	//		free(buffer);
	//	}

	//	std::cout << "loading";
	// Load images
	cv::Mat3b img1 = cv::imread("a.png");
	cv::Mat3b img2 = cv::imread("b.png");

	// Get dimension of final image
	int rows = cv::max(img1.rows, img2.rows);
	int cols = img1.cols + img2.cols;

	// Create a black image
	cv::Mat3b res(rows, cols, cv::Vec3b(0, 0, 0));


	// Copy images in correct position
	img1.copyTo(res(cv::Rect(0, 0, img1.cols, img1.rows)));
	img2.copyTo(res(cv::Rect(img1.cols, 0, img2.cols, img2.rows)));

	// Show result
	imshow("Img 1", img1);
	//	imshow("Img 2", img2);
	imshow("Result", res);
	cv::waitKey();

	return 0;
}

