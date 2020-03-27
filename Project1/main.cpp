#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//调用摄像头
	VideoCapture cap;
	cap.open(0);//
	if (!cap.isOpened())
	{
		std::cout << "不可打开视频文件" << std::endl;
		return -1;
	}
	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		Mat frame;
		Mat out_m_frame;
		Mat out_blur_frame;
		Mat out_G_frame;
		Mat out_sobel_frame;
		Mat rframe;
		Mat dx; Mat dy;
		Mat abs_dx;
		Mat abs_dy;
		int Ksize = 3 * 3;
		Size size;
		size.height = 3;
		size.width = 3;
		double sigmaX = 1;
		double sigmaY = 0;
	
		bool rSucess = cap.read(frame);
		if (!rSucess)
		{
			std::cout << "不能从视频中读取帧" << std::endl;
			break;
		}
		else
		{

			imshow("frame ", frame);
			//中值滤波---练习一
			medianBlur(frame, out_m_frame, Ksize);
			imshow("中值滤波", out_m_frame);
			//均值滤波---练习二
			blur(frame, out_blur_frame, size, Point(-1,-1), 4);
			imshow("均值滤波blur", out_blur_frame);
			//高斯滤波--练习三
			GaussianBlur(frame, out_G_frame, size, sigmaX, sigmaY, 4);
			imshow("高斯滤波", out_G_frame);
			//Sobel边缘提取--练习四
			cvtColor(frame, rframe, CV_RGB2GRAY);
			Sobel(rframe, dx, -1, 1, 0, 3);
			convertScaleAbs(dx, abs_dx);
			Sobel(rframe, dy, -1, 1, 0, 3);
		    convertScaleAbs(dy, abs_dy);
			
			imshow("边缘提取x", abs_dx);
			imshow("边缘提取y", abs_dy);
		

		}
		waitKey(30);

	}
	return 0;
}