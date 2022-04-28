#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const long long MX = 1e18;
 
const int N = 200001;
long long Segment_Tree[4*N];
long long Arr[N];
long long Lazy_Tree[4*N] = {0};
 
long long build(int Index , int Left , int Right){
 
  if (Left == Right)
  {
    return Segment_Tree[Index] = Arr[Left];
  }
  else{
    int Mid = (Left + Right) / 2;
    return Segment_Tree[Index] = build(2*Index + 1 , Left , Mid)+build(2*Index + 2, Mid + 1 , Right);
  }
}
 
long long Sum_Query(int Index , int Total_Left , int Total_Right , int Left , int Right){
 
  //Index ====> Index of the Node of Segment Tree.
  //Total_Left ====> Lower bound of the Range of the Segment Tree.
  //Total_Right ====> Upper bound of the Range of the Segment Tree.
  //Left ====> Lower bound of the Query.
  //Right ====> Upper bound of the Query.
 
  if (Left > Right)     //No Overlapp
    return 0;
 
  if (Lazy_Tree[Index] != 0)
  {
    Segment_Tree[Index] += (Total_Right - Total_Left + 1) * Lazy_Tree[Index];
    if (Total_Left != Total_Right)
    {
      Lazy_Tree[2*Index + 1] += Lazy_Tree[Index];
      Lazy_Tree[2*Index + 2] += Lazy_Tree[Index];
    }
    Lazy_Tree[Index] = 0;
  }
 
  if (Total_Left == Left and Total_Right == Right)    //Comaplete Overlapp
    return Segment_Tree[Index];
 
  int Total_Mid = (Total_Left + Total_Right) / 2;     //Partial Overlapp
  return Sum_Query(2*Index + 1 , Total_Left , Total_Mid , Left , min(Right , Total_Mid))
  +Sum_Query(2*Index + 2 , Total_Mid + 1 , Total_Right , max(Left , Total_Mid + 1) , Right);
}
 
void Range_UpDate(int Index , int Total_Left , int Total_Right , int Left , int Right , long long value){
 
  //Index ====> Index of the Node of Segment Tree.
  //Total_Left ====> Lower bound of the Range of the Segment Tree.
  //Total_Right ====> Upper bound of the Range of the Segment Tree.
  //Left ====> Lower bound of the Query.
  //Right ====> Upper bound of the Query.
  //Value ====> Value that we need to add to the Given Range.
 
  if (Left > Right)
    return;
 
  if (Lazy_Tree[Index] != 0)
  {
    Segment_Tree[Index] += (Total_Right - Total_Left + 1) * Lazy_Tree[Index];
    if (Total_Left != Total_Right)
    {
      Lazy_Tree[2*Index + 1] += Lazy_Tree[Index];
      Lazy_Tree[2*Index + 2] += Lazy_Tree[Index];
    }
    Lazy_Tree[Index] = 0;
  }
 
  if (Left > Right)     //No Overlapp
    return ;
 
  if (Total_Left == Left and Total_Right == Right){     //Comaplete Overlapp
    Segment_Tree[Index] += (Total_Right - Total_Left + 1) * value;
    if (Total_Left != Total_Right)
    {
      Lazy_Tree[2*Index + 1] += value;
      Lazy_Tree[2*Index + 2] += value;
    }
    return;
  }
 
  int Total_Mid = (Total_Left + Total_Right) / 2;     //Partial Overlapp
  Range_UpDate(2*Index + 1 , Total_Left , Total_Mid , Left , min(Right , Total_Mid) , value);
  Range_UpDate(2*Index + 2 , Total_Mid + 1 , Total_Right , max(Left , Total_Mid + 1) , Right , value);
  Segment_Tree[Index] = Segment_Tree[2*Index + 1] + Segment_Tree[2*Index + 2];
 
}
 
int main() {
  FAST
  int t = 1;
  //cin >> t;
  while (t--) {
    long long n,m;
    cin>>n>>m;
 
    for (int i = 0; i < n; ++i)
    {
      cin>>Arr[i];
    }
 
    build(0 , 0 , n-1);
    while(m--){
      long long x,u,v,z; 
      cin>>x;
      if (x == 1)
      {
        cin>>u>>v>>z;
        Range_UpDate(0,0,n-1,u-1,v-1,z);
      }
      else{
        cin>>u;
        cout<<Sum_Query(0 , 0 , n-1 , u-1 , u-1)<<endl;
      }
    }
  }
}
