/*Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right
*/
#include <stdio.h>

int main(){
    int n,position,i,x;
    int arr[100];
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter the position to insert the element: ");
    scanf("%d",&position);
    printf("Enter the element to insert: ");
    scanf("%d",&x);
    if(position<1 || position>n+1){
        printf("Invalid position\n");
        return 1;
    }
    else{
    for(i=n;i>=position;i--){
        arr[i]=arr[i-1];
    }
    arr[position-1]=x;
    printf("Updated array: ");
    for(i=0;i<=n;i++){
        printf("%d ",arr[i]);
    }
}
    return 0;

}