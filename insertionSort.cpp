void insertionSort_elements(int *arr, int beg, int end)
{
	int sorted_end = beg;
	int temp, j, k;
	for (int i = beg + 1; i < end; i++)
	{
		j = 0;
		while ((j < sorted_end + 1) && arr[i] > arr[j]) j++;
		temp = arr[i];
		for (k = sorted_end + 1; k > j; k--) arr[k] = arr[k - 1];
		arr[k] = temp;
		sorted_end++;
	}
}
void insertionSort()
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

	insertionSort_elements(elements, 0 , num_of_elements);
	printf("\n Sorted elements: ");
	for (int i = 0; i < num_of_elements; i++)
		printf("%d ", elements[i]);
	printf("\n");
}
