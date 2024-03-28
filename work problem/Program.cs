using System;
using System.Linq;

namespace q1
{
    internal class Program
    {
        static void Main()
        {
            int n = int.Parse(Console.ReadLine());

            int[] workers = new int[n];
            for (int i = 0; i < n; i++)
            {
                workers[i] = 0;
            }
            int unitTime = int.Parse(Console.ReadLine());
            string[] works = Console.ReadLine().Split(' ');
            int[] workTimes = new int[works.Length];
            
            for (int i = 0; i < works.Length;i++)
            {
                workTimes[i] = int.Parse(works[i]);
            }

            Array.Sort(workTimes);
            Array.Reverse(workTimes);

            for (int i = 0; i < works.Length; i++)
            {
                int minIndex = Array.IndexOf(workers, workers.Min());
                workers[minIndex] += workTimes[i];
            }

            Console.WriteLine(workers.Max() * unitTime);
        }
    }
}
