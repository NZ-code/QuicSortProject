#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "file_t.h"
using namespace std;
#define MAX_FILES 1000000

void swap(int *tab,int index1,int indxex2) {
    int temp = tab[index1];
    tab[index1] = tab[indxex2];
    tab[indxex2] = temp;
}
void swap(File_t** files, int index1, int index2) {
    File_t* temp = files[index1];
    files[index1] = files[index2];
    files[index2] = temp;
    
}

void quick_sort(int* tab, int lower_index, int higher_index) {
    int l = lower_index;
    int h = higher_index;
    int x = tab[(lower_index + higher_index) / 2];
    do {
        while (tab[l] < x) l++;
        while (tab[h] > x) h--;
        if (l<=h) {
            swap(tab, l, h);
            l++;
            h--;
        }
    } while (l<=h);
    if (lower_index < h) quick_sort(tab, lower_index, h);
    if (higher_index > l) quick_sort(tab, l, higher_index);
    
}
void quick_sort(File_t** files, int lower_index, int higher_index) {
    int l = lower_index;
    int h = higher_index;
    int x = files[(lower_index + higher_index) / 2]->size;
    do {
        while (files[l]->size < x) l++;
        while (files[h]->size > x) h--;
        if (l <= h) {
            swap(files, l, h);
            l++;
            h--;
        }
    } while (l <= h);
    if (lower_index < h) quick_sort(files, lower_index, h);
    if (higher_index > l) quick_sort(files, l, higher_index);

}
int main()
{
   
    int pendrive_size;
    
    
    int nums_of_files;
    scanf("%d",&nums_of_files);
    scanf("%d",&pendrive_size);
    File_t** files = new File_t * [nums_of_files];
    for (int i = 0; i < nums_of_files; i++)
    {
        int id = 0;
        int pendrive_size=0;
        scanf("%d", &id);
        scanf("%d", &pendrive_size);
       
        
        File_t* file = new File_t(id, pendrive_size);
        files[i] = file;
    }
    quick_sort(files, 0, nums_of_files-1);
    
    int sum_1 = 0;
    int sum_2 = 0;
    int last_index = -1;
    int cont_f1 = 0;
    int cont_f2 = 0;
    int *id_arr1 = new int[MAX_FILES];
    int *id_arr2 = new int[MAX_FILES];


    for (int i = 0; i < nums_of_files; i++)
    {
        if (files[0]->size >= pendrive_size) {
            break;
        }
        last_index = i;
        id_arr1[cont_f1] = files[i]->id;
        cont_f1++;
        sum_1 += files[i]->size;
        free(files[i]);
        if (i + 1 < nums_of_files) {
            if (files[i + 1]->size + sum_1 > pendrive_size) {
                break;
            }
            
        }
    }
    for (int i = last_index + 1; i < nums_of_files; i++)
    {
        if (files[last_index + 1]->size >= pendrive_size) {
            break;
        }
        sum_2 += files[i]->size;
        id_arr2[cont_f2] = files[i]->id;
        cont_f2++;
        free(files[i]);
        if (i + 1 < nums_of_files) {
            if (files[i + 1]->size + sum_2 > pendrive_size) {
                break;
            }
        }
    }
    delete [] files;
    printf("%d\n", cont_f1 + cont_f2);
    quick_sort(id_arr1, 0, cont_f1 -1);
    quick_sort(id_arr2, 0, cont_f2 -1);
    printf("1: ");
    for (int i = cont_f1-1; i >= 0; i--)
    {
        printf("%d ", id_arr1[i]);
        
    }
 
  printf("\n2: ");
    for (int i = cont_f2 - 1; i >= 0; i--)
    {
        printf("%d ",id_arr2[i]);
    }

    //zwalnianie
    delete[] id_arr1;
    delete[] id_arr2;

}

