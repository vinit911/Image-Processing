
//This program computes centre of mass of different blobs on the image.
//It uses Depth-First-Search to get distinct blobs and then computes centre of each blob. 
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

int visit[500][500],com[2];
Mat b=imread ("try.png",0);

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

void Com(int key)
{
	int xsum=0,sum=0,ysum=0,i,j;	
for(i=0;i<b.rows;i++)
{
xsum=0;
	for(j=0;j<b.cols;j++)
	{
		if(visit[i][j]==key) 	{  xsum++; sum++; }
	}
com[0]+=i*xsum;
}

for(j=0;j<b.cols;j++)
	{
	ysum=0;
		for(i=0;i<b.rows;i++)
		{		
			if(visit[i][j]==key)	ysum++; 
		}
	com[1]+=j*ysum;
	}

com[0]=com[0]/sum;
com[1]=com[1]/sum;
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
namedWindow("String",WINDOW_AUTOSIZE);
imshow("String",b);


cout<<"Pixels : "<<b.rows<<"X"<<b.cols<<endl;
for(i=0; i<4;i++)
{
Com(i);
cout<<"Centre of Mass of Blob "<<i <<" : "<<com[0]<<","<<com[1]<<endl;
}

waitKey(0);
return (0);
}


