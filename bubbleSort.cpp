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