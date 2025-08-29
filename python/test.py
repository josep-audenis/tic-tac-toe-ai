import sys
import os

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "build")))

import tictactoe

b = tictactoe.Board()
b.makeMove(0,0, "X")
b.display()