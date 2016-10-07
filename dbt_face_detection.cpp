#if defined(__linux__) || defined(LINUX) || defined(__APPLE__) || defined(ANDROID)

#include <opencv2/imgproc.hpp>  // Gaussian Blur
#include <opencv2/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>  // OpenCV window I/O
#include <opencv2/features2d.hpp>
#include <opencv2/objdetect.hpp>

#include <stdio.h>
#include <string>
#include <vector>







#include<stdlib.h>
#include<iostream>
#include<ctime>
#include<unistd.h>
#include<sys/types.h>
















using namespace std;
using namespace cv;

const string WindowName = "Face Detection example";

class CascadeDetectorAdapter: public DetectionBasedTracker::IDetector
{
    public:
        CascadeDetectorAdapter(cv::Ptr<cv::CascadeClassifier> detector):
            IDetector(),
            Detector(detector)
        {
            CV_Assert(detector);
        }

        void detect(const cv::Mat &Image, std::vector<cv::Rect> &objects)
        {
            Detector->detectMultiScale(Image, objects, scaleFactor, minNeighbours, 0, minObjSize, maxObjSize);
        }

        virtual ~CascadeDetectorAdapter()
        {}

    private:
        CascadeDetectorAdapter();
        cv::Ptr<cv::CascadeClassifier> Detector;
 };
int system(char  *xdotool );
int main(int , char** )
{
    namedWindow(WindowName);

//"http://192.168.254.1:8090/?action=stream"

    VideoCapture VideoStream("http://192.168.254.1:8090/?action=stream");

    if (!VideoStream.isOpened())
    {
        printf("Error: Cannot open video stream from camera\n");
        return 1;
    }

    std::string cascadeFrontalfilename = "../../data/lbpcascades/lbpcascade_frontalface.xml";
    cv::Ptr<cv::CascadeClassifier> cascade = makePtr<cv::CascadeClassifier>(cascadeFrontalfilename);
    cv::Ptr<DetectionBasedTracker::IDetector> MainDetector = makePtr<CascadeDetectorAdapter>(cascade);

    cascade = makePtr<cv::CascadeClassifier>(cascadeFrontalfilename);
    cv::Ptr<DetectionBasedTracker::IDetector> TrackingDetector = makePtr<CascadeDetectorAdapter>(cascade);

    DetectionBasedTracker::Parameters params;
    DetectionBasedTracker Detector(MainDetector, TrackingDetector, params);

    if (!Detector.run())
    {
        printf("Error: Detector initialization failed\n");
        return 2;
    }

    Mat ReferenceFrame;
    Mat GrayFrame;
    vector<Rect> Faces;
    

    while(true)
    {
        VideoStream >> ReferenceFrame;
        cvtColor(ReferenceFrame, GrayFrame, COLOR_RGB2GRAY);
        Detector.process(GrayFrame);
        Detector.getObjects(Faces);

        for (size_t i = 0; i < Faces.size(); i++)
        {
            rectangle(ReferenceFrame, Faces[i], Scalar(0,255,0));
          system("xdotool key alt+Tab");

//while (i<10) { 



system("xdotool key alt+Tab sleep 2");	
/*
system("xdotool key 5");

system("xdotool keydown ctrl; sleep 2");

system("xdotool keyup ctrl");

system("xdotool key 2");

system("xdotool keydown 0xff51; sleep 2; xdotool keyup 0xff51");/* mover para frente*/

//system("xdotool keydown 0xff52; sleep 2"); /* mover para a esquerda*/

/*system("xdotool keyup 0xff52");

system("xdotool keydown 0xff51; sleep 2; xdotool keyup 0xff51");

system("xdotool keydown 0xff54; sleep 2"); /* mover para a esquerda*/

//system("xdotool keyup 0xff54");

//i==i++;

/*
#define XK_Left                          0xff51   Move left, left arrow 
#define XK_Up                            0xff52   Move up, up arrow 
#define XK_Right                         0xff53   Move right, right arrow 
#define XK_Down                          0xff54   Move down, down arrow 


system("xdotool keydown alt key Tab; xdotool keyup alt");

traking objevt
aruco


april tag c++ library
*/
	//}
        }

        imshow(WindowName, ReferenceFrame);

        if (waitKey(1) == 1) break;
    }

    //Detector.stop();

    return 0;
}

#else

#include <stdio.h>
int main()
{
    printf("This sample works for UNIX or ANDROID only\n");
    return 0;
}

#endif
