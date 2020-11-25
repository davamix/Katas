using System;
using Xunit;
using MiddleString;

namespace MiddleString.Tests
{
    public class Tests
    {
        [Fact]
        public void GenericTests()
        {
            Assert.Equal("es", Implementation.GetMiddle("test"));
            Assert.Equal("t", Implementation.GetMiddle("testing"));
            Assert.Equal("dd", Implementation.GetMiddle("middle"));
            Assert.Equal("A", Implementation.GetMiddle("A"));
        }
    }
}
