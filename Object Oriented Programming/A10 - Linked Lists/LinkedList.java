// A linked list is a sequence of nodes with efficient
// element insertion and removal.
// This class contains a subset of the methods of the
// standard java.util.LinkedList class.

// Assignment #: 10
//         Name: Vincent Latona
//	Time took you to complete the assignment: 3 hours 42 minutes
//  Description: This class allows interaction with a list of user created
//				 elements in the form of a linked list.

import java.util.NoSuchElementException;

public class LinkedList
{
   //nested class to represent a node
   private class Node
   {
          public Object data;
          public Node next;
   }

   //only instance variable that points to the first node.
   private Node first;

   // Constructs an empty linked list.
   public LinkedList()
   {
      first = null;
   }


   // Returns the first element in the linked list.
   public Object getFirst()
   {
      if (first == null)
       {
         NoSuchElementException ex
             = new NoSuchElementException();
         throw ex;
       }
      else
         return first.data;
   }

   // Removes the first element in the linked list.
   public Object removeFirst()
   {
      if (first == null)
       {
         NoSuchElementException ex = new NoSuchElementException();
         throw ex;
       }
      else
       {
         Object element = first.data;
         first = first.next;  //change the reference since it's removed.
         return element;
       }
   }

   // Adds an element to the front of the linked list.
   public void addFirst(Object element)
   {
      //create a new node
      Node newNode = new Node();
      newNode.data = element;
      newNode.next = first;
      //change the first reference to the new node.
      first = newNode;
   }

   // Returns an iterator for iterating through this list.
   public ListIterator listIterator()
   {
      return new LinkedListIterator();
   }
   
   /**
    * This method returns a string of objects from the linked list
    */
   public String toString()
   {
	   
	   //Iterator
	   ListIterator listIterator = listIterator();
	   
	   //Variable to return
	   String str = "{ ";
	   
	   //Concatenation loop
	   while(listIterator.hasNext())
	   {
		   
		   //String concatenation
		   str += listIterator.next() + " ";
		   
	   }//End of concatenation loop
	   
	   str += "}\n";
	   
	   //String return
	   return str;
	   
   }//End of toString method
   
   /**
    * This method returns the number of elements in the linked list
    */
   public int size()
   {
	   
	   //Iterator
	   ListIterator listIterator = listIterator();
	   
	   //Variable to return
	   int count = 0;
	   
	   //Counting loop
	   while(listIterator.hasNext())
	   {
		   
		   //Iterate to next
		   listIterator.next();
		   
		   //Increment count
		   count++;
		   
	   }//End of counting loop
	   
	   //Variable return
	   return count;
	   
   }//End of size method
   
   /**
    * This method searches the list for the correct place to add, then adds the element
    */
   public void addElement(Object element)
   {
	   
	   //Iterators for placement determination
	   ListIterator listIterator1 = listIterator();
	   ListIterator listIterator2 = listIterator();
	   
	   //Strings to compare the parameter against the elements
	   String str1 = (String) element;
	   String str2 = "";
	   
	   //Counter for number of iterator passes
	   int counter = 0;
	   
	   //Empty list
	   if(!listIterator1.hasNext())
	   {
		   
		   //Add the element first
		   addFirst(element);
		   
	   }//End of empty list case
	   
	   //Search evaluation
	   else
	   {
		   
		   //Assign the first element to a string and increment the counter
		   str2 = (String) listIterator1.next();
		   counter++;
		   
		   //Smaller than first
		   if(str1.compareTo(str2) <= 0)
		   {
			   
			   //Add the element first
			   addFirst(element);
			   
		   }//End of smaller than first case
		   
		   //Searching
		   else
		   {
			   
			   //Finder loop
			   while(listIterator1.hasNext())
			   {
				   
				   //Make a string of the passed element and increment number of iterator uses
				   str2 = (String) listIterator1.next();
				   counter++;
				   
				   //Proper place found
				   if(str1.compareTo(str2) <= 0)
				   {
					   
					   //Break out of the loop
					   break;
					   
				   }//End of found place case
				   
			   }//End of finder loop
			   
			   //Place found or element belongs before the final element
			   if(listIterator1.hasNext() || str1.compareTo(str2) <= 0)
			   {
				   
				   //Iterate to one less space than the previous iterator
				   for(int i = 1; i < counter; i++)
				   {
					   
					   //Iterate to one less than previous iterator
					   listIterator2.next();
					   
				   }//End of iterator loop
				   
				   //Place the element in its proper place
				   listIterator2.add(element);
				   
			   }//End of place found or before final element case
			   
			   //Place not found
			   else
			   {
				   
				   //Add element to the end of the list
				   listIterator1.add(element);
				   
			   }//End of place not found case
			   
		   }//End of searching case
		   
	   }//End of search evaluation case
	   
   }//End of addElement method
   
   /**
    * This method removes elements at all even indices
    */
   public void removeElementsAtEvenIndices()
   {
	   
	   //Element removal
	   if(first != null)
	   {
		   
		   //First element removal
		   removeFirst();
		   
		   //Iterator
		   ListIterator listIterator = listIterator();
		   
		   //List size
		   int size = size();
		   
		   //Index counter
		   int counter = 0;
		   
		   //Removal loop
		   while(listIterator.hasNext() && counter <= size)
		   {
			   
			   //Iteration and counter incrementation
			   listIterator.next();
			   counter++;
			   
			   //Removal case
			   if((counter % 2) == 0)
			   {
				   
				   //Element removal
				   listIterator.remove();
				   
			   }//End of removal case
			   
		   }//End of removal loop
		   
	   }//End of element removal case
	   
   }//End of removeElementsAtEvenIndices method
   
   /**
    * This method counts how many elements appear before a given object in the list
    */
   public int howManyAppearBefore(Object element)
   {
	   
	   //Iterator
	   ListIterator listIterator = listIterator();
	   
	   //Variable counter
	   int count = 0;
	   
	   //Empty list
	   if(!listIterator.hasNext())
	   {
		   
		   //Return -1 for not found
		   count = -1;
		   
	   }//End of empty list case
	   
	   //Count
	   else
	   {
		   
		   //Object to compare the element to the iterator element
		   Object checker = new Object();
		   
		   //Searching loop
		   while(listIterator.hasNext())
		   {
			   
			   //Checker assignment to the iterator
			   checker = listIterator.next();
			   
			   //Found condition
			   if(element.equals(checker))
			   {
				   
				   //End loop when found
				   break;
				   
			   }//End of found condition
			   
			   //Counting condition
			   else
			   {
				   
				   //Increment count
				   count++;
				   
			   }//End of counting condition
			   
		   }//End of searching loop
		   
		   //Not found
		   if(!listIterator.hasNext() && !element.equals(checker))
		   {
			   
			   //Return -1 for not found
			   count = -1;
			   
		   }//End of not found case
		   
	   }//End of counting case
	   	   
	   //Variable return
	   return count;
	   
   }//End of howManyAppearBefore method
   
   /**
    * This method returns the index of the last occurrence of the indicated element
    */
   public int indexOfLast(Object element)
   {
	   
	   //Variable to return
	   int index = -1;
	   
	   //Index counter
	   int count = -1;
	   
	   //Iterator
	   ListIterator listIterator = listIterator();
	   
	   //Iterator loop
	   while(listIterator.hasNext())
	   {
		   
		   //Index incrementation
		   count++;
		   
		   //Occurrence found
		   if(element.equals(listIterator.next()))
		   {
			   
			   //Assign index the counter value
			   index = count;
			   
		   }//End of occurrence found case
		   
	   }//End of iterator loop
	   
	   //Variable return
	   return index;
	   
   }//End of indesOfLast method
   
   /**
    * This method duplicates and adds each element to the list
    */
   public void duplicateEach()
   {
	   
	   //Iterator
	   ListIterator listIterator = listIterator();
	   
	   //Object to hold the duplicate
	   Object duplicate = new Object();
	   
	   //New list that will be used to store duplicates
	   LinkedList local = new LinkedList();
	   
	   //Local iterator
	   ListIterator listIterator1 = local.listIterator();
	   
	   //Iterator loop
	   while(listIterator.hasNext())
	   {
		   
		   //Duplicate creation and addition
		   duplicate = listIterator.next();
		   
		   //Addition of duplicate to another list
		   local.addFirst(duplicate);
		   
	   }//End of iterator loop
	   
	   //Duplicate addition loop
	   while(listIterator1.hasNext())
	   {
		   
		   //Duplicate addition to the original list
		   addElement(listIterator1.next());
		   
	   }//End of duplicate addition loop
	   
   }//End of duplicateEach method
   
   /**
    * This method removes an element at the indicated index
    */
   public Object removeElementAt(int index)
   {
	   
	   int size = size();
	   
	   int count = -1;
	   
	   Object removed = new Object();
	   
	   //Erroneous indices
	   if(index > size-1 || index < 0)
	   {
		   
		   //Exception creation and throw
		   IndexOutOfBoundsException ex = new IndexOutOfBoundsException();
		   throw ex;
		   
	   }//End of erroneous indices
	   
	   //Iterator
	   ListIterator listIterator = listIterator();
	   
	   //Iterator loop
	   while(listIterator.hasNext())
	   {
		   
		   //Iterate and keep track of the index
		   count++;
		   removed = listIterator.next();
		   
		   //Removal
		   if(count == index)
		   {
			   
			   //Element removal and loop break
			   listIterator.remove();
			   break;
			   
		   }//End of element removal
		   
	   }//End of iterator loop
	   
	   //Variable return
	   return removed;
	   
   }//End of removeElementAt method

   //nested class to define its iterator
   private class LinkedListIterator implements ListIterator
   {
      private Node position; //current position
      private Node previous; //it is used for remove() method

      // Constructs an iterator that points to the front
      // of the linked list.

      public LinkedListIterator()
      {
         position = null;
         previous = null;
      }

     // Tests if there is an element after the iterator position.
     public boolean hasNext()
      {
         if (position == null) //not traversed yet
          {
             if (first != null)
                return true;
             else
                return false;
          }
         else
           {
              if (position.next != null)
                 return true;
              else
                 return false;
           }
      }

      // Moves the iterator past the next element, and returns
      // the traversed element's data.
      public Object next()
      {
         if (!hasNext())
          {
           NoSuchElementException ex = new NoSuchElementException();
           throw ex;
          }
         else
          {
            previous = position; // Remember for remove

            if (position == null)
               position = first;
            else
               position = position.next;

            return position.data;
          }
      }

      // Adds an element after the iterator position
      // and moves the iterator past the inserted element.
      public void add(Object element)
      {
         if (position == null) //never traversed yet
         {
            addFirst(element);
            position = first;
         }
         else
         {
            //making a new node to add
            Node newNode = new Node();
            newNode.data = element;
            newNode.next = position.next;
            //change the link to insert the new node
            position.next = newNode;
            //move the position forward to the new node
            position = newNode;
         }
         //this means that we cannot call remove() right after add()
         previous = position;
      }

      // Removes the last traversed element. This method may
      // only be called after a call to the next() method.
      public void remove()
      {
         if (previous == position)  //not after next() is called
          {
            IllegalStateException ex = new IllegalStateException();
            throw ex;
          }
         else
          {
           if (position == first)
            {
              removeFirst();
            }
           else
            {
              previous.next = position.next; //removing
            }
           //stepping back
           //this also means that remove() cannot be called twice in a row.
           position = previous;
      }
      }

      // Sets the last traversed element to a different value.
      public void set(Object element)
      {
         if (position == null)
          {
            NoSuchElementException ex = new NoSuchElementException();
            throw ex;
          }
         else
          position.data = element;
      }
   } //end of LinkedListIterator class
} //end of LinkedList class