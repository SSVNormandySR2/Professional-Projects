package application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;

public class Prototype_LogInPane extends BorderPane {

	Label title, userID, password;
	TextField userIDInput, passwordInput;
	
	Button logIn;
	
	HBox hPane, hPane2;
	VBox vPane;
	BorderPane bPane;
	
	public Prototype_LogInPane() {
		
		title = new Label("Portal Log In: ");
		userID = new Label("Enter User ID: ");
		password = new Label("Enter Password: ");
		
		userIDInput = new TextField();
		passwordInput = new TextField();
		
		logIn = new Button("Log In");
		//logIn.setPadding(new Insets(10, 20, 10, 20));
		logIn.setOnAction(new ButtonHandler());

		hPane = new HBox();
		hPane.setSpacing(34);
		hPane.getChildren().addAll(userID, userIDInput);
		
		hPane2 = new HBox();
		hPane2.setSpacing(20);
		hPane2.getChildren().addAll(password, passwordInput);
		
		vPane = new VBox();
		vPane.setSpacing(20);
		vPane.setPadding(new Insets(100, 50, 10, 100));
		vPane.getChildren().addAll(title, hPane, hPane2, logIn);
	
		
		/*bPane = new BorderPane();
		bPane.setTop(title);
		bPane.setCenter(vPane);
		bPane.setBottom(logIn);
		
		this.getChildren().add(bPane);
		this.setPrefSize(500, 500);*/
		
		//this.setTop(title);
		this.setCenter(vPane);
		//this.setBottom(logIn);
		
		
	}
	
	private class ButtonHandler implements EventHandler<ActionEvent> {

		@Override
		public void handle(ActionEvent event) {

			
			
		}	
	}
}