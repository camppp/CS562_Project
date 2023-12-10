void Pred(int x)
{
	int y = x;
	while (a[y] != y) y = a[y];
	while (a[x] != y)
	{
		int c = a[x];
		a[x] = y;
		x = c;
	}
}
