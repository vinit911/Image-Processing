#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int A[256];

int val=0,i,j,th,Max=0;
int main()
{

namedWindow ("String", WINDOW_NORMAL);

Mat b=imread ("abc.jpg",0);
Mat hist(400,257,CV_8UC3,Scalar(255,255,255));

for(i=0;i<b.rows;i++)
{
	for(j=0;j<b.cols;j++)
	{
   	val= b.at<uchar>(i,j);
	A[val]++;
	}
}

for(i=0;i<256;i++)
{
	if(Max<=A[i])
	Max=A[i];
}

int key=Max/400;
for(i=0;i<=400;i++)
{	for(j=0;j<=256;j++)
	if(i>400-A[j]/key)
	{
		hist.at<Vec3b>(i,j)[0]=0;
                hist.at<Vec3b>(i,j)[1]=0;
                hist.at<Vec3b>(i,j)[2]=255;
	}
}

imshow("String", hist);


waitKey(0);
return (0);
}

