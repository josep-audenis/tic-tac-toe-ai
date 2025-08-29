import sys
import os

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "build")))

import tictactoe


p1 = tictactoe.HumanPlayer("X")
p2 = tictactoe.AIPlayer("O")
game = tictactoe.Game(p1, p2)

game.play()