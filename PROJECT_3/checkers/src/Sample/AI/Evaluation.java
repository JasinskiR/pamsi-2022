package Sample.AI;

import Sample.Controllers.GlobalVar;

import java.util.*;

import static Sample.Controllers.GameFunctions.*;

public class Evaluation {
  Integer[][] board;
  int[] difficulty;

  public Evaluation(Integer[][] board) {
    this.board = board;
  }

  public int evaluate() {
    int numberOfYourPawns = 0;
    int numberOfYourKings = 0;
    int numberOfEnemyPawns = 0;
    int numberOfEnemyKings = 0;
    int numberOfSavePawns = 0;
    int numberOfSaveKings = 0;
    int numberOfMovablePawns = 0;
    int numberOfMovableKings = 0;
    int distanceOfPawnsToKingLine = 0;
    int numberOfUnoccupiedSquaresOnKingLine = 0;
    int numberOfDefenderPieces = 0;
    int numberOfAttackingPawns = 0;
    int numberOfCentrallyPositionedPawns = 0;
    int numberOfCentrallyPositionedKings = 0;
    int numberOfPawnsOnMainDiagonal = 0;
    int numberOfKingsOnMainDiagonal = 0;
    int numberOfPawnsOnDoubleDiagonal = 0;
    int numberOfKingsOnDoubleDiagonal = 0;
    int numberOfLonerPawn = 0; // pawn that has no adjacent
    int numberOfLonerKings = 0;
    int bridgePattern = 0;
    int numberOfHoles = 0;


    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        // numberOfPawns
        if (board[i][j] == 1) numberOfYourPawns++;
        if (board[i][j] == -1) numberOfEnemyPawns++;
        // numberOfKings
        if (board[i][j] == 2) numberOfYourKings++;
        if (board[i][j] == -2) numberOfEnemyKings++;
        // numberOfSavePawns
        if (board[i][j] == 1 && (j == 0 || j == 7)) numberOfSavePawns++;
        if (board[i][j] == -1 && (j == 0 || j == 7)) numberOfSavePawns--;
        // numberOfSaveKings
        if (board[i][j] == 2 && (j == 0 || j == 7)) numberOfSaveKings++;
        if (board[i][j] == -2 && (j == 0 || j == 7)) numberOfSaveKings--;
        // numberOfMovablePawns
        if (board[i][j] == 1 && insideBoard(i + 1, j + 1) && board[i + 1][j + 1] == 0)
          numberOfMovablePawns++;
        if (board[i][j] == 1 && insideBoard(i + 1, j - 1) && board[i + 1][j - 1] == 0)
          numberOfMovablePawns++;
        if (board[i][j] == -1 && insideBoard(i - 1, j - 1) && board[i - 1][j - 1] == 0)
          numberOfMovablePawns--;
        if (board[i][j] == -1 && insideBoard(i - 1, j + 1) && board[i - 1][j + 1] == 0)
          numberOfMovablePawns--;
        // numberOfMovableKings
        if (board[i][j] == 2 && insideBoard(i + 1, j + 1) && board[i + 1][j + 1] == 0)
          numberOfMovableKings++;
        if (board[i][j] == 2 && insideBoard(i + 1, j - 1) && board[i + 1][j - 1] == 0)
          numberOfMovableKings++;
        if (board[i][j] == -2 && insideBoard(i - 1, j - 1) && board[i - 1][j - 1] == 0)
          numberOfMovableKings--;
        if (board[i][j] == -2 && insideBoard(i - 1, j + 1) && board[i - 1][j + 1] == 0)
          numberOfMovableKings--;
        // distanceOfPawns
        if (board[i][j] == 1) distanceOfPawnsToKingLine += (7 - i);
        if (board[i][j] == -1) distanceOfPawnsToKingLine -= i;
        // number of unoccupied fields on promotion line
        if (i == 0 && board[i][j] == 0) numberOfUnoccupiedSquaresOnKingLine++;
        if (i == 7 && board[i][j] == 0) numberOfUnoccupiedSquaresOnKingLine--;
        // number of defender pieces
        if (board[i][j] == 1 && insideBoard(i + 1, j + 1) && board[i + 1][j + 1] > 0)
          numberOfMovablePawns++;
        if (board[i][j] == 1 && insideBoard(i + 1, j - 1) && board[i + 1][j - 1] > 0)
          numberOfMovablePawns++;
        if (board[i][j] == -1 && insideBoard(i - 1, j - 1) && board[i - 1][j - 1] < 0)
          numberOfMovablePawns--;
        if (board[i][j] == -1 && insideBoard(i - 1, j + 1) && board[i - 1][j + 1] < 0)
          numberOfMovablePawns--;
        // number of attacking pawns
        if (board[i][j] == 1 && i < 3) numberOfAttackingPawns++;
        if (board[i][j] == -1 && i > 4) numberOfAttackingPawns--;
        // number of centrally positioned pawns
        if (board[i][j] == 1 && i >= 2 && i <= 5 && j >= 2 && j <= 5)
          numberOfCentrallyPositionedPawns++;
        if (board[i][j] == -1 && i >= 2 && i <= 5 && j >= 2 && j <= 5)
          numberOfCentrallyPositionedPawns--;
        // number of centrally positioned kings
        if (board[i][j] == 2 && i >= 2 && i <= 5 && j >= 2 && j <= 5)
          numberOfCentrallyPositionedKings++;
        if (board[i][j] == -2 && i >= 2 && i <= 5 && j >= 2 && j <= 5)
          numberOfCentrallyPositionedKings--;
        // number of pawns positioned on the main diagonal
        if (board[i][j] == 1 && i + j == 7) numberOfPawnsOnMainDiagonal++;
        if (board[i][j] == -1 && i + j == 7) numberOfPawnsOnMainDiagonal--;
        // number of kings positioned on the main diagonal
        if (board[i][j] == 2 && i + j == 7) numberOfKingsOnMainDiagonal++;
        if (board[i][j] == -2 && i + j == 7) numberOfKingsOnMainDiagonal--;
        // number of pawns positioned on the double diagonal
        if (board[i][j] == 1 && Math.abs(i - j) == 1) numberOfPawnsOnDoubleDiagonal++;
        if (board[i][j] == -1 && Math.abs(i - j) == 1) numberOfPawnsOnDoubleDiagonal--;
        // number of pawns positioned on the double diagonal
        if (board[i][j] == 2 && Math.abs(i - j) == 1) numberOfKingsOnDoubleDiagonal++;
        if (board[i][j] == -2 && Math.abs(i - j) == 1) numberOfKingsOnDoubleDiagonal--;
        // number of loner pawns
        if (board[i][j] == 1 &&
                (!insideBoard(i + 1, j + 1) || board[i + 1][j + 1] == 0) &&
                (!insideBoard(i + 1, j - 1) || board[i + 1][j - 1] == 0) &&
                (!insideBoard(i - 1, j + 1) || board[i - 1][j + 1] == 0) &&
                (!insideBoard(i - 1, j - 1) || board[i - 1][j - 1] == 0))
          numberOfLonerPawn++;
        if (board[i][j] == -1 &&
                (!insideBoard(i + 1, j + 1) || board[i + 1][j + 1] == 0) &&
                (!insideBoard(i + 1, j - 1) || board[i + 1][j - 1] == 0) &&
                (!insideBoard(i - 1, j + 1) || board[i - 1][j + 1] == 0) &&
                (!insideBoard(i - 1, j - 1) || board[i - 1][j - 1] == 0))
          numberOfLonerPawn--;
        // number of loner kings
        if (board[i][j] == 2 &&
                (!insideBoard(i + 1, j + 1) || board[i + 1][j + 1] == 0) &&
                (!insideBoard(i + 1, j - 1) || board[i + 1][j - 1] == 0) &&
                (!insideBoard(i - 1, j + 1) || board[i - 1][j + 1] == 0) &&
                (!insideBoard(i - 1, j - 1) || board[i - 1][j - 1] == 0))
          numberOfLonerKings++;
        if (board[i][j] == -2 &&
                (!insideBoard(i + 1, j + 1) || board[i + 1][j + 1] == 0) &&
                (!insideBoard(i + 1, j - 1) || board[i + 1][j - 1] == 0) &&
                (!insideBoard(i - 1, j + 1) || board[i - 1][j + 1] == 0) &&
                (!insideBoard(i - 1, j - 1) || board[i - 1][j - 1] == 0))
          numberOfLonerKings--;
        // Number of holes
        if (board[i][j] == 0 && (i & 1) == (j & 1) &&
                ((!insideBoard(i + 1, j + 1) || board[i + 1][j + 1] > 0) ? 1 : 0) +
                        ((!insideBoard(i + 1, j - 1) || board[i + 1][j - 1] > 0) ? 1 :
                                0) +
                        ((!insideBoard(i - 1, j + 1) || board[i - 1][j + 1] > 0) ? 1 :
                                0) +
                        ((!insideBoard(i - 1, j - 1) || board[i - 1][j - 1] > 0) ? 1 :
                                0) >= 3) numberOfHoles++;
        if (board[i][j] == 0 && (i & 1) == (j & 1) &&
                ((!insideBoard(i + 1, j + 1) || board[i + 1][j + 1] < 0) ? 1 : 0) +
                        ((!insideBoard(i + 1, j - 1) || board[i + 1][j - 1] < 0) ? 1 :
                                0) +
                        ((!insideBoard(i - 1, j + 1) || board[i - 1][j + 1] < 0) ? 1 :
                                0) +
                        ((!insideBoard(i - 1, j - 1) || board[i - 1][j - 1] < 0) ? 1 :
                                0) >= 3) numberOfHoles--;
      }
    }
    if (board[7][2] > 0 && board[7][4] > 0) bridgePattern++;
    if (board[0][1] < 0 && board[0][3] < 0) bridgePattern--;

    int numberOfPawns = numberOfYourPawns - numberOfEnemyPawns;
    int numberOfKings = numberOfYourKings - numberOfEnemyKings;

    if (numberOfYourPawns + numberOfYourKings == 0) {
      numberOfPawns = -1000;
    }
    if (numberOfEnemyPawns + numberOfEnemyKings == 0) {
      numberOfPawns = 1000;
    }

    int[] param =
            new int[]{numberOfPawns,
                    numberOfKings,
                    numberOfSavePawns,
                    numberOfSaveKings,
                    numberOfMovablePawns,
                    numberOfMovableKings,
                    distanceOfPawnsToKingLine,
                    numberOfUnoccupiedSquaresOnKingLine,
                    numberOfDefenderPieces,
                    numberOfAttackingPawns,
                    numberOfCentrallyPositionedPawns,
                    numberOfCentrallyPositionedKings,
                    numberOfPawnsOnMainDiagonal,
                    numberOfKingsOnMainDiagonal,
                    numberOfPawnsOnDoubleDiagonal,
                    numberOfKingsOnDoubleDiagonal,
                    numberOfLonerPawn,
                    numberOfLonerKings,
                    bridgePattern,
                    numberOfHoles};


    // setting difficulty array

    if (GlobalVar.difficulty == 2) { //hard AI
      int[] h =
              new int[]{20, 80, 3, 10, 7, 20, 2, 8, 12, 12, 7, 20, 4, 8, 4, 8, 6, 10, 20,
                      20};
      difficulty = h;
    } else if (GlobalVar.difficulty == 1) { // medium AI
      int[] m = new int[20];
      Arrays.fill(m, 1);
      difficulty = m;

    } else { // random AI
      int[] r = new int[20];
      Random randParam = new Random();

      for (int i = 0; i < param.length; i++) {
        int random = randParam.nextInt(50) + 5;
        r[i] = random;
      }
      difficulty = r;
    }


    int result = 0;
    for (int i = 0; i < param.length; i++) {
      result += param[i] * difficulty[i];
    }

    return result;
  }

}
/*
2,5,0,2,2,3,0,0,2,2,3,3,0,0,0,0,2,3,0,2
Medium - all multiply by 1
 */