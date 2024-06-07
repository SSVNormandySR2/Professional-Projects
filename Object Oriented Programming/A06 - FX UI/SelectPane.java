package application;

//Name: Vincent Latona
//Time took you to complete the assignment: 3 hours 32 minutes
//Description: SelectPane displays a list of available clubs
//from which a user can select and compute their total number of members.

import javafx.scene.control.Label;
import javafx.scene.control.CheckBox;
import javafx.scene.layout.*;
import javafx.event.ActionEvent; //**Need to import
import javafx.event.EventHandler; //**Need to import
import java.util.ArrayList;
import javafx.collections.ObservableList;
import javafx.scene.Node;

//Packages imported in addition to those provided
import javafx.scene.control.*;

//SelectPane class creates the layout for tab 2 in the Assignment6 class
public class SelectPane extends BorderPane 
{
	
	//Creation of instance variables, layouts, and nodes
	private ArrayList<Club> clubList;
	private ArrayList<CheckBox> boxList;
	private VBox boxHolder;
	private CheckBox box;
	private ScrollPane scroller;
	private Label select;
	private Label totalMembers;
	private int sum;
	private SelectionHandler handler;

	/**
	 * This is the constructor for the SelectPane class, setting up the layout for
	 * the Assignment6 class
	 */
	public SelectPane(ArrayList<Club> list) 
	{
		//initialize instance variables
		this.clubList = list;

		//Label creation
		select = new Label("Select some clubs");
		totalMembers = new Label("The total number of members for the selected club(s): 0");
		
		//Handler instantiation
		handler = new SelectionHandler();

		//VBox to hold check boxes
		boxHolder = new VBox();
		
		//ArrayList to hold check boxes
		boxList = new ArrayList<CheckBox>();
		
		//Scroller to hold the VBox
		scroller = new ScrollPane(boxHolder);
		
		//Set node positioning
		this.setTop(select);
		this.setCenter(scroller);
		this.setBottom(totalMembers);
		
		this.getChildren().addAll();

	}//End of constructor
	

	/**
	 * This method creates and add check boxes to the VBox and associates them with
	 * the handler
	 */
	public void updateClubList(Club newClub) 
	{
		
		//CheckBox creation
		box = new CheckBox(newClub.toString());
		
		//Add the check box to the check box list
		boxList.add(box);
		
		//Handler association
		box.setOnAction(handler);
		
		//Add the check box to the VBox
		boxHolder.getChildren().add(box);
		
	}//End of updateClubList method

	//SelectionHandler class handles check box events
	private class SelectionHandler implements EventHandler<ActionEvent> 
	{
		
		/**
		 This method handles events for the check boxes
		 */
		public void handle(ActionEvent event) 
		{
			
			//Reset the member sum
			sum = 0;
			
			//Loop to check for checked boxes
			for (int i = 0; i < boxList.size(); i++)
			{
				
				//Case for when a check box is selected
				if (boxList.get(i).isSelected())
				{
					
					//Update the sum
					sum += clubList.get(i).getNumberOfMembers();
					
				}//End of selected case
				
			}//End of check box checker loop
			
			//Update the member label
			totalMembers.setText("The total number of members for the selected club(s): " + sum);
			
		}//End of handle method
		
	}//End of SelectHandler class
	
}//End of SelectPane class