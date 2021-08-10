#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using std::vector;
using std::string;

bool comparator(string first,string second)
{
    string one = first+second;
    string two = second+first;
    
    int i=0;
    while(one[i] && two[i])
    {
        if(one[i]>two[i])
            return true;
        else if(one[i]<two[i])
            return false;
        ++i;
    }
    
    return false;
}
string largest_number(vector<string> a) {
  
  for(int i=0;i<a.size();++i)
  {
  	int sm=i;
  	for(int j=i+1;i<a.size();++j)
  	{
  		if(comparator(a[i],a[j])==false)
  		sm=j;
	  }
	  swap(a[i],a[sm]);
  }
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
