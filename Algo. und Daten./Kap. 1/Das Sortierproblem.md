# Insertionsort

```Pseudocode
function INSERTION-SORT(A)
	for j from 2 to length[A] do
		key <- A[j]
		i <- j -1
		while i > 0 AND A[i] > key do
			A[i+1] <- A[i]
			i <- i - 1
		end while
		A[i+1] <- key
	end for
end function
```

``` Java
public void Insertion-Sort(int A[]){
	for (int j = 1; j < A.length(); j++){
		int key = A[j];
		i = j - 1;
		while (i > 0 && A[i] > key){
			A[i+1] = A[i];
			i = i - 1;
		}
		A[i+1] = key;
	}	
}
```

