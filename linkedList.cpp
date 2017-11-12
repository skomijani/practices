Node *createLinkedList()
{
	Node *head = NULL;
	int num_of_elements;
	int value;
	printf("Enter the number of linklist nodes: ");
	scanf("%d", &num_of_elements);
	printf("\nEnter linklist node values: ");
	for (int i = 0; i < num_of_elements; i++)
	{
		scanf("%d", &value);
		Node *tempNode = newNode(value);
		insertNode_sequential(&head, tempNode);
	}
	return head;
}


void removeDups()
{
	Node *head = createLinkedList();

	//brute force
	Node *curNode = head;
	Node *nextNode, *prevNode, *tempNode;
	while (curNode != NULL)
	{
		prevNode = curNode;
		nextNode = curNode->next;
		while (nextNode != NULL)
		{
			if (curNode->value == nextNode->value)
			{
				tempNode = nextNode;
				prevNode->next = nextNode->next;
				delete tempNode;
				nextNode = prevNode->next;
			}
			else
			{
				prevNode = nextNode;
				nextNode = nextNode->next;
			}
				

		}
		curNode = curNode->next;
	}
	printLinklist(head);
}


void deleteMiddleNode()
{
	Node *head = createLinkedList();
	Node *firstPtr = head;
	Node *secPtr = head->next;
	Node *prev = NULL;
	while (secPtr != NULL)
	{
		
		secPtr = secPtr->next;
		if (secPtr != NULL)
		{
			prev = firstPtr;
			firstPtr = firstPtr->next;
			secPtr = secPtr->next;
		}
			
	}
	printf(" value of middle node : %d \n", firstPtr->value);
	Node *tempNode = prev->next;
	prev->next = firstPtr->next;
	delete tempNode;
	printLinklist(head);
}

///

void partitionLinkedlist()
{
	Node * head = createLinkedList();
	printLinklist(head);
	printf("\nprint value X: ");
	int x;
	scanf("%d", &x);
	Node *Shead = NULL;
	Node *Stail = NULL;
	Node *Ghead = NULL;
	Node *Gtail = NULL;

	Node *curNode = head;
	while (curNode != NULL)
	{
		if (curNode->value < x)
		{
			if (Shead != NULL)
			{
				Stail->next = curNode;
				Stail = Stail->next;
			}
			else
			{
				Shead = curNode;
				Stail = curNode;
			}
		}
		else
		{
			if (Ghead != NULL)
			{
				Gtail->next = curNode;
				Gtail = Gtail->next;
			}
			else
			{
				Ghead = curNode;
				Gtail = curNode;
			}
		}
		curNode = curNode->next;
	}
	Stail->next = Ghead;
	Gtail->next = NULL;
	printLinklist(Shead);
}


void Palindrome_linkedlist()
{
	Node *head = createLinkedList();
	Node *ptr1 = head;
	if (head->next == NULL)
		printf("is Palindrome\n");
	Node *ptr2 = head->next;
	Node * curNode_secondHalf = NULL;
	vector<int> stack;
	while (ptr2 != NULL)
	{
		stack.push_back(ptr1->value);
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		if (ptr2 != NULL)
		{
			curNode_secondHalf = ptr1->next;
			ptr2 = ptr2->next;

		}
		else
			curNode_secondHalf = ptr1;
	}
	while (curNode_secondHalf != NULL)
	{
		if (curNode_secondHalf->value == stack.back())
		{
			stack.pop_back();
			curNode_secondHalf = curNode_secondHalf->next;
		}
		else
		{
			printf("is not Palindrome\n");
			return;
		}
		
	}
	printf("is Palindrome\n");
}
