package application;

//Name: Vincent Latona
//Time took you to complete the assignment: 5 hours 33 minutes
//Description: CreatePane generates a pane where a user can enter
//a club information and create a list of available clubs.

import java.util.ArrayList;
import javafx.scene.layout.HBox;

import javafx.event.ActionEvent; //**Need to import
import javafx.event.EventHandler; //**Need to import

//Packages imported in addition to the provided imported packages
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.scene.paint.Color;
import javafx.geometry.Insets;
import javafx.geometry.Pos;

//CreatePane class creates the layout for tab 1 in the Assignment6 class
public class CreatePane extends HBox 
{
	ArrayList<Club> clubList;

	// The relationship between CreatePane and SelectPane is Aggregation
	private SelectPane selectPane;

	// Creation of instances of layouts and nodes
	private BorderPane root;
	private GridPane prompts;
	private VBox holder;
	private HBox bHolder;
	private Label actionLabel;
	private Label titleLabel;
	private Label membersLabel;
	private Label universityLabel;
	private TextField titleField;
	private TextField membersField;
	private TextField universityField;
	private Button createClub;
	private TextArea clubViewer;
	private ButtonHandler handler;

	/**
	 * This is the constructor for the CreatePane class, setting up the layout for
	 * the Assignment6 class
	 */
	public CreatePane(ArrayList<Club> list, SelectPane sePane) 
	{

		// Provided instantiation
		this.clubList = list;
		this.selectPane = sePane;

		// Layout and node instantiation
		root = new BorderPane();
		prompts = new GridPane();
		holder = new VBox();
		bHolder = new HBox();
		actionLabel = new Label("");
		titleLabel = new Label("Title");
		membersLabel = new Label("Number of Members");
		universityLabel = new Label("University");
		titleField = new TextField("");
		membersField = new TextField("");
		universityField = new TextField("");
		createClub = new Button("Create a Club");
		clubViewer = new TextArea("No Club");
		handler = new ButtonHandler();

		// Set alignments and spacing for the GridPane
		prompts.setAlignment(Pos.CENTER);
		prompts.setPadding(new Insets(10, 11, 12, 13));
		prompts.setVgap(10);
		prompts.setHgap(10);

		// Add labels to GridPane
		prompts.add(titleLabel, 0, 0);
		prompts.add(membersLabel, 0, 1);
		prompts.add(universityLabel, 0, 2);

		// Add text fields to GridPane
		prompts.add(titleField, 1, 0);
		prompts.add(membersField, 1, 1);
		prompts.add(universityField, 1, 2);

		// Creation of HBox for holding the button and its addition
		bHolder.setAlignment(Pos.CENTER);
		bHolder.getChildren().addAll(createClub);

		// Addition of GridPane and HBox for the VBox holder
		holder.getChildren().addAll(prompts, bHolder);

		// Addition of sub-panes to specific areas
		root.setCenter(holder);
		root.setRight(clubViewer);
		root.setTop(actionLabel);

		// Addition of the root pane to the class pane
		this.getChildren().addAll(root);

		// Make label red and put it in the top left
		actionLabel.setTextFill(Color.RED);

		// Link of the button to its handler
		createClub.setOnAction(handler);

	} //End of constructor

	// Private class to handle button events and errors
	private class ButtonHandler implements EventHandler<ActionEvent> 
	{
		/**
		 This method handles button errors and club addition
		 */
		public void handle(ActionEvent event) 
		{
			
			//Integer to verify the membersField and boolean to verify club addition
			int members = 0;
			boolean correct = true;

			//Blank textField errors
			if (titleField.getText().equals("") || membersField.getText().equals("")
					|| universityField.getText().equals("")) 
			{
				
				//Label alteration and boolean conversion
				correct = false;
				actionLabel.setText("Please fill all fields");

			}//End of blank text field error case
			
			//Case for all other errors
			else
			{
				
				//String to integer parser error
				try 
				{
					
					//String parsed to an integer
					members = Integer.parseInt(membersField.getText());
					
				}//End of try block
				
				//Error catch of NumberFormatException
				catch (NumberFormatException e) 
				{
					
					//Label alteration and boolean conversion
					correct = false;
					actionLabel.setText("Please enter an integer for a number of members");
					
				}//End of catch block

				//Loop to find duplicate clubs
				for (int i = 0; i < clubList.size(); i++) 
				{
					
					//Duplicate finder
					if (clubList.get(i).getClubName().equalsIgnoreCase(titleField.getText())) 
					{
						
						//Label alteration and boolean conversion
						actionLabel.setText("Club not added - duplicate");
						correct = false;
						
						//Loop-breaker
						break;
						
					}//End of duplicate finder
					
				}//End of duplicate-finder loop

			}//End of alternate error-handling
			
			//Addition of club to the text area and club creation/addition to the ArrayList
			if (correct == true) 
			{
				
				//Label alteration
				actionLabel.setText("Club added");
				
				//Club addition and creation
				Club newClub = new Club();
				newClub.setClubName(titleField.getText());
				newClub.setNumberOfMembers(members);
				newClub.setUniversity(universityField.getText());
				selectPane.updateClubList(newClub);
				clubList.add(newClub);
				
				//Alteration of text area
				if (clubViewer.getText().equals("No Club")) 
				{
					
					//Text area alteration
					clubViewer.setText("");
					
				}//End of text area alteration
				
				//Append next club after each successful creation
				clubViewer.appendText(newClub.toString());
				
			}//End of club addition and text area alteration

		}//End of handle method
		
	}//End of ButtonHandler class

}//End of CreatePane class