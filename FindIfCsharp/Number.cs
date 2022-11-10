class Number : IMatcher<int>
{
    public int num;
    public Number(int a)
    {
        num = a;
    }
    public bool Match(int item)
    {
        return num == item;
    }
}
