# Image-Processing
Keeps my OpenCV codes.

# Day 1
OpenCV installation
Basic Programming
OpenCV
	Displaying an image
	Creating Patterns
		1. A Red square inside an image.
		2. A Square image coloured Red above the principal diagonal and black below it.
	Increasing Brightness of an image
  
Homework
	Displaying water image of a picture
	Creating a chess board
# Day 2
Converting a Binary Image to Grayscale image
	using average of BGR colour intensities
	using formula 0.587G + 0.299R + 0.114B
Converting a Grayscale Image to Binary image
	using manual Thresholding
Pixel Dilation
Pixel Contracion
Basic Filtering
	using mean of 3*3 kernel
	Using median of 5*5 kernel
	using Gaussian Kernel
Mouse-click functions

Homework
	Draw a Histogram having intensity in x-axis and no. of pixels having that intensity in y-axis
 	Converting a Grayscale Image to Binary image using Automatic Thresholdng such that 50% of image's pixels are white and rest are black.
# Day 3
Edge Detection 
	using Sobel Filters
	using max-min in 3X3 kernel
	using canny edge detector
Blob Detection
Erosion and Dilation
Track bar creation

Homework
	Draw a BGR Histogram having intensities of each colour on x-axis and no. of pixels having those intensities on y-axis.
# Day 4
1.Mid-Evaluation
2.To find out center of mass of each blob in a binary image
3.Converting an RGB image to binary using four trackbars to control R,G,B colour intensities and also the error range
4.Applying isValid function on Meanfilter program
5.Sinusoid representation of a binary image in Hough space


PROGRAMS:


PROGRAM: To find out center of mass of each blob in a binary image
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>

using namespace cv;
using namespace std;

void DFS_visit(int i, int j, int count, Mat img, Mat visited)
{
    visited.at<uchar>(i, j) = (int)(255 / count);
    int k, l;
    for (k = i - 1; k <= i + 1; k++)
    {
        for (l = j - 1; l <= j + 1; l++)
        {
            if (visited.at<uchar>(k, l) == 0 && img.at<uchar>(k, l) == 255)
                DFS_visit(k, l, count, img, visited);
        }
    }
}

int main(int, char)
{
    Mat img = imread("try.png", 0);

    Mat visited(img.rows, img.cols, CV_8UC1, Scalar(0));
    int i, j;

    int count = 1;
    for (i = 0; i < img.rows; i++)
    {
        for (j = 0; j < img.cols; j++)
        {
            if (visited.at<uchar>(i, j) == 0 && img.at<uchar>(i, j) == 255)
            {
                DFS_visit(i, j, count, img, visited);
                count++;
            }
        }
    }


    long int sumx = 0;
    long int sumy = 0;
    long int pixels = 0;

    int cnt = 1;
    while (cnt < 4)
    {
        for (i = 0; i < img.rows; i++)
        {
            for (j = 0; j < img.cols; j++)
            {
                if (visited.at<uchar>(i, j) == (int)(255 / cnt))
                {
                    sumx = sumx + i;
                    sumy = sumy + j;
                    pixels++;
                }
            }
        }
        cout << "CM of image" << cnt << "=" << double(sumx / pixels) << "," << double(sumy / pixels) << "\n";
        ++cnt;
    }



    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Image", img);

    namedWindow("Image1", WINDOW_AUTOSIZE);
    imshow("Image1", visited);
    waitKey(0);

}


PROGRAM: Converting an RGB image to binary using four trackbars to control R,G,B colour intensities and also the error range
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;


int main(int, char)
{
    int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    namedWindow("Image", WINDOW_AUTOSIZE);
    namedWindow("Final", WINDOW_AUTOSIZE);
    createTrackbar("TrackerB", "Final", &t1, 255);
    createTrackbar("TrackerG", "Final", &t2, 255);
    createTrackbar("TrackerR", "Final", &t3, 255);
    createTrackbar("TrackerE", "Final", &t4, 255);

    while (1)
    {
        Mat img = imread("E:\\Pics\\a.png", 1);
        Mat a(img.rows, img.cols, CV_8UC1, Scalar(0));
        int i, j;

        for (i = 0; i < img.rows; i++)
        {
            for (j = 0; j < img.cols; j++)
            {
                if ((img.at<Vec3b>(i, j)[0])>(t1 - t4) && (img.at<Vec3b>(i, j)[0])<(t1 + t4) &&
                    (img.at<Vec3b>(i, j)[1])>(t2 - t4) && (img.at<Vec3b>(i, j)[1])<(t2 + t4) &&
                    (img.at<Vec3b>(i, j)[2])>(t3 - t4) && (img.at<Vec3b>(i, j)[2]) < (t3 + t4) &&
                    (t1 - t4)>0 && (t2 - t4)>0 && (t3 - t4)>0)
                    a.at<uchar>(i, j) = 255;
                else
                    a.at<uchar>(i, j) = 0;
            }
        }

        imshow("Image", img);
        imshow("Final", a);

        int k = waitKey(50);
        if (k == 27)
            break;
    }


}


PROGRAM: Applying isValid function on Meanfilter program
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int isValid(Mat img, int i, int j)
{
    if ((i <= 0) || (j <= 0) || (i >= img.rows) || (j >= img.cols))
        return 0;
    else
        return 1;
}

int main(int, char)
{
    Mat img = imread("E:\\Pics\\lena_n.png", 0);
    int i, j, k, l, m = 0, p, q;

    p = img.rows;
    q = img.cols;

    Mat a(p, q, CV_8UC1, Scalar(0));

    double kernel[3][3];
    kernel[0][0] = kernel[0][2] = kernel[2][0] = kernel[2][2] = 0.0625;
    kernel[0][1] = kernel[1][0] = kernel[2][1] = kernel[1][2] = 0.125;
    kernel[1][1] = 0.25;

    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            for (k = -1; k < 2; k++)
            {
                for (l = -1; l < 2; l++)
                {

                    if (isValid(img, i + k, j + l))
                        a.at<uchar>(i, j) += img.at<uchar>(i + k, j + l)*kernel[k + 1][l + 1];
                }
            }

        }
    }

    namedWindow("Win", WINDOW_AUTOSIZE);
    imshow("Win", a);


    waitKey(0);
    return 0;
}


PROGRAM: Sinusoid representation of a binary image in Hough space
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<math.h>
using namespace cv;
using namespace std;


int main(int, char)
{
    Mat img = imread("E:\\Pics\\pentagon.png", 0);
    int p = img.rows, q = img.cols;
    int rows = (int)(sqrt(p*p + q*q)) + 1;
    int i, j;
    int d;
    Mat a(rows, 180, CV_8UC1, Scalar(0));
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            if (img.at<uchar>(i, j) == 255)
            {
                double theta, rad;
                for (theta = 0; theta <= 180; theta++)
                {
                    rad = ((3.14)*theta) / 180;
                    d = (int)(i*cos(rad) + j*sin(rad));
                    if (d>0)
                        a.at<uchar>(rows - d - 1, theta) = 255;
                }
            }
        }
    }

    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Image", img);
    namedWindow("sine", WINDOW_AUTOSIZE);
    imshow("sine", a);
    waitKey(0);
}

# Day 5
Retrieving a binary image back from its sinusoidal representation
Basic video capturing





PROGRAM: Retrieving a binary image back from its sinusoidal representation

We run a for loop throughout the sinusoid image and check for local maximas  using a kernel and a threshold for determining the maxima. The coordinates of each maxima are of the form (d,theta). Using the equation d=x*cos(theta) + y*sin(theta), each maxima can be converted into a straight line and we get back the original binary image. This is basically the reverse process of converting a binary image to sinusoids in Hough space.

#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include "opencv2\Core\Core.hpp"
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;


int main(int, char)
{
    Mat img = imread("E:\\Pics\\pentagon.png", 0);

    int p, k, l, n, m, max1, max2, x;
    double y;
    int cnt = 0;
    double d;
    double theta;
    p = (int)(sqrt(img.rows*img.rows + img.cols*img.cols));
    Mat curve((2 * p + 1), 180, CV_8UC1, Scalar(0));
    Mat Lines(img.rows, img.cols, CV_8UC1, Scalar(0));
    cout << p << endl;


    int i, j;
    int A[49];

    for (i = 0; i < 49; i++)
        A[i] = 0;

    for (i = 0; i < img.rows; i++)
    {

        for (j = 0; j < img.cols; j++)
        {
            if (img.at<uchar>(i, j) == 255)
            {
                for (theta = 0; theta < 180; theta++)
                {
                    d = j*cos((theta*3.14) / 180.00) + i*sin((theta*3.14) / 180.00) + p;
                    d = (int)d;
                    if (d>0)
                        curve.at<uchar>(d, theta) = curve.at<uchar>(d, theta) + 1;
                }
            }
        }
    }

    m = curve.rows;
    n = curve.cols;
    cout << m;
    for (i = 0; i < m; i++)
    {

        for (j = 0; j < n; j++)
        {
            max1 = curve.at<uchar>(i, j);
            if (max1>40)
            {

                for (x = 0; x < img.rows; x++)
                {

                    if (sin((j*3.14) / 180.00) != 0)
                        y = (i - p - x*cos((j*3.14) / 180.00)) / sin((j*3.14) / 180.00);
                    y = int(y);
                    if (y > 0 && y < img.rows)
                        Lines.at<uchar>(y, x) = 255;
                }
            }

        }
    }

    namedWindow("C", WINDOW_AUTOSIZE);
    imshow("C", Lines);

    namedWindow("B", WINDOW_AUTOSIZE);
    imshow("B", curve);

    namedWindow("A", WINDOW_AUTOSIZE);
    imshow("A", img);

    waitKey(0);
    return 0;
}


PROGRAM: Basic video capturing

The first command is: VideoCapture vid(0);  Here, 0 represents input from webcam. It can be replaced by 1(input from USB camera) or the path of an existing video file written in quotes.
We take an image Mat temp, which represents a frame of the video, and run it in a while loop in order to display the video(because a video is essentially a collection of fast moving frames)


Example program:(webcam input)


#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"


using namespace cv;
using namespace std;

int main(int, char)
{
    VideoCapture vid(0);
    Mat temp;
    namedWindow("window", WINDOW_AUTOSIZE);
    while (1)
    {
        vid.read(temp);

        imshow("window", temp);
        int k = waitKey(50);
        if (k == 27)
            break;
    }

}

# Day 6
Path planner using DFS involving a stack.
Basic Autonomous



Path planner:
We use DFS involving a stack.

DFS(start,end)
{
s.push(start);
while(start!=end)
{
temp=s.top();
for(    )
{
for(  )
{
current;
if(temp is not visited && no obstacle)
{
DFS(current,end);
pop();
}
}
}
…..


BASIC AUTONOMOUS

Microcontroller: brain of the bot
Supply to DC motor: battery or power supply(adapter)
Difference between microcontrollers and microprocessors: Microcontrollers are self-sufficient with inbuilt RAM, whereas microprocessors have external RAM and hence are not self-sufficient.
Sensor-->Microcontroller-->Actuator
4 types of commands in Arduino IDE: 
digitalWrite()
digitalRead() 
analogWrite()
analogRead()

Sample code in Arduino IDE:
void setup()
{
pinMode(13,OUTPUT);
}
void loop()
{
digitalWrite(13,HIGH);
delay(1000);
digitalWrite(13,LOW);
delay(1000);
}


# Day 7
Problem Statement:

"Perform Fillbucket operation like in MS-Paint"
"Counting the number of goals in Robosoccer"


Fillbucket:

First used a mouse-click function to get the coordinates of the points at which the mouse is clicked.
Then start a DFS until all the white pixel inside the borders are coloured.
I used a condition that if mouse is clicked on the borders than it will perform no task.

Robosoccer:
First I made a program to find the coordinates of the goal post
Then I extracted the orange colour of the ball
Using the colour of the ball I kept track of its movement
I declared an array(for each team) which stores a value for each frame. It stores 1 if ball inside the goal post and else 0
The point at which the array has a change in value from 1 to 0 is declared as a goal
