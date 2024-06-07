package application;

//Name: Vincent Latona
//Time took you to complete the assignment: 3 hours 7 minutes
//Description: PaneWithRectangles class creates a pane where we can use
//    mouse key to drag on grids and there will be some color following
//    the mouse. We can also use combo boxes to change its colors and stroke widths

//Provided imports
import javafx.scene.control.Label;
import javafx.scene.control.ComboBox;
import javafx.scene.layout.*;
import javafx.scene.shape.Rectangle;
import javafx.scene.paint.Color;
import javafx.geometry.Insets;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.input.MouseEvent;

//PaneWithRectangles class establishes nodes and handles associated events with nested classes 
public class PaneWithRectangles extends BorderPane 
{
	
	//Provided instance variables
	private ComboBox<String> primaryColorCombo;
	private ComboBox<String> backColorCombo;
	private ComboBox<String> widthCombo;

	private Color primaryColor, secondaryColor, backgroundColor;
	private double selectWidth;

	private Rectangle[][] rectArray;
	
	//Created instance variables
	private Rectangle rectangle;
	private Label primaryComboLabel;
	private Label backComboLabel;
	private Label widthComboLabel;
	private GridPane grid;
	
	/**
	 * This is the constructor of the PaneWithRectangles class, applying the layout
	 * for the class
	 */
	public PaneWithRectangles() 
	{
		primaryColor = Color.BLACK;
		secondaryColor = Color.GRAY;
		backgroundColor = Color.WHITE;
		selectWidth = 1.0;
		
		rectArray = new Rectangle[7][7];

		//ComboBox instantiation
		primaryColorCombo = new ComboBox<String>();
		backColorCombo = new ComboBox<String>();
		widthCombo = new ComboBox<String>();
		
		//ComboBox label instantiation
		primaryComboLabel = new Label("PrimaryColor");
		backComboLabel = new Label("BackgroundColor");
		widthComboLabel = new Label("StrokeWidth");
		
		//Addition of options to combo-boxes and setting of default values
		primaryColorCombo.getItems().addAll("Black" , "Blue" , "Red" , "Green");
		primaryColorCombo.setValue("Black");
		backColorCombo.getItems().addAll("White", "Yellow", "Orange");
		backColorCombo.setValue("White");
		widthCombo.getItems().addAll("1" , "3" , "5" , "7");
		widthCombo.setValue("1");

		//Loop variable initialization
		double xStartPixel = 0.0;
		double yStartPixel = 0.0;
		final double RECT_WIDTH = 470/7;
		final double RECT_HEIGHT = 390/7;
		
		//Nested loops to fill an array with rectangles
		//Outer loop to enter array rows
		for (int r = 0; r < rectArray.length; r++)
		{
			
			//Inner loop to create and assign individual elements
			for (int c = 0; c < rectArray[r].length; c++)
			{
				
				//Create and set parameters for a new rectangle
				rectangle = new Rectangle(xStartPixel, yStartPixel, RECT_WIDTH, RECT_HEIGHT);
				rectangle.setFill(Color.WHITE);
				rectangle.setStroke(Color.BLACK);
				rectangle.setStrokeWidth(1);
				
				//Add the rectangle to the array
				rectArray[r][c] = rectangle;
				
				//Define the new x-pixel starting point for the next rectangle
				xStartPixel += RECT_WIDTH;
				
				//Reset the x-pixel starting point for the next row
				if (c == rectArray[r].length-1)
				{
					
					xStartPixel = 0.0;
					
				}//End of x-pixel reset
				
			}//End of rectangle creation inner loop
			
			//Define the y-pixel starting point for the next row
			yStartPixel += RECT_HEIGHT;
			
		}//End of rectangle creation outer loop
		

		//grid is a GridPane containing 49 rectangles.
		grid = new GridPane();
		
		//Nested loops to fill the grid pane
		//Outer loop for rows
		for (int r = 0; r < rectArray.length; r++)
		{
			
			//Inner loop for columns and addition to grid
			for (int c = 0; c < rectArray[r].length; c++)
			{
				
				//GridPane addition
				grid.add(rectArray[r][c], c, r);
				
			}//End of inner loop
			
		}//End of outer loop

		//leftPane is a VBox, it should contain labels and combo boxes
		VBox leftPane = new VBox();
		leftPane.setSpacing(20);
		leftPane.setPadding(new Insets(10, 0, 10, 0));
		
		leftPane.getChildren().addAll(primaryComboLabel, primaryColorCombo, backComboLabel, 
				backColorCombo, widthComboLabel, widthCombo);

		//add the left pane to the left of the pane
		//and the grid pane contains rectangles at the center
		this.setLeft(leftPane);
		this.setCenter(grid);

		//register/link the source nodes with its handler objects
		grid.setOnMouseDragged(new MouseHandler());
		primaryColorCombo.setOnAction(new PrimColorHandler());
		backColorCombo.setOnAction(new BackColorHandler());
		widthCombo.setOnAction(new WidthHandler());

	}//End of constructor

	//A handler class used to handle mouse events
	private class MouseHandler implements EventHandler<MouseEvent> 
	{
		
		/**
		 * This method handles mouse events, altering the color of the rectangle wher
		 * the mouse was dragged
		 */
		public void handle(MouseEvent event) 
		{
			
			//Object to hold the event source
			Object src = event.getSource();
			
			//Evaluate if event and source are correct
			if(event.getEventType() == MouseEvent.MOUSE_DRAGGED && src == grid)
			{
				
				//Try to find an ArrayIndexOutOfBoundsException
				try
				{
					
					//X and Y locations of the mouse
					double x = event.getX();
					double y = event.getY();
					
					//Nested loops to change background color
					//Outer loop for rows
					for (int r = 0; r < rectArray.length; r++)
					{
						
						//Inner loop for element color change
						for (int c = 0; c < rectArray[r].length; c++)
						{
							
							//Element color conversion
							rectArray[r][c].setFill(backgroundColor);
							
						}//End of inner loop
						
					}//End of outer loop
					
					//Nested loop to evaluate where the mouse is dragged
					//Outer loop for each row
					for (int r = 0; r < rectArray.length; r++)
					{
						
						//Inner loop for each column and element
						for (int c = 0; c < rectArray[r].length; c++)
						{
							
							//Evaluation of mouse location within range of a rectangle's occupied space
							if ((x >= rectArray[r][c].getX()) && (x <= rectArray[r][c].getX()+470/7)
									&& (y >= rectArray[r][c].getY()) && (y <= rectArray[r][c].getY()+390/7))
							{
								
								//Upper right-rectangle alteration
								if (c == 6 && r == 0)
								{
									
									//Rectangle alteration
									rectArray[r][c].setFill(primaryColor);
									rectArray[r][c-1].setFill(secondaryColor);
									rectArray[r+1][c].setFill(secondaryColor);
									
								}//End of upper right-rectangle alteration
								
								//Lower right-rectangle alteration
								if (c == 6 && r == 6)
								{
									
									//Rectangle alteration
									rectArray[r][c].setFill(primaryColor);
									rectArray[r][c-1].setFill(secondaryColor);
									rectArray[r-1][c].setFill(secondaryColor);
									
								}//End of lower right-rectangle alteration
								
								//Upper-rectangle alteration
								if (r == 0)
								{
									
									//Rectangle alteration
									rectArray[r][c].setFill(primaryColor);
									rectArray[r+1][c].setFill(secondaryColor);
									rectArray[r][c+1].setFill(secondaryColor);
									rectArray[r][c-1].setFill(secondaryColor);
									
								}//End of upper-rectangle alteration
								
								//Lower-rectangle alteration
								if (r == 6)
								{
									
									//Rectangle alteration
									rectArray[r][c].setFill(primaryColor);
									rectArray[r-1][c].setFill(secondaryColor);
									rectArray[r][c+1].setFill(secondaryColor);
									rectArray[r][c-1].setFill(secondaryColor);
									
								}//End of lower-rectangle alteration
								
								//Right-rectangle alteration
								if (c == 6)
								{
									
									//Rectangle alteration
									rectArray[r][c].setFill(primaryColor);
									rectArray[r+1][c].setFill(secondaryColor);
									rectArray[r-1][c].setFill(secondaryColor);
									rectArray[r][c-1].setFill(secondaryColor);
									
								}//End of right-rectangle alteration
								
								//Alteration of body-rectangle color and neighboring rectangles
								rectArray[r][c].setFill(primaryColor);
								rectArray[r+1][c].setFill(secondaryColor);
								rectArray[r-1][c].setFill(secondaryColor);
								rectArray[r][c+1].setFill(secondaryColor);
								rectArray[r][c-1].setFill(secondaryColor);
								
							}//End of range evaluation
							
						}//End of inner loop
						
					}//End of outer loop
					
				}//End of try
				
				//Catch ArrayIndexOutOfBoundsException
				catch (ArrayIndexOutOfBoundsException e)
				{
				}//End of catch
				
			}//End of correct event and source case

		}//End of handle method

	}//End MouseHandler class

	//A handler class used to handle primary and secondary colors
	private class PrimColorHandler implements EventHandler<ActionEvent> 
	{
		
		/**
		 * This method handles the primary color combo box events, changing the primary
		 * color of the the rectangles when the mouse is dragged
		 */
		public void handle(ActionEvent event) 
		{
			
			//Blue case
			if (primaryColorCombo.getValue().equals("Blue"))
			{
				
				//Primary and secondary color conversion
				primaryColor = Color.BLUE;
				secondaryColor = Color.POWDERBLUE;
				
			}//End of Blue case
			
			//Red case
			else if (primaryColorCombo.getValue().equals("Red"))
			{
				
				//Primary and secondary color conversion
				primaryColor = Color.RED;
				secondaryColor = Color.PINK;
				
			}//End of Red case
			
			//Green case
			else if (primaryColorCombo.getValue().equals("Green"))
			{
				
				//Primary and secondary color conversion
				primaryColor = Color.GREEN;
				secondaryColor = Color.LIGHTGREEN;
				
			}//End of Green case
			
			//Default case
			else
			{
				
				//Primary and secondary color reversion
				primaryColor = Color.BLACK;
				secondaryColor = Color.GRAY;
				
			}//End of default case
			
		}//End of handle method
		
	}//End of PrimColorHandler class

	//A handler class used to handle background color
	private class BackColorHandler implements EventHandler<ActionEvent> 
	{
		
		/**
		 * This method handles background color combo box events, changing the color of
		 * the background rectangles
		 */
		public void handle(ActionEvent event) 
		{
			
			//Yellow case
			if (backColorCombo.getValue().equals("Yellow"))
			{
				
				//Background color conversion
				backgroundColor = Color.YELLOW;
				
			}//End of Yellow case
			
			//Orange case
			else if (backColorCombo.getValue().equals("Orange"))
			{
				
				//Background color conversion
				backgroundColor = Color.ORANGE;
				
			}//End of Orange case
			
			//Default case
			else
			{
				
				//Background color reversion
				backgroundColor = Color.WHITE;
				
			}//End of default case
			
			//Nested loops to change background color
			//Outer loop for rows
			for (int r = 0; r < rectArray.length; r++)
			{
				
				//Inner loop for element color change
				for (int c = 0; c < rectArray[r].length; c++)
				{
					
					//Element color conversion
					rectArray[r][c].setFill(backgroundColor);
					
				}//End of inner loop
				
			}//End of outer loop
			
		}//End of handle method
		
	}//End of BackColorHandler class

	//A handler class used to handle stroke width
	private class WidthHandler implements EventHandler<ActionEvent> 
	{
		
		/**
		 * This method handles stroke width combo box events,applying the necessary
		 * changes to the rectangles
		 */
		public void handle(ActionEvent event) 
		{
			
			//3 case
			if (widthCombo.getValue().equals("3"))
			{
				
				//Parse combo value to double
				selectWidth = Double.parseDouble(widthCombo.getValue());
				
			}//End of 3 case
			
			//5 case
			else if (widthCombo.getValue().equals("5"))
			{
				
				//Parse combo value to double
				selectWidth = Double.parseDouble(widthCombo.getValue());
				
			}//End of 5 case
			
			//7 case
			else if (widthCombo.getValue().equals("7"))
			{
				
				//Parse combo value to double
				selectWidth = Double.parseDouble(widthCombo.getValue());
				
			}//End of 7 case
			
			//Default case
			else
			{
				
				//Stroke width reversion
				selectWidth = 1.0;
				
			}//End of Default case
			
			//Nested loops to change stroke width
			//Outer loop for rows
			for (int r = 0; r < rectArray.length; r++)
			{
				
				//Inner loop for element stroke width change
				for (int c = 0; c < rectArray[r].length; c++)
				{
					
					//Stroke width conversion
					rectArray[r][c].setStrokeWidth(selectWidth);
					
				}//End of inner loop
				
			}//End of outer loop
			
		}//End of handle method
		
	}//End of WidthHandler class
	
} //End of PaneWithRectangles class