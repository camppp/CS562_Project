c
int power(int a, int b)
{
    int res = 1;
    while (b != 0)
    {
        if (b < 0)
        {
            res = res / a;
            b++;
        }
        else
        {
            res = res * a;
            b--;
        }
    }
    return res;
}
