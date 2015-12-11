#include "ComproTn920.h"
#include <opencv2\highgui\highgui.hpp>
#include <time.h>

void main()
{
	//�غc����椸
	ComproTn920 clsCamera("163.18.62.19");

	//��l�Ƥ@�i�v��
	//cv::Mat clsImage;
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
	const std::string d = "D://1.avi";
	clsCamera.Snapshot(clsImage2);
	//CV_FOURCC('M', 'P', 'E', 'G')
	cv::VideoWriter clsWrite = cv::VideoWriter(d, 0, 30, cv::Size(clsImage2.cols, clsImage2.rows));
	int i = 0;
	while (1)
	{
		cv::Mat clsImage;
		clsCamera.Snapshot(clsImage);
		if (!clsImage.empty())
		{
			cv::imshow("Camera Image", clsImage);
			clsWrite.write(clsImage);
		}
		if (cv::waitKey(1) == 27) {
			break;
		}
	}
	clsWrite.release();

	/*for (int i = 0; i < 10; i++)
	{
	cv::imshow("Camera Image" + i, clsImageList[i]);
	}*/


	//�۾����
	//clsCamera.Snapshot(clsImage2);

	//�q�X��쪺�Ӥ�
	//cv::imshow("Camera Image2", clsImage2);

	//cv::moveWindow("Camera Image", 0, 0); 
	cv::waitKey();

}