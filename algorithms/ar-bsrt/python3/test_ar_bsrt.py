import unittest
from ar_bsrt import bubble_sort


class Test_ar_bsrt(unittest.TestCase):
    """docstring for Test_ar_bsrt"""
    def test(self):
        arr = [5, 4, 3, 2, 1]
        self.assertEqual(bubble_sort(arr), [1, 2, 3, 4, 5])


if __name__ == "__main__":
    unittest.main()
