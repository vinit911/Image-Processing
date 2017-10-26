
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

int main()
{

VideoCapture vid("video.mp4");
Mat temp;
Mat img(800,1200,CV_8UC1,Scalar(0));
char key;
int fram,i,j;
fram=vid.get(CV_CAP_PROP_FRAME_COUNT);
namedWindow("String", WINDOW_AUTOSIZE);

while(1)
{
vid.read(temp);

for(i=0;i<temp.rows;i++)
{
	for(j=0;j<temp.cols;j++)
	{	img.at<uchar>(i,j)=(temp.at<Vec3b>(i,j)[1]+temp.at<Vec3b>(i,j)[0]+temp.at<Vec3b>(i,j)[2])/3;
	}
}

imshow("String", img);
key=waitKey(50);
if(key=='e')
break;
}


cout<<"Video Length : "<<fram<<endl;


return(0);
}


