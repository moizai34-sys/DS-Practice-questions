#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Activity
{
    string name;
    int time;
};

// **************** DISPLAY ****************

void displayNames(Activity arr[], int n)
{
    cout << endl;
    cout << "Activities:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << arr[i].name << endl;
    }
}

int findActivityTime(Activity arr[], int n, string name)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].name == name)
        {
            return arr[i].time;
        }
    }

    return -1;
}

void showTime(Activity arr[], int n)
{
    string name;

    cout << endl;
    cout << "Enter activity name: ";
    cin.ignore();
    getline(cin, name);

    int time = findActivityTime(arr, n, name);

    if (time != -1)
    {
        cout << "Time spent on " << name << ": "
             << time << " hours" << endl;
    }
    else
    {
        cout << "Activity not found." << endl;
    }
}

// **************** COPY ARRAY ****************

void copyArray(Activity source[], Activity destination[], int n)
{
    for (int i = 0; i < n; i++)
    {
        destination[i] = source[i];
    }
}

// **************** BUBBLE SORT ****************

void bubbleSort(Activity arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped=false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].time > arr[j + 1].time)
            {
                Activity temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped=true;
            }
            if (swapped==false)
            {
                cout<<"Array is already sorted.."<<endl;
                return;
            }
            
        }
    }
}

// **************** SELECTION SORT ****************

void selectionSort(Activity arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].time < arr[minIndex].time)
            {
                minIndex = j;
            }
        }

        Activity temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// **************** INSERTION SORT ****************

void insertionSort(Activity arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Activity key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].time > key.time)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// **************** SHELL SORT ****************

void shellSort(Activity arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            Activity temp = arr[i];

            int j;

            for (j = i; j >= gap &&
                 arr[j - gap].time > temp.time;
                 j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

// **************** COMB SORT ****************

void combSort(Activity arr[], int n)
{
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped)
    {
        gap = (gap * 10) / 13;

        if (gap < 1)
        {
            gap = 1;
        }

        swapped = false;

        for (int i = 0; i + gap < n; i++)
        {
            if (arr[i].time > arr[i + gap].time)
            {
                Activity temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;

                swapped = true;
            }
        }
    }
}

// **************** SORT RESULT ****************

void displaySortResult(Activity arr[], int n, string algorithm)
{
    cout << endl;
    cout << "========== " << algorithm << " ==========" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << arr[i].name << endl;
    }
}

// **************** RUN ONE SORT ****************

void runSort(Activity original[], int n, int choice)
{
    Activity temp[MAX];

    copyArray(original, temp, n);

    if (choice == 1)
    {
        bubbleSort(temp, n);
        displaySortResult(temp, n, "Bubble Sort");
    }
    else if (choice == 2)
    {
        selectionSort(temp, n);
        displaySortResult(temp, n, "Selection Sort");
    }
    else if (choice == 3)
    {
        insertionSort(temp, n);
        displaySortResult(temp, n, "Insertion Sort");
    }
    else if (choice == 4)
    {
        shellSort(temp, n);
        displaySortResult(temp, n, "Shell Sort");
    }
    else if (choice == 5)
    {
        combSort(temp, n);
        displaySortResult(temp, n, "Comb Sort");
    }
}

// **************** SORTING MENU ****************

void sortingMenu(Activity activities[], int n)
{
    int choice;

    do
    {
        cout << endl;
        cout << "========== SORTING MENU ==========" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Shell Sort" << endl;
        cout << "5. Comb Sort" << endl;
        cout << "6. Any Two Sorting Algorithms" << endl;
        cout << "7. All Five Sorting Algorithms" << endl;
        cout << "8. Back" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5)
        {
            runSort(activities, n, choice);
        }
        else if (choice == 6)
        {
            int first, second;

            cout << endl;
            cout << "Choose first algorithm (1-5): ";
            cin >> first;

            cout << "Choose second algorithm (1-5): ";
            cin >> second;

            if (first >= 1 && first <= 5 &&
                second >= 1 && second <= 5 &&
                first != second)
            {
                runSort(activities, n, first);
                runSort(activities, n, second);
            }
            else
            {
                cout << "Invalid choices." << endl;
            }
        }
        else if (choice == 7)
        {
            for (int i = 1; i <= 5; i++)
            {
                runSort(activities, n, i);
            }
        }

    } while (choice != 8);
}

// ****************
// SEARCHING
// ****************

// **************** LINEAR SEARCH ****************

int linearSearch(Activity arr[], int n, string key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].name == key)
        {
            return i;
        }
    }

    return -1;
}

// **************** ALPHABETICAL SORT ****************

void sortAlphabetically(Activity arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].name < arr[minIndex].name)
            {
                minIndex = j;
            }
        }

        Activity temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// **************** BINARY SEARCH ****************

int binarySearch(Activity arr[], int n, string key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid].name == key)
        {
            return mid;
        }
        else if (arr[mid].name < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

// **************** INTERPOLATION SEARCH ****************

int interpolationSearch(Activity arr[], int n, string key)
{
    int low = 0;
    int high = n - 1;

    int keyValue = (int)key[0];

    while (low <= high &&
           keyValue >= (int)arr[low].name[0] &&
           keyValue <= (int)arr[high].name[0])
    {
        int lowValue = (int)arr[low].name[0];
        int highValue = (int)arr[high].name[0];

        if (lowValue == highValue)
        {
            if (arr[low].name == key)
            {
                return low;
            }

            return -1;
        }

        int pos = low +
            ((keyValue - lowValue) * (high - low))
            / (highValue - lowValue);

        if (arr[pos].name == key)
        {
            return pos;
        }

        if ((int)arr[pos].name[0] < keyValue)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }

    return -1;
}

// **************** SEARCH RESULT ****************

void searchResult(Activity arr[], int n, string key, int method)
{
    Activity temp[MAX];

    copyArray(arr, temp, n);

    int index = -1;

    if (method == 1)
    {
        index = linearSearch(temp, n, key);
    }
    else if (method == 2)
    {
        sortAlphabetically(temp, n);
        index = binarySearch(temp, n, key);
    }
    else if (method == 3)
    {
        sortAlphabetically(temp, n);
        index = interpolationSearch(temp, n, key);

        if (index == -1)
        {
            for (int i = 0; i < n; i++)
            {
                if (temp[i].name == key)
                {
                    index = i;
                    break;
                }
            }
        }
    }

    if (index != -1)
    {
        cout << endl;
        cout << "Preference found: " << key << "." << endl;

        int choice;

        cout << endl;
        cout << "How much time?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Time spent on " << key << ": "
                 << temp[index].time << " hours" << endl;
        }
    }
    else
    {
        cout << endl;
        cout << "Preference not found." << endl;
    }
}

// **************** SEARCHING MENU ****************

void searchingMenu(Activity activities[], int n)
{
    int choice;

    do
    {
        cout << endl;
        cout << "========== SEARCHING MENU ==========" << endl;
        cout << "1. Linear Search" << endl;
        cout << "2. Binary Search" << endl;
        cout << "3. Interpolation Search" << endl;
        cout << "4. Any Two Searching Techniques" << endl;
        cout << "5. All Searching Techniques" << endl;
        cout << "6. Back" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3)
        {
            string key;

            cout << endl;
            cout << "Enter activity to search: ";
            cin.ignore();
            getline(cin, key);

            searchResult(activities, n, key, choice);
        }

        else if (choice == 4)
        {
            int first, second;

            cout << endl;
            cout << "Choose first technique:" << endl;
            cout << "1. Linear Search" << endl;
            cout << "2. Binary Search" << endl;
            cout << "3. Interpolation Search" << endl;
            cout << "Enter choice: ";
            cin >> first;

            cout << endl;
            cout << "Choose second technique:" << endl;
            cout << "1. Linear Search" << endl;
            cout << "2. Binary Search" << endl;
            cout << "3. Interpolation Search" << endl;
            cout << "Enter choice: ";
            cin >> second;

            if (first >= 1 && first <= 3 &&
                second >= 1 && second <= 3 &&
                first != second)
            {
                string key;

                cout << endl;
                cout << "Enter activity to search: ";
                cin.ignore();
                getline(cin, key);

                searchResult(activities, n, key, first);
                searchResult(activities, n, key, second);
            }
            else
            {
                cout << "Invalid choices." << endl;
            }
        }

        else if (choice == 5)
        {
            string key;

            cout << endl;
            cout << "Enter activity to search: ";
            cin.ignore();
            getline(cin, key);

            searchResult(activities, n, key, 1);
            searchResult(activities, n, key, 2);
            searchResult(activities, n, key, 3);
        }

    } while (choice != 6);
}

// **************** MOST TIME ****************

void mostTime(Activity activities[], int n)
{
    int maxIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (activities[i].time > activities[maxIndex].time)
        {
            maxIndex = i;
        }
    }

    cout << endl;
    cout << "You usually spend the most time on: "
         << activities[maxIndex].name << "." << endl;

    int choice;

    cout << endl;
    cout << "How much time?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Total time spent on "
             << activities[maxIndex].name << ": "
             << activities[maxIndex].time
             << " hours" << endl;
    }
}

// **************** MAIN ****************

int main()
{
    Activity activities[MAX];

    int n;

    cout << "****************===========" << endl;
    cout << "     DAILY TIME INVESTMENT ANALYZER" << endl;
    cout << "****************===========" << endl;

    do
    {
        cout << endl;
        cout << "Enter number of activities (minimum 7): ";
        cin >> n;

        if (n < 7)
        {
            cout << "You must enter at least 7 activities." << endl;
        }

        if (n > MAX)
        {
            cout << "Maximum allowed activities are 100." << endl;
        }

    } while (n < 7 || n > MAX);

    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        cout << endl;
        cout << "Enter activity " << i + 1 << ": ";
        getline(cin, activities[i].name);

        cout << "Enter time spent on "
             << activities[i].name << " (hours): ";
        cin >> activities[i].time;

        cin.ignore();
    }

    int choice;

    do
    {
        cout << endl;
        cout << "****************===========" << endl;
        cout << "              MAIN MENU" << endl;
        cout << "****************===========" << endl;
        cout << "1. Display Activities" << endl;
        cout << "2. Sorting Analysis" << endl;
        cout << "3. Searching Analysis" << endl;
        cout << "4. Find Most Time-Consuming Activity" << endl;
        cout << "5. Ask How Much Time" << endl;
        cout << "6. Exit" << endl;

        cout << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayNames(activities, n);
            break;

        case 2:
            sortingMenu(activities, n);
            break;

        case 3:
            searchingMenu(activities, n);
            break;

        case 4:
            mostTime(activities, n);
            break;

        case 5:
            showTime(activities, n);
            break;

        case 6:
            cout << endl;
            cout << "Thank you for using Daily Time Investment Analyzer!"
                 << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 6);

    return 0;
}