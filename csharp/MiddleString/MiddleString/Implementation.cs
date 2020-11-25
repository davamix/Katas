using System;

namespace MiddleString
{
    public class Implementation
    {
        public static string GetMiddle(string s)
        {
            if (string.IsNullOrEmpty(s)) return string.Empty;

            var length = s.Length;
            var startIndex = length > 1 ? (length / 2) : 0;

            if (length % 2 == 0)
                return s.Substring(startIndex - 1, 2);

            return s.Substring(startIndex, 1);
        }
    }
}