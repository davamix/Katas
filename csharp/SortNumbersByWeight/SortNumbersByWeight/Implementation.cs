using System;
using System.Linq;
using System.Collections.Generic;

namespace SortNumbersByWeight
{
    public class Number
    {
        public int Value { get; private set; }
        public int Weight => SumDigits();

        public Number(int value)
        {
            this.Value = value;
        }

        public int SumDigits()
        {
            if (this.Value < 10) return this.Value;

            var value = this.Value;
            var total = 0;

            while (value != 0)
            {
                value = Math.DivRem(value, 10, out int rem);

                total += rem;
            }

            return total;
        }
    }

    public class Implementation
    {
        public static string order(string strng)
        {
            if (string.IsNullOrEmpty(strng)) return string.Empty;

            var list = new List<Number>(strng.Split(" ").Select(x => new Number(Int32.Parse(x))));

            var sortedValues = list.OrderBy(n => n, new ValueComparer());

            return string.Join(" ", sortedValues.Select(x => x.Value));
        }
    }

    public class ValueComparer : IComparer<Number>
    {
        public int Compare(Number a, Number b)
        {
            if (a.Weight == b.Weight)
            {
                return string.Compare(a.Value.ToString(), b.Value.ToString());
            }

            if (a.Weight > b.Weight) return 1;

            return -1;
        }
    }
}
