/* Author : VANSH KAPILA */
#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
	int arr[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int interval = n / 2;
	//taking the interval as a geometric progression with r = 1/2
	while (interval > 0)
	{
		for (int i = interval; i < n; i++)
		{
			for (int k = i - interval; k >= 0; k -= interval)
			{
				if (arr[k + interval] < arr[k])
				{
					swap(arr[k], arr[k + interval]);
				}
			}
		}

		interval = interval / 2;
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}
