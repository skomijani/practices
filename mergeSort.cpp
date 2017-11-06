void merge_arrays(int *arr,int beg, int end)
{
	int m = 0;
	int n = 0;
	int mid = beg + ceil((end - beg) / 2) ;

	int *sorted_left = new int[mid - beg + 1];
	int *sorted_right = new int[end - mid ];
	for (int i = beg; i < mid + 1; i++)
	{
		sorted_left[m] = arr[i];
		m++;
	}
	for (int i = mid + 1; i < end + 1; i++)
	{
		sorted_right[n] = arr[i];
		n++;
	}
	m = 0; n = 0;
	for (int i = beg; i < end + 1; i++)
	{
		//swap if second half element is greater
		if (n == (end - mid) )
		{
			arr[i] = sorted_left[m];
			m++;
		}
		else if (m == (mid + 1 - beg) )
		{
			arr[i] = sorted_right[n];
			n++;
		}
		else if (sorted_left[m] > sorted_right[n])
		{
			arr[i] = sorted_right[n];
			n++;
		}
		else
		{
			arr[i] = sorted_left[m];
			m++;
		}
	}
}
void mergeSort_elements(int *arr, int beg, int end)
{
	if (beg == end) {
		return;
	}

	mergeSort_elements(arr, beg, beg + ceil((end - beg )/2));
	mergeSort_elements(arr, beg + ceil((end - beg) / 2) + 1, end);
	merge_arrays(arr, beg, end);
}

void mergeSort()
{
	//insert elements in an array
	int num_of_elements = 0;
	printf("Enter the number of elements: ");
	scanf("%d", &num_of_elements);
	if (num_of_elements <= 0) return;
	printf("Enter the elements:");
	int temp = 0;
	int *elements = new int[num_of_elements];
	for (int i = 0; i < num_of_elements; i++)
		scanf("%d", &(elements[i]));

	mergeSort_elements(elements, 0, num_of_elements -1 );

	printf("\n Sorted elements: ");
	for (int i = 0; i < num_of_elements; i++)
		printf("%d ", elements[i]);
	printf("\n");
}
void bubbleSort()
{
	int num_of_elements = 0;
	printf("Enter the number of elements: ");
	scanf("%d", &num_of_elements);
	if (num_of_elements <= 0) return;
	printf("Enter the elements:");
	int temp = 0;
	int *elements = new int[num_of_elements];
	for (int i = 0; i < num_of_elements; i++)
		scanf("%d", &(elements[i]));
	
	for (int j = 0; j < num_of_elements; j++)
	{
		for (int i = 0; i < num_of_elements - 1; i++)
		{
			if (elements[i] > elements[i + 1])
			{
				//swap
				temp = elements[i];
				elements[i] = elements[i + 1];
				elements[i + 1] = temp;
			}
		}
	}
	printf("\n Sorted elements: ");
	for (int i = 0; i < num_of_elements; i++)
		printf("%d ", elements[i]);
	printf("\n");
	
}
