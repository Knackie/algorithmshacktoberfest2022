import unittest
from gr_bfsrh import bfs

class Test_ar_bsrt(unittest.TestCase):
	"""docstring for Test_gr_bfsrh"""
	def test(self):
		arr = {
			"A":["B", "D"],
			"B":["A","C"],
			"C":["B"],
			"D":["A", "E", "F"],
			"E":["D","F","G"],
			"F":["D","E","H"],
			"G":["E","H"],
			"H":["G","F"]
		}
		self.assertEqual(bfs(arr), ['A', 'B', 'D', 'C', 'E', 'F', 'G', 'H'])

if __name__ == "__main__":
    unittest.main()