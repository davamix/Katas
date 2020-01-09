defmodule RomanNumeral do

@doc """

** First round ***

    def converts(number) when number < 1 do
        ""
    end
    
    def converts(number) when number >= 5 do
        "V" <> converts(number - 5)
    end
    
    #def converts(4) do
    #    "IV"
    #end
    def converts(number) when number >= 4 do
        "IV"
    end
    
    #def converts(number) do
    #    #String.duplicate("I", number)
    #    "I" <> converts(number - 1)
    #end
    def converts(number) when number >= 1 do
        "I" <> converts(number - 1)
    end
    
    """

    @doc "Second round - refactor"

    @numerals [{10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}]

    # one line function
    def converts(number), do: converts(number, @numerals)

    # _ symbol replace an unused parameter in order to avoid the "variable x is unused" warning message.
    # defp is a private function
    defp converts(number, _) when number < 1 do
        ""
    end

    # structure transformation:
    # @numerals == [head | tail] --> head == [{10, "X"}] | tail == [{9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}]
    # [head | tail] == [{Item1, Item2} | tail] --> head == {Item1, Item2} == {10, "X"} | tail == [{9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}] 
    defp converts(number, [{arabic, roman} | tail]) when number >= arabic do
        roman <> converts(number - arabic, [{arabic, roman} | tail])
    end

    defp converts(number, [_ | tail]) do
        converts(number, tail)
    end

end
