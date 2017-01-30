
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace cv;
using namespace std;



int main()
{
Mat b=imread ("pentagon.png",0);
float lim=2*sqrt(b.rows*b.rows+b.cols*b.cols)/5;
Mat img(lim,400,CV_8UC1,Scalar(0));
float rad,k;
rad=3.141/180;
int d;
int i,j;

for(i=0;i<b.rows;i++)
{
	for(j=0;j<b.cols;j++)
	{
		if(b.at<uchar>(i,j)==255)
		{		
		for(k=0;k<=360;k++)
		{ d=(int)(((i*cos(k*rad)+j*sin(k*rad))+lim/2+600)/5); 
		if(d>0)
		img.at<uchar>(d,k)++;
		}
		}
	}
}



namedWindow ("String", WINDOW_AUTOSIZE);
imshow("String", img);


waitKey(0);
return (0);
}


