using System;
using Xunit;
using SortNumbersByWeight;

namespace SortNumbersByWeight.Tests
{
    public class Tests
    {
        [Fact]
        public void Test1()
        {
            Assert.Equal("2000 103 123 4444 99", Implementation.order("103 123 4444 99 2000"));
            Assert.Equal("11 11 2000 10003 22 123 1234000 44444444 9999", Implementation.order("2000 10003 1234000 44444444 9999 11 11 22 123"));
        }
    }
}
