const boardDiv = document.getElementById("board");
const statusDiv = document.getElementById("status");
const resetBtn = document.getElementById("reset");

let board = [
    ["", "", ""],
    ["", "", ""],
    ["", "", ""]
];

let currentPlayer = "X"; 

const cells = document.querySelectorAll(".cell");
cells.forEach(cell => {
    cell.addEventListener("click", () => {
        const row = parseInt(cell.dataset.row);
        const col = parseInt(cell.dataset.col);
        humanMove(row, col);
    });
});

resetBtn.addEventListener("click", resetGame);


function humanMove(row, col) {
    if (board[row][col] !== "" || currentPlayer !== "X") return;

    board[row][col] = "X";
    updateBoard();
    if (checkWinner(board) || isFull(board)) return endGame();

    currentPlayer = "O";
    aiMove();
}

function aiMove() {
    const move = findBestMove(board);
    if (!move) return;

    const [row, col] = move;

    board[row][col] = "O";
    updateBoard();

    if (checkWinner(board) || isFull(board)) return endGame();
    currentPlayer = "X";
}

function updateBoard() {
    for (let r = 0; r < 3; r++) {
        for (let c = 0; c < 3; c++) {
            const cell = document.querySelector(`.cell[data-row="${r}"][data-col="${c}"]`);
            cell.textContent = board[r][c];
        }
    }
}


function findBestMove(b) {
    let bestScore = -Infinity;
    let move;
    for (let r = 0; r < 3; r++) {
        for (let c = 0; c < 3; c++) {
            if (b[r][c] === "") {
                b[r][c] = "O";
                let score = minimax(b, 0, false);
                b[r][c] = "";
                if (score > bestScore) {
                    bestScore = score;
                    move = [r, c];
                }
            }
        }
    }
    return move;
}

function minimax(b, depth, isMaximizing, alpha, beta) {
    const winner = checkWinner(b);
    if (winner !== null) {
        if (winner === "O") {
            return 10 - depth;
        }
        else if (winner === "X") {
            return depth - 10;
        }
    }

    if (isFull(b)) return 0;

    if (isMaximizing == true) {
        let bestScore = -Infinity;
        for (let r = 0; r < 3; r++) {
            for (let c = 0; c < 3; c++) {
                if (b[r][c] === "") {
                    b[r][c] = "O";
                    let score = minimax(b, depth + 1, false);
                    b[r][c] = "";
                    bestScore = Math.max(score, bestScore);
                    alpha = Math.max(alpha, bestScore);
                    if (beta <= alpha) {
                        return bestScore;
                    }
                }
            }
        }
        return bestScore;
    } else {
        let bestScore = Infinity;
        for (let r = 0; r < 3; r++) {
            for (let c = 0; c < 3; c++) {
                if (b[r][c] === "") {
                    b[r][c] = "X";
                    let score = minimax(b, depth + 1, true);
                    b[r][c] = "";
                    bestScore = Math.min(score, bestScore);
                    beta = Math.min(beta, bestScore);
                    if (beta <= alpha) {
                        return bestScore;
                    }
                }
            }
        }
        return bestScore;
    }
}


function checkWinner(b) {
    for (let i = 0; i < 3; i++) {
        if (b[i][0] && b[i][0] === b[i][1] && b[i][1] === b[i][2]) {
            return b[i][0];
        }
        if (b[0][i] && b[0][i] === b[1][i] && b[1][i] === b[2][i]) {
            return b[0][i];
        }
    }
    if (b[0][0] && b[0][0] === b[1][1] && b[1][1] === b[2][2]) return b[0][0];
    if (b[0][2] && b[0][2] === b[1][1] && b[1][1] === b[2][0]) return b[0][2];
    return null;
}

function isFull(b) {
    return b.flat().every(cell => cell !== "");
}

function endGame() {
    const winner = checkWinner(board);
    if (winner) {
        statusDiv.textContent = `${winner} wins!`;
    } else {
        statusDiv.textContent = "It's a draw!";
    }
    currentPlayer = null; 
}


function resetGame() {
    board = [
        ["", "", ""],
        ["", "", ""],
        ["", "", ""]
    ];
    currentPlayer = "X";
    statusDiv.textContent = "Player X's turn";
    updateBoard();
}
