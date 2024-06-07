
/*-------------------------------------------------------------------------
// FILENAME: Assignment6.java
// SPECIFICATION: This class prompts a user to enter a size for the array
//                and create a IntCollection object. Then it displays
//                a menu to a user, and process a requested task accordingly.
// TIME SPENT: 4 hours
//----------------------------------------------------------------------*/
/*Part 1: Written Exercises (7 pts.)
1a.Valid
1b.Invalid
1c.Invalid
1d.Valid
2a.0
2b.6
2c.6
2d.8
2e.5
*/
import java.util.Scanner;
import java.text.*;

public class Assignment6 {
	public static void main(String[] args) { // declare variables
		int number, size;
		String choice;
		char command;

		Scanner keyboard = new Scanner(System.in);
		// ask a user for a array size
		System.out.println("Please enter a size for the array.\n");
		size = keyboard.nextInt();

		// instantiate an IntCollection object
		Collection collection = new Collection(size);

		// print the menu
		printMenu();

		do {
			// ask a user to choose a command
			System.out.println("\nPlease enter a command or type ?");
			choice = keyboard.next().toLowerCase();
			command = choice.charAt(0);

			switch (command) {
			case 'a': // add a number
				System.out.println("\nPlease enter an integer to add.");
				number = keyboard.nextInt();
				if (collection.add(number))
					System.out.println("\n" + number + " successfully added.");
				else
					System.out.println("\n" + number + " is already in the array. " + number + " was not added.");
				break;
			case 'b': // remove from collection
				System.out.println("Please enter an integer to remove.");
				number = keyboard.nextInt();
				if (collection.remove(number))
					System.out.println("\n" + number + " successfully removed.");
				else
					System.out.println("\n" + number + " is not in the array. " + number + " was not removed.");
				break;
			case 'c': // display
				System.out.println(collection.toString());
				break;
			case 'd': // find largest
				System.out.println("The largest number is: " + collection.findLargest());
				break;

			case 'e': // count of positive
				System.out.println("\nThe count of positive numbers is: " + collection.countPositive());
				break;
			case 'f': // count of even numbers
				// Round the output to three decimal places
				DecimalFormat fmt = new DecimalFormat("0.###");
				System.out.println("\nThe average is: " + fmt.format(collection.computeAvg()));
				break;

			case '?':
				printMenu();
				break;
			case 'q':
				break;
			default:
				System.out.println("Invalid input!");
			}

		} while (command != 'q');

	} // end of the main method

	// this method prints out the menu to a user
	public static void printMenu() {
		System.out.print("\nCommand Options\n" + "-----------------------------------\n"
				+ "a: add an integer in the array\n" + "b: remove an integer from the array\n"
				+ "c: display the array\n" + "d: find largest\n" + "e: count positive numbers\n"
				+ "f: compute average\n" + "?: display the menu again\n" + "q: quit this program\n\n");

	} // end of the printMenu method
} // end of the Assignment6 class