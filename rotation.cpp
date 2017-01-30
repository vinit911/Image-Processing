#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

float rad;


int main()
{
rad=3.141/180;
Mat a=imread ("try.png",0);
Mat b(400,400,CV_8UC1,Scalar(0));

int i,j,x=200,y=200,quad,th=180;
float slope,hyp,nslope;
namedWindow ("String", WINDOW_NORMAL);
createTrackbar ("Angle", "String", &th , 360);


while(1)
{
for(i=0;i<a.rows;i++)
{
for(j=0;j<a.cols;j++)
{
	if(i!=a.rows/2)
	{

	if((j-a.cols/2)/(i-a.rows/2)+th<90 && (j-a.cols/2)/(i-a.rows/2)+th>=0)
	quad=1;
	else if((j-a.cols/2)/(i-a.rows/2)+th<180 && (j-a.cols/2)/(i-a.rows/2)+th>=90)
	quad=2;
	else if((j-a.cols/2)/(i-a.rows/2)+th<270 && (j-a.cols/2)/(i-a.rows/2)+th>=180)
	quad=3;
	else
	quad=4;

	slope=tan(rad*(j-a.cols/2)/(i-a.rows/2));
	hyp=sqrt((i-a.rows/2)*(i-a.rows/2)+(j-a.cols/2)*(j-a.cols/2));
	if(slope*(j-a.cols/2)/(i-a.rows/2)!=1)	
	nslope=(slope+(j-a.cols/2)/(i-a.rows/2))/(1-slope*(j-a.cols/2)/(i-a.rows/2));
	x=(200+hyp*cos(atan(nslope)));
	y=(200+hyp*sin(atan(nslope)));

	if(quad==1){
	x=abs(x);
	y=abs(y);	
	}
	else if(quad==2){
	x=-abs(x);
	y=abs(y);	
	}	
	else if(quad==3){
	x=-abs(x);
	y=-abs(y);	
	}	
	else{
	x=abs(x);
	y=-abs(y);	
	}

	b.at<uchar>(i,j)=a.at<uchar>(x,y);
	}

}
}

imshow("String", b);

char i=waitKey(50);
if(i=='e')
break;
}
return (0);
}

