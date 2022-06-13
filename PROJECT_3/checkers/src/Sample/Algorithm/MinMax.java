package Sample.Algorithm;

// TODO: game over inside first if statement

import Sample.AI.AllMoves;
import Sample.AI.Evaluation;

import java.util.ArrayList;

public class MinMax {
  public static Integer[][] minmax(Integer[][] position, int depth, Integer alpha,
                                   Integer beta, boolean maximizing) {

    if (depth == 0) return position;

    if (maximizing) {
      int maxEval = Integer.MIN_VALUE;
      Integer[][] res = null;
      AllMoves allMoves = new AllMoves(position, 1);
      ArrayList<Integer[][]> children = allMoves.getPossibleMoves();
      Integer[][] to_return = position;
      for (Integer[][] child : children) {
        Integer[][] eval = minmax(copyArray(child), depth - 1, alpha, beta, false);
        int evalScore = new Evaluation(eval).evaluate();
        if (maxEval < evalScore) {
          maxEval = evalScore;
          res = eval;
          to_return = child;
        }
        if (alpha < evalScore) alpha = evalScore;
        if (beta <= alpha) break;
      }
      return to_return;
    } else {
      int minEval = Integer.MAX_VALUE;
      Integer[][] res = null;
      AllMoves allMoves = new AllMoves(position, -1);
      ArrayList<Integer[][]> children = allMoves.getPossibleMoves();
      Integer[][] to_return = position;
      for (Integer[][] child : children) {
        Integer[][] eval = minmax(copyArray(child), depth - 1, alpha, beta, true);
        int evalScore = new Evaluation(eval).evaluate();
        if (evalScore < minEval) {
          minEval = evalScore;
          res = eval;
          to_return = child;
        }
        if (evalScore < beta) beta = evalScore;
        if (beta <= alpha) break;
      }
      return to_return;
    }
  }

  static Integer[][] copyArray(Integer[][] array) {
    Integer[][] newArray = new Integer[8][8];
    for (int a = 0; a < 8; a++)
      for (int b = 0; b < 8; b++)
        newArray[a][b] = array[a][b];
    return newArray;
  }
}
