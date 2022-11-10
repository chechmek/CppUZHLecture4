class Str : IMatcher<string>
{
    private readonly string _str;

    public Str(string str)
    {
        _str = str;
    }
    public bool Match(string item)
    {
        return item == _str;
    }
}
