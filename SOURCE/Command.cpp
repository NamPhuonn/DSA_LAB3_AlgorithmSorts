#include "Command.h"

//Hàm kiểm tra input order
bool inputOrder(int *a, int n, char* order) {
    if (strcmp(order,"-rand") == 0) {
        GenerateData(a,n,0);
        return true;
    }
    else if (strcmp(order,"-sorted") == 0) {
        GenerateData(a,n,1);
        return true;
    }
    else if (strcmp(order,"-rev") == 0) {
        GenerateData(a,n,2);
        return true;
    }
    else if (strcmp(order,"-nsorted") == 0) {
        GenerateData(a,n,3);
        return true;
    }
    return false;
}

//Hàm kiểm tra output parameter
void outputParameter(double time,unsigned long long comparision, char *parameter) {
    cout << "---------------------------------\n"; 
    if (strcmp(parameter,"-time") == 0) {
        cout << "Running time (if required): " << time << "ms\n";
        cout << endl;
    }
    else if (strcmp(parameter,"-comp") == 0) {
        cout << "Comparisions (if required): " << comparision << endl;
        cout << endl;
    }
    else if (strcmp(parameter,"-both") == 0) {
        cout << "Running time (if required): " << time << "ms\n";
        cout << "Comparisions (if required): " << comparision << endl;
        cout << endl;
    }
}


void output(double time1, double time2 , unsigned long long comparision1, unsigned long long comparision2) {
    cout << "---------------------------------\n"; 
    cout << "Running time: " << time1 << " | " << time2 << endl;
    cout << "Comparisions: " << comparision1 << " | " << comparision2 << endl;
}

//Hàm ghi mảng a vào nameFile
void writeFile(int *a, int n, char nameFile[]) {
    ofstream file;
    file.open(nameFile, ios_base::out);
    if (file.fail()){
        cout << "Khong the mo file!";
        exit(0);
    }
    else {
        file << n << endl;
        for (int i = 0; i < n; i++) {
            file << a[i] << " ";
        }
        file << endl;
    }
    file.close();

}


//Hàm chọn thuật toán sắp xếp
void algorithmSort(char* algorithm, int *arr, int N,unsigned long long &comparision) {
    if (strcmp(algorithm,"selection-sort") == 0) {
        selectionSort(arr,N,comparision);
    }
    else if (strcmp(algorithm,"insertion-sort") == 0) {
        insertionSort(arr,N,comparision); 
    }
    else if (strcmp(algorithm,"bubble-sort") == 0) {
        bubbleSort(arr,0,N,comparision); 
    }
    else if (strcmp(algorithm,"shaker-sort") == 0) {
        shakerSort(arr,N,comparision); 
    }
    else if (strcmp(algorithm,"shell-sort") == 0) {
        shellSort(arr,N,comparision); 
    }
    else if (strcmp(algorithm,"heap-sort") == 0) {
        heapSort(arr,N,comparision); 
    }
    else if (strcmp(algorithm,"merge-sort") == 0) {
        mergeSort(arr,0,N,comparision);
    }
    else if (strcmp(algorithm,"quick-sort") == 0) {
        quickSort(arr,0,N - 1,comparision); 
    }
    else if (strcmp(algorithm,"counting-sort") == 0) {
        countingSort(arr,N,comparision); 
    }
    else if (strcmp(algorithm,"radix-sort") == 0) {
        radixSort(arr,N,comparision); 
    }
    else if (strcmp(algorithm,"flash-sort") == 0) {
        flashSort(arr,N,comparision); 
    }
}

//Hàm đọc dữ liệu mảng từ nameFile
void readFile(int *&a, int &n, char *nameFile) {
    fstream file;
    file.open(nameFile, ios_base::in);
    if (file.fail()){
        cout << "Khong the mo file!";
        exit(0);
    }
    else {
        
        file >> n; //size
        a = new int[n];
		for (int i = 0; i < n; i++) {
			file >> a[i];
		}
    }
    file.close();
}