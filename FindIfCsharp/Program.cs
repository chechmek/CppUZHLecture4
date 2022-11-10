using System.Diagnostics;

var elementsCount = 10000000;
var num = new Number(elementsCount - 1);
var str = new Str("find");
List<int> listInt = new List<int>();
for(int i = 0; i < elementsCount; i++) // 100 000 000
{
    listInt.Add(i);
}
List<string> listStr = new List<string>();
for (int i = 0; i < elementsCount; i++) // 100 000 000
{
    listStr.Add(i.ToString());
}
listStr[elementsCount - 1] = "find";

Stopwatch sw1 = new Stopwatch();
sw1.Start();
var findedInt = FindIf<int>(listInt.GetEnumerator(), num);
sw1.Stop();

Console.WriteLine(findedInt);
Console.WriteLine($"Elapsed int = {sw1.Elapsed.TotalSeconds}");

Stopwatch sw2 = new Stopwatch();
sw2.Start();
var findedStr = FindIf<string>(listStr.GetEnumerator(), str);
sw2.Stop();

Console.WriteLine(findedStr);
Console.WriteLine($"Elapsed string = {sw2.Elapsed.TotalSeconds}");

T FindIf<T>(IEnumerator<T> iterator, IMatcher<T> matcher)
{
    while (iterator.MoveNext())
    {
        if (matcher.Match(iterator.Current))
            return iterator.Current;
    }
    throw new Exception("not found");
}
