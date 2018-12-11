#include <stdio.h>
#include <stdlib.h>

#define Queue_SIZE 100
int array[100], n;

struct heap{
    int data[Queue_SIZE];
    int cnt;
};

void display(){
    if (n == 0){
        printf("Heap is empty \n");
        return;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);

    printf("\n");
}

void display_struct(struct heap*q){
if (q->cnt == 0){
        printf("Heap is empty \n");
        return;
    }
    for (int i = 1; i <= q->cnt; i++)
        printf("%d ", q->data[i]);

    printf("%\n");
}

void insert(int num, int location){
    int parentnode;
    while (location > 0)
    {
        parentnode =(location - 1)/2;
        if (num <= array[parentnode])
        {
            array[location] = num;
            return;
        }
        array[location] = array[parentnode];
        location = parentnode;
    }/*End of while*/
    array[0] = num; /*assign number to the root node */
}/*End of insert()*/

void insertHeap(struct heap*q,int key){
    if(q->cnt!=Queue_SIZE){
        int index=++q->cnt;
        q->data[q->cnt]=key;

        while(index!=1&&q->data[index]<q->data[index/2]){
            int temp = q->data[index];
            q->data[index] = q->data[index/2];
            q->data[index/2] = temp;
            index=index/2;
        }
    }
}

int delete(int num){
    int left, right, i, temp, parentnode;

    for (i = 0; i < num; i++) {
        if (num == array[i])
            break;
    }
    if (num != array[i])
    {
        printf("%d not found in heap list\n", num);
        return;
    }
    array[i] = array[n - 1];
    n = n - 1;
    parentnode =(i - 1) / 2; /*find parentnode of node i */
    if (array[i] > array[parentnode])
    {
        insert(array[i], i);
        return;
    }
    left = 2 * i + 1; /*left child of i*/
    right = 2 * i + 2; /* right child of i*/
    while (right < n)
    {
        if (array[i] >= array[left] && array[i] >= array[right])
            return;
        if (array[right] <= array[left])
        {
            temp = array[i];
            array[i] = array[left];
            array[left] = temp;
            i = left;
        }
        else
        {
            temp = array[i];
            array[i] = array[right];
            array[right] = temp;
            i = right;
        }
        left = 2 * i + 1;
        right = 2 * i + 2;
    }
    if (left == n - 1 && array[i])    {
        temp = array[i];
        array[i] = array[left];
        array[left] = temp;
    }
}

int deleteHeap(struct heap*q){
if(q->cnt!=0){
    int min=q->data[1];//Min Bastaký Elemandýr.
    q->data[1]=q->data[q->cnt--];//Son Eleman Basa Gelýyor..
    int index=1;

    while(index<=q->cnt/2&&q->data[index]>q->data[2*index]||q->data[index]>q->data[2*index+1]){


        if(q->data[2*index]<q->data[2*index+1]){
            int temp = q->data[2*index];
            q->data[2*index] = q->data[2*index+1];
            q->data[2*index+1] = temp;
            index=2*index;
        }
        else{
            int temp = q->data[2*index+1];
            q->data[2*index+1] = q->data[2*index];
            q->data[2*index] = temp;
            index=2*index+1;
            }
        }



        return min;
    }
}

int main(){
    int secim, key;
    n = 0;/*Represents number of nodes in the heap*/

    struct heap q;
    q.cnt=0;

    insertHeap(&q,21);
        insertHeap(&q,15);
            insertHeap(&q,18);
            display_struct(&q);
                insertHeap(&q,11);
                display_struct(&q);
                    insertHeap(&q,13);
                    display_struct(&q);
                        insertHeap(&q,1);
                            insertHeap(&q,9);
                                insertHeap(&q,2);
                                    insertHeap(&q,7);
                                        insertHeap(&q,5);
                display_struct(&q);
                                    deleteHeap(&q);
                                    display_struct(&q);

 /*
 // Array Sistemi..
    while(1)
    {
        printf("1.Insert the element \n");
        printf("2.Delete the element \n");
        printf("3.Display all elements \n");
        printf("4.Quit \n");
        printf("Enter your Number : ");
        scanf("%d", &secim);
        switch(secim)
        {
        case 1:
            printf("Enter the element to be inserted to the list : ");
            scanf("%d", &key);
            n = n + 1;
            insert(key, n);

            break;
        case 2:
            printf("Enter the elements to be deleted from the list: ");
            scanf("%d", &key);
            delete(key);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Gecersiz islem \n");
        }
    }
*/
}
