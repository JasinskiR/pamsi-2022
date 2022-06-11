package Sample.Controllers;

import static Sample.Controllers.NeutralScreenController.*;

public class GameFunctions {
  /**
   * Method to check if current position is correct - inside 8x8 board
   *
   * @param X - vertical coordinate
   * @param Y - horizontal coordinate
   * @return -
   * true: It is inside the board
   * false: It is outside the board
   */
  public static boolean insideBoard(int X, int Y) {
    if ((X >= 0 && X <= 7) && (Y >= 0 && Y <= 7)) return true;
    return false;
  }

  /**
   * Method to get possible forward moves of pawn
   *
   * @param i - current vertical position of the pawn
   * @param j - current horizontal position of the pawn
   */
  public static void directionForward(int i, int j) {
    for (int[] dir : dirsForward) {
      if (button.get(i).get(j).getId().equals(Integer.toString(turn + 2))) {
        kingPossibleMoves(i, j, dir);
        continue;
      }
      if (!insideBoard(i + dir[0], j + dir[1]) || (turn == 1 - yourTurn &&
              !button.get(i + dir[0]).get(j + dir[1]).getId()
                      .equals(Integer.toString(yourTurn)) &&
              !button.get(i + dir[0]).get(j + dir[1]).getId()
                      .equals(Integer.toString(yourTurn + 2)))) continue;

      if ((button.get(i + dir[0]).get(j + dir[1]).getId()
              .equals(Integer.toString(1 - turn)) ||
              button.get(i + dir[0]).get(j + dir[1]).getId()
                      .equals(Integer.toString(3 - turn))) &&
              insideBoard(2 * dir[0] + i, 2 * dir[1] + j) &&
              button.get(2 * dir[0] + i).get(2 * dir[1] + j).getId().equals("empty")) {
        button.get(i + 2 * dir[0]).get(j + 2 * dir[1]).setStyle(greenSquare);
        green.add(new Square((i + 2 * dir[0]), (j + 2 * dir[1])));
      }

      if (button.get(i + dir[0]).get(j + dir[1]).getId().equals("empty")) {
        button.get(i + dir[0]).get(j + dir[1]).setStyle(greenSquare);
        green.add(new Square((i + dir[0]), (j + dir[1])));
      }
    }
  }

  /**
   * Method to get possible backward moves of pawn
   *
   * @param i - current vertical position of the pawn
   * @param j - current horizontal position of the pawn
   */
  public static void directionBackward(int i, int j) {
    for (int dir[] : dirsBackward) {
      if (button.get(i).get(j).getId().equals(Integer.toString(turn + 2))) {
        kingPossibleMoves(i, j, dir);
        continue;
      }


      if (!insideBoard(i + dir[0], j + dir[1]) || (turn == yourTurn &&
              !button.get(i + dir[0]).get(j + dir[1]).getId()
                      .equals(Integer.toString(1 - yourTurn)))) continue;

      if ((button.get(i + dir[0]).get(j + dir[1]).getId()
              .equals(Integer.toString(1 - turn)) ||
              button.get(i + dir[0]).get(j + dir[1]).getId()
                      .equals(Integer.toString(3 - turn))) &&
              insideBoard(2 * dir[0] + i, 2 * dir[1] + j) &&
              button.get(2 * dir[0] + i).get(2 * dir[1] + j).getId().equals("empty")) {
        button.get(i + 2 * dir[0]).get(j + 2 * dir[1]).setStyle(greenSquare);
        green.add(new Square((i + 2 * dir[0]), (j + 2 * dir[1])));
      }

      if (button.get(i + dir[0]).get(j + dir[1]).getId().equals("empty")) {
        button.get(i + dir[0]).get(j + dir[1]).setStyle(greenSquare);
        green.add(new Square((i + dir[0]), (j + dir[1])));
      }
    }
  }

  /**
   * Method to get possible move of the king piece
   *
   * @param i   - current vertical position of the king
   * @param j   - current horizontal position of the king
   * @param dir - array of preset possible move
   */
  public static void kingPossibleMoves(int i, int j, int[] dir) {
    int countEnemy = 0;
    int countYours = 0;
    int iter = 1;
    while (countEnemy < 2 && countYours == 0 &&
            insideBoard(i + iter * dir[0], j + iter * dir[1])) {

      if (button.get(i + iter * dir[0]).get(j + iter * dir[1]).getId().equals("empty")) {
        button.get(i + iter * dir[0]).get(j + iter * dir[1]).setStyle(greenSquare);
        green.add(new Square((i + iter * dir[0]), (j + iter * dir[1])));
      } else if (button.get(i + iter * dir[0]).get(j + iter * dir[1]).getId()
              .equals(Integer.toString(turn)) ||
              button.get(i + iter * dir[0]).get(j + iter * dir[1]).getId()
                      .equals(Integer.toString(turn + 2))) {
        countYours++;
      } else countEnemy++;
      iter++;
    }
  }

  /**
   * Method to get the 2dimension array of pieces
   *
   * @return - array with pieces
   */
  public static Integer[][] boardPosition() {
    Integer[][] board = new Integer[8][8];
    String pieceId;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        pieceId = button.get(i).get(j).getId();
        if (pieceId.equals(String.valueOf(yourTurn))) {
          board[i][j] = 1;
        }
        if (pieceId.equals(String.valueOf(yourTurn+2))) {
          board[i][j] = 2;
        }
        if (pieceId.equals(String.valueOf(1-yourTurn))) {
          board[i][j] = -1;
        }
        if (pieceId.equals(String.valueOf(3-yourTurn))) {
          board[i][j] = -2;
        }
        else if (pieceId.equals("empty")) board[i][j] = 0;
      }
    }
    return board;
  }
}
