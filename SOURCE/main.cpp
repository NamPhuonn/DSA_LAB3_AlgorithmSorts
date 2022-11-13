#include "Header.h"
#include "Command.h"

int main(int argc, char** argv)
{
    int *arr;
    int N;

    /*Khai báo để xài thư viện chrono*/
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    //Biến lưu số comparision
    unsigned long long comparision = 0;
    unsigned long long comparision1 = 0;
    unsigned long long comparision2 = 0;

    //Biến thời gian bắt đầu và kết thúc
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();

    //Biến thời gian chạy của hàm
    std::chrono::duration<double, std::milli> time;
    std::chrono::duration<double, std::milli> time1;
    std::chrono::duration<double, std::milli> time2;

    //ALGORITHM MODE
	if (strcmp(argv[1],"-a") == 0) {
        char *algorithm = argv[2];
        cout << "ALGORITHM MODE\n";
        cout << "Algorithm: " << algorithm << endl;

        //Phân biệt command 1 vs command 2,3
        if (isdigit(argv[3][0])) {
            N = atoi(argv[3]);
            arr = new int[N];
            char *order = argv[4];
            cout << "Input size: " << N << endl;
            
            //Command 2
            if (inputOrder(arr,N,order)) {
                char inputFileName[] = "input.txt";
                //Viết mảng khởi tạo vào file input.txt
                writeFile(arr,N,inputFileName);
                char *parameter = argv[5];
                cout << "Input order: " << order << endl;

                start = high_resolution_clock::now();
                algorithmSort(algorithm,arr,N,comparision);
                end = high_resolution_clock::now();
                time = end - start;
                outputParameter((float)time.count(),comparision,parameter);

                //Viết mảng đã sắp xếp vào file output.txt
                char outputFileName[] = "output.txt";
                writeFile(arr,N,outputFileName);
            }
            //Command 3
            else {
                cout << endl;
                char *parameter = argv[4];

                //Randomize data
                comparision = 0;
                cout << "Input order: Randomize\n"; 
                GenerateData(arr,N,0);
                char inputFileName1[] = "input_1.txt";
                writeFile(arr,N,inputFileName1);
                start = high_resolution_clock::now();
                algorithmSort(algorithm,arr,N,comparision);
                end = high_resolution_clock::now();
                time = end - start;
                outputParameter((float)time.count(),comparision,parameter);

                //Nearly sorted data
                comparision = 0;
                cout << "Input order: Nearly Sorted\n"; 
                GenerateData(arr,N,3);
                char inputFileName2[] = "input_2.txt";
                writeFile(arr,N,inputFileName2);
                start = high_resolution_clock::now();
                algorithmSort(algorithm,arr,N,comparision);
                end = high_resolution_clock::now(); 
                time = end - start;
                outputParameter((float)time.count(),comparision,parameter);

                //Sorted data
                comparision = 0;
                cout << "Input order: Sorted\n"; 
                GenerateData(arr,N,1);
                char inputFileName3[] = "input_3.txt";
                writeFile(arr,N,inputFileName3);
                start = high_resolution_clock::now();
                algorithmSort(algorithm,arr,N,comparision);
                end = high_resolution_clock::now(); 
                time = end - start;
                outputParameter((float)time.count(),comparision,parameter);

                //Reverse data
                comparision = 0;
                cout << "Input order: Reversed\n"; 
                GenerateData(arr,N,2);
                char inputFileName4[] = "input_4.txt";
                writeFile(arr,N,inputFileName4);
                start = high_resolution_clock::now();
                algorithmSort(algorithm,arr,N,comparision);
                end = high_resolution_clock::now();
                time = end - start;
                outputParameter((float)time.count(),comparision,parameter); 
            }
        }
        //Command 1
        else {
            char *nameFile = argv[3];
            char *parameter = argv[4];
            //Đọc dữ liệu mảng từ file 
            readFile(arr,N,nameFile);
            cout << "Input file: " << nameFile << endl;
            cout << "Input size: " << N << endl;

            start = high_resolution_clock::now();
            algorithmSort(algorithm,arr,N,comparision);
            end = high_resolution_clock::now();
            time = end - start;

            outputParameter((float)time.count(),comparision,parameter);

            //Viết mảng đã sắp xếp vào file output.txt
            char outputFileName[] = "output.txt";
            writeFile(arr,N,outputFileName);
        }
    }
    //COMPARE MODE
    else if (strcmp(argv[1],"-c") == 0){
        char *algorithm1 = argv[2];
        char *algorithm2 = argv[3];
        cout << "COMPARE MODE\n";
        cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << endl;
        //Command 5
        if (isdigit(argv[4][0])) {
            N = atoi(argv[4]);
            arr = new int[N];
            char *order = argv[5];
            
            cout << "Input size: " << N << endl;
            cout << "Input order: " << order << endl;

            if (inputOrder(arr,N,order)) {
                char inputFileName[] = "input.txt";
                //Ghi mảng đã khởi tạo vào file input.txt
                writeFile(arr,N,inputFileName);

                //Algorithm 1
                start = high_resolution_clock::now();
                algorithmSort(algorithm1,arr,N,comparision1);
                end = high_resolution_clock::now();
                time1 = end - start;
                
                //Algorithm 2
                start = high_resolution_clock::now();
                algorithmSort(algorithm2,arr,N,comparision2);
                end = high_resolution_clock::now();
                time2 = end - start;

                output((float)time1.count(), (float)time2.count(), comparision1, comparision2);
            }
        }
        //Command 4
        else {
            char* nameFile = argv[4];
            //Đọc dữ liệu mảng từ file
            readFile(arr,N,nameFile);
            cout << "Input file: " << nameFile << endl;
            cout << "Input size: " << N << endl;

            //Algorithm 1
            start = high_resolution_clock::now();
            algorithmSort(algorithm1,arr,N,comparision1);
            end = high_resolution_clock::now();
            time1 = end - start;
            
            //Algorithm 2
            start = high_resolution_clock::now();
            algorithmSort(algorithm2,arr,N,comparision2);
            end = high_resolution_clock::now();
            time2 = end - start;

            output((float)time1.count(), (float)time2.count(), comparision1, comparision2);
        }
    } 
    else {
        cout << "Không đúng cú pháp prototype. \n";
    }
    
    system("pause");
    return 0;
}
