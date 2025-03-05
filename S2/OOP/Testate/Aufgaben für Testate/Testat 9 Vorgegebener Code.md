Code der vorgegebenen Klassen `List` und `CircList`
```java
// Funktionale Schnittstelle fÃ¼r Aktionen,
// die mit einem int-Wert als Parameter aufgerufen werden.
interface Action {
    void execute (int x);
}

// Liste von int-Werten.
class List {
    protected int head;		// Erstes Element (Kopf).
    protected List tail;	// Restliste (Schwanz).

    // Initialisierung mit erstem Element h und ggf. Restliste t.
    public List (int h, List t) { head = h; tail = t; }
    public List (int h) { this(h, null); }

    // Erstes Element und Restliste abfragen.
    public int head () { return head; }
    public List tail () { return tail; }

    // Aktion a fÃ¼r jedes Element der Liste aufrufen.
    public void forEach (Action a) {
	for (List p = this; p != null; p = p.tail) {
	    a.execute(p.head);
	}
    }

    // Liste ausgeben.
    public void print () {
	forEach(x -> System.out.println(x));
    }

    // LÃ¤nge (d. h. Anzahl der Elemente) der Liste ermitteln.
    public int length () {
	// Einelementige int-Reihe anstelle einer int-Variablen,
	// weil eine Variable im Lambda-Ausdruck nicht verÃ¤ndert
	// werden darf.
	int [] n = { 0 };
	forEach(x -> n[0]++);
	return n[0];
    }
}

// ZirkulÃ¤re Liste.
class CircList extends List {
  // Initialisierung mit erstem Element h und ggf. Restliste t.
  public CircList (int h, CircList t) {
    super(h, t);

    // ZirkulÃ¤re Verkettung herstellen.
    if (t == null) {
	tail = this;
    }
    else {
	List p = t;
	while (p.tail != t) p = p.tail;
	p.tail = this;
    }
  }
  public CircList (int h) { this(h, null); }

  // Ãœberschreibung von tail mit kovarianter Anpassung
  // des Resultattyps (CircList statt List).
  public CircList tail () { return (CircList)tail; }

  // Anders als in Â§ 5.13 muss hier lediglich forEach Ã¼berschrieben
  // werden, um die ZirkularitÃ¤t zu beachten.
  // print und length (und eventuelle weitere Methoden, die forEach
  // verwenden, kÃ¶nnen unverÃ¤ndert bleiben.)
  public void forEach (Action a) {
      a.execute(head);
      for (List p = tail; p != this; p = p.tail) {
	  a.execute(p.head);
      }
  }
}****
```