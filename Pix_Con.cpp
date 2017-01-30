#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{

Mat a=imread ("a.png",1);
Mat b(a.rows/2+3, a.cols/2+3, CV_8UC3, Scalar(0,0,0));

int i,j,k;

for(i=0;i<a.rows/2;i++)
{
        for(j=0;j<a.cols/2;j++)
        {
        b.at<Vec3b>(i,j) = (a.at<Vec3b>(2*i,2*j) + a.at<Vec3b>(2*i+1,2*j) + a.at<Vec3b>(2*i,2*j+1) + a.at<Vec3b>(2*i+1,2*j+1))/4;
        }
}

namedWindow("String",WINDOW_AUTOSIZE);
imshow("String", b);

waitKey(0);
return(0);

}

