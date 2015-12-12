#include "ComproTn920.h"
#include <opencv2\highgui\highgui.hpp>
#include <time.h>

void main()
{
	//�غc����椸
	ComproTn920 clsCamera("163.18.62.19");

	//��l�Ƥ@�i�v��
	cv::Mat clsImage2;

	//��ĳ�������Y��Home�A�i�H�T�O�۾����ʪ���m�O�諸
	//clsCamera.Move(ComproTn920::MoveDirection::Home);

	//�]�w�۾��t��
	//clsCamera.SetMoveSpeed(ComproTn920::MoveSpeed::Ten);

	//�۾��V������
	//clsCamera.Move(ComproTn920::MoveDirection::Left);

	//�ݭnSleep�A���ݲ��ʰ���
	//Sleep(1000);
	
	//�۾����
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