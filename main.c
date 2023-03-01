/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findBlock(int arr[], int n) {
    int* left = (int*)malloc(n * sizeof(int));
    int* right = (int*)malloc(n * sizeof(int));
    int lava = 0;
    left[0] = arr[0];
    for (int i = 1; i < n; i++) {
        left[i] = (arr[i] > left[i - 1]) ? arr[i] : left[i - 1];
    }
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right[i] = (arr[i] > right[i + 1]) ? arr[i] : right[i + 1];
    }
    for (int i = 1; i < n - 1; i++) {
        int var = fmin(left[i - 1], right[i + 1]);
        if (var > arr[i]) {
            lava += var - arr[i];
        }
    }
    free(left);
    free(right);
    return lava;
}

int main() {
    int n;
    printf("Masukkan panjang rintangan: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Masukkan besaran rintangan:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Lava yang harus disiapkan Terang adalah: %d ember\n", findBlock(arr, n));
    free(arr);
    return 0;
}
