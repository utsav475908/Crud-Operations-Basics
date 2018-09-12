//
//  main.c
//  WorkNowINCommandLine
//
//  Created by Apple on 13/09/18.
//  Copyright © 2018 Kumar Utsav. All rights reserved.
//

#include <stdio.h>


void create_array(int a[], int n);
void display_array(int a[], int n);
int insert_at_pos(int item, int a[], int n , int pos);
int delete_at_pos(int a[], int n ,int pos);
int binary_search(int key, int a[], int n);


int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    
    int choice, a[10], n , item, pos;
    for (; ;) {
        printf("1. Create an array\n");
        printf("2. Display \n");
        printf("3. Insert at position \n");
        printf("4. Delete at position \n");
        printf("5. Exit \n");
        printf("Enter the choice \n");
        
        scanf("%d", &choice);;
        
        
        switch (choice) {
            case 1:
                printf("Enter the number of elements");
                scanf("%d", &n);
                printf("Enter %d elements\n", n);
                create_array(a, n);
                break;
                
            case 2:
                printf("The contents of the array are \n");
                display_array(a, n);
                break;
                
            case 3:
                printf("Enter the items to be inserted");
                scanf("%d", &item);
                printf("Enter the  position");
                scanf("%d", &pos);
                n = insert_at_pos(item, a, n, pos);
                break;
                
            case 4:
                printf("Enter the position");
                scanf("%d", &pos);
                n = delete_at_pos(a, n, pos);
                //create_array(a, n);
                delete_at_pos(a, n, pos);
                break;
                
            default:
                break;
        }
        
    }
    
    
    return 0;
}

void create_array(int a[], int n){
    int i;
    for (i = 0 ; i < n ; i ++){
        scanf("%d", & a[i]);
    }
}

void display_array(int a[], int n){
    int i;
    for (i = 0 ; i < n; i++){
        printf("%d", a[i]);
    }
}

int insert_at_pos(int item, int a[], int n , int pos){
    int i ;
    if (pos > n || pos < 0){
        printf("invalid positions");
        return n;
    }
    for(i = n - 1; i >= pos; i--){
        a[i + 1] = a[i];
        
    }
    
    return n + 1;
}


int delete_at_pos(int a[], int n ,int pos){
    int i ;
    if (pos >= n || pos < 0){
        printf("invalid position");
        return n;
    }
    
    printf("item deleted = %d\n" , a[pos]);
    for (i = pos + 1; i < n; i++) {
        a[i - 1] = a[i];
    }
    return n - 1;
}

int binary_search(int key, int a[], int n){
    int low, high, mid ;
    low = 0;
    high = n -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key == a[mid]) return mid;
        if (key < a[mid]) high = mid - 1;
        if (key > a[mid]) low = mid + 1;
        
    }
    return -1;
}

