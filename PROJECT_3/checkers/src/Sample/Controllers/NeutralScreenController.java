package Sample.Controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.*;

import static java.lang.Math.abs;
import static java.lang.Math.min;
import static Sample.Controllers.GameFunctions.*;

public class NeutralScreenController {
  @FXML
  Parent root;
  @FXML
  Stage stage;
  @FXML
  public Button aa;
  @FXML
  public Button ab;
  @FXML
  public Button ac;
  @FXML
  public Button ad;
  @FXML
  public Button ae;
  @FXML
  public Button af;
  @FXML
  public Button ag;
  @FXML
  public Button ah;
  @FXML
  public Button ba;
  @FXML
  public Button bb;
  @FXML
  public Button bc;
  @FXML
  public Button bd;
  @FXML
  public Button be;
  @FXML
  public Button bf;
  @FXML
  public Button bg;
  @FXML
  public Button bh;
  @FXML
  public Button ca;
  @FXML
  public Button cb;
  @FXML
  public Button cc;
  @FXML
  public Button cd;
  @FXML
  public Button ce;
  @FXML
  public Button cf;
  @FXML
  public Button cg;
  @FXML
  public Button ch;
  @FXML
  public Button da;
  @FXML
  public Button db;
  @FXML
  public Button dc;
  @FXML
  public Button dd;
  @FXML
  public Button de;
  @FXML
  public Button df;
  @FXML
  public Button dg;
  @FXML
  public Button dh;
  @FXML
  public Button ea;
  @FXML
  public Button eb;
  @FXML
  public Button ec;
  @FXML
  public Button ed;
  @FXML
  public Button ee;
  @FXML
  public Button ef;
  @FXML
  public Button eg;
  @FXML
  public Button eh;
  @FXML
  public Button fa;
  @FXML
  public Button fb;
  @FXML
  public Button fc;
  @FXML
  public Button fd;
  @FXML
  public Button fe;
  @FXML
  public Button ff;
  @FXML
  public Button fg;
  @FXML
  public Button fh;
  @FXML
  public Button ga;
  @FXML
  public Button gb;
  @FXML
  public Button gc;
  @FXML
  public Button gd;
  @FXML
  public Button ge;
  @FXML
  public Button gf;
  @FXML
  public Button gg;
  @FXML
  public Button gh;
  @FXML
  public Button ha;
  @FXML
  public Button hb;
  @FXML
  public Button hc;
  @FXML
  public Button hd;
  @FXML
  public Button he;
  @FXML
  public Button hf;
  @FXML
  public Button hg;
  @FXML
  public Button hh;

  @FXML
  Text yourPiecesLeft;
  @FXML
  Text enemyPiecesLeft;

  public static ArrayList<ArrayList<Button>> button;
  public static int[][] dirsForward;
  public static int[][] dirsBackward;
  public static Square clicked;
  public static ArrayList<Square> green;
  public static int turn;
  public static String yourColorPawn;
  public static String yourColorKing;
  public static String enemyColorPawn;
  public static String enemyColorKing;
  public static String greenSquare = "-fx-background-color: #a4b545";
  public static String whiteSquare = "-fx-background-color: #f0d9b5;";
  public static String blackSquare = "-fx-background-color: #b58863;";
  public static String dark_brown = "-fx-background-color: #825634";
  public static String previous_move = "-fx-background-color: #b59f8d";
  public static String whitePawn = "-fx-graphic: url('file:../." +
          "./images/pieces/in_game/wp" +
          ".png');";
  public static String blackPawn = "-fx-graphic: url('file:../." +
          "./images/pieces/in_game/bp" +
          ".png');";
  public static String whiteKing = "-fx-graphic: url('file:../." +
          "./images/pieces/in_game/wk" +
          ".png');";
  public static String blackKing = "-fx-graphic: url('file:../." +
          "./images/pieces/in_game/bk" +
          ".png');";
  public static int yourTurn;
  public static int yourPieces = 12;
  public static int enemyPieces = 12;


  @FXML
  public void initialize() throws FileNotFoundException {
    button = new ArrayList<>(
            Arrays.asList(new ArrayList<>(Arrays.asList(aa, ab, ac, ad, ae, af, ag, ah)),
                    new ArrayList<>(Arrays.asList(ba, bb, bc, bd, be, bf, bg, bh)),
                    new ArrayList<>(Arrays.asList(ca, cb, cc, cd, ce, cf, cg, ch)),
                    new ArrayList<>(Arrays.asList(da, db, dc, dd, de, df, dg, dh)),
                    new ArrayList<>(Arrays.asList(ea, eb, ec, ed, ee, ef, eg, eh)),
                    new ArrayList<>(Arrays.asList(fa, fb, fc, fd, fe, ff, fg, fh)),
                    new ArrayList<>(Arrays.asList(ga, gb, gc, gd, ge, gf, gg, gh)),
                    new ArrayList<>(Arrays.asList(ha, hb, hc, hd, he, hf, hg, hh))));

    clicked = null;
    green = new ArrayList<>();
    dirsForward = new int[][]{{-1, -1}, {-1, 1}};
    dirsBackward = new int[][]{{1, -1}, {1, 1}};
    yourTurn = GlobalVar.color == GlobalVar.Color.white ? 1 : 0;
    turn = 1;

    yourColorPawn = yourTurn == 1 ? whitePawn : blackPawn;
    yourColorKing = yourTurn == 1 ? whiteKing : blackKing;
    enemyColorPawn = yourTurn == 0 ? whitePawn : blackPawn;
    enemyColorKing = yourTurn == 0 ? whiteKing : blackKing;

    init_board();
  }

  @FXML
  public void toExit(ActionEvent e) throws IOException {
    root = FXMLLoader.load(
            Objects.requireNonNull(getClass().getResource("/Scenes/GameSettings.fxml")));
    stage = (Stage) ((Node) e.getSource()).getScene().getWindow();
    stage.setScene(new Scene(root));
    stage.show();
  }

  @FXML
  public void toMove(ActionEvent e, int i) throws IOException {

    //end of game
    if (yourPieces == 0 || enemyPieces == 0) {
      GlobalVar.result_ = yourPieces == 0 ? GlobalVar.Result.LOSE : GlobalVar.Result.WIN;
      toEndOfGame(e);
    }
    if (turn != yourTurn) {
      // bot move
      Integer[][] move = Sample.Algorithm.MinMax.minmax(boardPosition(), GlobalVar.depth,
              Integer.MIN_VALUE, Integer.MAX_VALUE,
              false);
      Integer[][] currentPosition = boardPosition();
      boolean aiMoved = false;
      if (move == null) {
        GlobalVar.result_ = GlobalVar.Result.TIE;
        System.out.println("NULL");
        toEndOfGame(e);
        return;
      }
      yourPieces = 0;
      enemyPieces = 0;
      //changing board - color fill
      for (int a = 0; a < 8; a++) {
        for (int b = 0; b < 8; b++) {
          if (!Objects.equals(move[a][b], currentPosition[a][b])) aiMoved = true;
          if ((a & 1) == (b & 1)) continue;
          if (move[a][b] == 0) {
            button.get(a).get(b).setId("empty");
            button.get(a).get(b).setStyle((move[a][b].equals(currentPosition[a][b]) ?
                    blackSquare : previous_move));
          } else if (move[a][b] == 1) {
            button.get(a).get(b).setId(Integer.toString(yourTurn));
            button.get(a).get(b)
                    .setStyle(yourColorPawn + (move[a][b].equals(currentPosition[a][b]) ?
                            blackSquare : previous_move));
            yourPieces++;
          } else if (move[a][b] == 2) {
            button.get(a).get(b).setId(Integer.toString(yourTurn + 2));
            button.get(a).get(b).setStyle(yourColorKing + (move[a][b].equals(currentPosition[a][b]) ?
                    blackSquare : previous_move));
            yourPieces++;
          } else if (move[a][b] == -1 && a != 7) {
            button.get(a).get(b).setId(Integer.toString(1 - yourTurn));
            button.get(a).get(b).setStyle(enemyColorPawn + (move[a][b].equals(currentPosition[a][b]) ?
                    blackSquare : previous_move));
            enemyPieces++;
          } else if (move[a][b] == -1 && a == 7) { // promotion to king
            button.get(a).get(b).setId(Integer.toString(3 - yourTurn));
            button.get(a).get(b).setStyle(enemyColorKing + (move[a][b].equals(currentPosition[a][b]) ?
                    blackSquare : previous_move));
            enemyPieces++;
          } else if (move[a][b] == -2) {
            button.get(a).get(b).setId(Integer.toString(3 - yourTurn));
            button.get(a).get(b).setStyle(enemyColorKing + (move[a][b].equals(currentPosition[a][b]) ?
                    blackSquare : previous_move));
            enemyPieces++;
          }
        }
      }
      turn = yourTurn;
      yourPiecesLeft.setText(String.valueOf(yourPieces));
      enemyPiecesLeft.setText(String.valueOf(enemyPieces));
      //end of game occur
      if (!aiMoved) {
        if (new Sample.AI.AllMoves(boardPosition(), 1).getPossibleMoves().isEmpty())
          GlobalVar.result_ = GlobalVar.Result.TIE;
        else GlobalVar.result_ = GlobalVar.Result.WIN;
        try {
          Thread.sleep(3000);
        } catch (InterruptedException ex) {
          throw new RuntimeException(ex);
        }
        toEndOfGame(e);
      } else if (yourPieces == 0) {
        GlobalVar.result_ = GlobalVar.Result.LOSE;
        try {
          Thread.sleep(3000);
        } catch (InterruptedException ex) {
          throw new RuntimeException(ex);
        }
        toEndOfGame(e);
      } else if (enemyPieces == 0) {
        GlobalVar.result_ = GlobalVar.Result.WIN;
        try {
          Thread.sleep(3000);
        } catch (InterruptedException ex) {
          throw new RuntimeException(ex);
        }
        toEndOfGame(e);
      } else if (new Sample.AI.AllMoves(boardPosition(), 1).getPossibleMoves().isEmpty()) {
        GlobalVar.result_ = GlobalVar.Result.LOSE;
        try {
          Thread.sleep(3000);
        } catch (InterruptedException ex) {
          throw new RuntimeException(ex);
        }
        toEndOfGame(e);
      }
      else {
        //checking if any king left
        Integer[][] temp = boardPosition();
        int pawnsLeft=0;
        int kingsLeft=0;
        for (int a = 0; a < 8; a++) {
          for (int b = 0; b < 8; b++) {
            if (Math.abs(temp[a][b])==2) kingsLeft++;
            if (Math.abs(temp[a][b])==1) pawnsLeft++;
          }
        }
        if(kingsLeft == 2 && pawnsLeft == 0) {
          GlobalVar.result_ = GlobalVar.Result.TIE;
          try {
            Thread.sleep(3000);
          } catch (InterruptedException ex) {
            throw new RuntimeException(ex);
          }
          toEndOfGame(e);
        }
      }
      return;
    }
    //setting coordinates of button
    int j = i % 8;
    i = i / 8;

    //clearing green squares
    for (Square square : green) {
      button.get(square.getX()).get(square.getY()).setStyle(blackSquare);
    }
    if (clicked != null && (button.get(clicked.getX()).get(clicked.getY()).getId()
            .equals(Integer.toString(turn)) ||
            button.get(clicked.getX()).get(clicked.getY()).getId()
                    .equals(Integer.toString(turn + 2))))
      button.get(clicked.getX()).get(clicked.getY()).setStyle(
              button.get(clicked.getX()).get(clicked.getY()).getStyle().substring(0, 60) +
                      blackSquare);

    boolean move = false;

    //move of pawn
    for (Square square : green) {
      if (square.getX() != i || square.getY() != j) continue;
      move = true;

      int signX = clicked.getX() < square.getX() ? 1 : -1;
      int signY = clicked.getY() < square.getY() ? 1 : -1;

      for (int iter = 1; iter < abs(square.getX() - clicked.getX()); iter++) {
        if (!button.get(clicked.getX() + iter * signX).get(clicked.getY() + iter * signY)
                .getId().equals("empty")) {
          if (turn == yourTurn) enemyPieces--;
          else yourPieces--;
          yourPiecesLeft.setText(String.valueOf(yourPieces));
          enemyPiecesLeft.setText(String.valueOf(enemyPieces));
        }
        button.get(clicked.getX() + iter * signX).get(clicked.getY() + iter * signY)
                .setStyle(blackSquare);
        button.get(clicked.getX() + iter * signX).get(clicked.getY() + iter * signY)
                .setId("empty");
      }

      //swap button - move
      Button temp = new Button();
      temp.setStyle(button.get(i).get(j).getStyle());
      temp.setId(button.get(i).get(j).getId());
      button.get(i).get(j)
              .setStyle(button.get(clicked.getX()).get(clicked.getY()).getStyle());
      button.get(i).get(j).setId(button.get(clicked.getX()).get(clicked.getY()).getId());
      button.get(clicked.getX()).get(clicked.getY()).setStyle(temp.getStyle());
      button.get(clicked.getX()).get(clicked.getY()).setId(temp.getId());

      //promotion to king
      if (i == 0 && turn == yourTurn) {
        button.get(i).get(j)
                .setStyle(turn == 1 ? whiteKing + blackSquare : blackKing + blackSquare);
        button.get(i).get(j).setId(Integer.toString(turn + 2));
      } else if (i == 7 && turn != yourTurn) {
        button.get(i).get(j)
                .setStyle(turn == 1 ? whiteKing + blackSquare : blackKing + blackSquare);
        button.get(i).get(j).setId(Integer.toString(turn + 2));
      }
      clicked = new Square(i, j);
    }

    if (move) turn = 1 - turn;
    green.clear();


    if (move || (!button.get(i).get(j).getId().equals(Integer.toString(turn)) &&
            !button.get(i).get(j).getId().equals(Integer.toString(turn + 2)))) {
      return;
    }
    //showing possible move squares
    directionForward(i, j);
    directionBackward(i, j);

    button.get(i).get(j)
            .setStyle(button.get(i).get(j).getStyle().substring(0, 60) + dark_brown);
    clicked = new Square(i, j);
  }

  /**
   * Method to call end of game
   *
   * @param e - action
   * @throws IOException
   */
  void toEndOfGame(ActionEvent e) throws IOException {
    root = FXMLLoader.load(
            Objects.requireNonNull(getClass().getResource("/Scenes/EndGameScreen.fxml")));
    stage = (Stage) ((Node) e.getSource()).getScene().getWindow();
    stage.setScene(new Scene(root));
    stage.show();
  }

  /**
   * Initialize the board with pieces and colors
   */
  public void init_board() {
    for (int i = 0; i < 8; i++) {
      //button.add(new ArrayList<>());
      for (int j = 0; j < 8; j++) {
        if (i % 2 == j % 2) {
          button.get(i).get(j).setStyle(whiteSquare);
          button.get(i).get(j).setId("empty");

        } else if (i == 3 || i == 4) {
          button.get(i).get(j).setStyle(blackSquare); //brown square
          button.get(i).get(j).setId("empty");

        } else if ((yourTurn == 1 && i > 4) || (yourTurn == 0 && i < 3)) {
          button.get(i).get(j).setStyle(whitePawn + blackSquare); //white piece
          button.get(i).get(j).setId(Integer.toString(turn));

        } else {
          button.get(i).get(j).setStyle(blackPawn + blackSquare); //black piece
          button.get(i).get(j).setId(Integer.toString(1 - turn));
        }
      }
    }
  }


  @FXML
  public void toMoveAA(ActionEvent e) throws IOException {
    toMove(e, 0);
  }

  @FXML
  public void toMoveAB(ActionEvent e) throws IOException {
    toMove(e, 1);
  }

  @FXML
  public void toMoveAC(ActionEvent e) throws IOException {
    toMove(e, 2);
  }

  @FXML
  public void toMoveAD(ActionEvent e) throws IOException {
    toMove(e, 3);
  }

  @FXML
  public void toMoveAE(ActionEvent e) throws IOException {
    toMove(e, 4);
  }

  @FXML
  public void toMoveAF(ActionEvent e) throws IOException {
    toMove(e, 5);
  }

  @FXML
  public void toMoveAG(ActionEvent e) throws IOException {
    toMove(e, 6);
  }

  @FXML
  public void toMoveAH(ActionEvent e) throws IOException {
    toMove(e, 7);
  }

  @FXML
  public void toMoveBA(ActionEvent e) throws IOException {
    toMove(e, 8);
  }

  @FXML
  public void toMoveBB(ActionEvent e) throws IOException {
    toMove(e, 9);
  }

  @FXML
  public void toMoveBC(ActionEvent e) throws IOException {
    toMove(e, 10);
  }

  @FXML
  public void toMoveBD(ActionEvent e) throws IOException {
    toMove(e, 11);
  }

  @FXML
  public void toMoveBE(ActionEvent e) throws IOException {
    toMove(e, 12);
  }

  @FXML
  public void toMoveBF(ActionEvent e) throws IOException {
    toMove(e, 13);
  }

  @FXML
  public void toMoveBG(ActionEvent e) throws IOException {
    toMove(e, 14);
  }

  @FXML
  public void toMoveBH(ActionEvent e) throws IOException {
    toMove(e, 15);
  }

  @FXML
  public void toMoveCA(ActionEvent e) throws IOException {
    toMove(e, 16);
  }

  @FXML
  public void toMoveCB(ActionEvent e) throws IOException {
    toMove(e, 17);
  }

  @FXML
  public void toMoveCC(ActionEvent e) throws IOException {
    toMove(e, 18);
  }

  @FXML
  public void toMoveCD(ActionEvent e) throws IOException {
    toMove(e, 19);
  }

  @FXML
  public void toMoveCE(ActionEvent e) throws IOException {
    toMove(e, 20);
  }

  @FXML
  public void toMoveCF(ActionEvent e) throws IOException {
    toMove(e, 21);
  }

  @FXML
  public void toMoveCG(ActionEvent e) throws IOException {
    toMove(e, 22);
  }

  @FXML
  public void toMoveCH(ActionEvent e) throws IOException {
    toMove(e, 23);
  }

  @FXML
  public void toMoveDA(ActionEvent e) throws IOException {
    toMove(e, 24);
  }

  @FXML
  public void toMoveDB(ActionEvent e) throws IOException {
    toMove(e, 25);
  }

  @FXML
  public void toMoveDC(ActionEvent e) throws IOException {
    toMove(e, 26);
  }

  @FXML
  public void toMoveDD(ActionEvent e) throws IOException {
    toMove(e, 27);
  }

  @FXML
  public void toMoveDE(ActionEvent e) throws IOException {
    toMove(e, 28);
  }

  @FXML
  public void toMoveDF(ActionEvent e) throws IOException {
    toMove(e, 29);
  }

  @FXML
  public void toMoveDG(ActionEvent e) throws IOException {
    toMove(e, 30);
  }

  @FXML
  public void toMoveDH(ActionEvent e) throws IOException {
    toMove(e, 31);
  }

  @FXML
  public void toMoveEA(ActionEvent e) throws IOException {
    toMove(e, 32);
  }

  @FXML
  public void toMoveEB(ActionEvent e) throws IOException {
    toMove(e, 33);
  }

  @FXML
  public void toMoveEC(ActionEvent e) throws IOException {
    toMove(e, 34);
  }

  @FXML
  public void toMoveED(ActionEvent e) throws IOException {
    toMove(e, 35);
  }

  @FXML
  public void toMoveEE(ActionEvent e) throws IOException {
    toMove(e, 36);
  }

  @FXML
  public void toMoveEF(ActionEvent e) throws IOException {
    toMove(e, 37);
  }

  @FXML
  public void toMoveEG(ActionEvent e) throws IOException {
    toMove(e, 38);
  }

  @FXML
  public void toMoveEH(ActionEvent e) throws IOException {
    toMove(e, 39);
  }

  @FXML
  public void toMoveFA(ActionEvent e) throws IOException {
    toMove(e, 40);
  }

  @FXML
  public void toMoveFB(ActionEvent e) throws IOException {
    toMove(e, 41);
  }

  @FXML
  public void toMoveFC(ActionEvent e) throws IOException {
    toMove(e, 42);
  }

  @FXML
  public void toMoveFD(ActionEvent e) throws IOException {
    toMove(e, 43);
  }

  @FXML
  public void toMoveFE(ActionEvent e) throws IOException {
    toMove(e, 44);
  }

  @FXML
  public void toMoveFF(ActionEvent e) throws IOException {
    toMove(e, 45);
  }

  @FXML
  public void toMoveFG(ActionEvent e) throws IOException {
    toMove(e, 46);
  }

  @FXML
  public void toMoveFH(ActionEvent e) throws IOException {
    toMove(e, 47);
  }

  @FXML
  public void toMoveGA(ActionEvent e) throws IOException {
    toMove(e, 48);
  }

  @FXML
  public void toMoveGB(ActionEvent e) throws IOException {
    toMove(e, 49);
  }

  @FXML
  public void toMoveGC(ActionEvent e) throws IOException {
    toMove(e, 50);
  }

  @FXML
  public void toMoveGD(ActionEvent e) throws IOException {
    toMove(e, 51);
  }

  @FXML
  public void toMoveGE(ActionEvent e) throws IOException {
    toMove(e, 52);
  }

  @FXML
  public void toMoveGF(ActionEvent e) throws IOException {
    toMove(e, 53);
  }

  @FXML
  public void toMoveGG(ActionEvent e) throws IOException {
    toMove(e, 54);
  }

  @FXML
  public void toMoveGH(ActionEvent e) throws IOException {
    toMove(e, 55);
  }

  @FXML
  public void toMoveHA(ActionEvent e) throws IOException {
    toMove(e, 56);
  }

  @FXML
  public void toMoveHB(ActionEvent e) throws IOException {
    toMove(e, 57);
  }

  @FXML
  public void toMoveHC(ActionEvent e) throws IOException {
    toMove(e, 58);
  }

  @FXML
  public void toMoveHD(ActionEvent e) throws IOException {
    toMove(e, 59);
  }

  @FXML
  public void toMoveHE(ActionEvent e) throws IOException {
    toMove(e, 60);
  }

  @FXML
  public void toMoveHF(ActionEvent e) throws IOException {
    toMove(e, 61);
  }

  @FXML
  public void toMoveHG(ActionEvent e) throws IOException {
    toMove(e, 62);
  }

  @FXML
  public void toMoveHH(ActionEvent e) throws IOException {
    toMove(e, 63);
  }

}