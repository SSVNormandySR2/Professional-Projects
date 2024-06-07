import java.io.FileWriter;
import java.io.IOException;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;

public class Create_Account extends BorderPane {

	Label title, firstName, lastName, phoneNumber, dateOfBirth, email, createUserID, createPassword;
	TextField fName, lName, pNumber, dob, e, userID;
	PasswordField password;

	Label message;
	Button createAccount;

	private ComboBox<String> profession;
	Label professionLabel;
	GridPane gPane;
	VBox vPane;

	TextArea patientListArea;
	HBox pPane;

	public Create_Account() {

		title = new Label("Create Account");

		firstName = new Label("First Name: ");
		lastName = new Label("Last Name: ");
		phoneNumber = new Label("Phone Number: ");
		dateOfBirth = new Label("Date of Birth: ");
		email = new Label("Email: ");
		createUserID = new Label("User ID: ");
		createPassword = new Label("Password: ");

		fName = new TextField();
		lName = new TextField();
		pNumber = new TextField();
		dob = new TextField();
		e = new TextField();
		userID = new TextField();
		password = new PasswordField();

		createAccount = new Button("Create Account");
		createAccount.setOnAction(new ButtonHandler());

		professionLabel = new Label("Profession: ");

		profession = new ComboBox<String>();
		profession.getItems().addAll("Doctor", "Nurse", "Patient");
		profession.setPromptText("--Select--");
		// profession.setOnAction(new ButtonHandler());

		message = new Label();

		gPane = new GridPane();
		gPane.setPadding(new Insets(40, 40, 40, 40));
		gPane.setHgap(30);
		gPane.setVgap(30);

		gPane.add(firstName, 0, 0);
		gPane.add(fName, 1, 0);
		gPane.add(lastName, 2, 0);
		gPane.add(lName, 3, 0);
		gPane.add(phoneNumber, 0, 1);
		gPane.add(pNumber, 1, 1);
		gPane.add(dateOfBirth, 2, 1);
		gPane.add(dob, 3, 1);
		gPane.add(createUserID, 0, 2);
		gPane.add(userID, 1, 2);
		gPane.add(createPassword, 2, 2);
		gPane.add(password, 3, 2);
		gPane.add(email, 0, 3);
		gPane.add(e, 1, 3);
		gPane.add(professionLabel, 2, 3);
		gPane.add(profession, 3, 3);

		vPane = new VBox();
		vPane.setSpacing(20);
		vPane.setPadding(new Insets(100, 100, 100, 100));
		vPane.setAlignment(Pos.CENTER);
		vPane.getChildren().addAll(title, gPane, createAccount, message);

		/*
		 * pPane = new HBox(); patientListArea = new TextArea();
		 * patientListArea.setText("No Patients");
		 * pPane.getChildren().add(patientListArea);
		 */

		this.setCenter(vPane);
		// this.setRight(pPane);
	}

	public class ButtonHandler implements EventHandler<ActionEvent> {

		@Override
		public void handle(ActionEvent event) {

			if (fName.getText().toString().isEmpty() || lName.getText().toString().isEmpty()
					|| dob.getText().toString().isEmpty() || userID.getText().toString().isEmpty()
					|| password.getText().toString().isEmpty() || pNumber.getText().toString().isEmpty()
					|| e.getText().toString().isEmpty()) {

				message.setText("Incomplete Fields Detected");
				message.setTextFill(Color.RED);

			} else if (profession.getValue().isEmpty()) {

				message.setText("Incomplete Fields Detected");
				message.setTextFill(Color.RED);

			} else {
				message.setText("Account Created");
				message.setTextFill(Color.GREEN);

				// System.out.println(profession.getValue());

			}

			if (profession.getValue().equalsIgnoreCase("Patient")) {

				try {

					FileWriter myFile = new FileWriter("Patient_file.txt");

					Patient p = new Patient(false, false, true, fName.getText(), lName.getText(), dob.getText(),
							userID.getText(), password.getText(), pNumber.getText(), e.getText());

					myFile.write(userID.getText() + "\n");
					myFile.write(password.getText() + "\n");

					myFile.write(p.toString());
					myFile.close();

					System.out.println("Wrote to file successfully");

				} catch (IOException e) {
					e.printStackTrace();
				}

			} else if (profession.getValue().equalsIgnoreCase("Doctor")) {

				try {

					FileWriter myFile = new FileWriter("Doctor_File.txt");

					Doctor d = new Doctor(fName.getText(), lName.getText(), dob.getText(), userID.getText(),
							password.getText(), pNumber.getText(), e.getText());

					myFile.write(userID.getText() + "\n");
					myFile.write(password.getText() + "\n");

					myFile.write(d.toString());
					myFile.close();

					System.out.println("Wrote to file successfully");

				} catch (IOException e) {
					e.printStackTrace();
				}

			} else if (profession.getValue().equalsIgnoreCase("Nurse")) {

				try {

					FileWriter myFile = new FileWriter("Nurse_file.txt");

					Nurse n = new Nurse(fName.getText(), lName.getText(), dob.getText(), userID.getText(),
							password.getText(), pNumber.getText(), e.getText());

					myFile.write(userID.getText() + "\n");
					myFile.write(password.getText() + "\n");

					myFile.write(n.toString());
					myFile.close();

					System.out.println("Wrote to file successfully");

				} catch (IOException e) {
					e.printStackTrace();
				}

			}

			fName.setText("");
			lName.setText("");
			dob.setText("");
			userID.setText("");
			password.setText("");
			pNumber.setText("");
			e.setText("");
			profession.setValue("--Select--");

		}
	}
}
