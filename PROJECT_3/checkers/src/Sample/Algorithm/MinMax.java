package Sample.Algorithm;

// TODO: game over inside first if statement

import Sample.AI.AllMoves;
import Sample.AI.Evaluation;

import java.util.ArrayList;

public class MinMax {
  public static Integer[][] minmax(Integer[][] position, int depth, Integer[][] alpha,
                                   Integer[][] beta,
                                   boolean maximizing) {
    if (alpha == null && beta == null) {
      alpha = new Integer[8][8];
      for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
          alpha[i][j] = -2;
      beta = new Integer[8][8];
      for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
          beta[i][j] = 2;
    }
    if (depth == 0) return position;

    if (maximizing) {
      int maxEval = Integer.MIN_VALUE;
      Integer[][] res = null;
      AllMoves allMoves = new AllMoves(position, 1);
      ArrayList<Integer[][]> children = allMoves.getPossibleMoves();
      Integer[][] to_return = position;
      for (Integer[][] child : children) {
        Integer[][] eval = minmax(copyArray(child), depth - 1, copyArray(alpha),
                copyArray(beta),
                false);
        int evalScore = new Evaluation(eval).evaluate();
        if (maxEval < evalScore) {
          maxEval = evalScore;
          res = eval;
          to_return = child;
        }
        if (new Evaluation(alpha).evaluate() < evalScore)
          alpha = eval;
        if (new Evaluation(beta).evaluate() <= new Evaluation(alpha).evaluate())
          break;
      }
      return to_return;
    } else {
      int minEval = Integer.MAX_VALUE;
      Integer[][] res = null;
      AllMoves allMoves = new AllMoves(position, -1);
      ArrayList<Integer[][]> children = allMoves.getPossibleMoves();
      Integer[][] to_return = position;
      for (Integer[][] child : children) {
        Integer[][] eval = minmax(copyArray(child), depth - 1, copyArray(alpha), copyArray(beta),
                true);
        int evalScore = new Evaluation(eval).evaluate();
        if (evalScore < minEval) {
          minEval = evalScore;
          res = eval;
          to_return = child;
        }
        if (evalScore < new Evaluation(beta).evaluate())
          beta = eval;
        if (new Evaluation(beta).evaluate() <= new Evaluation(alpha).evaluate())
          break;
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
