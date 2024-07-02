#include <stdio.h>
void menu(){
    printf("1. Insertion Sort\n");
    printf("2. Buble Sort\n");
    printf("3. Quicksort\n");
    printf("4. Sequential Search\n");
    printf("5. Binary Search\n");
    printf("0. keluar\n");
}

void data(){
    printf("Data:\n");
    printf("1. 1000\n");
    printf("2. 16000\n");
    printf("3. 64000\n");
}

void insertionSort(long arr[], long n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    for (int a = 0; a < n; a++){
        printf("%d ", arr[a]);
    }
}

void swap(long* arr, long i, long j)
{
    long temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


void bubbleSort(long arr[], long n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
}


void printArray(long arr[], long size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swaps(long* a, long* b)
{
    long temp = *a;
    *a = *b;
    *b = temp;
}


long partition(long arr[], long low, long high)
{

    long pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swaps(&arr[i], &arr[j]);
        }
    }
    swaps(&arr[low], &arr[j]);
    return j;
}

void quickSort(long arr[], long low, long high)
{
    if (low < high) {

        long partitionIndex = partition(arr, low, high);

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);

    }
}

void sequentialSearch(long arr[], long n)
{
    int cari;
    printf("Masukkkan angka yang ingin dicari : ");
    scanf("%d", &cari);
    for (int i = 0; i < n - 1; i++){
        printf("%d ", arr[i]);
        if (arr[i] == cari){
            printf("Angka yang di cari berada di index : %d", i);
            return;
        }

    }
    printf("Tidak ada angka %d dalam array", cari);
}

int binarySearch(long arr[], int low, int high, int cari) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == cari) {
            return mid;
        }

        if (arr[mid] < cari) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int binarySearchForPosition(long arr[], int item, int low, int high) {
    if (high <= low) {
        return (item > arr[low]) ? (low + 1) : low;
    }

    int mid = (low + high) / 2;

    if (item == arr[mid]) {
        return mid + 1;
    }

    if (item > arr[mid]) {
        return binarySearchForPosition(arr, item, mid + 1, high);
    }

    return binarySearchForPosition(arr, item, low, mid - 1);
}

void binarySearchInsertionSort(long arr[], long n) {
    int i, j, pos;
    long key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        pos = binarySearchForPosition(arr, key, 0, j);

        while (j >= pos) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void binarySearchFunction(long arr[], long n) {
    int cari;
    printf("Masukkan angka yang ingin dicari: ");
    scanf("%d", &cari);

    binarySearchInsertionSort(arr, n);

    printf("Array yang sudah diurutkan: ");
    for (int i = 0; i < n; i++) {
        printf("%ld ", arr[i]);
    }
    printf("\n");

    int result = binarySearch(arr, 0, n - 1, cari);
    if (result != -1) {
        printf("Angka yang dicari berada di index: %d\n", result);
    } else {
        printf("Tidak ada angka %d dalam array\n", cari);
    }
}


void main(){
    char keluar = 'N';
    while(keluar == 'N'){
        printf("Silahkan memilih menu berikut : \n");
        menu();

        int pilihan, masukkan;

        printf("masukkan pilihan : ");
        scanf("%d", &pilihan);

        if(pilihan == 1){
            data();
            printf("masukkan pilihan : ");
            scanf("%d", &masukkan);
            if(masukkan == 1){
                long array[1000], i;
                for(i = 0; i < 1000; i++){
                    array[i] = rand()%1000;
                }
                long jumlah_data = sizeof(array) / sizeof(array[0]);
                insertionSort(array, jumlah_data);
            }
            else if(masukkan == 2){
                long array[16000], i;
                for(i = 0; i < 16000; i++){
                    array[i] = rand()%16000;
                }
                long jumlah_data = sizeof(array) / sizeof(array[0]);
                insertionSort(array, jumlah_data);
            }
            else if(masukkan == 3){
                long array[64000], i;
                for(i = 0; i < 64000; i++){
                    array[i] = rand()%64000;
                }
                long jumlah_data = sizeof(array) / sizeof(array[0]);
                insertionSort(array, jumlah_data);
            }
            else{
                printf("Data tidak sesuai");
            }
        }

        else if(pilihan == 2){
            data();
            printf("masukkan pilihan : ");
            scanf("%d", &masukkan);
            if(masukkan == 1){
                long array[1000], i;
                for(i = 0; i < 1000; i++){
                    array[i] = rand()%1000;
                }
                long jumlah_data = sizeof(array) / sizeof(array[0]);
                bubbleSort(array, jumlah_data);
                printArray(array, jumlah_data);
            }
            else if(masukkan == 2){
                long array[16000], i;
                for(i = 0; i < 16000; i++){
                    array[i] = rand()%16000;
                }
                long jumlah_data = sizeof(array) / sizeof(array[0]);
                bubbleSort(array, jumlah_data);
                printArray(array, jumlah_data);
            }
            else if(masukkan == 3){
                long array[64000], i;
                for(i = 0; i < 64000; i++){
                    array[i] = rand()%64000;
                }
                long jumlah_data = sizeof(array) / sizeof(array[0]);
                bubbleSort(array, jumlah_data);
                printArray(array, jumlah_data);
            }
            else{
                printf("Data tidak sesuai");
            }
        }

        else if(pilihan == 3){
            data();
            printf("masukkan pilihan : ");
            scanf("%d", &masukkan);
            if(masukkan == 1){
                long array[1000], i;
                for(i = 0; i < 1000; i++){
                    array[i] = rand()%1000;
                }
                long jumlah_data = sizeof(array) / sizeof(array[0]);
                quickSort(array, 0, jumlah_data - 1);
                for ( i = 0; i < jumlah_data; i++) {
                    printf("%d ", array[i]);
                }
            }
            else if(masukkan == 2){
                long array[16000], i;
                for(i = 0; i < 16000; i++){
                    array[i] = rand()%16000;
                }
                long jumlah_data = sizeof(array) / sizeof(array[0]);
                quickSort(array, 0, jumlah_data - 1);
                for ( i = 0; i < jumlah_data; i++) {
                    printf("%d ", array[i]);
                }
            }
            else if(masukkan == 3){
                long array[64000], i;
                for(i = 0; i < 64000; i++){
                    array[i] = rand()%64000;
                }
                long jumlah_data = sizeof(array) / sizeof(array[0]);
                quickSort(array, 0, jumlah_data - 1);
                for ( i = 0; i < jumlah_data; i++) {
                    printf("%d ", array[i]);
                }
            }
            else{
                printf("Data tidak sesuai");
            }
        }

        else if(pilihan == 4){
            data();
            printf("masukkan pilihan : ");
            scanf("%d", &masukkan);
            if(masukkan == 1){
                long array[1000], i;
                for(i = 0; i < 1000; i++){
                    array[i] = rand()%1000;
                }
                long jumlah_data = sizeof(array) / sizeof(array[0]);
                sequentialSearch(array, jumlah_data);

            }
            else if(masukkan == 2){
                long array[16000], i;
                for(i = 0; i < 16000; i++){
                    array[i] = rand()%16000;
                }
                long jumlah_data = sizeof(array) / sizeof(array[0]);
                sequentialSearch(array, jumlah_data);

            }
            else if(masukkan == 3){
                long array[64000], i;
                for(i = 0; i < 64000; i++){
                    array[i] = rand()%64000;
                }
                long jumlah_data = sizeof(array) / sizeof(array[0]);
                sequentialSearch(array, jumlah_data);

            }
            else{
                printf("Data tidak sesuai");
            }
        }

        else if(pilihan == 5){
            data();
            printf("masukkan pilihan : ");
            scanf("%d", &masukkan);
            if(masukkan == 1){
                long array[1000], i;
                for(i = 0; i < 1000; i++){
                    array[i] = rand()%1000;
                }
                long jumlah_data = sizeof(array) / sizeof(array[0]);
                binarySearchFunction(array, jumlah_data);

            }
            else if(masukkan == 2){
                long array[16000], i;
                for(i = 0; i < 16000; i++){
                    array[i] = rand()%16000;
                }
                long jumlah_data = sizeof(array) / sizeof(array[0]);
                binarySearchFunction(array, jumlah_data);

            }
            else if(masukkan == 3){
                long array[64000], i;
                for(i = 0; i < 64000; i++){
                    array[i] = rand()%64000;
                }
                long jumlah_data = sizeof(array) / sizeof(array[0]);
                binarySearchFunction(array, jumlah_data);

            }
            else{
                printf("Data tidak sesuai");
            }
        }

        else if(pilihan == 0){
            printf("keluar");
        }

        else{
            printf("pilihan tidak ada");
        }
        printf("Keluar (Y/N) : ");
        scanf(" %c", &keluar);
    }

}
