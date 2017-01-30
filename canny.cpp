
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

int main()
{

Mat b=imread ("ext4.png",1);
Mat img(b.rows,b.cols,CV_8UC3,Scalar(0,0,0));
namedWindow ("String", WINDOW_NORMAL);
int x,y;
createTrackbar ("Low", "String", &x , 300);
createTrackbar ("High", "String", &y , 300);
while(1)
{
namedWindow ("String", WINDOW_AUTOSIZE);

Canny(b,img,x,y);
imshow("String",img);
char i=waitKey(50);
if(i=='e')
break;

}
imwrite("ext4e.jpg",img);
return (0);
}


