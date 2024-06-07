import java.util.*;

//Class UserDatabase for user maintenance
public class UserDatabase {

	// Private variables
	private ArrayList<User> users;

	// Public methods
	// Create User
	public User createUser(boolean dr, boolean nurse, boolean patient, String fName, String lName, String dob,
			String uname, String pass, String phone, String email) {

		// Create new doctor
		User user = new User(dr, nurse, patient, fName, lName, dob, uname, pass, phone, email);

		// Add user to list of users
		boolean bool = users.add(user);

		// Successful add
		if (bool) {

			// Return pointer
			return user;

		} // End of successful add

		// Unsuccessful add
		else {

			// Return null pointer
			return null;

		} // End of unsuccessful add

	}// End of method createUser

	// User Authentication
	public User authenticate(String uname, String pass) {

		// User iterator
		for (int a = 0; a < users.size(); a++) {

			// Check for user
			if (users.get(a).getUserName().equals(uname) && users.get(a).getPassword().equals(pass)) {

				// Return found user
				return users.get(a);

			} // End of user check

		} // End of user iterator

		// Return null for non-existent
		return null;

	}// End of method authenticate
}