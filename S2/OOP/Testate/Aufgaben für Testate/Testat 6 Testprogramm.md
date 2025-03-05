```java
// Punkt im zweidimensionalen Raum.
class Point {
    // Koordinaten des Punkts.
    public final double x, y;

    // Punkt mit Koordinaten x und y initialisieren.
    public Point (double x, double y) {
	this.x = x;
	this.y = y;
    }

    // Zeichenkettendarstellung des aktuellen Punkts liefern.
    public String toString () {
	return "(" + x + ", " + y + ")";
    }

    // Vergleich des aktuellen Punkts mit einem anderen Objekt other.
    public boolean equals (Object other) {
	if (!(other instanceof Point that)) return false;
	return this.x == that.x && this.y == that.y;
    }

    // Streuwert fÃ¼r den aktuellen Punkt liefern.
    public int hashCode () {
	return (int)(x + y);
    }
}

// Testprogramm fÃ¼r die Klasse MultiSet.
class MultiSetTest {
    public static void main (String [] args) {
	int n = args.length;

	// Je zwei Kommandozeilenargumente definieren einen Punkt p.
	// Jeder solche Punkt wird zur Multimenge s1 hinzugefÃ¼gt.
	MultiSet s1 = new MultiSet(n/2);
	for (int i = 0; i < n; i += 2) {
	    double x = Double.parseDouble(args[i]);
	    double y = Double.parseDouble(args[i+1]);
	    Point p = new Point(x, y);
	    s1.add(p);
	}
	System.out.println(s1 + " " + s1.hashCode());

	// Zur Multimenge s2 werden die gleichen Punkte hinzugefÃ¼gt
	// wie zu s1, aber in umgekehrter Reihenfolge.
	MultiSet s2 = new MultiSet(n/2);
	for (int i = n - 2; i >= 0; i -= 2) {
	    double x = Double.parseDouble(args[i]);
	    double y = Double.parseDouble(args[i+1]);
	    Point p = new Point(x, y);
	    s2.add(p);
	}
	System.out.println(s2 + " " + s2.hashCode());

	// Vergleich von s1 und s2.
	System.out.println(s1.equals(s2));

	// Da s1 und s2 selbst wieder Objekte sind, kÃ¶nnen sie zu einer
	// dritten Multimenge s3 hinzugefÃ¼gt werden.
	MultiSet s3 = new MultiSet(2);
	s3.add(s1);
	s3.add(s2);
	System.out.println(s3.count(s1) + " " + s3.count(s2));
	System.out.println(s3);
    }
}
```