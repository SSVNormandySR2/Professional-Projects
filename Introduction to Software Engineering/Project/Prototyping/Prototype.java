package application;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Prototype extends Application{

	private Prototype_LogInPane pane;
	
	@Override
	public void start(Stage stage) {
		// TODO Auto-generated method stub
		
		Prototype_LogInPane pane = new Prototype_LogInPane();		
		
	    Scene scene = new Scene(pane, 500, 500);
		stage.setTitle("Portal Log In");
		stage.setScene(scene);
		stage.show();
	}
	
	public static void main(String[] args) {
		Application.launch(args);
	}
	

}
