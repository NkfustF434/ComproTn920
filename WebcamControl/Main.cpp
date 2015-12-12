#include "ComproTn920.h"
#include <opencv2\highgui\highgui.hpp>
#include <time.h>

void main()
{
	//建構控制單元
	ComproTn920 clsCamera("163.18.62.19");

	//初始化一張影像
	cv::Mat clsImage2;

	//建議先讓鏡頭做Home，可以確保相機移動的位置是對的
	//clsCamera.Move(ComproTn920::MoveDirection::Home);

	//設定相機速度
	//clsCamera.SetMoveSpeed(ComproTn920::MoveSpeed::Ten);

	//相機向左移動
	//clsCamera.Move(ComproTn920::MoveDirection::Left);

	//需要Sleep，等待移動停止
	//Sleep(1000);
	
	//相機拍照
	int i = 0;
	while (1)
	{
		cv::Mat clsImage;
		clsCamera.Snapshot(clsImage);

		if (!clsImage.empty())
		{
			cv::imshow("Camera Image", clsImage);
		}

		if (cv::waitKey(1) == 27) {
			break;
		}
	}

	cv::waitKey();

}