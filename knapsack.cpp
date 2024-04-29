#include <bits/stdc++.h>

using namespace std;

struct Item{
  int weight;
  int value;
};

class Fractional_knapsack{
  public :
    bool static comp(Item a,Item b){
      double r1 = (double) a.value / (double) a.weight;
      double r2 = (double) b.value / (double) b.weight;
      return r1 > r2;
    }

    double fractionalKnapsack(int W,Item arr[],int n){
      sort(arr,arr + n,comp);

      int currWeight = 0;
      double finalvalue = 0.0;

      for(int i=0;i<n;i++){
        if(currWeight + arr[i].weight <= W){
          currWeight += arr[i].weight;
          finalvalue += arr[i].value;
        }
        else{
          int remain = W - currWeight;
          finalvalue += ( arr[i].value / (double)arr[i].weight) * (double)remain;
          break;
        }
      }
      return finalvalue;
    }
};

int main(){
  int n;
  cout << "Enter the number of items :";
  cin >> n;

  cout << "Enter the capacity :";
  int capacity;
  cin>>capacity;
  Item arr[n];

  cout<<"Enter the weights and profits of "<<n<<" items"<<endl;;
  for(int i=0;i<n;i++){
    cout << "Item - "<<i+1<<endl;
    cout<<"Enter weight : ";
    cin>>arr[i].weight;
    cout<<"Enter profit : ";
    cin >> arr[i].value;
  }

  Fractional_knapsack obj;
  double ans = obj.fractionalKnapsack(capacity,arr,n);
  cout << " the final value is : "<< setprecision(2)<<fixed<<ans;
}
