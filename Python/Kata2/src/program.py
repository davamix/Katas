def is_multiple_of_three(number):
    return True if number % 3 == 0 else False

def is_multiple_of_five(number):
    return True if number % 5 == 0 else False

def sum(numbers):
    total = 0
    for n in numbers:
        if is_multiple_of_three(n) or is_multiple_of_five(n):
            total = total + n
    
    return total

if __name__ == '__main__':
    print(sum(range(1000)))