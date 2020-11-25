using System;
using Xunit;

namespace SortCsvColumns.Tests
{
    public class Tests
    {
        [Fact]
        public void Test1()
        {
            string preSorting = "myjinxin2015;raulbc777;smile67;Dentzil;SteffenVogel_79\n"
                      + "17945;10091;10088;3907;10132\n"
                      + "2;12;13;48;11";
            
            string postSorting = "Dentzil;myjinxin2015;raulbc777;smile67;SteffenVogel_79\n"
                               + "3907;17945;10091;10088;10132\n"
                               + "48;2;12;13;11";

            Assert.Equal(postSorting, Implementation.Csv(preSorting));
        }
    }
}
