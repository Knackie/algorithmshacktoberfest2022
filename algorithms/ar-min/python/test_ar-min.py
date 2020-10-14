import unittest
from ar_min import ar_min


class Test_ar_min(unittest.TestCase):
    """docstring for Test_ar_min"""
    def test(self):
        arr = [1, 2, 3, -1]
        self.assertEqual(ar_min(arr), -1)


if __name__ == "__main__":
    unittest.main()
