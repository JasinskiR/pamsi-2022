package Sample.Controllers;

import javafx.stage.Stage;

import java.io.Serializable;
import java.util.Random;

public class GlobalVar {

  static public Stage mainStage;

  // RESULT SHOWN AT THE END GAME SCREEN
  static public Result result_;

  // SETTINGS
  static public int difficulty = 1;
  static public int depth = 4;
  // SETTINGS
  public static String currentError =
          "Everything seems to be fine. This shouldn't have happened.";

  // COLORS
  public enum Color {
    black,
    white,
    none;
  }

  public static Color color = Color.none;
  static Random r = new Random();



  // ALL POSSIBLE RESULTS
  enum Result {
    WIN, LOSE, TIE;
  }

  public static class Settings implements Serializable {
    public String text;
    public int difficulty;
    public int depth;

    Settings(String text, int difficulty, int depth) {
      this.text = text;
      this.difficulty = difficulty;
      this.depth = depth;
    }

    public String getText() {
      return text;
    }

  }
}
