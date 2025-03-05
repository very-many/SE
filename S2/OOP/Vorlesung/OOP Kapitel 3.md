# Arrays in Java (lol)
```java
class Test {
	public static void main (String[] args){
		double [] a = new double[Integer.parseInt(args[0])];
		System.out.println("penis");
	}
}
```

# Strings in Java (x to uppercase X)
```Java
class Scratch {  
    public static void main(String[] args) {  
        String s = "abcxyz";  
        System.out.println(s);  
  
        String t = "";  
        for (int i = 0; i < s.length(); i++){  
            char c = s.charAt(i);  
            if (c == 'x') c  = 'X';  
            t += c;  
        }  
        System.out.println(t);  
    }  
}
```

# Neue for-Schleife
```Java
double [] a = new double[...];
//...
for(int i=0, i < a, i++){
	System.out.println(a[i]);
}
for(double x:a){
	System.out.println(a[i]);
}
```

# Switch case
```Java
switch(/*char, byte, short, int, string*/){
	case 1:
		//...
		break;
	
	case 2:
		//...
		break;

	case 3:
	case 4:
		//...
		break;
	
	case 5-> //-> als alternative zu break
		//...
	
	case 6,7-> //-> bei mehreren cases ohne break
		//...
	
	default:
		//...
		break;
}

/* statt break geht noch continue (wenn schleife außenrum), return oder throw */
/* case -Marken müssen typ-passende konstante sein*/




//NOCHMAL KÜRZER!!!
void print (String [] msgs, String which) { 
	int i = 
		switch (which) { 
		case "1st", "first" -> 0; 
		case "2nd", "second" -> { yield 1; }
		default -> throw new IndexOutOfBoundsException(which); 
		}; 
	System.out.println(msgs[i]); 
}
/* Wenn nach einem Pfeil ein Anweisungsblock steht, muss er seinen Wer t mit einer yield-Anweisung (vgl. § 3.4.3) zurückliefern, ähnlich wie eine Methode ihren Resultatwer t mit return zurückliefer t.*/
```

# Check 
Überprüfen, ob jede Zeile von a min. einen positiven Wert enthält.
```Java
public static boolean check(double[][]a) {  
    outer:  
    for (int i = 0; i < a.length; i++) {    //a.length ist hier die Anzahl der Zeilen  
        for (int j = 0; j<a[i].length;j++) { //a[i].length ist hier die Anzahl der Spalten  
            if(a[i][j]>0) {  
                continue outer;  
            }  
        }  
        return false; //eine Zeile ohne positive Zahl  
    }  
    return true;  
}  
public static boolean checkWithBetterFor(double[][]a) {  
    outer:  
    for (double[] doubles : a) {
        for (double aDouble : doubles) { 
            if (aDouble > 0) {  
                continue outer;  
            }  
        }  
        return false;
    }  
    return true;  
}
```