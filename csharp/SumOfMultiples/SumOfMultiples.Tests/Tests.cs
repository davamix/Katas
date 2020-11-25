using System;
using Xunit;
using SumOfMultiples;

namespace SumOfMultiples.Tests
{
    public class UnitTest1
    {
        [Fact]
        public void Test()
        {
            Assert.Equal(23, Implementation.Solution(10));
        }

        [Fact]
        public void Test200()
        {
            Assert.Equal(9168, Implementation.Solution(200));
        }

        [Fact]
        public void ValueIsZero()
        {
            Assert.Equal(0, Implementation.Solution(0));
        }

        [Fact]
        public void ValueIsNegative()
        {
            Assert.Equal(0, Implementation.Solution(-15));
        }
    }
}
