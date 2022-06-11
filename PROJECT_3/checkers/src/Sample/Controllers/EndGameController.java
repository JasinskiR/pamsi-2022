package Sample.Controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.Objects;

public class EndGameController {
  String win = "You have achieved a victory!";
  String lose = "Oops. . .\n You did not make that this time.\nTry again or leave as defeated one!";
  String tie = "It's seems it was a nice duel. Who will win this next time ?";
  Color blue = Color.rgb(0, 85, 130);
  Color red = Color.rgb(156, 0, 0);
  @FXML
  Text to_be_shown;
  @FXML
  public void initialize() {
    if (GlobalVar.result_ == GlobalVar.Result.WIN) {
      to_be_shown.setText(win);
      to_be_shown.setFill(blue);
    }
    else if (GlobalVar.result_ == GlobalVar.Result.LOSE) {
      to_be_shown.setText(lose);
      to_be_shown.setFill(red);
    }
    else if (GlobalVar.result_ == GlobalVar.Result.TIE) {
      to_be_shown.setText(tie);
      to_be_shown.setFill(Color.YELLOW);
    }
  }
  @FXML
  public void toGame(ActionEvent event) throws IOException {
    FXMLLoader loader = new FXMLLoader(getClass().getResource("/Scenes/NeutralScreen.fxml"));
    Parent root = loader.load();
    Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
    stage.setScene(new Scene(root));
    stage.show();
  }
  @FXML
  protected void back(ActionEvent e) throws IOException {
    GlobalVar.difficulty = 1;
    Parent root = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("/Scenes/Menu.fxml")));
    Stage stage = (Stage)((Node)e.getSource()).getScene().getWindow();
    stage.setScene(new Scene(root));
    stage.show();
  }
}
