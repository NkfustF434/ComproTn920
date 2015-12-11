#ifndef _COMPRO_TN920_H
#define _COMPRO_TN920_H

#include <opencv2\highgui\highgui.hpp>
#include <stdio.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <string>
#include <thread> 
/*
class StreamThread
	{
	private:
		cv::Mat g_clsImage;
	public:
		StreamThread(cv::Mat clsImage)
		{
			g_clsImage = clsImage;
		}

		void GetStream()
		{
			;
		}

		void StartThread()
		{
			std::thread g_clsThread = std::thread(GetStream);
		}


	};*/
class ComproTn920
{
private:
	CURL* g_clsCurl;
	cv::VideoCapture g_clsCapture;
	bool g_bThreadStart = false;
	std::thread g_clsStreamThread;
	cv::Mat g_clsImage;

	std::string g_strIP;
	std::string const HTTP = "http://";
	std::string const RTSP = "rtsp://";

	/*Direction*/
	std::string const HOME = "/cgi-bin/view/cammove.cgi?move=home";
	std::string const UP = "/cgi-bin/view/cammove.cgi?move=up";
	std::string const RIGHT_UP = "/cgi-bin/view/cammove.cgi?move=rightup";
	std::string const RIGHT = "/cgi-bin/view/cammove.cgi?move=right";
	std::string const RIGHT_DOWN = "/cgi-bin/view/cammove.cgi?move=rightdown";
	std::string const DOWN = "/cgi-bin/view/cammove.cgi?move=down";
	std::string const LEFT_DOWN = "/cgi-bin/view/cammove.cgi?move=leftdown";
	std::string const LEFT = "/cgi-bin/view/cammove.cgi?move=left";
	std::string const LEFT_UP = "/cgi-bin/view/cammove.cgi?move=leftup";

	std::string const SPEED = "/cgi-bin/view/ptzspeed.cgi?speed=";

	/*Image*/
	std::string const NEW_IMAGE = "/snapshot.jpg";
	std::string const SHNAPSHOT = "/cgi-bin/view/ss.cgi";

	/*Stream*/
	std::string const STREAM = "/medias1";

public:
	enum class MoveDirection
	{
		Home,
		Up,
		RightUp,
		Right,
		RightDown,
		Down,
		LeftDown,
		Left,
		LeftUp
	};

	enum class MoveSpeed
	{
		One = 1,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Night,
		Ten
	};

private:

	//size_t write_data(char *ptr, size_t size, size_t nmemb, void* userdata);

	void PerformUrl(const char* cUrl);
	void ImageStream();

public:

	explicit ComproTn920(std::string);
	~ComproTn920();

	void Snapshot(cv::Mat& clsImage);

	void ChangeIP(std::string);

	void Move(MoveDirection eMoveDorection);

	void SetMoveSpeed(MoveSpeed eMoveSpeed);

	void Disconnect();

};

#endif