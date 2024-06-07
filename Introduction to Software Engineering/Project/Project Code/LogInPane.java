import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TabPane;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;

public class LogInPane extends BorderPane {

	String testUser = "";
	String testPass = "";
	String checkUser, checkPass;

	Label title, userID, password;
	TextField userIDInput;
	PasswordField passwordInput;

	Label message;
	Button logIn, createAccount;

	HBox hPane, hPane2;
	VBox vPane;
	TabPane tPane;
	GridPane gPane;

	public LogInPane() {

		title = new Label("Portal Log In: ");
		userID = new Label("Enter User ID: ");
		password = new Label("Enter Password: ");

		userIDInput = new TextField();
		passwordInput = new PasswordField();

		message = new Label();

		logIn = new Button("Log In");
		logIn.setOnAction(new ButtonHandler());

		/*
		 * hPane = new HBox(); hPane.setSpacing(34); hPane.getChildren().addAll(userID,
		 * userIDInput);
		 * 
		 * hPane2 = new HBox(); hPane2.setSpacing(34);
		 * hPane2.getChildren().addAll(password, passwordInput);
		 */

		gPane = new GridPane();
		gPane.setPadding(new Insets(40, 40, 40, 40));
		gPane.setHgap(30);
		gPane.setVgap(30);

		// gPane.add(title, 0, 1);
		gPane.add(userID, 0, 0);
		gPane.add(userIDInput, 1, 0);
		gPane.add(password, 0, 1);
		gPane.add(passwordInput, 1, 1);
		// gPane.add(logIn, 2, 4);
		// gPane.add(message, 2, 5);

		vPane = new VBox();
		vPane.setSpacing(20);
		vPane.setPadding(new Insets(100, 100, 100, 100));
		vPane.setAlignment(Pos.CENTER);
		vPane.getChildren().addAll(title, gPane, logIn, message);

		this.setCenter(vPane);

	}

	private class ButtonHandler implements EventHandler<ActionEvent> {

		@Override
		public void handle(ActionEvent event) {

			checkUser = userIDInput.getText().toString();
			checkPass = passwordInput.getText().toString();

			searchPatient();
			searchDoctor();
			searchNurse();

			if (checkUser.equals(testUser) && checkPass.equals(testPass)) {
				message.setText("Log in successful");
				message.setTextFill(Color.GREEN);
			} else {
				message.setText("Incorrect Username or Password");
				message.setTextFill(Color.RED);
			}

			userIDInput.setText("");
			passwordInput.setText("");
		}
	}

	public void searchPatient() {
		// BufferedReader myFile = new BufferedReader(
		// new FileReader("/Users/aryankhanna/Documents/ASU/CSE
		// 360/Test/Patient_file.txt"));

		try {
			String userID = Files
					.readAllLines(Paths.get("Patient_file.txt")).get(0);

			String password = Files
					.readAllLines(Paths.get("Patient_file.txt")).get(1);

			// System.out.println(userID);
			// System.out.println(password);

			if (userIDInput.getText().equalsIgnoreCase(userID) && passwordInput.getText().equalsIgnoreCase(password)) {

				testUser = userIDInput.getText();
				testPass = passwordInput.getText();
			}
			
			
			Patient p = new Patient();

		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	public void searchDoctor() {
		// BufferedReader myFile = new BufferedReader(
		// new FileReader("/Users/aryankhanna/Documents/ASU/CSE
		// 360/Test/Patient_file.txt"));

		try {
			String userID = Files
					.readAllLines(Paths.get("Doctor_file.txt")).get(0);

			String password = Files
					.readAllLines(Paths.get("Doctor_file.txt")).get(1);

			// System.out.println(userID);
			// System.out.println(password);

			if (userIDInput.getText().equalsIgnoreCase(userID) && passwordInput.getText().equalsIgnoreCase(password)) {

				testUser = userIDInput.getText();
				testPass = passwordInput.getText();
			}

		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	public void searchNurse() {
		// BufferedReader myFile = new BufferedReader(
		// new FileReader("/Users/aryankhanna/Documents/ASU/CSE
		// 360/Test/Patient_file.txt"));

		try {
			String userID = Files
					.readAllLines(Paths.get("Nurse_file.txt")).get(0);

			String password = Files
					.readAllLines(Paths.get("Nurse_file.txt")).get(1);

			// System.out.println(userID);
			// System.out.println(password);

			if (userIDInput.getText().equalsIgnoreCase(userID) && passwordInput.getText().equalsIgnoreCase(password)) {

				testUser = userIDInput.getText();
				testPass = passwordInput.getText();
			}

		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}
