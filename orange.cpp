
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

int main()
{

VideoCapture vid("new.mp4");
VideoWriter yo;
Mat temp;
Mat img(800,1200,CV_8UC1,Scalar(0));
char key;
int fram,i,j;
fram=vid.get(CV_CAP_PROP_FRAME_COUNT);
namedWindow("String", WINDOW_AUTOSIZE);

Size S = Size((int) vid.get(CV_CAP_PROP_FRAME_WIDTH), (int) vid.get(CV_CAP_PROP_FRAME_HEIGHT));
int ex = static_cast<int>(vid.get(CV_CAP_PROP_FOURCC));

while(1)
{
vid.read(temp);

for(i=0;i<temp.rows;i++)
{
	for(j=0;j<temp.cols;j++)
	{	
		if(abs(temp.at<Vec3b>(i,j)[0]-30)<30 && abs(temp.at<Vec3b>(i,j)[1]-165)<50 && abs(temp.at<Vec3b>(i,j)[2]-240)<15)
		img.at<uchar>(i,j)=255;
		else img.at<uchar>(i,j)=0;
	}
}

imshow("String", img);
key=waitKey(50);
if(key=='e')
break;

}

yo.open("yo.mp4", ex, vid.get(CV_CAP_PROP_FPS), S, true);
cout<<"Video Length : "<<fram<<endl;


return(0);
}


