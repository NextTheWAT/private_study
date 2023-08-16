using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello C#");
            Console.WriteLine("Hellow " + args[0]);
            Console.WriteLine("args 문자열 갯수 : " + args.Length);
            Console.ReadKey();  //키를 받을때까지 기다린다.
        }
    }
}
