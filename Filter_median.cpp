
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

int main()
{

Mat b=imread ("vinit.jpg",0);
Mat img(b.rows,b.cols,CV_8UC1,Scalar(0));

int arr[49],key=0;

for(int i=3;i<b.rows-3;i++)
{
	for(int j=3;j<b.cols-3;j++)
	{
	key=0;	
		for(int k=-3;k<=3;k++)
		{	for(int l=-3;l<=3;l++)
			{
			arr[key++]=b.at<uchar>(i+k,j+l);	    
			}
		}
	sort(arr,arr+49);
	img.at<uchar>(i,j)=arr[24];
	}
}

namedWindow ("String", WINDOW_AUTOSIZE);
imshow("String", img);

imwrite("Fil_vinit.jpg",img);

waitKey(0);
return (0);
}


