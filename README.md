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

# Day 5
Retrieving a binary image back from its sinusoidal representation
Basic video processing using webcam input.

# Day 6
Path planner using DFS involving a stack.
Basic Autonomous

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
