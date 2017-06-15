/*This main class is mostly for file reading 
 * and reads a text file line by line and puts each word from each line
 * through the hash function and into the hash table. It then prints out
 * the number of collisions. 
 */

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class main {
	public static void main(String[] args) throws IOException {
		//reads string line by line from text file 
		HashTable hashtable = new HashTable();
		try {
			File f = new File("src/test.txt"); 
			BufferedReader b = new BufferedReader(new FileReader(f));
			String line =  "";
			while ((line = b.readLine()) != null) {
				hashtable.add(line);
			}
		} catch(IOException e) {
			e.printStackTrace();
		}
		hashtable.numCollisions();
	}
}
