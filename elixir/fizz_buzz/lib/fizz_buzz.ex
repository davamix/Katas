defmodule FizzBuzz do
	def run(number) when number == 3 do
		"Fizz"
	end
	
	def run(number) when number == 5 do
		"Buzz"
	end
	
	def run(number) when number == 15 do
		"FizzBuzz"
	end
	
	def run(number) do
		number
	end
end
