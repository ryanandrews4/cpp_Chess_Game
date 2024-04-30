//Game of Chess

#include <iostream>
#include <vector>

//EnPassant
//Castling
//Promotion
//Check
//Checkmate
//Stalemate
//Dont allow to move king into check
//Dont allow to move pieces that block check on your own king
//Dont allow Castle if King or Rook has moved
//Dont allow Castle if King is in check
//Dont allow pawn to move two spaces if it has moved already
//Dont allow pawn to take piece if it is not diagonal
//Improve the User Experience, maybe give a list of possible moves to choose from.
//Definetly need to make 1-8 and a-h border




class WhiteRook {
private:
    bool hasMoved;

public:
    int positionX;
    int positionY;

    WhiteRook(int startX, int startY) {
        positionX = startX;
        positionY = startY;
        hasMoved = false;
    }

    bool isWhitePiece(char piece) {
        return (piece >= 'A' && piece <= 'Z');
    }

    void move(int targetX, int targetY, std::vector<std::vector<char>> board) {
        // Implement the logic to move the Rook to the new position
        // Make sure to update the hasMoved flag accordingly
        // Check if there are any pieces between the old position and the new position
        if (targetX == positionX) {
            // Moving vertically
            for (int y = positionY + 1; y < targetY; y++) {
                if (board[y][targetX] != ' ') {
                    std::cout << "Invalid move. There is a piece blocking the path." << std::endl;
                    return;
                }
            }
            if (board[targetY][targetX] != ' ') {
                if (isWhitePiece(board[targetY][targetX])) {
                    std::cout << "Invalid move. The target position is occupied by a piece of the same color." << std::endl;
                    return;
                } 
            }

        } else if (targetY == positionY) {
            // Moving horizontally
            for (int x = positionX + 1; x < targetX; x++) {
                if (board[targetY][x] != ' ') {
                    std::cout << "Invalid move. There is a piece blocking the path." << std::endl;
                    return;
                }
            }
            if (board[targetY][targetX] != ' ') {
                if (isWhitePiece(board[targetY][targetX])) {
                    std::cout << "Invalid move. The target position is occupied by a piece of the same color." << std::endl;
                    return;
                } 
            }
        } else {
            std::cout << "Invalid move. The new position must be on the same column or the same row." << std::endl;
            return;
        }

        positionX = targetX;
        positionY = targetY;
        hasMoved = true;
    }

    // Add any other member functions or variables as needed
};

class WhiteKnight {
private:
    bool hasMoved;

public:
    int positionX;
    int positionY;

    WhiteKnight(int startX, int startY) {
        positionX = startX;
        positionY = startY;
        hasMoved = false;
    }

    bool isWhitePiece(char piece) {
        return (piece >= 'A' && piece <= 'Z');
    }

    void move(int targetX, int targetY, std::vector<std::vector<char>> board) {
        // Implement the logic to move the knight to the new position
        // Make sure to update the hasMoved flag accordingly
        int deltaX = abs(targetX - positionX);
        int deltaY = abs(targetY - positionY);

        if ((deltaX == 2 && deltaY == 1) || (deltaX == 1 && deltaY == 2)) {
            if (board[targetY][targetX] == ' ' || !isWhitePiece(board[targetY][targetX])) {
                positionX = targetX;
                positionY = targetY;
                hasMoved = true;
            } else {
                std::cout << "Invalid move for the knight. Cant attack same color pieces." << std::endl;
            }
        } else {
            std::cout << "Invalid move for the knight. Cant move other than 1x2." << std::endl;
        }
    }

    // Add any other member functions or variables as needed
};

class WhiteBishop {
private:
    bool hasMoved;

public:
    int positionX;
    int positionY;

    WhiteBishop(int startX, int startY) {
        positionX = startX;
        positionY = startY;
        hasMoved = false;
    }

    bool isWhitePiece(char piece) {
        return (piece >= 'A' && piece <= 'Z');
    }

    void move(int targetX, int targetY, std::vector<std::vector<char>> board) {
        // Implement the logic to move the bishop to the new position
        // Make sure to update the hasMoved flag accordingly
        if (abs(targetX - positionX) == abs(targetY - positionY)) {
            // Check if the path is clear
            int dx = (targetX > positionX) ? 1 : -1;
            int dy = (targetY > positionY) ? 1 : -1;
            int x = positionX + dx;
            int y = positionY + dy;
            while (x != targetX && y != targetY) {
                if (board[y][x] != ' ') {
                    // Path is not clear
                    std::cout << "Invalid move for the bishop. There is a piece blocking the path." << std::endl;
                    return;
                }
                x += dx;
                y += dy;
            }
            
            if (board[targetY][targetX] == ' ' || !isWhitePiece(board[targetY][targetX])) {
                // Move the bishop to the new position
                positionX = targetX;
                positionY = targetY;
                hasMoved = true;
            } else {
                std::cout << "Invalid move for the bishop. Can't attack same color pieces." << std::endl;
            }
        }
        

    }
    // Add any other member functions or variables as needed
};

class WhiteQueen {
private:
    bool hasMoved;

public:
    int positionX;
    int positionY;

    WhiteQueen(int startX, int startY) {
        positionX = startX;
        positionY = startY;
        hasMoved = false;
    }

    bool isWhitePiece(char piece) {
        return (piece >= 'A' && piece <= 'Z');
    }

    void move(int targetX, int targetY, std::vector<std::vector<char>> board) {
        // Implement the logic to move the queen to the new position
        // Make sure to update the hasMoved flag accordingly
        if (targetX == positionX || targetY == positionY || abs(targetX - positionX) == abs(targetY - positionY)) {
            // Check if the target position is in the same row, column, or diagonal as the current position
            // If it is, update the position and set hasMoved to true
            int dx = (targetX > positionX) ? 1 : (targetX < positionX) ? -1 : 0;
            int dy = (targetY > positionY) ? 1 : (targetY < positionY) ? -1 : 0;
            int x = positionX + dx;
            int y = positionY + dy;
            while (x != targetX && y != targetY) {
                if (board[y][x] != ' ') {
                    // Path is not clear
                    std::cout << "Invalid move for the queen. There is a piece blocking the path." << std::endl;
                    return;
                }
                x += dx;
                y += dy;
            }

            if (!isWhitePiece(board[targetY][targetX])) {
                    // Check if the target position contains a black piece
                    // If it does, update the position and set hasMoved to true
                    positionX = targetX;
                    positionY = targetY;
                    hasMoved = true;
                } else {
                    // If the target position contains a white piece, the move is invalid
                    std::cout << "Invalid move for the queen. Cannot capture a white piece." << std::endl;
                }
        } else {
            // If the target position is not in the same row, column, or diagonal, the move is invalid
            std::cout << "Invalid move for the queen. Must be horizontal, vertical, or diagonal." << std::endl;
        }
    }

    // Add any other member functions or variables as needed
};

class WhiteKing {
private:
    bool hasMoved;

public:
    int positionX;
    int positionY;

    WhiteKing(int startX, int startY) {
        positionX = startX;
        positionY = startY;
        hasMoved = false;
    }

    bool isWhitePiece(char piece) {
        return (piece >= 'A' && piece <= 'Z');
    }

    void move(int targetX, int targetY, std::vector<std::vector<char>>& board) {

        // Check if the target position is reachable by the king
        if (abs(targetX - positionX) > 1 || abs(targetY - positionY) > 1) {
            std::cout << "Invalid move for the king. Cant Move more than One space." << std::endl;
            return;
        }

        // Check if the target position is occupied by a friendly piece
        if (isWhitePiece(board[targetY][targetX])) {
            std::cout << "Cannot capture a friendly piece." << std::endl;
            return;
        }

        positionX = targetX;
        positionY = targetY;
        hasMoved = true;
    }

    // Add any other member functions or variables as needed
};

class WhitePawn {
private:
    bool hasMoved;

public:
    int positionX;
    int positionY;

    WhitePawn(int startX, int startY) {
        positionX = startX;
        positionY = startY;
        hasMoved = false;
    }

    bool isBlackPiece(char piece) {
        return (piece >= 'a' && piece <= 'z');
    }

    void move(int targetX, int targetY, std::vector<std::vector<char>> board) {
        // Implement the logic to move the pawn to the new position
        // Make sure to update the hasMoved flag accordingly
        if (!hasMoved && targetY == positionY + 2 && targetX == positionX && board[targetY][targetX] == ' ' && board[targetY - 1][targetX] == ' ') {
            // Move the pawn two steps forward
            positionX = targetX;
            positionY = targetY;
            hasMoved = true;
        } else if (targetY == positionY + 1 && targetX == positionX && board[targetY][targetX] == ' ') {
            // Move the pawn one step forward
            positionX = targetX;
            positionY = targetY;
            hasMoved = true;
        } else if (targetY == positionY + 1 && (targetX == positionX + 1 || targetX == positionX - 1)) {
            // Capture an opponent's piece diagonally
            if (board[targetY][targetX] != ' ' && isBlackPiece(board[targetY][targetX])) {
                // Capture the piece
                positionX = targetX;
                positionY = targetY;
                hasMoved = true;
            } else {
                // Invalid move
                std::cout << "Invalid move for the pawn!" << std::endl;
            }
        } else {
            // Invalid move
            std::cout << "Invalid move for the pawn!" << std::endl;
        }
    }

    // Add any other member functions or variables as needed
};

class BlackRook {
private:
    bool hasMoved;

public:
    int positionX;
    int positionY;

    BlackRook(int startX, int startY) {
        positionX = startX;
        positionY = startY;
        hasMoved = false;
    }

    bool isBlackPiece(char piece) {
        return (piece >= 'a' && piece <= 'z');
    }

    void move(int targetX, int targetY, std::vector<std::vector<char>> board) {
        // Implement the logic to move the Rook to the new position
        // Make sure to update the hasMoved flag accordingly
        // Check if there are any pieces between the old position and the new position
        if (targetX == positionX) {
            // Moving vertically
            for (int y = positionY + 1; y < targetY; y++) {
                if (board[y][targetX] != ' ') {
                    std::cout << "Invalid move. There is a piece blocking the path." << std::endl;
                    return;
                }
            }
            if (board[targetY][targetX] != ' ') {
                if (isBlackPiece(board[targetY][targetX])) {
                    std::cout << "Invalid move. The target position is occupied by a piece of the same color." << std::endl;
                    return;
                } 
            }

        } else if (targetY == positionY) {
            // Moving horizontally
            for (int x = positionX + 1; x < targetX; x++) {
                if (board[targetY][x] != ' ') {
                    std::cout << "Invalid move. There is a piece blocking the path." << std::endl;
                    return;
                }
            }
            if (board[targetY][targetX] != ' ') {
                if (isBlackPiece(board[targetY][targetX])) {
                    std::cout << "Invalid move. The target position is occupied by a piece of the same color." << std::endl;
                    return;
                } 
            }
        } else {
            std::cout << "Invalid move. The new position must be on the same column or the same row." << std::endl;
            return;
        }

        positionX = targetX;
        positionY = targetY;
        hasMoved = true;
    }

    // Add any other member functions or variables as needed
};

class BlackKnight {
private:
    bool hasMoved;

public:
    int positionX;
    int positionY;

    BlackKnight(int startX, int startY) {
        positionX = startX;
        positionY = startY;
        hasMoved = false;
    }

    bool isBlackPiece(char piece) {
        return (piece >= 'a' && piece <= 'z');
    }

    void move(int targetX, int targetY, std::vector<std::vector<char>> board) {
        // Implement the logic to move the knight to the new position
        // Make sure to update the hasMoved flag accordingly
        int deltaX = abs(targetX - positionX);
        int deltaY = abs(targetY - positionY);

        if ((deltaX == 2 && deltaY == 1) || (deltaX == 1 && deltaY == 2)) {
            if (board[targetY][targetX] == ' ' || !isBlackPiece(board[targetY][targetX])) {
                positionX = targetX;
                positionY = targetY;
                hasMoved = true;
            } else {
                std::cout << "Invalid move for the knight. Can't attack same color pieces." << std::endl;
            }
        } else {
            std::cout << "Invalid move for the knight. Can't move other than 1x2." << std::endl;
        }
    }

    // Add any other member functions or variables as needed
};

class BlackBishop {
private:
    bool hasMoved;

public:
    int positionX;
    int positionY;

    BlackBishop(int startX, int startY) {
        positionX = startX;
        positionY = startY;
        hasMoved = false;
    }

    bool isBlackPiece(char piece) {
        return (piece >= 'a' && piece <= 'z');
    }

    void move(int targetX, int targetY, std::vector<std::vector<char>> board) {
        // Implement the logic to move the black bishop to the new position
        // Make sure to update the hasMoved flag accordingly
        if (abs(targetX - positionX) == abs(targetY - positionY)) {
            // Check if the path is clear
            int dx = (targetX > positionX) ? 1 : -1;
            int dy = (targetY > positionY) ? 1 : -1;
            int x = positionX + dx;
            int y = positionY + dy;
            while (x != targetX && y != targetY) {
                if (board[y][x] != ' ') {
                    // Path is not clear
                    std::cout << "Invalid move for the black bishop. There is a piece blocking the path." << std::endl;
                    return;
                }
                x += dx;
                y += dy;
            }
            
            if (board[targetY][targetX] == ' ' || !isBlackPiece(board[targetY][targetX])) {
                // Move the black bishop to the new position
                positionX = targetX;
                positionY = targetY;
                hasMoved = true;
            } else {
                std::cout << "Invalid move for the black bishop. Can't attack same color pieces." << std::endl;
            }
        }
    }
    // Add any other member functions or variables as needed
};

class BlackQueen {
private:
    bool hasMoved;

public:
    int positionX;
    int positionY;

    BlackQueen(int startX, int startY) {
        positionX = startX;
        positionY = startY;
        hasMoved = false;
    }

    bool isBlackPiece(char piece) {
        return (piece >= 'a' && piece <= 'z');
    }

    void move(int targetX, int targetY, std::vector<std::vector<char>> board) {
        // Implement the logic to move the queen to the new position
        // Make sure to update the hasMoved flag accordingly
        if (targetX == positionX || targetY == positionY || abs(targetX - positionX) == abs(targetY - positionY)) {
            // Check if the target position is in the same row, column, or diagonal as the current position
            // If it is, update the position and set hasMoved to true
            int dx = (targetX > positionX) ? 1 : (targetX < positionX) ? -1 : 0;
            int dy = (targetY > positionY) ? 1 : (targetY < positionY) ? -1 : 0;
            int x = positionX + dx;
            int y = positionY + dy;
            while (x != targetX && y != targetY) {
                if (board[y][x] != ' ') {
                    // Path is not clear
                    std::cout << "Invalid move for the queen. There is a piece blocking the path." << std::endl;
                    return;
                }
                x += dx;
                y += dy;
            }

            if (!isBlackPiece(board[targetY][targetX])) {
                    // Check if the target position contains a white piece
                    // If it does, update the position and set hasMoved to true
                    positionX = targetX;
                    positionY = targetY;
                    hasMoved = true;
                } else {
                    // If the target position contains a black piece, the move is invalid
                    std::cout << "Invalid move for the queen. Cannot capture a black piece." << std::endl;
                }
        } else {
            // If the target position is not in the same row, column, or diagonal, the move is invalid
            std::cout << "Invalid move for the queen. Must be horizontal, vertical, or diagonal." << std::endl;
        }
    }

    // Add any other member functions or variables as needed
};

class BlackKing {
private:
    bool hasMoved;

public:
    int positionX;
    int positionY;

    BlackKing(int startX, int startY) {
        positionX = startX;
        positionY = startY;
        hasMoved = false;
    }

    bool isBlackPiece(char piece) {
        return (piece >= 'a' && piece <= 'z');
    }

    void move(int targetX, int targetY, std::vector<std::vector<char>>& board) {

        // Check if the target position is reachable by the king
        if (abs(targetX - positionX) > 1 || abs(targetY - positionY) > 1) {
            std::cout << "Invalid move for the king. Can't move more than one space." << std::endl;
            return;
        }

        // Check if the target position is occupied by a friendly piece
        if (isBlackPiece(board[targetY][targetX])) {
            std::cout << "Cannot capture a friendly piece." << std::endl;
            return;
        }

        positionX = targetX;
        positionY = targetY;
        hasMoved = true;
    }

    // Add any other member functions or variables as needed
};

class BlackPawn {
private:
    bool hasMoved;

public:
    int positionX;
    int positionY;

    BlackPawn(int startX, int startY) {
        positionX = startX;
        positionY = startY;
        hasMoved = false;
    }

    bool isWhitePiece(char piece) {
        return (piece >= 'A' && piece <= 'Z');
    }

    void move(int targetX, int targetY, std::vector<std::vector<char>> board) {
        // Implement the logic to move the pawn to the new position
        // Make sure to update the hasMoved flag accordingly
        if (targetX == positionX && targetY == positionY + 1 && board[targetY][targetX] == ' ') {
            // Move the pawn one step forward
            positionX = targetX;
            positionY = targetY;
            hasMoved = true;
        } else if (targetX == positionX && targetY == positionY - 2 && !hasMoved && board[targetY][targetX] == ' ' && board[targetY + 1][targetX] == ' ') {
            // Move the pawn two steps forward if it hasn't moved yet
            positionX = targetX;
            positionY = targetY;
            hasMoved = true;
        } else if (targetX == positionX - 1 && targetY == positionY - 1 && board[targetY][targetX] != ' ' && isWhitePiece(board[targetY][targetX])) {
            // Capture an opponent's piece diagonally to the left
            positionX = targetX;
            positionY = targetY;
            hasMoved = true;
        } else if (targetX == positionX + 1 && targetY == positionY - 1 && board[targetY][targetX] != ' ' && isWhitePiece(board[targetY][targetX])) {
            // Capture an opponent's piece diagonally to the right
            positionX = targetX;
            positionY = targetY;
            hasMoved = true;
        } else {
            // Invalid move
            std::cout << "Invalid move for the pawn." << std::endl;
        }

    }

    // Add any other member functions or variables as needed
};

class ChessBoard {
public:
    std::vector<std::vector<char>> board;
    

    ChessBoard() {
        // Initialize the board with empty spaces
        board.resize(8, std::vector<char>(8, ' '));
    }

    void placePiece(int x, int y, char piece) {
        // Check if the position is valid
        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            // Place the piece on the board
            board[y][x] = piece;
        }
    }

    char getPiece(int x, int y) {
        // Check if the position is valid
        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            // Return the piece at the specified position
            return board[y][x];
        }
        return ' ';
    }


    void printBoard() {
        // Print the board
        std::cout << "    WHITE SIDE" << std::endl;
        std::cout << "  0 1 2 3 4 5 6 7" << std::endl; // X-axis border
        for (int y = 0; y < 8; y++) {
            std::cout << y << ' '; // Y-axis border
            for (int x = 0; x < 8; x++) {
                std::cout << board[y][x] << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << "    BLACK SIDE" << std::endl;
    }
};    

bool isWhitePiece(char piece) {
    return (piece >= 'A' && piece <= 'Z');
}

bool isBlackPiece(char piece) {
    return (piece >= 'a' && piece <= 'z');
}

int main() {
    ChessBoard chessBoard;
    

    // Place the white pieces
    chessBoard.placePiece(0, 0, 'R');
    chessBoard.placePiece(1, 0, 'N');
    chessBoard.placePiece(2, 0, 'B');
    chessBoard.placePiece(3, 0, 'Q');
    chessBoard.placePiece(4, 0, 'K');
    chessBoard.placePiece(5, 0, 'B');
    chessBoard.placePiece(6, 0, 'N');
    chessBoard.placePiece(7, 0, 'R');
    for (int x = 0; x < 8; x++) {
        chessBoard.placePiece(x, 1, 'P');
    }

    // Place the black pieces
    chessBoard.placePiece(0, 7, 'r');
    chessBoard.placePiece(1, 7, 'n');
    chessBoard.placePiece(2, 7, 'b');
    chessBoard.placePiece(3, 7, 'q');
    chessBoard.placePiece(4, 7, 'k');
    chessBoard.placePiece(5, 7, 'b');
    chessBoard.placePiece(6, 7, 'n');
    chessBoard.placePiece(7, 7, 'r');
    for (int x = 0; x < 8; x++) {
        chessBoard.placePiece(x, 6, 'p');
    }

    // Print the board
    chessBoard.printBoard();

    // Initialize the white pieces
    WhiteRook whiteRook1(0, 0);
    WhiteKnight whiteKnight1(1, 0);
    WhiteBishop whiteBishop1(2, 0);
    WhiteQueen whiteQueen(3, 0);
    WhiteKing whiteKing(4, 0);
    WhiteBishop whiteBishop2(5, 0);
    WhiteKnight whiteKnight2(6, 0);
    WhiteRook whiteRook2(7, 0);
    WhitePawn whitePawn1(0, 1);
    WhitePawn whitePawn2(1, 1);
    WhitePawn whitePawn3(2, 1);
    WhitePawn whitePawn4(3, 1);
    WhitePawn whitePawn5(4, 1);
    WhitePawn whitePawn6(5, 1);
    WhitePawn whitePawn7(6, 1);
    WhitePawn whitePawn8(7, 1);

    // Initialize the black pieces
    BlackRook blackRook1(0, 7);
    BlackKnight blackKnight1(1, 7);
    BlackBishop blackBishop1(2, 7);
    BlackQueen blackQueen(3, 7);
    BlackKing blackKing(4, 7);
    BlackBishop blackBishop2(5, 7);
    BlackKnight blackKnight2(6, 7);
    BlackRook blackRook2(7, 7);
    BlackPawn blackPawn1(0, 6);
    BlackPawn blackPawn2(1, 6);
    BlackPawn blackPawn3(2, 6);
    BlackPawn blackPawn4(3, 6);
    BlackPawn blackPawn5(4, 6);
    BlackPawn blackPawn6(5, 6);
    BlackPawn blackPawn7(6, 6);
    BlackPawn blackPawn8(7, 6);

    bool isWhiteTurn = true;
    bool turnSuccess = true;

    while (true) {
        // Get user input for piece position and target position
        int positionX, positionY, targetX, targetY;
        std::cout << "Enter the current position of the piece (x y): ";
        std::cin >> positionX >> positionY;
        std::cout << "Enter the target position (x y): ";
        std::cin >> targetX >> targetY;

        // Check if the starting position is valid
        if (positionX < 0 || positionX >= 8 || positionY < 0 || positionY >= 8) {
            std::cout << "Invalid starting position." << std::endl;
            continue;
        }

        // Check if the target position is valid
        if (targetX < 0 || targetX >= 8 || targetY < 0 || targetY >= 8) {
            std::cout << "Invalid target position." << std::endl;
            continue;
        }

        // Get the piece at the starting position
        char piece = chessBoard.getPiece(positionX, positionY);

        // Check if the piece is valid
        if (piece == ' ') {
            std::cout << "No piece found at the starting position." << std::endl;
            continue;
        }

        // Check if it's the player's turn to move the piece
        if (isWhitePiece(piece) && !isWhiteTurn) {
            std::cout << "It's not your turn to move the white pieces." << std::endl;
            continue;
        } else if (isBlackPiece(piece) && isWhiteTurn) {
            std::cout << "It's not your turn to move the black pieces." << std::endl;
            continue;
        }

        // Move or capture the piece
        if (isWhitePiece(piece)) {
            // White piece
            switch (piece) {
                case 'R':
                    if (whiteRook1.positionX == positionX && whiteRook1.positionY == positionY) {
                        whiteRook1.move(targetX, targetY, chessBoard.board);
                        if (whiteRook1.positionX == targetX && whiteRook1.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'R');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (whiteRook2.positionX == positionX && whiteRook2.positionY == positionY) {
                        whiteRook2.move(targetX, targetY, chessBoard.board);
                        if (whiteRook2.positionX == targetX && whiteRook2.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'R');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else {
                        std::cout << "Invalid current position for the white rook." << std::endl;
                        continue;
                    }
                    break;
                case 'N':
                    if (whiteKnight1.positionX == positionX && whiteKnight1.positionY == positionY) {
                        whiteKnight1.move(targetX, targetY, chessBoard.board);
                        if (whiteKnight1.positionX == targetX && whiteKnight1.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'N');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (whiteKnight2.positionX == positionX && whiteKnight2.positionY == positionY) {
                        whiteKnight2.move(targetX, targetY, chessBoard.board);
                        if (whiteKnight2.positionX == targetX && whiteKnight2.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'N');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else {
                        std::cout << "Invalid current position for the white knight." << std::endl;
                        continue;
                    }
                    break;
                case 'B':
                    if (whiteBishop1.positionX == positionX && whiteBishop1.positionY == positionY) {
                        whiteBishop1.move(targetX, targetY, chessBoard.board);
                        if (whiteBishop1.positionX == targetX && whiteBishop1.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'B');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (whiteBishop2.positionX == positionX && whiteBishop2.positionY == positionY) {
                        whiteBishop2.move(targetX, targetY, chessBoard.board);
                        if (whiteBishop2.positionX == targetX && whiteBishop2.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'B');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }  
                    } else {
                        std::cout << "Invalid current position for the white bishop." << std::endl;
                        continue;
                    }
                    break;
                case 'Q':
                    whiteQueen.move(targetX, targetY, chessBoard.board);
                    if (whiteQueen.positionX == targetX && whiteQueen.positionY == targetY) {
                        chessBoard.placePiece(targetX, targetY, 'Q');
                        chessBoard.placePiece(positionX, positionY, ' ');
                    } else {
                        continue;
                    }
                    break;
                case 'K':
                    whiteKing.move(targetX, targetY, chessBoard.board);
                    if (whiteKing.positionX == targetX && whiteKing.positionY == targetY) {
                        chessBoard.placePiece(targetX, targetY, 'K');
                        chessBoard.placePiece(positionX, positionY, ' ');
                    } else {
                        continue;
                    }
                    break;
                case 'P':
                    if (whitePawn1.positionX == positionX && whitePawn1.positionY == positionY) {
                        whitePawn1.move(targetX, targetY, chessBoard.board);
                        if (whitePawn1.positionX == targetX && whitePawn1.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'P');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                        
                    } else if (whitePawn2.positionX == positionX && whitePawn2.positionY == positionY) {
                        whitePawn2.move(targetX, targetY, chessBoard.board);
                        if (whitePawn2.positionX == targetX && whitePawn2.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'P');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }

                    } else if (whitePawn3.positionX == positionX && whitePawn3.positionY == positionY) {
                        whitePawn3.move(targetX, targetY, chessBoard.board);
                        if (whitePawn3.positionX == targetX && whitePawn3.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'P');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (whitePawn4.positionX == positionX && whitePawn4.positionY == positionY) {
                        whitePawn4.move(targetX, targetY, chessBoard.board);
                        if (whitePawn4.positionX == targetX && whitePawn4.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'P');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (whitePawn5.positionX == positionX && whitePawn5.positionY == positionY) {
                        whitePawn5.move(targetX, targetY, chessBoard.board);
                        if (whitePawn5.positionX == targetX && whitePawn5.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'P');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (whitePawn6.positionX == positionX && whitePawn6.positionY == positionY) {
                        whitePawn6.move(targetX, targetY, chessBoard.board);
                        if (whitePawn6.positionX == targetX && whitePawn6.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'P');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (whitePawn7.positionX == positionX && whitePawn7.positionY == positionY) {
                        whitePawn7.move(targetX, targetY, chessBoard.board);
                        if (whitePawn7.positionX == targetX && whitePawn7.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'P');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (whitePawn8.positionX == positionX && whitePawn8.positionY == positionY) {
                        whitePawn8.move(targetX, targetY, chessBoard.board);
                        if (whitePawn8.positionX == targetX && whitePawn8.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'P');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else {
                        std::cout << "Invalid current position for the white pawn." << std::endl;
                        continue;
                    }
                    break;
            }
        } else {
            // Black piece
            switch (piece) {
                case 'r':
                    if (blackRook1.positionX == positionX && blackRook1.positionY == positionY) {
                        blackRook1.move(targetX, targetY, chessBoard.board);
                        if (blackRook1.positionX == targetX && blackRook1.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'r');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (blackRook2.positionX == positionX && blackRook2.positionY == positionY) {
                        blackRook2.move(targetX, targetY, chessBoard.board);
                        if (blackRook2.positionX == targetX && blackRook2.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'r');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else {
                        std::cout << "Invalid current position for the black rook." << std::endl;
                        continue;
                    }
                    break;
                case 'n':
                    if (blackKnight1.positionX == positionX && blackKnight1.positionY == positionY) {
                        blackKnight1.move(targetX, targetY, chessBoard.board);
                        if (blackKnight1.positionX == targetX && blackKnight1.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'n');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (blackKnight2.positionX == positionX && blackKnight2.positionY == positionY) {
                        blackKnight2.move(targetX, targetY, chessBoard.board);
                        if (blackKnight2.positionX == targetX && blackKnight2.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'n');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else {
                        std::cout << "Invalid current position for the black knight." << std::endl;
                        continue;
                    }
                    break;
                case 'b':
                    if (blackBishop1.positionX == positionX && blackBishop1.positionY == positionY) {
                        blackBishop1.move(targetX, targetY, chessBoard.board);
                        if (blackBishop1.positionX == targetX && blackBishop1.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'b');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (blackBishop2.positionX == positionX && blackBishop2.positionY == positionY) {
                        blackBishop2.move(targetX, targetY, chessBoard.board);
                        if (blackBishop2.positionX == targetX && blackBishop2.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'b');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else {
                        std::cout << "Invalid current position for the black bishop." << std::endl;
                        continue;
                    }
                    break;
                case 'q':
                    blackQueen.move(targetX, targetY, chessBoard.board);
                    if (blackQueen.positionX == targetX && blackQueen.positionY == targetY) {
                        chessBoard.placePiece(targetX, targetY, 'q');
                        chessBoard.placePiece(positionX, positionY, ' ');
                    } else {
                        continue;
                    }
                    break;
                case 'k':
                    blackKing.move(targetX, targetY, chessBoard.board);
                    if (blackKing.positionX == targetX && blackKing.positionY == targetY) {
                        chessBoard.placePiece(targetX, targetY, 'k');
                        chessBoard.placePiece(positionX, positionY, ' ');
                    } else {
                        continue;
                    }
                    break;
                case 'p':
                    if (blackPawn1.positionX == positionX && blackPawn1.positionY == positionY) {
                        blackPawn1.move(targetX, targetY, chessBoard.board);
                        if (blackPawn1.positionX == targetX && blackPawn1.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'p');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (blackPawn2.positionX == positionX && blackPawn2.positionY == positionY) {
                        blackPawn2.move(targetX, targetY, chessBoard.board);
                        if (blackPawn2.positionX == targetX && blackPawn2.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'p');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (blackPawn3.positionX == positionX && blackPawn3.positionY == positionY) {
                        blackPawn3.move(targetX, targetY, chessBoard.board);
                        if (blackPawn3.positionX == targetX && blackPawn3.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'p');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (blackPawn4.positionX == positionX && blackPawn4.positionY == positionY) {
                        blackPawn4.move(targetX, targetY, chessBoard.board);
                        if (blackPawn4.positionX == targetX && blackPawn4.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'p');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (blackPawn5.positionX == positionX && blackPawn5.positionY == positionY) {
                        blackPawn5.move(targetX, targetY, chessBoard.board);
                        if (blackPawn5.positionX == targetX && blackPawn5.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'p');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (blackPawn6.positionX == positionX && blackPawn6.positionY == positionY) {
                        blackPawn6.move(targetX, targetY, chessBoard.board);
                        if (blackPawn6.positionX == targetX && blackPawn6.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'p');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (blackPawn7.positionX == positionX && blackPawn7.positionY == positionY) {
                        blackPawn7.move(targetX, targetY, chessBoard.board);
                        if (blackPawn7.positionX == targetX && blackPawn7.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'p');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else if (blackPawn8.positionX == positionX && blackPawn8.positionY == positionY) {
                        blackPawn8.move(targetX, targetY, chessBoard.board);
                        if (blackPawn8.positionX == targetX && blackPawn8.positionY == targetY) {
                            chessBoard.placePiece(targetX, targetY, 'p');
                            chessBoard.placePiece(positionX, positionY, ' ');
                        } else {
                            continue;
                        }
                    } else {
                        std::cout << "Invalid current position for the black pawn." << std::endl;
                        continue;
                    }
                    break;

            }
        }
        // Print the updated board
        chessBoard.printBoard();
      
        // Switch the turn to the other player
        isWhiteTurn = !isWhiteTurn;
     
        
    }
    return 0;
}
//