# Pseudocode
**Achtung - VERÄNDERUNG**
- Arrays beginnen bei 1

**Algo. um den größten gemeinsamen Teiler zu finden**

``` Pseudocode
function GGT(a, b)
	while a>0 AND b>0 do
		if a>b then
			a <- a mod b
		else
			b <- b mod a
		end if
	end while
	return MAXIMUM(a,b)
end function	
```

``` C
int GGT(int a, int b){
	while (a > 0 && b > 0){
		if (a > b)
			a = a % b;
		else
			b = b % a;
	}
	return Math.max(a, b);
}
```
# Programmablaufplan

![[Pasted image 20240312101844.png]]
