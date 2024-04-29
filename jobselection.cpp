#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Structure to represent a job
struct Job
{
    int start, finish;
};

// Function to compare two jobs based on their finish times
bool compareJobs(Job a, Job b)
{
    return a.finish < b.finish;
}

// Function to find the maximum number of jobs that can be selected
// without overlapping
void selectJobs(Job arr[], int n)
{
    // Sort jobs based on their finish times
    sort(arr, arr + n, compareJobs);

    // Vector to store the selected jobs
    vector<Job> selectedJobs;

    // Select the first job since it has the earliest finish time
    selectedJobs.push_back(arr[0]);

    // Iterate through the remaining jobs
    int lastSelected = 0;
    for (int i = 1; i < n; i++)
    {
        // If the start time of the current job is greater than or equal
        // to the finish time of the last selected job, select the current job
        if (arr[i].start >= arr[lastSelected].finish)
        {
            selectedJobs.push_back(arr[i]);
            lastSelected = i;
        }
    }

    // Print the selected jobs
    cout << "Selected Jobs: " << endl;
    for (int i = 0; i < selectedJobs.size(); i++)
    {
        cout << "Job " << i + 1 << ": Start time = " << selectedJobs[i].start
             << ", Finish time = " << selectedJobs[i].finish << endl;
    }
}

int main()
{
    // Example job array
    Job arr[] = {{1, 3}, {2, 5}, {4, 6}, {6, 7}, {5, 8}, {7, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find and print the selected jobs
    selectJobs(arr, n);

    return 0;
}
