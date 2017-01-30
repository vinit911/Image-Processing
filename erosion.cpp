
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

int arr[9];
int Search()
{
	int c=0;	
	for(int i=0;i<9;i++)
	{
	if(arr[i]==255)
	c++;
	}
if(c>0)
return 255;
else
return 0;
}

int main()
{

Mat b=imread ("filter2.png",0);
Mat img(b.rows,b.cols,CV_8UC1,Scalar(0));

int i,j,k,l,key=0,u=0;

for(i=1;i<b.rows-1;i++)
{
	for(j=1;j<b.cols-1;j++)
	{
	key=0;u=0;	
		for(k=-1;k<=1;k++)
		{	for(l=-1;l<=1;l++)
			{
			arr[key++]=b.at<uchar>(i+k,j+l);	    
			}
		}	
	img.at<uchar>(i,j)=Search();

	}
}

namedWindow ("String", WINDOW_AUTOSIZE);
imshow("String", img);


waitKey(0);
return (0);
}


