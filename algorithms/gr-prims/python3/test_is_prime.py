import unittest
from is_prime import is_prime


class Test_is_prime(unittest.TestCase):
    def test_true(self):
        self.assertEquals(is_prime(2), True)

    def test_false(self):
        self.assertEquals(is_prime(4), False)

    def test_false_mul(self):
        self.assertEquals(all([is_prime(x) for x in range(10)]), False)

    def test_true_mul(self):
        self.assertEquals(all([is_prime(x) for x in [2, 3, 5, 7, 11]]), True)


if __name__ == "__main__":
    unittest.main()
