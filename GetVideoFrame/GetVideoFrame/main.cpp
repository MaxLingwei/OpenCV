#include <stdio.h>


#include<iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

#define STUDENT_ANALYSIS_GAP_IN_SECONDS 3
#define TEST_COUNT 10000
#define NUM_LEN 10
#define FILE_NAME_LEN 30

using namespace std;
using namespace cv;


int main()
{
	int iVideoFps = 0;
	int iFrameCount = 0;
	int iAnalysisFrameGap = 0;
	int iCurrentFrameNo = 0;
	unsigned int ui = 0;
	char szFileName[FILE_NAME_LEN];
	Mat mFrame;
	VideoCapture cCaptureTest;

	cCaptureTest = VideoCapture("D:\\Project\\Video\\cc\\Student0.mp4");


	if (cCaptureTest.isOpened())
	{
		cout << "open video" << endl;
	}
	else
	{
		cout << "faild" << endl;
	}

	iVideoFps = cCaptureTest.get(CV_CAP_PROP_FPS);
	iFrameCount = cCaptureTest.get(CV_CAP_PROP_FRAME_COUNT);
	iAnalysisFrameGap = STUDENT_ANALYSIS_GAP_IN_SECONDS * iVideoFps;


	while (iCurrentFrameNo < iFrameCount)
	{
		cCaptureTest >> mFrame;

		if (iCurrentFrameNo % 2 == 0)
		{
			sprintf(szFileName, "%u.jpg", ui);
			imwrite(szFileName, mFrame);
			cout << "capture frame" << ui++ << endl;
			
		}
		iCurrentFrameNo++;
	}
	return 0;
}