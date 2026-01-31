 #include <stdio.h> 
 
 int main() { 
  int arr[5] = {64, 25, 12, 22, 11}; 
  int i, j, min, temp; 
 
  for (i = 0; i < 4; i++) { 
      min = i; 
      for (j = i + 1; j < 5; j++) { 
          if (arr[j] < arr[min]) 
              min = j; 
      } 
      temp = arr[i]; 
      arr[i] = arr[min]; 
      arr[min] = temp; 
  } 
 
printf("Sorted Array:\n"); 
for (i = 0; i < 5; i++) 
printf("%d ", arr[i]); 
return 0; 
} 