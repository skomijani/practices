//------------------------------------------------------------------------------------------------------------------------------------
//--------- Triple Steps- ------------------------------------------------------------------------------------------------------------

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



//------------------------------------------------------------------------------------------------------------------------------------
//--------- Robot in Grid ------------------------------------------------------------------------------------------------------------

struct Cell
{
	int x;
	int y;
};

typedef struct Cell Cell;

template<std::size_t SIZE>
bool findPath_noMem(array<array<bool, SIZE>, SIZE> maze, int x, int y, vector<Cell *> *path)
{

	if (x == ROWS - 1  && y == COLS - 1)
	{
		return true;
	}
	else if (x == ROWS || y == COLS) return false;
	else if (maze[x][y] == 0) return false;
	else if (findPath_noMem(maze, x + 1, y, path))
	{
		Cell *tempCell = new Cell;
		tempCell->x = x + 1;
		tempCell->y = y;
		path->push_back(tempCell);
		return true;
	}
	else if(findPath_noMem(maze, x, y + 1, path))
	{
		Cell *tempCell = new Cell;
		tempCell->x = x;
		tempCell->y = y + 1;
		path->push_back(tempCell);
		return true;
	}
	return false;
}

void robotInGrid()
{
	array<array<bool, 5>,5> maze;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			maze[i][j] = 0;
		}
	}

	maze[0][0] = 1;
	maze[1][0] = maze[1][1] = maze[1][3] = 1;
	maze[2][0] = maze[2][1] = maze[2][2] = 1;
	maze[3][2] = maze[3][3] = maze[3][4] = 1;
	maze[4][3] = maze[4][4] = 1;

	vector<Cell *> path;

	if (findPath_noMem(maze, 0, 0, &path))
	{
		printf("path is: %d \n", path.size());
		for (int i = 0; i < path.size(); i++)
		{
			printf("%d, %d\n", path[i]->x, path[i]->y);
		}
	}
	// 1 0 0 0 0 
	// 1 1 0 1 0
	// 1 1 1 0 0
	// 0 0 1 1 1
	// 0 0 0 1 1

	
}



//------------------------------------------------------------------------------------------------------------------------------------
