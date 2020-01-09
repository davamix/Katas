defmodule FizzBuzzTest do
  use ExUnit.Case
  doctest FizzBuzz
  
  test "1 is 1" do
    assert FizzBuzz.run(1) == 1
  end
  
  test "2 is 2" do
    assert FizzBuzz.run(2) == 2
  end

  test "3 is Fizz" do
    assert FizzBuzz.run(3) == "Fizz"
  end
  
  test "5 is Buzz" do
    assert FizzBuzz.run(5) == "Buzz"
  end
  
  test "15 is Fizz" do
    assert FizzBuzz.run(15) == "FizzBuzz"
  end
end
