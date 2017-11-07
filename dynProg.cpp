int findVariousWays(int steps)
{
	if(steps < 0)
		return 0;
	if (steps == 0)
		return 1;
	else
	{
		return findVariousWays(steps - 1) + findVariousWays(steps - 2) + findVariousWays(steps - 3);
	}
}

int findVariousWays_mem(int steps, int *mem)
{
	if (steps < 0)
	{
		return 0;
	}
	else if (steps == 0)
	{
		return 1;
	}
	else if (mem[steps] > -1)
	{
		return mem[steps];
	}
	else
	{
		mem[steps] = findVariousWays_mem(steps - 1, mem) + findVariousWays_mem(steps - 2, mem) + findVariousWays_mem(steps - 3, mem);
		return mem[steps];
	}
}
//recursion and dynamic programming
void tripleStep()
{
	auto start_recursion = chrono::system_clock::now();
	//brute-force: recursion
	printf("Please enter number of steps: ");
	int steps = 0;
	scanf("%d", &steps);
	printf("\n there are %d ways\n" ,findVariousWays(steps));
	auto end_recursion = chrono::system_clock::now();

	chrono::duration<double> elapsed_seconds = end_recursion - start_recursion;
	cout <<  "recursive approach, no memorization , elapsed time: " << elapsed_seconds.count() << "s\n";


	auto start_recursion_mem = chrono::system_clock::now();
	int *mem = new int[steps];
	for (int i = 0; i < steps; i++)
		mem[i] = -1;
	//recursion with memorization
	printf("\n there are %d ways\n", findVariousWays_mem(steps,mem));
	auto end_recursion_mem = chrono::system_clock::now();

	chrono::duration<double> elapsed_seconds_mem = end_recursion_mem - start_recursion_mem;
	cout << "recursive approach, memorization , elapsed time: " << elapsed_seconds_mem.count() << "s\n";
}