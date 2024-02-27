#include <iostream>

void merge(std::string array[], int left, int mid, int right);//to i
void mergeSort(std::string array[], int begin, int end);////////to jest algorytm mergesort zaporzyczony z internetu

int main() {
    int numOfCases, numOfTests, numOfRep;
    std::string temp;
//    auto *resoult = new std::string;
    std::cin>>numOfTests;
    int arrayForLenghts[numOfTests];
    std::string **arrayForClients = new std::string*[numOfTests];

    for(int xx=0;xx<numOfTests;xx++){//dla każdego testu
//        resoult->clear();
        numOfRep=1;
        std::cin>>numOfCases;
        arrayForLenghts[xx] = numOfCases;
        arrayForClients[xx] = new std::string[numOfCases];
//        std::string arrayForClients[numOfCases];
        std::fflush(stdin);
        for(int i=0;i<numOfCases;i++){//pobieranie numerow
            std::getline(std::cin, arrayForClients[xx][i]);
        }
        if(xx+1 != numOfTests){
            std::getline(std::cin, temp);//przyjmuje jedna pusta linie
            std::fflush(stdin);
        }
        mergeSort(arrayForClients[xx], 0, numOfCases - 1);//sortowanie listy

//        for(int i=1;i<numOfCases;i++){//wyswietlanie pojedynczo w posortowanej kolejnosci numerow kont i ilosci ich powtorzen
//            if(arrayForClients[i - 1] == arrayForClients[i]){
//                numOfRep++;
//            } else {
////                resoult->append(arrayForClients[i-1] + ' ' + '\n');
//                std::cout<<arrayForClients[i-1]<<' '<<numOfRep<<'\n';
//                numOfRep=1;
//            }
//        }
//        resoult->append(arrayForClients[numOfCases-1] + ' ' + '\n');
//        std::cout<<arrayForClients[numOfCases-1]<<' '<<numOfRep<<'\n';//wyswietlenie numeru konta i liczby powtorzen tylko ze dla ostatniego numeru
////        std::cout<<resoult<<'\n';
//        if(xx != numOfTests-1){
//            std::cin>>temp;
//        }
    }
    for(int xx=0;xx<numOfTests;xx++){
        numOfRep = 1;
        for(int i=1;i<arrayForLenghts[xx];i++){//wyswietlanie pojedynczo w posortowanej kolejnosci numerow kont i ilosci ich powtorzen
            if(arrayForClients[xx][i - 1] == arrayForClients[xx][i]){
                numOfRep++;
            } else {
//                resoult->append(arrayForClients[i-1] + ' ' + '\n');
                std::cout<<arrayForClients[xx][i-1]<<' '<<numOfRep<<'\n';
                numOfRep=1;
            }
        }
        std::cout<<arrayForClients[xx][numOfCases-1]<<' '<<numOfRep<<'\n';//wyswietlenie numeru konta i liczby powtorzen tylko ze dla ostatniego numeru
//        std::cout<<resoult<<'\n';
//        if(xx != numOfTests-1){
//            std::cin>>temp;
//        }
        std::cout<<'\n';
    }
    return 0;
}

void merge(std::string array[], int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new std::string[subArrayOne],
            *rightArray = new std::string[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne].compare(rightArray[indexOfSubArrayTwo]) < 0) {
            array[indexOfMergedArray]
                    = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                    = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(std::string array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}