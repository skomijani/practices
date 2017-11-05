void convertZigzag(string text, int rows_MAX)
{
	bool flag = false;
	int j = 0;
	int row_num = 0;
	
	vector<string> rows;
	rows.resize(rows_MAX);
	for (int i = 0; i < rows.size(); i++)
		rows[i].resize(MAX, ' ');
	for (unsigned int i = 0; i < text.length(); i++)
	{
		if (!flag)
		{
			rows[row_num][j] = text[i];
			row_num++;
			if (row_num == rows_MAX) {
				row_num--; flag = true;
			}
		}
		else
		{
			row_num--;
			j++;
			rows[row_num][j] = text[i];
			if (row_num == 0)
			{
				row_num++;
				flag = false;
			}
		}
	}

	for (int i = 0; i < rows_MAX; i++)
	{
		for (j = 0; j < 10; j++)
			printf("%c ", rows[i][j]);
		printf("\n");
	}
}