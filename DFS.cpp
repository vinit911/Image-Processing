
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

int visit[2000][2000];
Mat b=imread ("dfs_path.jpg",0);
Mat img(b.rows,b.cols,CV_8UC3,Scalar(0,0,0));

int isvalid(int i,int j)
{
if((i<0)||(j<0)||(i>=b.rows) || (j>=b.cols))
return 0;
else return 1;
}

int DFS(Point start,Point end)
{
int k,l;
Point current,temp;
stack<Point> s;
s.push(start);

while(1)
{
	current=s.top();
	for(k=current.x-1;k<=current.x+1;k++)
	for(l=current.x-1;l<=current.x+1;l++)
	{
		if(isvalid(k,l))
		{
			if(b.at<uchar>(k,l)==255)
			{
			temp.x=k; temp.y=l;
			s.push(temp);
			}
			if(temp==end || DFS(temp,end)==1)
			{
			visit[k][l]=1;
			s.pop();
			return 1;
			}
		}
	}
	s.pop();	
	return 0;
}
}


int main()
{
int i,j;
Point start,end;
for(i=0;i<b.rows;i++)
for(j=0;j<b.cols;j++)
visit[i][j]=0;

namedWindow ("String", WINDOW_AUTOSIZE);
cout<<"rows : "<<b.rows<<endl;
cout<<"cols : "<<b.cols<<endl;
start.x=0;
start.y=0;
end.x=b.rows-1;
end.y=b.cols-1;


DFS(start,end);

for(i=1;i<b.rows-1;i++)
{
	for(j=1;j<b.cols-1;j++)
	{
		img.at<Vec3b>(i,j)[visit[i][j]]=255;
	}
}


imshow("String", img);


waitKey(0);
return (0);
}


