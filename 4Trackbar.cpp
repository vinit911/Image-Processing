#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{

Mat a=imread ("a.png",1);
Mat b=imread ("a.png",0);

int i,j,x=0,y=0,z=0;
namedWindow ("String", WINDOW_NORMAL);
createTrackbar ("Blue", "String", &x , 300);
createTrackbar ("Green", "String", &y , 300);
createTrackbar ("Red", "String", &z , 300);


while(1)
{
for(i=0;i<a.rows;i++)
{
for(j=0;j<a.cols;j++)
{

  /*  b.at<uchar>(i,j) = ( a.at<Vec3b>(i,j)[0]+ a.at<Vec3b>(i,j)[1]+ a.at<Vec3b>(i,j)[2])/3 ;*/
if(a.at<Vec3b>(i,j)[2] <z  && a.at<Vec3b>(i,j)[0]<x && a.at<Vec3b>(i,j)[1]<y)      b.at<uchar>(i,j)=255;
else  b.at<uchar>(i,j)=0;

}
}

imshow("String", b);

char i=waitKey(50);
if(i=='e')
break;
}
return (0);
}

