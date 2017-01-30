
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

VideoCapture vid("new.mp4");
Mat temp;

void Callbackfunc (int Event, int  y, int x, int flags, void *userdata)
{
	if (Event==EVENT_LBUTTONDOWN)
	{
	cout<<"x : "<<x<<" y: "<<y<<endl;
	cout<<"Frame : "<<vid.get(CV_CAP_PROP_POS_FRAMES)<<endl;
	printf("B=%d\n",temp.at<Vec3b>(x,y)[0]);
        printf("G=%d\n",temp.at<Vec3b>(x,y)[1]);
        printf("R=%d\n",temp.at<Vec3b>(x,y)[2]);
	}
}

int main()
{

Mat img(800,1200,CV_8UC1,Scalar(0));
char key;
int fram,i,j;
fram=vid.get(CV_CAP_PROP_FRAME_COUNT);
cout<<"fram :"<<fram;
namedWindow("String", WINDOW_AUTOSIZE);

while(1)
{
vid.read(temp);

imshow("win",temp);
setMouseCallback ("win",Callbackfunc,NULL);

key=waitKey(50);
if(key=='e')
break;

}

return(0);
}


