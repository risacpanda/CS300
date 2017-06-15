//This class provides the hash table

import java.util.*;
import java.io.*;

public class HashTable {
	private int arraySize = 29; //size of array/hash table
	private HashEntry[] elementData = new HashEntry[arraySize]; 
	private int size = 0;
	private int collisions = 0;
	
	//Adds word into hash set
	public void add(String str) {
		int key = hashFunction(str);
		if (elementData[key] != null) {
			collisions++;
		}
		elementData[key] = new HashEntry(str, elementData[key]);
		size++;
	}
	 
	//returns true if word is in hash set. otherwise false if not found
	public boolean contains(String str) {
		int key = hashFunction(str);
		HashEntry current = elementData[key];
		while (current != null) {
			if (current.data == str) {
				return true;
			}
			current = current.next;
		}
		return false;
	}
	
	//returns key for word from hash set
	public int get(String str) {
		for (int i = 0; i < arraySize; i++) {
			HashEntry current = elementData[i];
			while (current != null) {
				if (current.data == str) {
					return i;
				}
				current = current.next;
			}
		}
		return -1;
	}
	
	//sets which index of the hash table to store word
	private int hashFunction(String str) {
		int hash = 0;
		for (int i = 0; i < str.length(); i++) {
			hash = 31 * hash + str.charAt(i);
		}
		return hash % 29;
	}
	
	//Prints the number of collisions
	public void numCollisions(){
		System.out.println("Number of collisions: " + collisions);
	}
}


