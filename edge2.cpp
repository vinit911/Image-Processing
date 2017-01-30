
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

int main()
{

Mat b=imread ("a.png",0);
Mat var;
int v,key=0;
namedWindow ("String", WINDOW_NORMAL);
createTrackbar ("Threshold", "String", &v , 260);
var=Mat(b.rows,b.cols,CV_8UC1,Scalar(0));
int arr[9];

while(1)
{
for(int i=1;i<b.rows-1;i++)
{
        for(int j=1;j<b.cols-1;j++) 
	{  key=0;
                for(int k=-1;k<=1;k++)
                {       for(int l=-1;l<=1;l++)
                        {
                        arr[key++]=b.at<uchar>(k+i,l+j);     
			}
                }
	sort(arr,arr+9);
	if(arr[8]-arr[0]>v)
        var.at<uchar>(i,j)=255;
	else
	var.at<uchar>(i,j)=0;
        }
}


imshow("String", var);


char i=waitKey(50);
if(i=='e')
break;
}

return (0);
}

