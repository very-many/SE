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
