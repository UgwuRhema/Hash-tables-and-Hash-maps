import java.util.HashMap;

public class Hmap {
	public static void main(String[] args){
		System.out.println("HASH_MAP EXAMPLE!");
		HashMap<String, Integer> mymap = new HashMap<>();
		mymap.put("Frank", 13);
		mymap.put("Rhema", 17);
		int name = mymap.get("Rhema");
		System.out.println("The value from the name Rhema is: " + name);
		//let's interate through the entries
		for (var e : mymap.entrySet()){
			System.out.println(e.getKey() + "-> " + e.getValue());
		}
	}
}
