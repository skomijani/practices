bool isLeaf( int curNode_index, int len)
{
	int leftChild_index = 2 * curNode_index + 1;
	int rightChild_index = 2 * curNode_index + 2;
	if (leftChild_index <= len || rightChild_index <= len)
		return false;
	return true;
}

void buildHeap(int *elements, int num_of_elements)
{
	int MAX_index;
	int temp;
	int curNode_index;// = floor(num_of_elements / 2) - 1;
	for (int i = (int)floor(num_of_elements / 2) - 1; i >= 0; i--)
	{
		curNode_index = i;
		while (!isLeaf(curNode_index, num_of_elements - 1))
		{
			MAX_index = curNode_index;
			int leftChild_index = 2 * curNode_index + 1;
			int rightChild_index = 2 * curNode_index + 2;
			if (leftChild_index <= (num_of_elements - 1) && elements[MAX_index] < elements[leftChild_index])
			{
				MAX_index = leftChild_index;

			}
			if (rightChild_index <= (num_of_elements - 1) && elements[MAX_index] < elements[rightChild_index])
			{
				MAX_index = rightChild_index;
			}
			temp = elements[MAX_index];
			elements[MAX_index] = elements[curNode_index];
			elements[curNode_index] = temp;
			if (MAX_index == curNode_index) curNode_index = leftChild_index;
			else curNode_index = MAX_index;

		}
	}

}
void heapSort()
{
	int num_of_elements = 0;
	printf("Enter the number of elements: ");
	scanf("%d", &num_of_elements);
	if (num_of_elements <= 0) return;
	printf("Enter the elements:");
	int temp = 0;
	int MAX_index;
	int *elements = new int[num_of_elements];
	for (int i = 0; i < num_of_elements; i++)
		scanf("%d", &(elements[i]));
	buildHeap(elements, num_of_elements);
	int last_index = num_of_elements - 1;
	for (int i = 0; i < num_of_elements; i++)
	{
		printf("%d ", elements[0]);
		elements[0] = elements[last_index];
		buildHeap(elements, last_index);
		last_index--;
	}
}