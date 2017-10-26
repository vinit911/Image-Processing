//Creates a Histogram having intensity along x-axis and no. of pixels having that intensity along y-axis.
//It superimposes the red, green and blue intensity histograms to get a aesthetic look.
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int B[256],G[256],R[256];

int val=0,i,j,th,Max=0;
int main()
{

for(i=0;i<256;i++)
{
B[i]=0;
G[i]=0;
R[i]=0;
}
namedWindow ("String", WINDOW_NORMAL);

Mat b=imread ("abc.jpg",1);
Mat hist(400,257,CV_8UC3,Scalar(0,0,0));

for(i=0;i<b.rows;i++)
{
	for(j=0;j<b.cols;j++)
	{
   	val= b.at<Vec3b>(i,j)[0];
	B[val]++;
        val= b.at<Vec3b>(i,j)[1];
        G[val]++;
        val= b.at<Vec3b>(i,j)[2];
        R[val]++;
	}
}

for(i=0;i<256;i++)
{
	if(Max<=B[i])
	Max=B[i];
        if(Max<=G[i])
        Max=G[i];
        if(Max<=R[i])
        Max=R[i];
}

int key=Max/2000;

for(i=0;i<=400;i++)
{	for(j=0;j<=256;j++)
	{
	if(i>400-B[j]/key)
		hist.at<Vec3b>(i,j)[0]=255;
        if(i>400-G[j]/key)
                hist.at<Vec3b>(i,j)[1]=255;
        if(i>400-R[j]/key)
                hist.at<Vec3b>(i,j)[2]=255;
	}
}

imshow("String", hist);


waitKey(0);
return (0);
}

