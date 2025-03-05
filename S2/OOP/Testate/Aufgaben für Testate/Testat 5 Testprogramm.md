``` java
// Testprogramm fÃ¼r die Klasse StringSet.
class StringSetTest {
    public static void main (String [] args) {
	// Abbruch, wenn keine Konsole verfÃ¼gbar ist (z. B. in Eclipse).
	if (System.console() == null) {
	    System.out.println("console not available");
	    return;
	}

	// Aktuelle Menge s.
	StringSet s = null;

	// Endlosschleife.
	while (true) {
	    // Kommandozeile lesen und in WÃ¶rter zerlegen.
	    // Abbruch bei Ende der Eingabe oder leerer Eingabezeile.
	    String line = System.console().readLine("command: ");
	    if (line == null || line.equals("")) return;
	    String [] cmd = line.split(" ");

	    // Fallunterscheidung anhand des ersten Worts.
	    switch (cmd[0]) {
	    default: // new set
		int n = Integer.parseInt(cmd[0]);
		if (cmd.length == 1) s = new StringSet(n);
		else s = new StringSet(n, cmd[1]);
		break;
	    case "+": // insert
		System.out.println(s.insert(cmd[1]));
		break;
	    case "-": // remove
		System.out.println(s.remove(cmd[1]));
		break;
	    case "?": // contains
		System.out.println(s.contains(cmd[1]));
		break;
	    case "&": // intersection
		StringSet t = new StringSet(cmd.length - 1);
		for (int i = 1; i < cmd.length; i++) t.insert(cmd[i]);
		s = StringSet.intersection(s, t);
		break;
	    }

	    // KardinalitÃ¤t, KapazitÃ¤t und Inhalt der Menge s ausgeben.
	    System.out.print(s.card() + " of " + s.capacity() + " element(s): ");
	    s.print();
	    System.out.println();
	}
    }
}
```