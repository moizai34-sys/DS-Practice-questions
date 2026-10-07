#include <iostream>
#include <string>
using namespace std;

// Linear Search
int Linear_Search(int rank[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (rank[i] == target)
            return i;
    }

    return -1;
}

// Sort for Binary and Interpolation Search
void Sort_Ranks(int rank[], string position[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (rank[j] > rank[j + 1])
            {
                int temp = rank[j];
                rank[j] = rank[j + 1];
                rank[j + 1] = temp;

                string tempPosition = position[j];
                position[j] = position[j + 1];
                position[j + 1] = tempPosition;
            }
        }
    }
}

// Binary Search
int Binary_Search(int rank[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (rank[mid] == target)
            return mid;

        if (rank[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// Interpolation Search
int Interpolation_Search(int rank[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high &&
           target >= rank[low] &&
           target <= rank[high])
    {
        if (rank[low] == rank[high])
        {
            if (rank[low] == target)
                return low;

            return -1;
        }

        int pos = low +
            ((target - rank[low]) * (high - low)) /
            (rank[high] - rank[low]);

        if (rank[pos] == target)
            return pos;

        if (rank[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

// Display
void Display(string position[], int rank[], int n)
{
    cout << "\n========== CAREER RANKING ==========\n";

    for (int i = 0; i < n; i++)
    {
        cout << rank[i] << ". " << position[i] << endl;
    }
}

// Search Menu
void Search_Menu(string position[], int rank[], int n)
{
    int choice;
    int target;

    while (true)
    {
        cout << "\n========== SEARCHING MENU ==========\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Interpolation Search\n";
        cout << "4. Any Two Searching Techniques\n";
        cout << "5. All Searching Techniques\n";
        cout << "6. Back\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 6)
            return;

        if (choice < 1 || choice > 5)
        {
            cout << "Invalid choice.\n";
            continue;
        }

        cout << "\nEnter rank to search: ";
        cin >> target;

        if (target < 1 || target > n)
        {
            cout << "Invalid rank.\n";
            continue;
        }

        if (choice == 1)
        {
            int index = Linear_Search(rank, n, target);

            cout << "\nLinear Search:\n";

            if (index != -1)
                cout << "Rank " << target << " = "
                     << position[index] << endl;
            else
                cout << "Rank not found.\n";
        }

        else if (choice == 2)
        {
            int copyRank[10];
            string copyPosition[10];

            for (int i = 0; i < n; i++)
            {
                copyRank[i] = rank[i];
                copyPosition[i] = position[i];
            }

            Sort_Ranks(copyRank, copyPosition, n);

            int index = Binary_Search(copyRank, n, target);

            cout << "\nBinary Search:\n";

            if (index != -1)
                cout << "Rank " << target << " = "
                     << copyPosition[index] << endl;
            else
                cout << "Rank not found.\n";
        }

        else if (choice == 3)
        {
            int copyRank[10];
            string copyPosition[10];

            for (int i = 0; i < n; i++)
            {
                copyRank[i] = rank[i];
                copyPosition[i] = position[i];
            }

            Sort_Ranks(copyRank, copyPosition, n);

            int index = Interpolation_Search(copyRank, n, target);

            cout << "\nInterpolation Search:\n";

            if (index != -1)
                cout << "Rank " << target << " = "
                     << copyPosition[index] << endl;
            else
                cout << "Rank not found.\n";
        }

        else if (choice == 4)
        {
            int first, second;

            cout << "\n1. Linear Search\n";
            cout << "2. Binary Search\n";
            cout << "3. Interpolation Search\n";

            cout << "\nEnter first technique: ";
            cin >> first;

            cout << "Enter second technique: ";
            cin >> second;

            if (first == second ||
                first < 1 || first > 3 ||
                second < 1 || second > 3)
            {
                cout << "Invalid selection.\n";
                continue;
            }

            for (int x = 1; x <= 3; x++)
            {
                if (x != first && x != second)
                    continue;

                int index = -1;

                int copyRank[10];
                string copyPosition[10];

                for (int i = 0; i < n; i++)
                {
                    copyRank[i] = rank[i];
                    copyPosition[i] = position[i];
                }

                if (x == 1)
                {
                    index = Linear_Search(copyRank, n, target);
                    cout << "\nLinear Search:\n";
                }
                else if (x == 2)
                {
                    Sort_Ranks(copyRank, copyPosition, n);
                    index = Binary_Search(copyRank, n, target);
                    cout << "\nBinary Search:\n";
                }
                else
                {
                    Sort_Ranks(copyRank, copyPosition, n);
                    index = Interpolation_Search(copyRank, n, target);
                    cout << "\nInterpolation Search:\n";
                }

                if (index != -1)
                    cout << "Rank " << target << " = "
                         << copyPosition[index] << endl;
                else
                    cout << "Rank not found.\n";
            }
        }

        else if (choice == 5)
        {
            int index;

            index = Linear_Search(rank, n, target);

            cout << "\nLinear Search:\n";

            if (index != -1)
                cout << "Rank " << target << " = "
                     << position[index] << endl;

            int copyRank[10];
            string copyPosition[10];

            for (int i = 0; i < n; i++)
            {
                copyRank[i] = rank[i];
                copyPosition[i] = position[i];
            }

            Sort_Ranks(copyRank, copyPosition, n);

            index = Binary_Search(copyRank, n, target);

            cout << "\nBinary Search:\n";

            if (index != -1)
                cout << "Rank " << target << " = "
                     << copyPosition[index] << endl;

            index = Interpolation_Search(copyRank, n, target);

            cout << "\nInterpolation Search:\n";

            if (index != -1)
                cout << "Rank " << target << " = "
                     << copyPosition[index] << endl;
        }
    }
}

int main()
{
    int choice;

    cout << "========== FUTURE CAREER PATH ANALYZER ==========\n";

    cout << "\n1. Academia\n";
    cout << "2. Industry\n";

    cout << "\nSelect your career path: ";
    cin >> choice;

    cin.ignore();

    string reason;

    if (choice == 1)
    {
        cout << "\nYou selected: Academia\n";

        cout << "Why would you choose Academia?\n";
        getline(cin, reason);

        cout << "\nYour reason: " << reason << endl;

        string position[5] =
        {
            "University Professor/Lecturer",
            "Research Scientist",
            "Research Assistant",
            "PhD Researcher",
            "Academic Researcher"
        };

        int rank[5];

        cout << "\nRank positions from 1 (Most Preferred) "
             << "to 5 (Least Preferred):\n";

        for (int i = 0; i < 5; i++)
        {
            cout << position[i] << ": ";
            cin >> rank[i];
        }

        Display(position, rank, 5);

        Search_Menu(position, rank, 5);
    }

    else if (choice == 2)
    {
        cout << "\nYou selected: Industry\n";

        cout << "Why would you choose Industry?\n";
        getline(cin, reason);

        cout << "\nYour reason: " << reason << endl;

        string position[9] =
        {
            "AI Engineer",
            "Software Engineer",
            "Data Scientist",
            "Machine Learning Engineer",
            "DevOps Engineer",
            "Data Engineer",
            "Cybersecurity Engineer",
            "Project Manager",
            "Cloud Engineer"
        };

        int rank[9];

        cout << "\nRank positions from 1 (Most Preferred) "
             << "to 9 (Least Preferred):\n";

        for (int i = 0; i < 9; i++)
        {
            cout << position[i] << ": ";
            cin >> rank[i];
        }

        Display(position, rank, 9);

        Search_Menu(position, rank, 9);
    }

    else
    {
        cout << "\nInvalid choice.\n";
    }

    cout << "\nThank you for using Future Career Path Analyzer!\n";

    return 0;
}