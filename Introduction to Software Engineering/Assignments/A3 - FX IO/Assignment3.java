/*
 * Assignment 3
 * Vincent Latona
 */

package application;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;

/*
 * This class constructs the GUI for the credit card application
 */
public class Assignment3 extends Application
{
	
	//Private data
	private applicationPane root;
	
	/*
	 * This method constructs the stage for the GUI application
	 */
	public void start(Stage stage)
	{
		
		//Set up GUI presentation
		root = new applicationPane();
		Scene scene = new Scene(root, 500, 400);
		stage.setTitle("SunDevil Credit Application");
		stage.setScene(scene);
		stage.show();
		
	}//End of method start
	
	/*
	 * This method executes the GUI application
	 */
	public static void main(String[] args)
	{
		
		//Launch args
		launch(args);
		
	}//End of method main

}//End of class Assignment3