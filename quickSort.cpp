
int partition_arr(int *arr, int beg, int end)
{
	int pivot = arr[end];
	int m = beg; // keeps the pointer the end of left array
	int temp;
	for(int i = beg; i < end;i++ )
	{
		if (arr[i] < pivot)
		{
			temp = arr[i];
			arr[i] = arr[m];
			arr[m] = temp;
			m++;
		}
	}
	temp = arr[m];
	arr[m] = arr[end];
	arr[end] = temp;
	return m;
	
}
void quickSort_elements(int *arr, int beg, int end)
{
	int index = partition_arr(arr, beg, end);
	if(beg < index - 1)
		quickSort_elements(arr, beg, index - 1);
	if(index < end)
		quickSort_elements(arr, index, end);
}
void quickSort()
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

	quickSort_elements(elements, 0, num_of_elements -1);
	printf("\n Sorted elements: ");
	for (int i = 0; i < num_of_elements; i++)
		printf("%d ", elements[i]);
	printf("\n");
}