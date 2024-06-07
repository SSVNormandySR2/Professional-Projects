package application;

//Assignment #: 12
//Name: Vincent Latona
//Time took you to complete the assignment: 1 hour 28 minutes
//Description: This class handles the animations of strings
//		and provides methods for manipulating the animation

//Import necessary classes and packages
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.util.Duration;
import javafx.animation.Timeline;
import javafx.animation.KeyFrame;
import javafx.scene.text.*;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;

//TextPane class
public class TextPane extends Pane
{
	
	//Instance variables
	private double x1;
	private double y1;
	private double stepX;
	private double stepY;
	private String string1;
	private Color currentColor;
	private Timeline timeline;
	
	/**
	 * This is the constructor for the TextPane class
	 */
	TextPane(Color color, String initialString)
	{
		
		//Initialize instance variables
		currentColor = color;
		string1 = initialString;
		x1 = 0;
		y1 = 0;
		stepX = 30;
		stepY = 30;
		
		//Timeline setup
		timeline = new Timeline(new KeyFrame(Duration.millis(1000), new TextHandler()));
		timeline.setRate(1.0);
		
		//Background set to black
		this.setStyle("-fx-background-color: black;");
		
		//Start timeline
		timeline.setCycleCount(Timeline.INDEFINITE);
		timeline.play();
		
	}//End of TextPane constructor
	
	/**
	 * This method resumes the animation from its current position
	 */
	public void resume()
	{
		
		//Resume from current position
		timeline.play();
		
	}//End of resume method
	
	/**
	 * This method stops the animation
	 */
	public void suspend()
	{
		
		//Suspend animation
		timeline.stop();
		
	}//End of suspend method
	
	/**
	 * This method changes the color of the string
	 */
	public void changeColor(Color anotherColor)
	{
		
		//Assign the new color as the current color
		currentColor = anotherColor;
		
	}//End of changeColor method
	
	/**
	 * This method changes the string to the entered string
	 */
	public void changeString(String string2)
	{
		
		//Assign the new string to the current string
		string1 = string2;
		
	}//End of changeString method
	
	/**
	 * This method clears the pane of strings
	 */
	public void clear()
	{
		
		//Clear the pane
		this.getChildren().clear();
		
	}//End of clear method
	
	/**
	 * This method resets the rate of the animation
	 */
	public void setRate(int rate1)
	{
		
		//Set rate of animation
		timeline.setRate(rate1);
		
	}//End of setRate method
	
	//TextHandler class
	private class TextHandler implements EventHandler<ActionEvent>
	{
		
		/**
		 * This method handles how to alter the animation
		 */
		public void handle(ActionEvent event)
		{
			
			//Establish x-bounds for the text within the pane
			if(x1+stepX < 0 || x1+stepX > getWidth()-string1.length()*7)
			{
				
				//Change the step to +/- 1
				stepX *= -1;
				
			}//End of x-bounds
			
			//Establish y-bounds for the text within the pane
			if(y1+stepY < 0 || y1+stepY > getHeight())
			{
				
				//Change the step to +/- 1
				stepY *= -1;
				
			}///End of y-bounds
			
			//Change point positions
			x1 += stepX;
			y1 += stepY;
			
			//Create new text at new positions for x and y
			Text text = new Text(x1, y1, string1);
			text.setFill(currentColor);
			getChildren().add(text);
			
		}//End of handle method
		
	}//End of TextHandler class
	
}//End of TextPane class
