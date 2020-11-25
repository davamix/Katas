using System;

namespace SumOfMultiples
{
    public static class Implementation
    {
        public static int Solution(int value)
        {
            if (value <= 0) return 0;

            var total = 0;

            for (var x = 0; x < value; x++)
            {
                total += (IsMultipleOfThree(x)) || (IsMultipleOfFive(x)) ? x : 0;
            }

            return total;
        }

        static bool IsMultipleOfThree(int value)
        {
            return (value % 3 == 0);
        }

        static bool IsMultipleOfFive(int value)
        {
            return (value % 5 == 0);
        }
    }
}
