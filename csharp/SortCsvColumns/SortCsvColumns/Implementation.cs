using System;
using System.Linq;
using System.Collections.Generic;

namespace SortCsvColumns
{
    public class Implementation
    {
        public static string Csv(string csvFileContent)
        {

            var lines = csvFileContent.Split("\n");

            var headers = lines[0].Split(";");

            var sortedHeaders = new string[headers.Length];
            Array.Copy(headers, sortedHeaders, headers.Length);
            Array.Sort(sortedHeaders);

            var sortedCsv = new List<string>() { string.Join(";", sortedHeaders) };

            foreach (var line in lines.Skip(1))
            {
                var newLine = new string[headers.Length];
                var values = line.Split(";");

                for (var x = 0; x < headers.Length; x++)
                {
                    var newIndex = Array.IndexOf(sortedHeaders, headers[x]);
                    newLine[newIndex] = values[x];
                }

                sortedCsv.Add(string.Join(";", newLine));

            }

            return string.Join("\n", sortedCsv);
        }
    }
}
