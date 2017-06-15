/*This class provides information about 
 * each hash entry to be in the hash table. Since we will
 * be using separate chaining, each entry will include 
 * the next entry (like a linked list) to avoid collisions
 */

public class HashEntry {
	public String data;
	public HashEntry next;
	
	public HashEntry(String data) {
		this(data, null);
	}
	
	public HashEntry(String data, HashEntry next) {
		this.data = data;
		this.next = next;
	}
}