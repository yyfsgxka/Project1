#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//��������ͷ
	VideoCapture cap;
	cap.open(0);//
	if (!cap.isOpened())
	{
		std::cout << "���ɴ���Ƶ�ļ�" << std::endl;
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
		int Ksize = 3 * 3;
		Size size;
		size.height = 3;
		size.width = 3;
		double sigmaX = 1;
		double sigmaY = 0;
		int dx = 1;
		int dy = 0;


		bool rSucess = cap.read(frame);
		if (!rSucess)
		{
			std::cout << "���ܴ���Ƶ�ж�ȡ֡" << std::endl;
			break;
		}
		else
		{

			imshow("frame ", frame);
			//��ֵ�˲�---��ϰһ
			medianBlur(frame, out_m_frame, Ksize);
			imshow("��ֵ�˲�", out_m_frame);
			//��ֵ�˲�---��ϰ��
			blur(frame, out_blur_frame, size, Point(-1,-1), 4);
			imshow("��ֵ�˲�blur", out_blur_frame);
			//��˹�˲�--��ϰ��
			GaussianBlur(frame, out_G_frame, size, sigmaX, sigmaY, 4);
			imshow("��˹�˲�", out_G_frame);
			//Sobel��Ե��ȡ--��ϰ��
			Sobel(frame, out_sobel_frame, -1, dx, dy, 3, (1, 0), (0, 0), 4);
			imshow("��Ե��ȡ", out_sobel_frame);
		

		}
		waitKey(30);

	}
	return 0;
}