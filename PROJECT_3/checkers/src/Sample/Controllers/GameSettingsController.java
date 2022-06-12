package Sample.Controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Objects;
import java.util.Random;

public class GameSettingsController {
  @FXML
  Parent root;
  @FXML
  Stage stage;
  @FXML
  public Text id_difficulty;
  @FXML
  public Text id_depth;

  @FXML
  public void initialize() throws FileNotFoundException {
    if (GlobalVar.difficulty == 0) {
      id_difficulty.setText("Random fiesta");
    } else if (GlobalVar.difficulty == 1) {
      id_difficulty.setText("Mid");
    } else {
      id_difficulty.setText("Hard");
    }
    id_depth.setText(Integer.toString(GlobalVar.depth));
    Sample.Controllers.NeutralScreenController.yourPieces = 12;
    Sample.Controllers.NeutralScreenController.enemyPieces = 12;
  }

  @FXML
  protected void upDifficulty() {
    if (GlobalVar.difficulty < 2) GlobalVar.difficulty++;
    if (GlobalVar.difficulty == 1) id_difficulty.setText("Mid");
    else id_difficulty.setText("Hard");
  }

  @FXML
  protected void downDifficulty() {
    if (GlobalVar.difficulty > 0) GlobalVar.difficulty--;
    if (GlobalVar.difficulty == 1) id_difficulty.setText("Mid");
    else id_difficulty.setText("Random fiesta");
  }

  @FXML
  protected void upDepth() {
    if (GlobalVar.depth < 6) GlobalVar.depth += 2;
    id_depth.setText(Integer.toString(GlobalVar.depth));
  }

  @FXML
  protected void downDepth() {
    if (GlobalVar.depth > 2) GlobalVar.depth -= 2;
    id_depth.setText(Integer.toString(GlobalVar.depth));
  }

  @FXML
  protected void toGame(ActionEvent e) throws IOException {
    if (GlobalVar.color == GlobalVar.Color.none) chosenColorWB();
    root = FXMLLoader.load(
            Objects.requireNonNull(getClass().getResource("/Scenes/NeutralScreen.fxml")));
    stage = (Stage) ((Node) e.getSource()).getScene().getWindow();
    stage.setScene(new Scene(root));
    stage.show();
  }

  @FXML
  protected void back(ActionEvent e) throws IOException {
    GlobalVar.difficulty = 1;
    GlobalVar.depth = 4;
    root = FXMLLoader.load(
            Objects.requireNonNull(getClass().getResource("/Scenes/Menu.fxml")));
    stage = (Stage) ((Node) e.getSource()).getScene().getWindow();
    stage.setScene(new Scene(root));
    stage.show();
  }

  @FXML
  protected void chosenColorB() throws IOException {
    GlobalVar.color = GlobalVar.Color.black;
  }

  public void chosenColorW() {
    GlobalVar.color = GlobalVar.Color.white;
  }

  public void chosenColorWB() throws IOException {
    Random rand = new Random();
    int draw = rand.nextInt(2);
    switch (draw) {
      case 0: {
        chosenColorB();
        break;
      }
      case 1: {
        chosenColorW();
        break;
      }
    }
  }
}
