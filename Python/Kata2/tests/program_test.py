import unittest
from src import program

class TestProgram(unittest.TestCase):
    def test_is_multiple_of_three(self):
        self.assertEqual(program.is_multiple_of_three(3), True)
        self.assertEqual(program.is_multiple_of_three(6), True)
        self.assertEqual(program.is_multiple_of_three(15), True)

    def test_is_multiple_of_five(self):
        self.assertEqual(program.is_multiple_of_five(5), True)
        self.assertEqual(program.is_multiple_of_five(15), True)
        self.assertEqual(program.is_multiple_of_five(25), True)

    def test_sum_multiples(self):
        self.assertEqual(program.sum([3,5,6,9]), 23)
        self.assertEqual(program.sum([1,2,3,5,6,7,8,9]), 23)

suite = unittest.TestLoader().loadTestsFromTestCase(TestProgram)
unittest.TextTestRunner(verbosity=2).run(suite)