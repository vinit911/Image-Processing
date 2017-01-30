
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

VideoCapture vid("new.mp4");
Mat temp;

int isvalid(int i,int j)
{
if((i<0)||(j<0)||(i>=temp.rows) || (j>=temp.cols))
return 0;
else return 1;
}

int main()
{

Mat img(800,1200,CV_8UC1,Scalar(0));
char key;
int i,j;
int g1[600],g2[600],c=0,d=0,fram=0,goal1=0,goal2=0;

namedWindow("String", WINDOW_AUTOSIZE);

for(i=0;i<600;i++)
{	g1[i]=0; g2[i]=0;
}

vid.read(temp);
cout<<"Row : "<<temp.rows<<endl;
cout<<"Column : "<<temp.cols<<endl;

while(1)
{
vid.read(temp);
c=0;d=0;
for(i=231;i<502;i++)
{
	for(j=0;j<80;j++)
	{	
		if(isvalid(i,j))		
		if(abs(temp.at<Vec3b>(i,j)[0]-30)<30 && abs(temp.at<Vec3b>(i,j)[1]-165)<20 && abs(temp.at<Vec3b>(i,j)[2]-250)<5)
		{ c++; }
	}
	if(c>0)
	{break;}
	
}
for(i=279;i<555;i++)
{
	for(j=1062;j<1151;j++)
	{	
		if(isvalid(i,j))		
		if(abs(temp.at<Vec3b>(i,j)[0]-30)<30 && abs(temp.at<Vec3b>(i,j)[1]-165)<20 && abs(temp.at<Vec3b>(i,j)[2]-250)<5)
		//if(abs(temp.at<Vec3b>(i,j)[0]-30)<30 && abs(temp.at<Vec3b>(i,j)[1]-165)<50 && abs(temp.at<Vec3b>(i,j)[2]-240)<15)
		{ d++; break; }
	}
	if(d>0)
	break;
}

g1[fram]=c;
g2[fram]=d;
fram++;
imshow("String", temp);
key=waitKey(50);
if(key=='e')
break;

if(fram==550)
break;

}
for(i=0; i<fram;i++)
{
cout<<g1[i];
if(g1[i]==0 && g1[i+1]==0 && g1[i+2]==0 && g1[i+3]==0 && g1[i+4]>0 && g1[i+5]>0 && g1[i+6]>0 && g1[i+7]>0)
goal1++;
if(g2[i]==1 && g2[i+1]==1 && g2[i+2]==0 && g2[i+3]==0)
goal2++;
}

cout<<"Goal done by 1 : "<<goal1<<endl;
cout<<"Goal done by 2 : "<<goal2<<endl;


return(0);
}


