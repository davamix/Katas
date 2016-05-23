defmodule RomanNumeralTest do
  use ExUnit.Case
  doctest RomanNumeral
  
  test "converts arabic into roman numerals" do
    test_values = [{0, ""},
                  {1, "I"},
                  {2, "II"},
                  {3, "III"},
                  {4, "IV"},
                  {5, "V"},
                  {6, "VI"}, 
                  {9, "IX"}, 
                  {10, "X"},
                  {28, "XXVIII"}]
    
    Enum.each test_values, fn({arabic, roman}) -> assert RomanNumeral.converts(arabic) == roman end
    
  end

@doc """ 

** With @doc and triple quotes and the final triple quotes is possible to simulate a multiline comment **

  test "converts to 0" do
    assert RomanNumeral.converts(0) == ""
  end
  
  test "converts to 1" do
    assert RomanNumeral.converts(1) == "I"
  end
  
  test "converts to 2" do
    assert RomanNumeral.converts(2) == "II"
  end
  
  test "convert to 3" do
    assert RomanNumeral.converts(3) == "III"
  end
  """
end
