//Counting Sort Algorithm 
//CountingSort.cpp
//Luke Simpson - Christopher Klippert, Alex Salas, Lyndon Wilson
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

//global variable(s) and array 
int arrLength = 500000;
int* arr;

//print function
void print()
{
	//basic for-loop for displaying the array
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//sorting function
void CountingSort()
{
	//counter variables i and j. 
	int i, j = 0;

	//range variable
	int range = 0;

	//other variables
	int index = 0;
	int min = 0;
	int max = 0;

	//init min and max as first element
	min = max = arr[0];

	//loop to constantly find new min and max values if they do exist
	for (i = 1; i < arrLength; i++)
	{
		//if arr[i] is < min, return arr[i], otherwise return previous min (same for max)
		min = (arr[i] < min) ? arr[i] : min;
		max = (arr[i] > max) ? arr[i] : max;
	}

	//sets the range from min to max value to be used for bucket array
	range = max - min + 1;

	//creates the bucket array based off of range
	int* arrBucket = new int[range];

	//builds the bucket array based off the range of the array
	for (i = 0; i < range; i++)
	{
		arrBucket[i] = 0;
	}

	//counts the # of times each number in the range appears 
	for (i = 0; i < arrLength; i++)
	{
		arrBucket[arr[i] - min]++;
	}

	//nested for-loop 
	//loops through # of times starting from min to max value of the array
	for (i = min; i <= max; i++)
	{
		//loops through the bucket array sorting it
		for (j = 0; j < arrBucket[i - min]; j++)
		{
			//stores sorted numbers in the array (arr)
			arr[index++] = i;
		}

	}

	//delete space
	delete[] arrBucket;
}

//function that creates array and copies data
void createArray()
{
	//file object
	ifstream dataset;

	//checks if file exists
	dataset.open("dataset.txt");
	if (!dataset)
	{
		//displays error message and stops if file did not exist. 
		cout << "Unable to open file datafile.txt" << endl;
		exit(1);
	}

	// initialize arr with arrLength
	arr = new int[arrLength];

	//counter variable (i)
	int i = 0;

	//copy data from dataset1.txt file (500,000 unsorted numbers)
	while (!dataset.eof())
	{
		dataset >> arr[i];
		i++;
	}

	//close file
	dataset.close();
}

//main function
int main()
{
	//declare clock variables
	clock_t start, stop;
	double time;

	//starts the clock 
	createArray();
	start = clock();

	//prints out the array after sorting
	cout << "After sorting: " << endl;
	CountingSort();

	//counting sort complete
	//initialize clock variables 
	stop = clock();
	time = (stop - start);

	//prints sorted array
	print();

	//Displays run time after sorting
	cout << "\n\nCounting sort took: " << time << " milliseconds" << endl;

	//deletes space after use
	delete[] arr;

	return 0;
}