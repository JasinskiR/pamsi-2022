package Sample.Controllers;

public class Square {
  private int x;
  private int y;

  protected int getX() {
    return x;
  }

  protected int getY() {
    return y;
  }

  Square(int x, int y) {
    this.x = x;
    this.y = y;
  }
}
