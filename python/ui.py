import tkinter as tk
import sys
import os

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "build")))

from tictactoe import Board, AIPlayer 

class TicTacToeUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Tic Tac Toe")
        self.board = Board()
        self.ai = AIPlayer('O')
        self.current_symbol = 'X'

        self.buttons = [
            [tk.Button(root, text="", font=("Arial", 24), width=5, height=2,
                       command=lambda r=r, c=c: self.on_click(r, c))
             for c in range(3)] for r in range(3)
        ]
        for r in range(3):
            for c in range(3):
                self.buttons[r][c].grid(row=r, column=c)

    def on_click(self, row, col):
        if self.board.get_cell(row, col) == " " and self.current_symbol == 'X':
            self.board.make_move(row, col, 'X')
            self.buttons[row][col].config(text='X')
            if self.check_game_over():
                return
            r, c = self.ai.get_move(self.board, False)
            self.board.make_move(r, c, 'O')
            self.buttons[r][c].config(text='O')
            self.check_game_over()

    def check_game_over(self):
        winner = self.board.check_winner()
        if winner == "X" or winner == "O":
            self.end_game(f"{winner} wins!")
            return True
        elif self.board.is_full():
            self.end_game("It's a draw!")
            return True
        return False

    def end_game(self, msg):
        popup = tk.Toplevel()
        popup.title("Game Over")
        tk.Label(popup, text=msg, font=("Arial", 18)).pack(pady=10)
        tk.Button(popup, text="OK", command=self.root.quit).pack(pady=5)

if __name__ == "__main__":
    root = tk.Tk()
    app = TicTacToeUI(root)
    root.mainloop()
