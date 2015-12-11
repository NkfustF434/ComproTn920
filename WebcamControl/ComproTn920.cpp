#include "ComproTn920.h"
#include <opencv2\highgui\highgui.hpp>
#include <stdio.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <string>

/* Methods New */

size_t write_data(char* ptr, size_t size, size_t nmemb, void* userdata) {
	/*((std::stringstream*)userdata)->write(ptr, size * nmemb);
	return size * nmemb;*/
	
	size_t segsize = size * nmemb;
	return segsize;
}

void ComproTn920::ImageStream()
{
	while (g_bThreadStart)
	{
		g_clsCapture.read(g_clsImage);
		Sleep(1);
	}
}

ComproTn920::ComproTn920(std::string strIP)
{
	g_strIP = strIP;
	g_clsCapture = cv::VideoCapture(RTSP+g_strIP+STREAM);
	g_bThreadStart = true;
	g_clsStreamThread = std::thread(&ComproTn920::ImageStream,this);
}

ComproTn920::~ComproTn920()
{
	g_bThreadStart = false;
	g_clsStreamThread.join();
}

/* Private Methods */

void ComproTn920::PerformUrl(const char* cUrl)
{
	curl_easy_setopt(g_clsCurl, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(g_clsCurl, CURLOPT_WRITEDATA, NULL);

	curl_easy_setopt(g_clsCurl, CURLOPT_URL, cUrl);
	curl_easy_setopt(g_clsCurl, CURLOPT_NOBODY, true);
	//curl_easy_setopt(g_clsCurl, CURLOPT_HEADER, true);
	curl_easy_perform(g_clsCurl);
}


/* Public Methods */

void ComproTn920::Snapshot(cv::Mat& clsImage)
{
	clsImage = g_clsImage;
}

void ComproTn920::ChangeIP(std::string strNewIP)
{
	//Clean
	curl_easy_cleanup(g_clsCurl);

	g_strIP = strNewIP;
	g_clsCurl = curl_easy_init();
}

void ComproTn920::Move(ComproTn920::MoveDirection eMotionDirection)
{
	std::string strMoveUrl = "";

	switch (eMotionDirection)
	{
	case ComproTn920::MoveDirection::Home:
		strMoveUrl = HTTP + g_strIP + HOME;
		break;
	case ComproTn920::MoveDirection::Up:
		strMoveUrl = HTTP + g_strIP + UP;
		break;
	case ComproTn920::MoveDirection::RightUp:
		strMoveUrl = HTTP + g_strIP + RIGHT_UP;
		break;
	case ComproTn920::MoveDirection::Right:
		strMoveUrl = HTTP + g_strIP + RIGHT;
		break;
	case ComproTn920::MoveDirection::RightDown:
		strMoveUrl = HTTP + g_strIP + RIGHT_DOWN;
		break;
	case ComproTn920::MoveDirection::Down:
		strMoveUrl = HTTP + g_strIP + DOWN;
		break;
	case ComproTn920::MoveDirection::LeftDown:
		strMoveUrl = HTTP + g_strIP + LEFT_DOWN;
		break;
	case ComproTn920::MoveDirection::Left:
		strMoveUrl = HTTP + g_strIP + LEFT;
		break;
	case ComproTn920::MoveDirection::LeftUp:
		strMoveUrl = HTTP + g_strIP + LEFT_UP;
		break;
	default:
		break;
	}

	const char* cMoveUrl = strMoveUrl.c_str();
	PerformUrl(cMoveUrl);
}

void ComproTn920::SetMoveSpeed(ComproTn920::MoveSpeed eMotionSpeed)
{
	std::string strSpeedUrl = "";

	//--special--
	//std::stringstream ss;
	//ss << static_cast<int>(eMotionSpeed);
	//strSpeedUrl = HTTP + g_strIP + SPEED + ss.str();

	switch (eMotionSpeed)
	{
	case ComproTn920::MoveSpeed::One:
		strSpeedUrl = HTTP + g_strIP + SPEED + "1";
		break;
	case ComproTn920::MoveSpeed::Two:
		strSpeedUrl = HTTP + g_strIP + SPEED + "2";
		break;
	case ComproTn920::MoveSpeed::Three:
		strSpeedUrl = HTTP + g_strIP + SPEED + "3";
		break;
	case ComproTn920::MoveSpeed::Four:
		strSpeedUrl = HTTP + g_strIP + SPEED + "4";
		break;
	case ComproTn920::MoveSpeed::Five:
		strSpeedUrl = HTTP + g_strIP + SPEED + "5";
		break;
	case ComproTn920::MoveSpeed::Six:
		strSpeedUrl = HTTP + g_strIP + SPEED + "6";
		break;
	case ComproTn920::MoveSpeed::Seven:
		strSpeedUrl = HTTP + g_strIP + SPEED + "7";
		break;
	case ComproTn920::MoveSpeed::Eight:
		strSpeedUrl = HTTP + g_strIP + SPEED + "8";
		break;
	case ComproTn920::MoveSpeed::Night:
		strSpeedUrl = HTTP + g_strIP + SPEED + "9";
		break;
	case ComproTn920::MoveSpeed::Ten:
		strSpeedUrl = HTTP + g_strIP + SPEED + "10";
		break;
	default:
		break;
	}
	const char* cSpeedUrl = strSpeedUrl.c_str();
	PerformUrl(cSpeedUrl);
}

void ComproTn920::Disconnect()
{
	//Clean
	curl_easy_cleanup(g_clsCurl);
}