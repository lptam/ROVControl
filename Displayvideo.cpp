//MJPEG network stream to OpenCV 2

#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>


//"http://192.168.254.1:8090/?action=stream"

int main(){

    CvCapture* camera=cvCaptureFromFile("0");
    if (camera==NULL)
        printf("camera is null\n");
    else
        printf("camera is not null");

    cvNamedWindow("img");
    while (cvWaitKey(10)!=atoi("q")){
        double t1=(double)cvGetTickCount();
        IplImage *img=cvQueryFrame(camera);
        double t2=(double)cvGetTickCount();
        printf("time: %gms  fps: %.2g\n",(t2-t1)/(cvGetTickFrequency()*1000.), 1000./((t2-t1)/(cvGetTickFrequency()*1000.)));
        cvShowImage("img",img);
    }
    cvReleaseCapture(&camera);
}
