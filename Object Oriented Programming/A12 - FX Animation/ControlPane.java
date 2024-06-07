package application;

//Assignment #: 12
//Name: Vincent Latona
//Description: The ControlPane class creates panes and
//    control panes that control their movement.

import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.geometry.Orientation;


public class ControlPane extends StackPane
{
private int width, height;
private int paneNum;

//The constructor creates panes and
//control panes that control their movement, and organize them using layouts
public ControlPane(int width, int height)
{
this.width = width;
this.height = height;
paneNum = 2; //the number of panes

//create 2 panes to control the movement
TextControlPane[] textPanes;
textPanes = new TextControlPane[paneNum];
textPanes[0] = new TextControlPane(width, height/paneNum, Color.RED, "Hello");
textPanes[1] = new TextControlPane(width, height/paneNum, Color.BLUE, "Hello");

GridPane pane1 = new GridPane();

//add two panes into this control panel using GridPane
for (int i = 0; i < paneNum; i++)
 pane1.add(textPanes[i], 0, i);

this.getChildren().add(pane1);
}
}