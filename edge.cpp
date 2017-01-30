
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

int main()
{

float Gx[3][3]={{-1,0,1},{-2,0,2},{-1,0,1}};
float Gy[3][3]={{-1,-2,-1},{0,0,0},{1,2,1}};

Mat b=imread ("a.png",0);
Mat var;
var=Mat(b.rows,b.cols,CV_8UC1,Scalar(0));
int sumx=0,sumy=0;

for(int i=1;i<b.rows-1;i++)
{
        for(int j=1;j<b.cols-1;j++) 
	{sumx=0,sumy=0;  
                for(int k=-1;k<=1;k++)
                {       for(int l=-1;l<=1;l++)
                        {
                        sumx+=b.at<uchar>(i+k,j+l)*Gx[k+1][l+1];            
                        sumy+=b.at<uchar>(i+k,j+l)*Gy[k+1][l+1];     
			}
                }
        var.at<uchar>(i,j)=sqrt(sumx*sumx+sumy*sumy)/4;
        }
}

namedWindow ("String", WINDOW_NORMAL);
imshow("String", var);


waitKey(0);
return (0);
}

