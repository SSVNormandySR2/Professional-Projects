import java.io.File;
import java.io.IOException;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Tab;
import javafx.scene.control.TabPane;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class HospitalSystem extends Application {

	private TabPane tPane;
	private StackPane rootPane;
	private LogInPane logInPane;
	private Create_Account createAccountPane;

	@Override
	public void start(Stage stage) {
		// TODO Auto-generated method stub

		rootPane = new StackPane();


		Create_Account createAccountPane = new Create_Account();

		LogInPane logInPane = new LogInPane();
		
		UserPortal_Appointment apt = new UserPortal_Appointment();

		HistoryPane hist = new HistoryPane();

		tPane = new TabPane();
		Tab tab1 = new Tab();
		tab1.setText("Create Account");
		tab1.setContent(createAccountPane);

		Tab tab2 = new Tab();
		tab2.setText("Log In");
		tab2.setContent(logInPane);

		Tab tab3 = new Tab();
		tab3.setText("Appointment");
		tab3.setContent(apt);
		
		Tab tab4 = new Tab();
		tab4.setText("History");
		tab4.setContent(hist);

		tPane.getSelectionModel().select(0);
		tPane.getTabs().addAll(tab1, tab2, tab3, tab4);

		rootPane.getChildren().add(tPane);

		Scene scene = new Scene(rootPane, 1000, 700);
		stage.setTitle("Portal Log In");
		stage.setScene(scene);
		stage.show();
	}

	public static void main(String[] args) {
		Application.launch(args);
		
	}
}
