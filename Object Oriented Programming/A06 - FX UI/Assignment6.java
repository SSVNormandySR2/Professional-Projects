package application;

//Name: Vincent Latona
//Description: The Assignment6 class creates a Tabbed Pane with
//    two tabs, one for Club Creation and one for
//    Club Selection.

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Tab;
import javafx.scene.control.TabPane;
import javafx.scene.layout.StackPane;
import java.util.ArrayList;

public class Assignment6 extends Application
{
private TabPane tabPane;
private CreatePane createPane;
private SelectPane selectPane;
private ArrayList<Club> clubList;

public void start(Stage stage)
{
StackPane root = new StackPane();

//clubList to be used in both createPane & selectPane
clubList = new ArrayList<Club>();

selectPane = new SelectPane(clubList);
createPane = new CreatePane(clubList, selectPane);

tabPane = new TabPane();

Tab tab1 = new Tab();
tab1.setText("Club Creation");
tab1.setContent(createPane);

Tab tab2 = new Tab();
tab2.setText("Club Selection");
tab2.setContent(selectPane);

tabPane.getSelectionModel().select(0);
tabPane.getTabs().addAll(tab1, tab2);

root.getChildren().add(tabPane);

Scene scene = new Scene(root, 900, 400);
stage.setTitle("Club Selection Apps");
stage.setScene(scene);
stage.show();
}

public static void main(String[] args)
{
launch(args);
}
}