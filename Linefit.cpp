
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

int isvalid(Mat img, int i, int j)
{
if((i<0)||(j<0)||(i>=img.rows)||(j>=img.cols))
return 0;
else return 1;
}
struct spot
{
int x=0;
int y=0;
int bright=0;
};

int main()
{
namedWindow ("String", WINDOW_NORMAL);
int th=80;
createTrackbar ("Threshold", "String", &th , 100);



spot Max,arr[500];
Mat b=imread ("pentagon.png",0);
float lim=2*sqrt(b.rows*b.rows+b.cols*b.cols);
Mat img(lim+1,200,CV_8UC1,Scalar(0));
Mat c(b.rows,b.cols,CV_8UC1,Scalar(0));
float rad;
rad=3.141/180;
int d;
int i,j,k,l,val=0;

for(i=0;i<b.rows;i++)
{
	for(j=0;j<b.cols;j++)
	{
		if(b.at<uchar>(i,j)==255)
		{		
		for(k=0;k<180;k++)
		{ d=(int)(((i*cos(k*rad)+j*sin(k*rad))+lim/2)); 
		if(d>0)
		img.at<uchar>(d,k)++;
		}
		}
	}
}

int yo=10;

cout<<"img.rows : "<<img.rows<<"  img.cols : "<<img.cols<<endl;
for(i=yo;i<img.rows-yo;i++)
{
	for(j=yo;j<img.cols-yo;j++)
	{
	Max.bright=0;
	if(img.at<uchar>(i,j)>th)
	{
		for(k=i-yo;k<=i+yo;k++)
		{
		for(l=j-yo;l<=j+yo;l++)
		{	
			//if(isvalid(img,i+k,j+l))			
			if(img.at<uchar>(i,j)>Max.bright) 
			Max={i,j,img.at<uchar>(i,j)};    
		}
		}	
	}
	if(Max.x==i && Max.y==j)
	arr[val++]=Max;
	}
}
cout<<val<<endl;

for(i=0;i<c.rows;i++)
{
	for(j=0;j<c.cols;j++)
	{
	for(k=0;k<val;k++)
	{
		if(abs(i*cos((arr[k].y)*rad)+j*sin((arr[k].y)*rad)-(arr[k].x-lim/2))<1)
		c.at<uchar>(i,j)=255;
	}
	}
}	

imshow("String", c);
waitKey(0);
return (0);
}


