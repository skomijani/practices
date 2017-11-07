
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
