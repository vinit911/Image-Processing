
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

int visit[500][500];
Mat b=imread ("binary.png",0);
Mat img(b.rows,b.cols,CV_8UC3,Scalar(0,0,0));

void DFS_visit(int i,int j,int count)
{
	visit[i][j]=count;
	for(int k=i-1; k<=i+1;k++)
		for(int l=j-1;l<=j+1;l++)
		{	if(visit[k][l]==0 && b.at<uchar>(k,l)==255) 
			DFS_visit(k,l,count);		
		}
	return;
}


int main()
{
int i,j,count=0;
for(i=0;i<b.rows;i++)
for(j=0;j<b.cols;j++)
visit[i][j]=0;

for(i=1;i<b.rows-1;i++)
{
	for(j=1;j<b.cols-1;j++)
	{
		if(visit[i][j]==0 && b.at<uchar>(i,j)==255)
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

namedWindow ("String", WINDOW_AUTOSIZE);
imshow("String", img);


waitKey(0);
return (0);
}


