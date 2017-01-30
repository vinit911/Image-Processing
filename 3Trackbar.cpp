#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{

Mat a=imread ("a.png",1);
Mat b=imread ("a.png",0);

int i,j,x=0,y=0,z=0,e=0;
namedWindow ("String", WINDOW_NORMAL);
createTrackbar ("Blue", "String", &x , 255);
createTrackbar ("Green", "String", &y , 255);
createTrackbar ("Red", "String", &z , 255);
createTrackbar ("Error", "String", &e , 50);


while(1)
{
for(i=0;i<a.rows;i++)
{
for(j=0;j<a.cols;j++)
{
if(a.at<Vec3b>(i,j)[0] <x+e  && a.at<Vec3b>(i,j)[0]>x-e) 
{	if(a.at<Vec3b>(i,j)[1] <y+e  && a.at<Vec3b>(i,j)[1]>y-e) 
	{	if(a.at<Vec3b>(i,j)[2] <z+e  && a.at<Vec3b>(i,j)[2]>z-e) 
	        b.at<uchar>(i,j)=255;
	}
}
else
b.at<uchar>(i,j)=0;
}
}

imshow("String", b);

char i=waitKey(50);
if(i=='e')
break;
}
return (0);
}

