import java.io.FileWriter;
import java.io.IOException;

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

public class UserPortal_Appointment extends BorderPane {

	Label title, fName, lName, height, weight, bp, pharmacy;

	TextField firstName, lastName, patientHeight, patientWeight, patientBP, pharmacyName;

	Label message, message2;

	Button createApt;

	Label allergy, concern, meds;
	ComboBox<String> allergies;
	ComboBox<String> concerns;
	ComboBox<String> medications;

	Appointment apt;
	Patient p;

	GridPane gPane;
	VBox vPane;

	public UserPortal_Appointment() {

		title = new Label("Appointment");

		fName = new Label("First Name: ");
		lName = new Label("Last Name: ");
		height = new Label("Patient Height: ");
		weight = new Label("Patient Weight: ");
		bp = new Label("Patient Blood Pressure: ");
		// date = new Label("Appointment Date: ");
		// time = new Label("Appointment Time: ");
		allergy = new Label("Allergy: ");
		concern = new Label("Concern: ");
		meds = new Label("Medications: ");
		pharmacy = new Label("Pharmacy: ");

		firstName = new TextField();
		lastName = new TextField();
		patientHeight = new TextField();
		patientWeight = new TextField();
		patientBP = new TextField();
		pharmacyName = new TextField();

		allergies = new ComboBox<String>();
		allergies.getItems().addAll("Animal", "Nuts", "Grass/Tree");
		allergies.setPromptText("--Select--");
		// allergies.setOnAction(new AllergiesHandler());

		concerns = new ComboBox<String>();
		concerns.getItems().addAll("Headache", "Fever", "Covid-19");
		concerns.setPromptText("--Select--");
		// concerns.setOnAction(new ConcernHandler());

		medications = new ComboBox<String>();
		medications.getItems().addAll("Tylenol", "Ibuprofen", "Shot");
		medications.setPromptText("--Select--");
		// medications.setOnAction(new MedHandler());

		createApt = new Button("Create Appointment");
		createApt.setOnAction(new ButtonHandler());

		message = new Label();
		message2 = new Label();

		gPane = new GridPane();
		gPane.setPadding(new Insets(40, 40, 40, 40));
		gPane.setHgap(30);
		gPane.setVgap(30);

		gPane.add(fName, 0, 0);
		gPane.add(firstName, 1, 0);
		gPane.add(lName, 2, 0);
		gPane.add(lastName, 3, 0);
		gPane.add(height, 0, 1);
		gPane.add(patientHeight, 1, 1);
		gPane.add(weight, 2, 1);
		gPane.add(patientWeight, 3, 1);
		gPane.add(bp, 0, 2);
		gPane.add(patientBP, 1, 2);
		gPane.add(allergy, 0, 3);
		gPane.add(allergies, 1, 3);
		gPane.add(concern, 2, 3);
		gPane.add(concerns, 3, 3);
		gPane.add(meds, 0, 4);
		gPane.add(medications, 1, 4);
		gPane.add(pharmacy, 2, 4);
		gPane.add(pharmacyName, 3, 4);

		vPane = new VBox();
		vPane.setSpacing(20);
		vPane.setPadding(new Insets(100, 100, 100, 100));
		vPane.setAlignment(Pos.CENTER);
		vPane.getChildren().addAll(title, gPane, createApt, message, message2);

		this.setCenter(vPane);

	}

	private class ButtonHandler implements EventHandler<ActionEvent> {

		public void handle(ActionEvent event) {

			if (firstName.getText().isEmpty() || lastName.getText().isEmpty() || patientHeight.getText().isEmpty()
					|| patientWeight.getText().isEmpty() || patientBP.getText().isEmpty()
					|| allergies.getValue().isEmpty() || concerns.getValue().isEmpty()
					|| medications.getValue().isEmpty()) {

				message.setText("Incomplete Fields Detected");
				message.setTextFill(Color.RED);

			} else {
				/*
				 * apt.addAllergy(allergies.getValue()); apt.addConcern(concerns.getValue());
				 * apt.addMed(medications.getValue());
				 */

				message.setText("Appointment Created");
				message.setTextFill(Color.GREEN);
				message2.setText(medications.getValue() + " sent to " + pharmacyName.getText());
				message2.setTextFill(Color.GREEN);

				// System.out.println(allergies.getValue());
				// System.out.println(concerns.getValue());
				// System.out.println(medications.getValue());

				try {

					FileWriter myFile = new FileWriter("Patient_Appointment.txt");

					apt = new Appointment(patientHeight.getText(), patientWeight.getText(), patientBP.getText(), p);

					myFile.write("Patient Name: " + firstName.getText() + " " + lastName.getText());
					myFile.write("\nPatient Allergies: " + allergies.getValue());
					myFile.write("\nPatient Concerns: " + concerns.getValue());
					myFile.write("\nPatient Medications: " + medications.getValue());

					myFile.close();

					System.out.println("Wrote to Patient_Appointment successfully");

				} catch (IOException e) {
					e.printStackTrace();

				}
			}

			/*
			 * p.setFName(firstName.getText()); p.setLName(lastName.getText());
			 * 
			 * apt.setHeight(patientHeight.getText());
			 * apt.setWeight(patientWeight.getText()); apt.setBP(patientBP.getText());
			 * apt.setPatient(p);
			 * 
			 * apt.addAllergy(allergies.getValue()); apt.addConcern(concerns.getValue());
			 * apt.addMed(medications.getValue()); apt.setSummary(apt.createSummary());
			 */

			firstName.setText("");
			lastName.setText("");
			patientHeight.setText("");
			patientWeight.setText("");
			patientBP.setText("");
			allergies.setValue("--Select--");
			concerns.setValue("--Select--");
			medications.setValue("--Select--");
			pharmacyName.setText("");

		}
	}
}
