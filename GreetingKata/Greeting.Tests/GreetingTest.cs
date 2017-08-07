// https://github.com/testdouble/contributing-tests/wiki/Greeting-Kata

using System;
using Xunit;

namespace GreetingKata.Tests
{
    public class GreetingTest
    {
        private readonly Greeting _sut;

        public GreetingTest()
        {
            _sut = new Greeting();
        }

        [Theory]
        [InlineData("Bob", "Hello, Bob.")]
        public void Requirement_1(string parameter, string expected)
        {
            var result = _sut.Greet(parameter);

            Assert.Equal(expected, result);
        }

        [Theory]
        [InlineData("Hello, my friend.")]
        public void Requirement_2(string expected){
            var result = _sut.Greet();

            Assert.Equal(expected, result);
        }

        [Theory]
        [InlineData("JERRY", "HELLO JERRY!")]
        public void Requirement_3(string parameter, string expected){
            var result = _sut.Greet(parameter);

            Assert.Equal(expected, result);
        }

        [Theory]
        [InlineData(new[]{"Jill", "Jane"}, "Hello, Jill and Jane.")]
        public void Requirement_4(string[] parameters, string expected){
            var result = _sut.Greet(parameters);

            Assert.Equal(expected, result);
        }

        [Theory]
        [InlineData(new[]{"Amy", "Brian", "Charlotte"}, "Hello, Amy, Brian and Charlotte.")]
        public void Requirement_5(string[] parameters, string expected){
            var result = _sut.Greet(parameters);

            Assert.Equal(expected, result);
        }

        [Theory]
        [InlineData(new[]{"Amy", "BRIAN", "Charlotte"}, "Hello, Amy and Charlotte. AND HELLO BRIAN!")]
        public void Requirement_6(string[] parameters, string expected){
            var result = _sut.Greet(parameters);

            Assert.Equal(expected, result);
        }

        // TODO: To be implemented
        [Theory]
        [InlineData(new[]{"Bob", "Charlie, Dianne"}, "Hello, Bob, Charlie, and Dianne.")]
        public void Requirement_7(string[] parameters, string expected){
            var result = _sut.Greet(parameters);

            Assert.Equal(expected, result);
        }

        // [Theory]
        // [InlineData(new[]{"Bob", "\"Charlie, Dianne\""}, "Hello, Bob and Charlie, Dianne.")]
        // public void Requirement_7(string[] parameters, string expected){
        //     var result = _sut.Greet(parameters);

        //     Assert.Equal(expected, result);
        // }
    }
}
