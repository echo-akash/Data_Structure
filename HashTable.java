package hashtable;

public class HashTable {    
    private static int INIT_SIZE = 15;
    private HashEntry[] entries =  new HashEntry[INIT_SIZE];
    public void put(String key, String value){
        int hash = getHash(key);
        final HashEntry hashEntry =  new HashEntry(key, value);
        if(entries[hash]==null){
            entries[hash] = hashEntry;
        }else{  //if element present at current hash, it enter to linked list
            HashEntry temp = entries[hash];
            while(temp.next!= null){
                temp = temp.next;
            }
            temp.next = hashEntry;
        }
    }
    
    public String get(String key){
        int hash = getHash(key);
        if(entries[hash]!= null){
            HashEntry temp = entries[hash];
            while(!temp.key.equals(key) && temp.next!=null){    // check in the linked list if any element available for the given key
                temp = temp.next;
            }
            return temp.value;
        }
        return null;    //return null if element not found
    }
    
    private int getHash(String key){
        return key.hashCode() % INIT_SIZE;  //getting hashed code for the given key
    }
    
    public static class HashEntry{
        String key, value;
        HashEntry next;
        public HashEntry(String key, String value){
            this.key = key;
            this.value = value;
            this.next = next;
        }
        @Override
        public String toString(){
            return "<" + key + ", " + value + ">";
        }
    }
    
    @Override
    public String toString(){
        int bucket = 0;
        StringBuilder hashTableStr =  new StringBuilder();
        for (HashEntry entry : entries){
            if(entry == null){
                continue;
            }
            hashTableStr.append("\n bucket<").append(bucket).append("> = ").append(entry.toString());
            bucket++;
            HashEntry temp = entry.next;
            while(temp != null){
                hashTableStr.append(" -- ");
                hashTableStr.append(temp.toString());
                temp = temp.next;
            }
        }
        return hashTableStr.toString();
    }
    
    public static void main(String[] args) {
        HashTable hashTable = new HashTable();
        for (int i = 0; i < 30; i++) {
            final String key = String.valueOf(i);
            hashTable.put(key, key);     //put values in hashtable
        }
        
        print("****     HashTable    ****");
        print(hashTable.toString());
        print("\nValue for key(25): " + hashTable.get("25"));
        
    }   
    
    private static void print(String message){
        System.out.println(message);
    }
}
