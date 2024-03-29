#include <iostream>
using namespace std;

// array of integers to hold values
int arr[20]; 
int cmp_count = 0; // number of datamovements
int mov_count = 0; // number of comparasion
int n;

void input() 
{
	while (true)
	{
		cout << "Masukan panjang elemen array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}
	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}
//swaps the element at index x with the element at index y
void swap(int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
	mov_count++;


}

void q_short(int low, int high)
{
	
	int temp;
	int pivot, i, j;
	if (low > high) {// step 1
		return;
	}

	pivot = arr[low]; // step 2
	i = low + 1; // step 3
	j = high; // step 4

	while (i <= j) //step 10
	{
		//search for an element greater than pivot
		while ((arr[i] <= pivot) && (i <= high)) // step 5
		{
			i++; // step 6
			cmp_count++;
		}
		cmp_count++;
		//search for an elemnt less than or equal to pivot
		while ((arr[j] > pivot) && (j >= low)) // step 7
		{
			j--; //step 8
			cmp_count++;
		}
		cmp_count++;
		if (i < j) // step 9
		{
			//swap the element at index i with the element at index j
			swap(low, j);
		}
	}

	if (low < j) //step 11
	{
		//swap the pivot element with the element at index j
		swap(low, j);
	}

	//recuresive call to sort the left sub array
	q_short(low, j - 1); //step 12

	//recusive call to sort the right sub array

	q_short(j + 1, high); // step 13


}

void display() {
	cout << "\n--------------" << endl;
	cout << "\Sorted Array" << endl;
	cout << "\n--------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	
	cout << "\n\nNumber of comparasions: " << cmp_count << endl;
	cout << "Number of daa movements: " << mov_count << endl;
 }
int main()
{
	char ch;

	do {
		input();
		q_short(0, n - 1);
		display();
		cout << "\n\nDo you want to continue ? (y/n):";
		cin >> ch;
	}
}



