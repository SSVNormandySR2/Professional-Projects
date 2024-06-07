import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;

public class HistoryPane extends BorderPane {

	String testUser = "";
	String testPass = "";

	Label title, firstName, lastName;
	TextField firstNameInput, lastNameInput;

	Label message;

	Button addHis;

	Label visit, vac, surgeries, famHis;

	ComboBox<String> visits;
	ComboBox<String> vaccines;
	ComboBox<String> surgery;
	ComboBox<String> family;

	GridPane gPane;
	VBox vPane;

	History his;

	public HistoryPane() {

		title = new Label("Patient History");

		firstName = new Label("First Name: ");
		lastName = new Label("Last Name: ");

		firstNameInput = new TextField();
		lastNameInput = new TextField();

		visit = new Label("Prior Visits");
		visits = new ComboBox<String>();
		visits.getItems().addAll("1 month ago", "6 months ago", "Over a year ago", "None");
		visits.setPromptText("--Select--");

		vac = new Label("Prior Vaccines");
		vaccines = new ComboBox<String>();
		vaccines.getItems().addAll("Covid-19", "Flu", "Tetanus", "None");
		vaccines.setPromptText("--Select--");

		surgeries = new Label("Prior Surgeries");
		surgery = new ComboBox<String>();
		surgery.getItems().addAll("No surgery", "Any prior surgery");
		surgery.setPromptText("--Select--");

		famHis = new Label("Family History");
		family = new ComboBox<String>();
		family.getItems().addAll("No family History", "Diabetes", "Cancer");
		family.setPromptText("--Select--");

		addHis = new Button("Add History");
		addHis.setOnAction(new ButtoneHandler());

		message = new Label();

		gPane = new GridPane();
		gPane.setPadding(new Insets(40, 40, 40, 40));
		gPane.setHgap(30);
		gPane.setVgap(30);

		gPane.add(firstName, 0, 0);
		gPane.add(firstNameInput, 1, 0);
		gPane.add(lastName, 2, 0);
		gPane.add(lastNameInput, 3, 0);
		gPane.add(visit, 0, 1);
		gPane.add(visits, 1, 1);
		gPane.add(vac, 2, 1);
		gPane.add(vaccines, 3, 1);
		gPane.add(surgeries, 0, 2);
		gPane.add(surgery, 1, 2);
		gPane.add(famHis, 2, 2);
		gPane.add(family, 3, 2);

		vPane = new VBox();
		vPane.setSpacing(20);
		vPane.setPadding(new Insets(100, 100, 100, 100));
		vPane.setAlignment(Pos.CENTER);
		vPane.getChildren().addAll(title, gPane, addHis, message);

		this.setCenter(vPane);

	}

	private class ButtoneHandler implements EventHandler<ActionEvent> {

		public void handle(ActionEvent event) {

			searchPatient();

			if (firstNameInput.getText().isEmpty() || lastNameInput.getText().isEmpty()) {

				message.setText("Incomplete Fields Detected");
				message.setTextFill(Color.RED);

			} else {

				message.setText("History Updated");
				message.setTextFill(Color.GREEN);

				try {

					FileWriter myFile = new FileWriter("Patient_History.txt");

					myFile.write("Patient Name " + firstNameInput.getText() + " " + lastNameInput.getText());
					myFile.write("\n\nImmunizations: ");
					myFile.write("\nPatient Visits: " + visits.getValue());
					myFile.write("\nPatient Vaccines: " + vaccines.getValue());
					myFile.write("\nPatient Surgeries: " + surgery.getValue());
					myFile.write("\nFamily History: " + family.getValue());

					myFile.close();
					
					System.out.println("Wrote to Patient_History file");
					
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			
			firstNameInput.setText("");
			lastNameInput.setText("");
			visits.setValue("--Select--");
			vaccines.setValue("--Select--");
			surgery.setValue("--Select--");
			family.setValue("--Select--");
		}
	}

	public void searchPatient() {

		try {
			String fName = Files.readAllLines(Paths.get("Patient_file.txt")).get(3);

			String lName = Files.readAllLines(Paths.get("Patient_file.txt")).get(4);

			// System.out.println(userID);
			// System.out.println(password);

			if (firstName.getText().equalsIgnoreCase(fName) && lastName.getText().equalsIgnoreCase(lName)) {

				testUser = firstName.getText();
				testPass = lastName.getText();
			}

			Patient p = new Patient();

		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
