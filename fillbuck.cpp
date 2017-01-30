
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

Mat b=imread ("shapes.jpg",0);

void DFS_visit(int i,int j)
{
if(b.at<uchar>(i,j)!=0)
{	
	b.at<uchar>(i,j)=0;
	for(int k=i-1; k<=i+1;k++)
		for(int l=j-1;l<=j+1;l++)
		{	if(b.at<uchar>(k,l)==255) 
			DFS_visit(k,l);		
		}
}
	return;
}

void Callbackfunc (int Event, int  y, int x, int flags, void *userdata)
{
	if (Event==EVENT_LBUTTONDOWN)
	{
	DFS_visit(x,y);
	}
}





int main()
{
int i,j,count=0;

namedWindow ("String", WINDOW_AUTOSIZE);
while(1)
{
imshow("win",b);
setMouseCallback ("win",Callbackfunc,NULL);
char i=waitKey(50);
if(i=='e')
break;
}
/*
for(i=1;i<b.rows-1;i++)
{
	for(j=1;j<b.cols-1;j++)
	{
		if(visit[i][j]==0 && b.at<uchar>(i,j)==0)
		{
		count++;
		DFS_visit(i,j,count);	
		}
	}
}

for(i=1;i<b.rows-1;i++)
{
	for(j=1;j<b.cols-1;j++)
	{
		img.at<Vec3b>(i,j)[visit[i][j]]=255;
	}
}


imshow("String", img);
*/

return (0);
}


