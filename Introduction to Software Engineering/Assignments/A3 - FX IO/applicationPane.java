/*
 * Assignment 3
 * Vincent Latona
 */

package application;
import java.io.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.scene.paint.Color;
import javafx.geometry.*;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;

/*
 * This class constructs the pane for the GUI application
 */
public class applicationPane extends Pane
{
	
	//Private Panes and Nodes
	private BorderPane root;
	private GridPane grid;
	private VBox fNameFields;
	private VBox lNameFields;
	private VBox custIDFields;
	private VBox phoneFields;
	private VBox addressFields;
	private VBox savingsAcctFields;
	private VBox checkingAcctFields;
	private VBox appHolder;
	private VBox messageHolder;
	private VBox cancelHolder;
	private VBox saveHolder;
	private Label app;
	private Label message;
	private Label fName;
	private TextField fNameField;
	private Label lName;
	private TextField lNameField;
	private Label custID;
	private TextField custIDField;
	private Label phone;
	private TextField phoneField;
	private Label address;
	private TextField addressField;
	private Label savings;
	private TextField savingsField;
	private Label checking;
	private TextField checkingField;
	private Button cancelButton;
	private Button saveButton;
	private CancelHandle cancelHandle;
	private SaveHandle saveHandle;
	
	/*
	 * This constructor constructs the Panes and Nodes
	 */
	public applicationPane()
	{
		
		//Pane and Node instantiation
		root = new BorderPane();
		grid = new GridPane();
		fNameFields = new VBox();
		lNameFields = new VBox();
		custIDFields = new VBox();
		phoneFields = new VBox();
		addressFields = new VBox();
		savingsAcctFields = new VBox();
		checkingAcctFields = new VBox();
		appHolder = new VBox();
		messageHolder = new VBox();
		cancelHolder = new VBox();
		saveHolder = new VBox();
		app = new Label("Credit Card Application Form: SunDevil Bank");
		message = new Label("");
		fName = new Label("First Name:");
		lName = new Label("Last Name:");
		custID = new Label("Customer ID: (4-digit Integer)");
		phone = new Label("Phone Number:");
		address = new Label("Address:");
		savings = new Label("Savings Account Number: (Integer)");
		checking = new Label("Checking Account Number: (Integer)");
		cancelButton = new Button("Cancel");
		saveButton = new Button("Save");
		cancelHandle = new CancelHandle();
		saveHandle = new SaveHandle();
		fNameField = new TextField("");
		lNameField = new TextField("");
		custIDField = new TextField("");
		phoneField = new TextField("");
		addressField = new TextField("");
		savingsField = new TextField("");
		checkingField = new TextField("");
		
		//Set alignment of each container and node
		grid.setAlignment(Pos.CENTER);
		fNameFields.setAlignment(Pos.CENTER);
		lNameFields.setAlignment(Pos.CENTER);
		custIDFields.setAlignment(Pos.CENTER);
		phoneFields.setAlignment(Pos.CENTER);
		addressFields.setAlignment(Pos.CENTER);
		savingsAcctFields.setAlignment(Pos.CENTER);
		checkingAcctFields.setAlignment(Pos.CENTER);
		cancelHolder.setAlignment(Pos.CENTER);
		saveHolder.setAlignment(Pos.CENTER);
		appHolder.setAlignment(Pos.CENTER);
		messageHolder.setAlignment(Pos.CENTER);
		
		//Fill VBoxes with their proper contents
		fNameFields.getChildren().addAll(fName, fNameField);
		lNameFields.getChildren().addAll(lName, lNameField);
		custIDFields.getChildren().addAll(custID, custIDField);
		phoneFields.getChildren().addAll(phone, phoneField);
		addressFields.getChildren().addAll(address, addressField);
		savingsAcctFields.getChildren().addAll(savings, savingsField);
		checkingAcctFields.getChildren().addAll(checking, checkingField);
		appHolder.getChildren().addAll(app);
		messageHolder.getChildren().addAll(message);
		cancelHolder.getChildren().addAll(cancelButton);
		saveHolder.getChildren().addAll(saveButton);
		
		//Add VBoxes to grid and set gaps
		grid.setVgap(10);
		grid.setHgap(10);
		grid.add(fNameFields, 0, 0);
		grid.add(lNameFields, 1, 0);
		grid.add(custIDFields, 0, 1);
		grid.add(phoneFields, 1, 1);
		grid.add(addressFields, 0, 2);
		grid.add(savingsAcctFields, 0, 3);
		grid.add(checkingAcctFields, 1, 3);
		grid.add(cancelHolder, 0, 4);
		grid.add(saveHolder, 1, 4);
		
		//Bind buttons to handlers
		cancelButton.setOnAction(cancelHandle);
		saveButton.setOnAction(saveHandle);
		
		//Add children of root
		root.setTop(appHolder);
		root.setCenter(grid);
		root.setBottom(messageHolder);
		
		//Add children to presentation pane
		this.getChildren().addAll(root);
		
	}//End of constructor
	
	/*
	 * This class constructs a cancel button handler
	 */
	private class CancelHandle implements EventHandler<ActionEvent>
	{
		
		/*
		 * This method handles when the cancel button is pressed
		 */
		public void handle(ActionEvent event)
		{
			
			//Clear all text fields
			fNameField.clear();
			lNameField.clear();
			custIDField.clear();
			phoneField.clear();
			addressField.clear();
			savingsField.clear();
			checkingField.clear();
			
		}//End of method handle
		
	}//End of class CancelHandler
	
	/*
	 * This class constructs a cancel button handler
	 */
	private class SaveHandle implements EventHandler<ActionEvent>
	{
		
		/*
		 * This method handles when the save button is pressed
		 */
		public void handle(ActionEvent event)
		{
			
			//Empty fields check
			if(fNameField.getText().equals("") || lNameField.getText().equals("") ||
					custIDField.getText().equals("") || phoneField.getText().equals("") ||
					addressField.getText().equals("") || checkingField.getText().equals("") ||
					savingsField.getText().equals(""))
			{
				
				//Error message display
				message.setTextFill(Color.RED);
				message.setText("Error: Empty fields detected, file not written.");
				
			}//End of empty fields check
			
			//Wrong id length case
			else if(!(custIDField.getText().length() == 4))
			{
				
				//Error message display
				message.setTextFill(Color.RED);
				message.setText("Error: Incorrect Customer ID length.\n"
						+ "Please enter a 4-digit integer Customer ID.");
				
			}//End of wrong id length case
			
			//Write case
			else
			{
				
				//Test integer conversion
				try
				{
					
					//String to integer conversion
					int id = Integer.parseInt(custIDField.getText());
					int savings = Integer.parseInt(savingsField.getText());
					int checking = Integer.parseInt(checkingField.getText());
					
					//Attempt file writing
					try
					{
						
						//Create file writing objects
						String filename = fNameField.getText() + lNameField.getText() + custIDField.getText() + ".txt";
						FileWriter fileWrite = new FileWriter(filename);
						BufferedWriter bufferWrite = new BufferedWriter(fileWrite);
						PrintWriter print = new PrintWriter(bufferWrite);
						
						//Write application contents
						print.print("First Name: " + fNameField.getText() + "\n");
						print.print("Last Name: "+ lNameField.getText() + "\n");
						print.print("Customer ID: " + custIDField.getText() + "\n");
						print.print("Phone Number: " + phoneField.getText() + "\n");
						print.print("Address: " + addressField.getText() + "\n");
						print.print("Savings Account Number: " + savingsField.getText() + "\n");
						print.print("Checking Account Number: " + checkingField.getText() + "\n");
						
						//Close file
						print.close();
						
						//Successful write message
						message.setTextFill(Color.GREEN);
						message.setText("Success: Application successfully wirtten to file.");
						
					}//End of file writing
					
					//IOException case
					catch(IOException e)
					{
						
						//Error message display
						message.setTextFill(Color.RED);
						message.setText("Error: File not written.");
						
					}//End of IOException case
					
				}//End of integer conversion
				
				//Conversion error handle
				catch (NumberFormatException e)
				{
					
					//Error message display
					message.setTextFill(Color.RED);
					message.setText("Error: Some integer fields may not contain integers.");
					
				}//End of conversion error handle
				
			}//End of write case
			
		}//End of method handle
		
	}//End of class CancelHandler

}//End of class applicationPane