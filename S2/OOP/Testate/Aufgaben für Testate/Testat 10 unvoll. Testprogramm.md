Weiß nicht mehr warum er uns das unvollständig gegeben hat, hat bestimmt was mit der Aufgabe zu tun oder so.
```java
class QueueTest {
    public static void main (String [] args) {
	// Der Code des try-Blocks darf nicht verÃ¤ndert werden!
	try {
	    // Warteschlange q erzeugen.
	    Queue q = new ListQueue();

	    // Kommandozeilenargumente verarbeiten.
	    for (String a : args) {
		// "-" bedeutet: erstes Element von q entfernen und ausgeben.
		if (a.equals("-")) {
		    System.out.println(q.dequeue());
		}
		// "@NNN" bedeutet: NNN-tes Element von q abfragen und ausgeben.
		else if (a.charAt(0) == '@') {
		    int j = Integer.parseInt(a.substring(1));
		    System.out.println(q.elem(j));
		}
		// Andere Argumente bedeuten: a am Ende von q anfÃ¼gen.
		else {
		    q.enqueue(a);
		}
	    }
	}
	// Hier sollen catch-Klauseln ergÃ¤nzt werden!
    }
}
```