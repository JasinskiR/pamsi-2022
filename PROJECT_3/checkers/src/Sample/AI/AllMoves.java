package Sample.AI;

import java.util.ArrayList;

import static Sample.Controllers.GameFunctions.insideBoard;
import static Sample.Controllers.NeutralScreenController.dirsBackward;
import static Sample.Controllers.NeutralScreenController.dirsForward;

public class AllMoves {
  Integer[][] board;
  ArrayList<Integer[][]> possibleMoves;
  int turn;

  public AllMoves(Integer[][] board, int turn) {
    this.board = board;
    possibleMoves = new ArrayList<>();
    this.turn = turn;
  }

  /**
   * Method to get all possible moves from current position
   * @return - array with possible moves
   */
  public ArrayList<Integer[][]> getPossibleMoves() {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (board[i][j] * turn <= 0) continue;
        if (turn > 0 && Math.abs(board[i][j]) == 1) {
          // pawn move
          for (int[] dir : dirsForward) {
            if (!insideBoard(i + dir[0], j + dir[1])) continue;
            if (board[i + dir[0]][j + dir[1]] * turn > 0) continue;
            if (board[i + dir[0]][j + dir[1]] * turn == 0) {
              // empty square in front of you
              Integer[][] newBoard = copyArray(board);
              // adding new move
              newBoard[i][j] = 0;
              newBoard[i + dir[0]][j + dir[1]] = board[i][j];
              if (i + dir[0] == 0)
                newBoard[i + dir[0]][j + dir[1]] = 2 * board[i][j];
              possibleMoves.add(newBoard);
            }
            // enemy pawn in front of you
            if (board[i + dir[0]][j + dir[1]] * turn < 0) {
              if (!insideBoard(i + 2 * dir[0], j + 2 * dir[1])) continue;
              if (board[i + 2 * dir[0]][j + 2 * dir[1]] != 0) continue;
              Integer[][] newBoard = copyArray(board);
              // adding new move
              newBoard[i][j] = 0;
              newBoard[i + dir[0]][j + dir[1]] = 0;
              newBoard[i + 2 * dir[0]][j + 2 * dir[1]] = board[i][j];
              if (i + 2 * dir[0] == 0 && turn == 1)
                newBoard[i + 2 * dir[0]][j + 2 * dir[1]] = 2 * board[i][j];
              possibleMoves.add(newBoard);
            }
          }
          for (int[] dir : dirsBackward) {
            if (!insideBoard(i + dir[0], j + dir[1])) continue;
            if (board[i + dir[0]][j + dir[1]] * turn >= 0) continue;
            if (!insideBoard(i + 2 * dir[0], j + 2 * dir[1])) continue;
            if (board[i + 2 * dir[0]][j + 2 * dir[1]] != 0) continue;
            Integer[][] newBoard = copyArray(board);
            // adding new move
            newBoard[i][j] = 0;
            newBoard[i + dir[0]][j + dir[1]] = 0;
            newBoard[i + 2 * dir[0]][j + 2 * dir[1]] = board[i][j];
            possibleMoves.add(newBoard);
          }
        } else if (turn < 0 && Math.abs(board[i][j]) == 1) { // pawn move
          for (int[] dir : dirsBackward) {
            if (!insideBoard(i + dir[0], j + dir[1])) continue;
            if (board[i + dir[0]][j + dir[1]] * turn > 0) continue;
            // empty square in front of enemy
            if (board[i + dir[0]][j + dir[1]] * turn == 0) {
              Integer[][] newBoard = copyArray(board);
              // adding new move
              newBoard[i][j] = 0;
              newBoard[i + dir[0]][j + dir[1]] = board[i][j];
              if (i + dir[0] == 7)
                newBoard[i + dir[0]][j + dir[1]] = 2 * board[i][j];
              possibleMoves.add(newBoard);
            }
            // your pawn in front of enemy
            if (board[i + dir[0]][j + dir[1]] * turn < 0) {
              if (!insideBoard(i + 2 * dir[0], j + 2 * dir[1])) continue;
              if (board[i + 2 * dir[0]][j + 2 * dir[1]] != 0) continue;
              Integer[][] newBoard = copyArray(board);
              // adding new move
              newBoard[i][j] = 0;
              newBoard[i + dir[0]][j + dir[1]] = 0;
              newBoard[i + 2 * dir[0]][j + 2 * dir[1]] = board[i][j];
              if (i + 2 * dir[0] == 7)
                newBoard[i + 2 * dir[0]][j + 2 * dir[1]] = 2 * board[i][j];
              possibleMoves.add(newBoard);
            }
          }
          // your pawn behind enemy
          for (int[] dir : dirsForward) {
            if (!insideBoard(i + dir[0], j + dir[1])) continue;
            if (board[i + dir[0]][j + dir[1]] * turn >= 0) continue;
            if (!insideBoard(i + 2 * dir[0], j + 2 * dir[1])) continue;
            if (board[i + 2 * dir[0]][j + 2 * dir[1]] != 0) continue;
            Integer[][] newBoard = copyArray(board);
            // adding new move
            newBoard[i][j] = 0;
            newBoard[i + dir[0]][j + dir[1]] = 0;
            newBoard[i + 2 * dir[0]][j + 2 * dir[1]] = board[i][j];
            possibleMoves.add(newBoard);
          }
        } else { // king move

          for (int[] dir : dirsForward) {
            int countYours = 0;
            int countEnemy = 0;
            int[] enemyPos = null;
            for (int iter = 1;
                 insideBoard(i + iter * dir[0], j + iter * dir[1]) && countYours == 0 &&
                         countEnemy < 2; iter++) {
              if (board[i + iter * dir[0]][j + iter * dir[1]] * turn < 0) { // enemy piece
                if (++countEnemy == 1) {
                  // copying enemy position and piece
                  enemyPos = new int[2];
                  enemyPos[0] = i + iter * dir[0];
                  enemyPos[1] = j + iter * dir[1];
                }
              } else if (board[i + iter * dir[0]][j + iter * dir[1]] * turn > 0) {
                // your piece
                countYours++;
              } else { // empty position - swapping squares and adding to array
                Integer[][] newBoard = copyArray(board);
                newBoard[i + iter * dir[0]][j + iter * dir[1]] = newBoard[i][j];
                newBoard[i][j] = 0; // now this position is empty
                if (countEnemy == 1) {
                  newBoard[enemyPos[0]][enemyPos[1]] = 0;
                }
                possibleMoves.add(newBoard);
              }
            }
          }
          // now backwards

          for (int[] dir : dirsBackward) {
            int countYours = 0;
            int countEnemy = 0;
            int[] enemyPos = null;
            for (int iter = 1;
                 insideBoard(i + iter * dir[0], j + iter * dir[1]) && countYours == 0 &&
                         countEnemy < 2; iter++) {
              if (board[i + iter * dir[0]][j + iter * dir[1]] * turn < 0) { // enemy piece
                if (++countEnemy == 1) {
                  // copying enemy position and piece
                  enemyPos = new int[2];
                  enemyPos[0] = i + iter * dir[0];
                  enemyPos[1] = j + iter * dir[1];
                }
              } else if (board[i + iter * dir[0]][j + iter * dir[1]] * turn > 0) {
                // your piece
                countYours++;
              } else { // empty position - swapping squares and adding to array
                Integer[][] newBoard = copyArray(board);
                newBoard[i + iter * dir[0]][j + iter * dir[1]] = board[i][j];
                newBoard[i][j] = 0; // now this position is empty
                if (countEnemy == 1) {
                  newBoard[enemyPos[0]][enemyPos[1]] = 0;
                }
                possibleMoves.add(newBoard);
              }
            }
          }
        }
      }
    }

    return possibleMoves;
  }

  Integer[][] copyArray(Integer[][] array) {
    Integer[][] newArray = new Integer[8][8];
    for (int a = 0; a < 8; a++)
      for (int b = 0; b < 8; b++)
        newArray[a][b] = array[a][b];
    return newArray;
  }
}


