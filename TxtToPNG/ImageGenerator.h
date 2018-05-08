#pragma once
class ImageGenerator
{
public:
	ImageGenerator();
	~ImageGenerator();
	void CreateImg(std::string txt);
	std::string ReturnName(char sign);
	void Test();
	void Test(char sign);
};

